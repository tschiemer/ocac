//
// Created by Philip Tschiemer on 24.06.20.
//

#include "ocac/reset.h"

#define OCAC_RESET_STATUS_SET       1
#define OCAC_RESET_STATUS_UNSET     0

static struct ocac_reset_cfg reset_cfgs[OCAC_RESET_CFG_MAX_COUNT];

u8_t ocac_reset_add_key(struct ocac_session * session, struct ocac_net_addr * addr, OcaBlobFixedLen16 * key)
{
    OCAC_ASSERT("session != NULL", session != NULL);
    OCAC_ASSERT("addr != NULL", addr != NULL);
    OCAC_ASSERT("key != NULL", key != NULL);

    // TODO allow only 1 key per session?

    for(int i = 0; i < OCAC_RESET_CFG_MAX_COUNT; i++){
        if (reset_cfgs[i].status == OCAC_RESET_STATUS_UNSET){

            reset_cfgs[i].status = OCAC_RESET_STATUS_SET;

            reset_cfgs[i].session = session;

            ocac_memcpy(&reset_cfgs[i].addr, addr, sizeof(struct ocac_net_addr));
            ocac_memcpy(&reset_cfgs[i].key, key, sizeof(OcaBlobFixedLen16));
        }
    }

    return OCAC_RESET_NO_MEM;
}

void ocac_reset_clear_addr(struct ocac_net_addr * addr)
{
    OCAC_ASSERT("addr != NULL", addr != NULL);

    for(int i = 0; i < OCAC_RESET_CFG_MAX_COUNT; i++){
        if (reset_cfgs[i].status == OCAC_RESET_STATUS_SET && ocac_net_ipeq(&reset_cfgs[i].addr, addr)){

            reset_cfgs[i].status = OCAC_RESET_STATUS_UNSET;
        }
    }
}

void ocac_reset_clear_session(struct ocac_session * session)
{
    OCAC_ASSERT("session != NULL", session != NULL);

    for(int i = 0; i < OCAC_RESET_CFG_MAX_COUNT; i++){
        if (reset_cfgs[i].status == OCAC_RESET_STATUS_SET && reset_cfgs[i].session == session){

            reset_cfgs[i].status = OCAC_RESET_STATUS_UNSET;
        }
    }
}

u8_t ocac_reset_check(struct ocac_net_addr * addr, OcaBlobFixedLen16 * key)
{
    OCAC_ASSERT("addr != NULL", addr != NULL);
    OCAC_ASSERT("key != NULL", key != NULL);


    for(int i = 0; i < OCAC_RESET_CFG_MAX_COUNT; i++){
        if (reset_cfgs[i].status == OCAC_RESET_STATUS_SET && ocac_net_ipeq(&reset_cfgs[i].addr, addr)){

            if (ocac_memcmp(&reset_cfgs[i].key, key, sizeof(OcaBlobFixedLen16)) == 0){
                return OCAC_RESET_OK;
            } else {
                return OCAC_RESET_WRONG_KEY;
            }
        }
    }

    return OCAC_RESET_UNKNOWN_ADDR;
}