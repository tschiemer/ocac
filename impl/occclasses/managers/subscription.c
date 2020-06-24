//
// Created by Philip Tschiemer on 19.06.20.
//

#include "occclasses/managers/subscription.h"


OCAC_CLASS_TYPE(OcaSubscriptionManager) OCAC_CLASS_NAME(OcaSubscriptionManager) = {

    .class_identification = {
        .ClassID = OCAC_CLASS_SUBSCRIPTIONMANAGER_ID,
        .ClassVersion = OCAC_CLASS_SUBSCRIPTIONMANAGER_VERSION
    },

    .parent = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaManager),

    .method_count = OCAC_CLASS_SUBSCRIPTIONMANAGER_NMETHODS_TOTAL,
    .methods = {
        OCAC_CLASS_SUBSCRIPTIONMANAGER_XXmXX
    },

#ifndef OCAC_NO_PROPERTIES
    .property_count = OCAC_CLASS_SUBSCRIPTIONMANAGER_NPROPERTIES_TOTAL,
    .properties = {
        OCAC_CLASS_SUBSCRIPTIONMANAGER_03pXX
    },
#endif

#ifndef OCAC_NO_EVENTS
    .event_count = OCAC_CLASS_SUBSCRIPTIONMANAGER_NEVENTS_TOTAL,
    .events = {
        OCAC_CLASS_SUBSCRIPTIONMANAGER_03eXX
    },
#endif

#if DEBUG
        .dump = ocac_dump_subscriptionmanager
#endif

} OCAC_CLASS_SUBSCRIPTIONMANAGER_ATTRIBUTES;


OCAC_OBJ_TYPE(OcaSubscriptionManager) OCAC_OBJ_NAME(OcaSubscriptionManager) = {
    .ono = OCAC_OBJ_SUBSCRIPTIONMANAGER_ONO,
    .class_ptr = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaSubscriptionManager),

    #ifdef OCAC_OBJ_ROOT_DEF_ROLE_USE
    .role = {8,"SubsMngr"},
    #endif

    .mngr_name = {19,"SubscriptionManager"},

    #ifdef OCAC_OBJ_SUBSCRIPTIONMANAGER_DEF_STATE_USE
    .state = OcaSubscriptionManagerState_EventsDisabled,
    #endif
};


OcaStatus ocac_m_devicemanager_addSubscription(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}


OcaStatus ocac_m_devicemanager_removeSubscription(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_disableNotifications(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_reenableNotifications(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}


#ifdef DEBUG
void ocac_dump_subscriptionmanager(OCAC_OBJ_BASE * obj){

    ocac_dump_manager(obj);

    OCAC_OBJ_TYPE(OcaSubscriptionManager) * mngr_obj = OCAC_OBJ_CAST(OcaSubscriptionManager,obj);

    #ifdef OCAC_OBJ_MANAGER_DEF_STATE_USE
    printf(" State = %d\n", mngr_obj->state);
    #endif
}
#endif