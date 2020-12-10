/**
 * MIT License
 *
 * Copyright (c) 2020 Philip Tschiemer, https://github.com/tschiemer/ocac
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "ocac/core.h"

#include "ocac/session.h"

void ocac_core_init()
{
    ocac_session_init();
}

void ocac_core_deinit()
{
    ocac_session_deinit();
}


void ocac_core_rx_packet(struct ocac_sock * sock, u8_t * inbuf, u16_t inlen, u8_t * outbuf, u16_t maxoutlen)
{
    OCAC_ASSERT("sock != NULL", sock != NULL);
    OCAC_ASSERT("OCAC_NET_TYPE_ISVALID(sock->type)", OCAC_NET_TYPE_ISVALID(sock->type));
    OCAC_ASSERT("inbuf != NULL", inbuf != NULL);
    OCAC_ASSERT("outbuf != NULL", outbuf != NULL);
    OCAC_ASSERT("maxoutlen > OCAC_OCP1_HEADER_SIZE", maxoutlen > OCAC_OCP1_HEADER_SIZE + 4); // sync + header + at least four bytes of data


    // get session for address
    struct ocac_session * session;

    session = ocac_session_get(sock);

    if (session == NULL){

        // initialize a new session as necessary
        session = ocac_session_new(sock);

        // if we don't have any, there likely isn't enough (pool) space for another session
        if (session == NULL){
            OCAC_DEBUGF(OCAC_DBG_LEVEL_WARNING, "Too small session pool!");
            return;
        }
    }


    // check if first byte is sync value
    if (inbuf[0] != OCP_SYNC_VAL){

        OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "Missing sync byte");

        // the AES70 standard demands that sessions of invalid packets (well, not starting with a sync) are terminated
        ocac_session_delete(session);

        // and sockets terminated (only applies to TCP based sockets)
        // TODO maybe leave this to host implementations??
        if (OCAC_NET_TYPE_ISSTATEFUL(sock->type)){
            ocac_sock_close(sock);
        }
        return;
    }


    // read out PDU header
    Ocp1Header header;

    ocac_ocp1_header_read(&header, &inbuf[1]);

    // check if actual packet length is equal to inbuffer length
    if (header.pduSize + 1 != inlen){

        OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "Invalid packet length");

        // _could_ be treated like a missing sync byte, ie session termination
        return;
    }

    // heartbeat messages MUST have a message count of 1 ..
    if (header.messageCount <= 1){

        OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "invalid message count");

        // (we could choose not to be so strict about it if the packet length is right)
        return;
    }

    if (header.pduType == OcaMessageType_KeepAlive){

        // heartbeat messages MUST have a message count of 1 ..
        if (header.messageCount != 1){

            OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "invalid message count");

            // (we could choose not to be so strict about it if the packet length is right)
            return;
        }

        if (inlen == 1 + sizeof(Ocp1Header) + Ocp1HeartBeatTimeType_Seconds){

            u32_t sec = ocac_ntohs(*(u16_t*)&inbuf[1 + sizeof(Ocp1Header)]);

            if (sec == 0){
                OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "invalid heartbeat time");
                return;
            }

            session->heartbeat_msec = 1000 * (u32_t)sec;
        }
        else if (inlen == 1 + sizeof(Ocp1Header) + Ocp1HeartBeatTimeType_Milliseconds){

            u32_t msec = ocac_ntohl(*(u16_t*)&inbuf[1 + sizeof(Ocp1Header)]);

            if (msec == 0){
                OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "invalid heartbeat time");
                return;
            }

            session->heartbeat_msec = msec;
        }
        else {
            OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "invalid heartbeat message");
            return;
        }

        u32_t timeout = ocac_ocp1_heartbeat_timeout(session->heartbeat_msec);

        ocac_timer_enable(&session->heartbeat_timer, session->heartbeat_msec);
        ocac_timer_enable(&session->heartbeat_remote_timeout, timeout);

        return;
    }

    #if OCAC_USE_RESPONSE_HANDLER == 1
    if (header.pduType == OcaMessageType_Response){
        u16_t pos = 1 + sizeof(Ocp1Header);
        u16_t msgn = header.messageCount;

        for(u16_t i = 0; i < msgn; i++){

            // make sure the four first bytes of the message (denoting its total length) are there
            if (pos + 4 > inlen){
                OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "missing msg size");
                return;
            }

            u32_t len = ocac_ntohl(*(u32_t*)&inbuf[pos]);

            // make sure all bytes of the message are there
            if (pos + len > inlen){
                OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "missing msg data");
                return;
            }

            Ocp1ResponseRef response;

            ocac_ocp1_responseref_read(&response, &inbuf[pos]);

            ocac_core_response_handler(&response);

            pos += len;
        }
    }
    #endif //OCAC_USE_RESPONSE_HANDLER == 1

    #if OCAC_USE_NOTIFICATION_HANDLER == 1
    if (header.pduType == OcaMessageType_Notification){
        u16_t pos = 1 + sizeof(Ocp1Header);
        u16_t msgn = header.messageCount;

        for(u16_t i = 0; i < msgn; i++){

            // make sure the two first bytes of the message (denoting its total length) are there
            if (pos + 4 > inlen){
                OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "missing msg size");
                return;
            }

            u32_t len = ocac_ntohl(*(u32_t*)&inbuf[pos]);

            // make sure all bytes of the message are there
            if (pos + len > inlen){
                OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "missing msg data");
                return;
            }

            Ocp1Notification notification;

            if (ocac_ocp1_notification_read(&notification, &inbuf[pos])){
                OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "corrupt context blob");
                return;
            }

            ocac_core_notification_handler(&notification);

            pos += len;
        }
    }
    #endif //OCAC_USE_NOTIFICATION_HANDLER == 1

}


#if OCAC_USE_RESPONSE_HANDLER == 1
__weak void ocac_core_response_handler(Ocp1ResponseRef * response);
#endif

#if OCAC_USE_NOTIFICATION_HANDLER == 1
__weak void ocac_core_notification_handler(Ocp1Notification * notification);
#endif