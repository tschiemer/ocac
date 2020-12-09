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

#ifndef OCAC_SESSION_H
#define OCAC_SESSION_H

#include "ocac/arch.h"
#include "ocac/ocp/ocp1.h"
#include "ocac/net.h"
#include "ocac/host/timer.h"

#ifdef __cplusplus
extern "C" {
#endif


#define OCAC_SESSION_STATUS_USED    1

struct ocac_session {
    u8_t status;

    struct ocac_net_addr addr;

    OcaNetworkControlProtocol ocp; // well, as long there is only ocp1 this is somewhat unnecessary..

    Ocp1HeartBeatTimeType heartbeat_type;
    Ocp1KeepAlive heartbeat_interval;

    struct ocac_timer timeout;

    #ifndef OCAC_NO_EVENTS
    u16_t subscription_count;
    struct ocac_net_addr subscription_addr;
    #endif

    #if OCAC_USE_SESSION_POOL == 0
    struct ocac_session * next;
    #endif

} PACK_STRUCT_STRUCT;


void ocac_session_init(void);
void ocac_session_deinit(void);

u16_t ocac_session_count(void);

struct ocac_session * ocac_session_get_by_address(struct ocac_net_addr * addr);

struct ocac_session * ocac_session_new(struct ocac_net_addr * addr);

void ocac_session_delete(struct ocac_session * session);

struct ocac_session * ocac_session_get_timedout(void);

#ifdef __cplusplus
}
#endif


#endif //OCAC_SESSION_H
