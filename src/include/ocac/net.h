//
// Created by Philip Tschiemer on 21.06.20.
//

#ifndef OCAC_NET_H
#define OCAC_NET_H

#include "ocac/arch.h"
#include "ocac/def.h"
#include "ocac/occ/datatypes/base.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef OCAC_USE_IPv6
#define OCAC_NET_ADDR_SIZE 16
#else
#define OCAC_NET_ADDR_SIZE 4
#endif

enum ocac_net_ipver {
    ocac_net_ipver_4  = 4,
    ocac_net_ipver_6 = 6
} PACK_STRUCT_STRUCT;

enum ocac_net_type {
    ocac_net_type_tcp = 1,
    ocac_net_type_udp = 2,
    ocac_net_type_websocket = 3
} PACK_STRUCT_STRUCT;


struct ocac_net_addr {
    enum ocac_net_ipver ipver;
//    enum ocac_net_type type;
    u16_t port;
    u8_t addr[OCAC_NET_ADDR_SIZE];
} PACK_STRUCT_STRUCT;


inline uint8_t ocac_net_addreq(struct ocac_net_addr * dst, struct ocac_net_addr * src)
{
    #ifdef OCAC_USE_IPv6
    return ocac_memcmp(dst, src, dst->ipver == ocac_net_ipver_4 ? 8 : sizeof(struct ocac_net_addr)) == 0;
    #else
    return ocac_memcmp(dst, src, sizeof(struct ocac_net_addr)) == 0;
    #endif
}

s32_t ocac_net_str2addr(struct ocac_net_addr * addr, OcaString * str);
s32_t ocac_net_addr2str(OcaString * str, struct ocac_net_addr * addr);

#ifdef DEBUG
void ocac_dump_net_addr(struct ocac_net_addr * addr);
#endif


#ifdef __cplusplus
}
#endif

#endif //OCAC_NET_H
