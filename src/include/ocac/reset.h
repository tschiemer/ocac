//
// Created by Philip Tschiemer on 24.06.20.
//

#ifndef OCAC_RESET_H
#define OCAC_RESET_H

#include "ocac/arch.h"
#include "ocac/session.h"
#include "ocac/net.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCAC_RESET_OK           0
#define OCAC_RESET_NOK          1

#define OCAC_RESET_NO_MEM       2
#define OCAC_RESET_UNKNOWN_ADDR 3
#define OCAC_RESET_WRONG_KEY    4

struct ocac_reset_cfg {
    u8_t status;
    struct ocac_session * session;
    struct ocac_net_addr addr;
    OcaBlobFixedLen16 key;
} PACK_STRUCT_STRUCT;


u8_t ocac_reset_add_key(struct ocac_session * session, struct ocac_net_addr * addr, OcaBlobFixedLen16 * key);
void ocac_reset_clear_addr(struct ocac_net_addr * addr);
void ocac_reset_clear_session(struct ocac_session * session);

u8_t ocac_reset_check(struct ocac_net_addr * addr, OcaBlobFixedLen16 * key);

#ifdef __cplusplus
}
#endif

#endif //OCAC_RESET_H
