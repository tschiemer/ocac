//
// Created by Philip Tschiemer on 21.06.20.
//

#ifndef OCAC_TIMER_H
#define OCAC_TIMER_H

#include "ocac/arch.h"

struct ocac_timer {
//    u64_t timeout;
    u8_t expired;
    u8_t running;

    void * impl;
} PACK_STRUCT_STRUCT;

extern void ocac_timer_init(struct ocac_timer * timer);

extern void ocac_timer_enable(struct ocac_timer * timer, u32_t millisec);

extern void ocac_timer_disable(struct ocac_timer * timer);

extern void ocac_timer_deinit(struct ocac_timer * timer);



#endif //OCAC_TIMER_H
