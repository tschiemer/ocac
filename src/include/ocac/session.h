//
// Created by Philip Tschiemer on 17.06.20.
//

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
