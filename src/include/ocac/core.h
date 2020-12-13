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

#ifndef OCAC_CORE_H
#define OCAC_CORE_H

#include "ocac/host/sock.h"
#include "ocac/ocp/ocp1.h"
#include "ocac/opt.h"

#ifdef __cplusplus
extern "C" {
#endif


void ocac_core_init();

void ocac_core_deinit();


void ocac_core_rx_packet(struct ocac_sock *sock, u8_t *inbuf, u32_t inlen, u8_t *outbuf, u32_t maxoutlen);

u8_t ocac_core_command_handler(Ocp1CommandRef * command, u8_t requirersp, u8_t * outbuf, u32_t * outlen, u32_t maxoutlen, struct ocac_session * session);


#if OCAC_USE_RESPONSE_HANDLER == 1
void ocac_core_response_handler(Ocp1ResponseRef * response);
#endif


#if OCAC_USE_NOTIFICATION_HANDLER == 1
void ocac_core_notification_handler(Ocp1Notification * notification);
#endif

#ifdef __cplusplus
}
#endif

#endif //OCAC_CORE_H
