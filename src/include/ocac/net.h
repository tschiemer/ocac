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

#if OCAC_USE_IPv6
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




s32_t ocac_net_str2addr(struct ocac_net_addr * addr, OcaString * str);
s32_t ocac_net_addr2str(OcaString * str, struct ocac_net_addr * addr);

u8_t ocac_net_ipeq(const struct ocac_net_addr * lhs, const struct ocac_net_addr * rhs);

inline u8_t ocac_net_addreq(const struct ocac_net_addr * lhs, const struct ocac_net_addr * rhs)
{
    if (ocac_net_ipeq(lhs, rhs) == false) return false;
    if (lhs->port != rhs->port) return false;

    return true;
}

#ifdef DEBUG
void ocac_dump_net_addr(struct ocac_net_addr * addr);
#endif


#ifdef __cplusplus
}
#endif

#endif //OCAC_NET_H
