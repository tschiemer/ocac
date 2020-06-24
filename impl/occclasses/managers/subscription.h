//
// Created by Philip Tschiemer on 19.06.20.
//

#ifndef OCAC_IMPL_OCCCLASSES_MANAGERS_SUBSCRIPTION_H
#define OCAC_IMPL_OCCCLASSES_MANAGERS_SUBSCRIPTION_H

#include "ocac/occ/datatypes/eventsubscription.h"
#include "occclasses/managers/abstract.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * CONSTANTS
 * Don't change!
 */


#define OCAC_CLASS_SUBSCRIPTIONMANAGER_ID          {3, {1,3,4}}
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_VERSION     2
#define OCAC_OBJ_SUBSCRIPTIONMANAGER_ONO           4

#define OCAC__SubscriptionManager_DefLevel  3

#define OCAC__SubscriptionManager_m_addSubscription         1
#define OCAC__SubscriptionManager_m_removeSubscription      2
#define OCAC__SubscriptionManager_m_disableNotifications    3
#define OCAC__SubscriptionManager_m_reenableNotifications   4

#define OCAC__SubscriptionManager_p_state                   1

#define OCAC__SubscriptionManager_e_NotificationDisabled    1
#define OCAC__SubscriptionManager_e_SynchronizeState        2


/**
 * CONFIGURATION
 * Edit here if wanted.
 *
 * To enable/disable a method/property/event define/undefine given method/property/event AND set the number of
 * methods/properties/events accordingly
 */

#define OCAC_CLASS_SUBSCRIPTIONMANAGER_NMETHODS     4
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_NPROPERTIES  1
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_NEVENTS      2


#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03m01       {{3,1}, ocac_m_devicemanager_addSubscription},
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03m02       {{3,2}, ocac_m_devicemanager_removeSubscription},
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03m03       {{3,3}, ocac_m_devicemanager_disableNotifications},
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03m04       {{3,4}, ocac_m_devicemanager_reenableNotifications},

#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03p01

#ifdef OCAC_OVERRIDEABLE_METHODS
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_01m01       {{1,1}, ocac_m_root_getClassIdentification},
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_01m02       {{1,2}, ocac_m_root_getLockable},
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_01m03       {{1,3}, ocac_m_root_lock},
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_01m04       {{1,4}, ocac_m_root_unlock},
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_01m05       {{1,5}, ocac_m_root_getRole},
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_01m06       {{1,5}, ocac_m_root_lockReadonly},
#endif

#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03e01

#define OCAC_OBJ_SUBSCRIPTIONMANAGER_DEF_STATE            OcaSubscriptionManagerState state;

// Add your own definitions if desired
#define OCAC_OBJ_SUBSCRIPTIONMANAGER_DEF_CUSTOM



/** /CONFIGURATION **/



/**
 * AUTO CONFIG
 * You should not need to change anything.
 */

#ifndef OCAC_CLASS_SUBSCRIPTIONMANAGER_03m01
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03m01
#endif
#ifndef OCAC_CLASS_SUBSCRIPTIONMANAGER_03m02
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03m02
#endif
#ifndef OCAC_CLASS_SUBSCRIPTIONMANAGER_03m03
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03m03
#endif
#ifndef OCAC_CLASS_SUBSCRIPTIONMANAGER_03m04
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03m04
#endif

#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03mXX \
    OCAC_CLASS_SUBSCRIPTIONMANAGER_03m01 \
    OCAC_CLASS_SUBSCRIPTIONMANAGER_03m02 \
    OCAC_CLASS_SUBSCRIPTIONMANAGER_03m03 \
    OCAC_CLASS_SUBSCRIPTIONMANAGER_03m04


#ifdef OCAC_OVERRIDEABLE_METHODS


#define OCAC_CLASS_SUBSCRIPTIONMANAGER_XXmXX \
    OCAC_CLASS_SUBSCRIPTIONMANAGER_01m01 \
    OCAC_CLASS_SUBSCRIPTIONMANAGER_01m02 \
    OCAC_CLASS_SUBSCRIPTIONMANAGER_01m03 \
    OCAC_CLASS_SUBSCRIPTIONMANAGER_01m04 \
    OCAC_CLASS_SUBSCRIPTIONMANAGER_03mXX

#define OCAC_CLASS_SUBSCRIPTIONMANAGER_NMETHODS_TOTAL (OCAC_CLASS_SUBSCRIPTIONMANAGER_NMETHODS + OCAC_CLASS_MANAGER_NMETHODS_TOTAL)

#else

#define OCAC_CLASS_SUBSCRIPTIONMANAGER_XXmXX \
    OCAC_CLASS_SUBSCRIPTIONMANAGER_03mXX

#define OCAC_CLASS_SUBSCRIPTIONMANAGER_NMETHODS_TOTAL OCAC_CLASS_SUBSCRIPTIONMANAGER_NMETHODS

#endif //OCAC_OVERRIDEABLE_METHODS



#ifndef OCAC_CLASS_SUBSCRIPTIONMANAGER_03p01
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03p01
#endif

#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03pXX \
    OCAC_CLASS_SUBSCRIPTIONMANAGER_03p01

//#define OCAC_CLASS_SUBSCRIPTIONMANAGER_NPROPERTIES_TOTAL (OCAC_CLASS_SUBSCRIPTIONMANAGER_NPROPERTIES + OCAC_CLASS_MANAGER_NPROPERTIES_TOTAL)
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_NPROPERTIES_TOTAL OCAC_CLASS_SUBSCRIPTIONMANAGER_NPROPERTIES


#ifndef OCAC_CLASS_SUBSCRIPTIONMANAGER_03e01
#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03e01
#endif

#define OCAC_CLASS_SUBSCRIPTIONMANAGER_03eXX \
    OCAC_CLASS_SUBSCRIPTIONMANAGER_03e01

#define OCAC_CLASS_SUBSCRIPTIONMANAGER_NEVENTS_TOTAL OCAC_CLASS_SUBSCRIPTIONMANAGER_NEVENTS


#ifndef OCAC_OBJ_SUBSCRIPTIONMANAGER_DEF_STATE
#define OCAC_OBJ_SUBSCRIPTIONMANAGER_DEF_STATE
#else
#define OCAC_OBJ_SUBSCRIPTIONMANAGER_DEF_STATE_USE
#endif
#ifndef OCAC_OBJ_SUBSCRIPTIONMANAGER_DEF_CUSTOM
#define OCAC_OBJ_SUBSCRIPTIONMANAGER_DEF_CUSTOM
#endif

#define OCAC_OBJ_SUBSCRIPTIONMANAGER_DEF \
    OCAC_OBJ_SUBSCRIPTIONMANAGER_DEF_STATE \
    OCAC_OBJ_SUBSCRIPTIONMANAGER_DEF_CUSTOM


/** /AUTO CONFIG **/


/**
 * CLASS/OBJECT DECLARATION
 * You should not need to edit anything.
 */


/** Class type */
OCAC_CLASS_DEF_BEGIN(OcaSubscriptionManager)
    OCAC_CLASS_DEF_DATA(OCAC_CLASS_SUBSCRIPTIONMANAGER_NMETHODS_TOTAL, OCAC_CLASS_SUBSCRIPTIONMANAGER_NPROPERTIES_TOTAL, OCAC_CLASS_SUBSCRIPTIONMANAGER_NEVENTS_TOTAL)
OCAC_CLASS_DEF_END(OcaSubscriptionManager)


/** Object type */
OCAC_OBJ_DEF_BEGIN(OcaSubscriptionManager)
    OCAC_OBJ_ROOT_DEF
    OCAC_OBJ_MANAGER_DEF
    OCAC_OBJ_SUBSCRIPTIONMANAGER_DEF
OCAC_OBJ_DEF_END(OcaSubscriptionManager)


/** Class object (will be allocated) */
extern OCAC_CLASS_TYPE(OcaSubscriptionManager) OCAC_CLASS_NAME(OcaSubscriptionManager);

/** Object instance (will be allocated) */
extern OCAC_OBJ_TYPE(OcaSubscriptionManager) OCAC_OBJ_NAME(OcaSubscriptionManager);



/** Class methods */
OcaStatus ocac_m_devicemanager_addSubscription(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_devicemanager_removeSubscription(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_devicemanager_disableNotifications(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_devicemanager_reenableNotifications(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);

/** /CLASS/OBJECT DECLARATION **/


#ifdef DEBUG
void ocac_dump_subscriptionmanager(OCAC_OBJ_BASE * obj);
#endif

#ifdef __cplusplus
}
#endif

#endif //OCAC_IMPL_OCCCLASSES_MANAGERS_SUBSCRIPTION_H
