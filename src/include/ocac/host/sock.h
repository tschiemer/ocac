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

#ifndef OCAC_HOST_SOCK_H
#define OCAC_HOST_SOCK_H

#include "ocac/arch.h"
#include "ocac/net.h"
#include "ocac/occ/datatypes/framework.h"

#ifndef OCAC_HOST_SOCK_TYPE
#define OCAC_HOST_SOCK_TYPE void *
#endif

struct ocac_sock {
    struct ocac_net_addr addr;  // remote address
    enum ocac_net_type type;    // basic OCP1 connection type
    OCAC_HOST_SOCK_TYPE impl;                // host implementation reference
};

/**
 * Get socket address info.
 */
//extern void ocac_sock_getaddr(struct ocac_sock * sock, struct ocac_net_addr * addr);

/**
 * Send data to given (destination) address using socket
 */
extern void ocac_sock_tx(struct ocac_sock * sock, u8_t * data, u16_t length);


#if OCAC_USE_EVENTS == 1
extern void ocac_sock_tx_fast_notification(struct ocac_net_addr * dst, u8_t * data, u16_t length);
#endif


/**
 * The system might request sockets to be closed/reset.
 * In particular this might be the case, when the first received byte of a PDU is NOT the sync byte.
 */
extern void ocac_sock_close(struct ocac_sock * sock);

/**
 * Open UDP port as given in address struct. If a multicast address is given, join said multicast group.
 * (of course, close/leave any previous port)
 *
 * @return OcaStatus_OK on success
 */
extern OcaStatus ocac_sock_open_resetport(struct ocac_net_addr * addr);


#endif //OCAC_HOST_SOCK_H
