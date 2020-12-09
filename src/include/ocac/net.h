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

#ifndef OCAC_NET_H
#define OCAC_NET_H

#include "ocac/arch.h"
#include "ocac/def.h"
#include "ocac/occ/datatypes/base.h"

#ifdef __cplusplus
extern "C" {
#endif

#if OCAC_USE_IPv6
#define OCAC_NET_ADDR_SIZE 16
#else
#define OCAC_NET_ADDR_SIZE 4
#endif

enum ocac_net_ipver {
    ocac_net_ipver_4    = 4,
    ocac_net_ipver_6    = 6
} PACK_STRUCT_STRUCT;

#define OCAC_NET_IPVER_ISVALID( __ip__ ) ( \
    (__ip__) == ocac_net_ipver_4 ||\
    (__ip__) == ocac_net_ipver_6 \
    )

enum ocac_net_type {
    ocac_net_type_none      = 0,
    ocac_net_type_tcp       = 1,
    ocac_net_type_tcpsec    = 2,
    ocac_net_type_udp       = 3,
    ocac_net_type_websocket = 4
} PACK_STRUCT_STRUCT;

#define OCAC_NET_TYPE_ISVALID(__type__) (\
    (__type__) == ocac_net_type_none || \
    (__type__) == ocac_net_type_tcp || \
    (__type__) == ocac_net_type_tcpsec || \
    (__type__) == ocac_net_type_udp || \
    (__type__) == ocac_net_type_websocket \
    )


struct ocac_net_addr {
    enum ocac_net_ipver ipver;
//    enum ocac_net_type type;
    u16_t port;
    u8_t addr[OCAC_NET_ADDR_SIZE];
} PACK_STRUCT_STRUCT;




s32_t ocac_net_str2addr(struct ocac_net_addr * addr, OcaString * str);
s32_t ocac_net_addr2str(OcaString * str, struct ocac_net_addr * addr);

u8_t ocac_net_ipeq(const struct ocac_net_addr * lhs, const struct ocac_net_addr * rhs);

inline u8_t ocac_net_addreq(const struct ocac_net_addr * lhs, const struct ocac_net_addr * rhs)
{
    if (ocac_net_ipeq(lhs, rhs) == false) return false;
    if (lhs->port != rhs->port) return false;

    return true;
}

inline void ocac_net_addrcp(struct ocac_net_addr * to, const struct ocac_net_addr * from)
{
    ocac_memcmp(to, from, sizeof(struct ocac_net_addr));
}

#ifdef DEBUG
void ocac_dump_net_addr(struct ocac_net_addr * addr);
#endif


#ifdef __cplusplus
}
#endif

#endif //OCAC_NET_H
