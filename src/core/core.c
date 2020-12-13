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

#include <ocac/ocp/ocp1.h>
#include <ocac/obj.h>
#include <ocac/occ/datatypes/framework.h>
#include "ocac/core.h"

#include "ocac/session.h"


extern OCAC_OBJ_BASE * ocac_obj_registry_get(OcaONo ono);


void ocac_core_init()
{
    ocac_session_init();
}

void ocac_core_deinit()
{
    ocac_session_deinit();
}


void ocac_core_rx_packet(struct ocac_sock * sock, u8_t * inbuf, u32_t inlen, u8_t * outbuf, u32_t maxoutlen)
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
    Ocp1Header inheader;

    ocac_ocp1_header_read(&inheader, &inbuf[1]);

    // check if actual packet length is equal to inbuffer length (+1 for syn byte)
    if (inheader.pduSize + 1 != inlen){

        OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "Invalid packet length");

        // _could_ be treated like a missing sync byte, ie session termination
        return;
    }

    // messagecount must be at least 1
    if (inheader.messageCount == 0){

        OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "invalid message count");

        // (we could choose not to be so strict about it if the packet length is right)
        return;
    }

    if (inheader.pduType == OcaMessageType_KeepAlive){

        // heartbeat messages MUST have a message count of 1 ..
        if (inheader.messageCount != 1){

            OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "invalid message count");

            // (we could choose not to be so strict about it if the packet length is right)
            return;
        }

        if (inlen == 1 + sizeof(Ocp1Header) + sizeof(OcaUint16)){

            u32_t sec = ocac_ntohs(*(u16_t*)&inbuf[1 + sizeof(Ocp1Header)]);

            if (sec == 0){
                OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "invalid heartbeat time");
                return;
            }

            session->heartbeat_msec = 1000 * (u32_t)sec;
        }
        else if (inlen == 1 + sizeof(Ocp1Header) + sizeof(OcaUint32)){

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

    if (inheader.pduType == OcaMessageType_Command || inheader.pduType == OcaMessageType_CommandNR){

        u32_t inpos = 1 + sizeof(Ocp1Header); // sync byte + header
        u32_t outpos = 1 + sizeof(Ocp1Header);

        Ocp1Header outheader;

        ocac_memset( &outheader, 0, sizeof(Ocp1Header));

        for(u16_t i = 0; i < inheader.messageCount; i++){

            // make sure the four first bytes of the message (denoting its total length) are there
            if (inpos + 4 > inlen){
                OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "missing msg size");
                return;
            }

            u32_t len = ocac_ntohl(*(u32_t*)&inbuf[inpos]);

            // make sure all bytes of the message are there
            if (inpos + len > inlen){
                OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "missing msg data");
                return;
            }

            Ocp1CommandRef command;

            ocac_ocp1_commandref_read(&command, &inbuf[inpos]);

            u32_t posbefore = outheader.pduSize;

            ocac_core_command_handler(&command, (inheader.pduType == OcaMessageType_Command), &outbuf[outpos], &outpos, maxoutlen, session);

            // if the outpos changed, a response was written to outbuf
            if (outpos != posbefore){
                outheader.messageCount++;
            }

            inpos += len;
        }

        // if outpos changed response data was written by the handler
        if (outheader.messageCount > 0) {

            // finalize header
            outheader.pduSize = outpos;
            outheader.pduType = OcaMessageType_Response;
            outheader.protocolVersion = OCAC_OCA_VERSION;

            outbuf[0] = OCP_SYNC_VAL;

            //write header to outbuf
            ocac_ocp1_header_write(&outbuf[1], &outheader);

            // TX of outbuf
            ocac_sock_tx(sock, outbuf, outheader.pduSize + 1);
        }

        return;
    }

    #if OCAC_USE_RESPONSE_HANDLER == 1
    if (inheader.pduType == OcaMessageType_Response){

        u32_t pos = 1 + sizeof(Ocp1Header);

        for(u16_t i = 0; i < inheader.messageCount; i++){

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

        return;
    }
    #endif //OCAC_USE_RESPONSE_HANDLER == 1

    #if OCAC_USE_NOTIFICATION_HANDLER == 1
    if (inheader.pduType == OcaMessageType_Notification){

        u32_t pos = 1 + sizeof(Ocp1Header);

        for(u16_t i = 0; i < inheader.messageCount; i++){

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

            Ocp1Notification notification;

            if (ocac_ocp1_notification_read(&notification, &inbuf[pos])){
                OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "corrupt context blob");
                return;
            }

            ocac_core_notification_handler(&notification);

            pos += len;
        }

        return;
    }
    #endif //OCAC_USE_NOTIFICATION_HANDLER == 1

}

u8_t ocac_core_command_handler(Ocp1CommandRef * command, u8_t requirersp, u8_t * outbuf, u32_t * outlen, u32_t maxoutlen, struct ocac_session * session)
{
    OCAC_ASSERT("command != NULL", command != NULL);
    OCAC_ASSERT("outbuf != NULL", outbuf != NULL);
    OCAC_ASSERT("outlen != NULL", outlen != NULL);


    // if a response is required, make sure there is at least space for response meta data
    if (requirersp != 0 && *outlen + sizeof(Ocp1Response) < maxoutlen){

        OCAC_DEBUGF(OCAC_DBG_TRACE | OCAC_DBG_LEVEL_WARNING, "not enough space for msg");

        return 1;
    }

    Ocp1ResponseRef response;

    response.statusCode = OcaStatus_OK;

    // attempt to get the called object
    OCAC_OBJ_BASE * obj = ocac_obj_registry_get(command->targetONo);

    if (obj == NULL){
        response.statusCode = OcaStatus_BadONo;
        response.responseSize = 0;
    } else {
        // note
        // developers implementing class methods may intuitively assume that the passed buffer is the starting point
        // for writing response data and that the outlen reference thus initially is zero.
        // This assumption (which makes developing methods easier in the first place) should be true.

        u32_t pos = *outlen + sizeof(Ocp1Response);
        u32_t len = 0;
        u32_t max = maxoutlen - pos;

        // call class method on object
        // note: response data is written directly to outbuf
        response.statusCode = ocac_obj_exec(obj, command->methodID.DefLevel, command->methodID.MethodIndex, command->parameters.parameters, command->parameters.parameterCount, &outbuf[pos], &len, max, session);

        response.responseSize = len;
    }

    // write response header if either required, there is response data or the command failed
    if (requirersp != 0 || response.responseSize > 0 || response.statusCode != OcaStatus_OK){

        response.responseSize += sizeof(Ocp1Response);
        response.handle = command->handle;

        ocac_ocp1_responseref_write(outbuf, &response);
    }

    return 0;
}

#if OCAC_USE_RESPONSE_HANDLER == 1
__weak void ocac_core_response_handler(Ocp1ResponseRef * response);
#endif

#if OCAC_USE_NOTIFICATION_HANDLER == 1
__weak void ocac_core_notification_handler(Ocp1Notification * notification);
#endif