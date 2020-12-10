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

//struct ocac_api_buffer {
//    Ocp1Header header;
//    u16_t maxlen;
//    u16_t curlen;
//    u8_t * bytes;
//};
//#define OCAC_API_BUFFER_INIT(__bytes__, __maxlen__) {.bytes = __bytes__, .maxlen = __maxlen__, .curlen = 0 }
//
//inline void ocac_api_buffer_init( struct ocac_api_buffer * buf, u8_t * bytes, u16_t maxlen ){
//    OCAC_ASSERT("buf != NULL", buf != NULL);
//    OCAC_ASSERT("bytes != NULL", bytes != NULL);
//    OCAC_ASSERT("maxlen > 0", maxlen > 0);
//
//    buf->bytes = bytes;
//    buf->maxlen = maxlen;
//    buf->curlen = 0;
//}


void ocac_core_init();

void ocac_core_deinit();


void ocac_core_rx_packet(struct ocac_sock *sock, u8_t *inbuf, u16_t inlen, u8_t *outbuf, u16_t maxoutlen);

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
