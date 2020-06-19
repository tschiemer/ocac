//
// Created by Philip Tschiemer on 13.06.20.
//

#ifndef OCAC_IMPL_OCCCLASSES_MANAGERS_DEVICE_H
#define OCAC_IMPL_OCCCLASSES_MANAGERS_DEVICE_H

#include "ocac/occ/datatypes/management.h"
#include "occclasses/managers/manager.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * CONSTANTS
 * Don't change!
 */


#define OCAC_CLASS_DEVICEMANAGER_ID          {3, {1,3,1}}
#define OCAC_CLASS_DEVICEMANAGER_VERSION     2
#define OCAC_OBJ_DEVICEMANAGER_ONO           1

#define OCAC__DeviceManager__DefLevel  3

#define OCAC__DeviceManager_getOcaVersion        1
#define OCAC__DeviceManager_getModelGUID         2
#define OCAC__DeviceManager_getSerialNumber      3
#define OCAC__DeviceManager_getDeviceName        4
#define OCAC__DeviceManager_setDeviceName        5
#define OCAC__DeviceManager_getModelDescription  6
#define OCAC__DeviceManager_getRole              7
#define OCAC__DeviceManager_setRole              8
#define OCAC__DeviceManager_getUserInventoryCode 9
#define OCAC__DeviceManager_setUserInventoryCode 10
#define OCAC__DeviceManager_getEnabled           11
#define OCAC__DeviceManager_setEnabled           12
#define OCAC__DeviceManager_getState             13
#define OCAC__DeviceManager_setResetKey          14
#define OCAC__DeviceManager_getResetCause        15
#define OCAC__DeviceManager_clearResetCause      16
#define OCAC__DeviceManager_getMessage           17
#define OCAC__DeviceManager_setMessage           18
#define OCAC__DeviceManager_getManagers          19

/**
 * CONFIGURATION
 * Edit here if wanted.
 *
 * To enable/disable a method/property/event define/undefine given method/property/event AND set the number of
 * methods/properties/events accordingly
 */

#define OCAC_CLASS_DEVICEMANAGER_NMETHODS     19
#define OCAC_CLASS_DEVICEMANAGER_NPROPERTIES  12
#define OCAC_CLASS_DEVICEMANAGER_NEVENTS      0


#define OCAC_CLASS_DEVICEMANAGER_03m01       {{3,1}, ocac_m_devicemanager_getOcaVersion},
#define OCAC_CLASS_DEVICEMANAGER_03m02       {{3,2}, ocac_m_devicemanager_getModelGUID},
#define OCAC_CLASS_DEVICEMANAGER_03m03       {{3,3}, ocac_m_devicemanager_getSerialNumber},
#define OCAC_CLASS_DEVICEMANAGER_03m04       {{3,4}, ocac_m_devicemanager_getDeviceName},
#define OCAC_CLASS_DEVICEMANAGER_03m05       {{3,5}, ocac_m_devicemanager_setDeviceName},
#define OCAC_CLASS_DEVICEMANAGER_03m06       {{3,6}, ocac_m_devicemanager_getModelDescription},
#define OCAC_CLASS_DEVICEMANAGER_03m07       {{3,7}, ocac_m_devicemanager_getRole},
#define OCAC_CLASS_DEVICEMANAGER_03m08       {{3,8}, ocac_m_devicemanager_setRole},
#define OCAC_CLASS_DEVICEMANAGER_03m09       {{3,9}, ocac_m_devicemanager_getUserInventoryCode},
#define OCAC_CLASS_DEVICEMANAGER_03m10       {{3,10}, ocac_m_devicemanager_setUserInventoryCode},
#define OCAC_CLASS_DEVICEMANAGER_03m11       {{3,11}, ocac_m_devicemanager_getEnabled},
#define OCAC_CLASS_DEVICEMANAGER_03m12       {{3,12}, ocac_m_devicemanager_setEnabled},
#define OCAC_CLASS_DEVICEMANAGER_03m13       {{3,13}, ocac_m_devicemanager_getState},
#define OCAC_CLASS_DEVICEMANAGER_03m14       {{3,14}, ocac_m_devicemanager_setResetKey},
#define OCAC_CLASS_DEVICEMANAGER_03m15       {{3,15}, ocac_m_devicemanager_getResetCause},
#define OCAC_CLASS_DEVICEMANAGER_03m16       {{3,16}, ocac_m_devicemanager_clearResetCause},
#define OCAC_CLASS_DEVICEMANAGER_03m17       {{3,17}, ocac_m_devicemanager_getMessage},
#define OCAC_CLASS_DEVICEMANAGER_03m18       {{3,18}, ocac_m_devicemanager_setMessage},
#define OCAC_CLASS_DEVICEMANAGER_03m19       {{3,19}, ocac_m_devicemanager_getManagers},

#define OCAC_CLASS_DEVICEMANAGER_03p01
#define OCAC_CLASS_DEVICEMANAGER_03p02
#define OCAC_CLASS_DEVICEMANAGER_03p03
#define OCAC_CLASS_DEVICEMANAGER_03p04
#define OCAC_CLASS_DEVICEMANAGER_03p05

#ifdef OCAC_OVERRIDEABLE_METHODS
#define OCAC_CLASS_DEVICEMANAGER_01m01       {{1,1}, ocac_m_root_getClassIdentification},
#define OCAC_CLASS_DEVICEMANAGER_01m02       {{1,2}, ocac_m_root_getLockable},
#define OCAC_CLASS_DEVICEMANAGER_01m03       {{1,3}, ocac_m_root_lock},
#define OCAC_CLASS_DEVICEMANAGER_01m04       {{1,4}, ocac_m_root_unlock},
#define OCAC_CLASS_DEVICEMANAGER_01m05       {{1,5}, ocac_m_root_getRole},
#define OCAC_CLASS_DEVICEMANAGER_01m06       {{1,5}, ocac_m_root_lockReadonly},
#endif

#define OCAC_OBJ_DEVICEMANAGER_DEF_MODELGUID            OcaModelGUID model_guid;
#define OCAC_OBJ_DEVICEMANAGER_DEF_SERIAL               OCAC_STRING(sizeof(OCAC_DEVICE_SERIAL_DEFAULT)) serial;
#define OCAC_OBJ_DEVICEMANAGER_DEF_MODELDESC            OcaModelDescription model_desc;
#define OCAC_OBJ_DEVICEMANAGER_DEF_DEVICENAME           OCAC_STRING(OCAC_OBJ_DEVICEMANAGER_DEVICENAME_MAXLEN) device_name;
#define OCAC_OBJ_DEVICEMANAGER_DEF_OCAVERSION           OcaUint16 oca_version; // if is static in firmware this can be set directly in the getter..
#define OCAC_OBJ_DEVICEMANAGER_DEF_USERINVENTORYCODE    OCAC_STRING(OCAC_OBJ_DEVICEMANAGER_USERINVENTORYCODE_MAXLEN) user_inventory_code;
#define OCAC_OBJ_DEVICEMANAGER_DEF_ENABLED              OcaBoolean enabled;
#define OCAC_OBJ_DEVICEMANAGER_DEF_STATE                OcaDeviceState state;
#define OCAC_OBJ_DEVICEMANAGER_DEF_BUSY                 OcaBoolean busy;
#define OCAC_OBJ_DEVICEMANAGER_DEF_RESETCAUSE           OcaResetCause reset_cause;
#define OCAC_OBJ_DEVICEMANAGER_DEF_MESSAGE              OCAC_STRING(OCAC_OBJ_DEVICEMANAGER_MESSAGE_MAXLEN) message;
#define OCAC_OBJ_DEVICEMANAGER_DEF_ROLE                 OCAC_STRING(OCAC_OBJ_ROOT_ROLE_MAXLEN) dm_role; // NOTE: root has role already...
//#define OCAC_OBJ_DEVICEMANAGER_DEF_MANAGERS             OcaList<OcaManagerDescriptor> Managers;  // 03p13 (does not make so much sense to use this)

// Add your own definitions if desired
#define OCAC_OBJ_DEVICEMANAGER_DEF_CUSTOM



/** /CONFIGURATION **/



/**
 * AUTO CONFIG
 * You should not need to change anything.
 */

#ifndef OCAC_CLASS_DEVICEMANAGER_03m01
#define OCAC_CLASS_DEVICEMANAGER_03m01
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m02
#define OCAC_CLASS_DEVICEMANAGER_03m02
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m03
#define OCAC_CLASS_DEVICEMANAGER_03m03
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m04
#define OCAC_CLASS_DEVICEMANAGER_03m04
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m05
#define OCAC_CLASS_DEVICEMANAGER_03m05
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m06
#define OCAC_CLASS_DEVICEMANAGER_03m06
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m07
#define OCAC_CLASS_DEVICEMANAGER_03m07
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m08
#define OCAC_CLASS_DEVICEMANAGER_03m08
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m09
#define OCAC_CLASS_DEVICEMANAGER_03m09
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m10
#define OCAC_CLASS_DEVICEMANAGER_03m10
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m11
#define OCAC_CLASS_DEVICEMANAGER_03m11
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m12
#define OCAC_CLASS_DEVICEMANAGER_03m12
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m13
#define OCAC_CLASS_DEVICEMANAGER_03m13
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m14
#define OCAC_CLASS_DEVICEMANAGER_03m14
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m15
#define OCAC_CLASS_DEVICEMANAGER_03m15
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m16
#define OCAC_CLASS_DEVICEMANAGER_03m16
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m17
#define OCAC_CLASS_DEVICEMANAGER_03m17
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m18
#define OCAC_CLASS_DEVICEMANAGER_03m18
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_03m19
#define OCAC_CLASS_DEVICEMANAGER_03m19
#endif

#define OCAC_CLASS_DEVICEMANAGER_03mXX \
    OCAC_CLASS_DEVICEMANAGER_03m01 \
    OCAC_CLASS_DEVICEMANAGER_03m02 \
    OCAC_CLASS_DEVICEMANAGER_03m03 \
    OCAC_CLASS_DEVICEMANAGER_03m04 \
    OCAC_CLASS_DEVICEMANAGER_03m05 \
    OCAC_CLASS_DEVICEMANAGER_03m06 \
    OCAC_CLASS_DEVICEMANAGER_03m07 \
    OCAC_CLASS_DEVICEMANAGER_03m08 \
    OCAC_CLASS_DEVICEMANAGER_03m09 \
    OCAC_CLASS_DEVICEMANAGER_03m10 \
    OCAC_CLASS_DEVICEMANAGER_03m11 \
    OCAC_CLASS_DEVICEMANAGER_03m12 \
    OCAC_CLASS_DEVICEMANAGER_03m13 \
    OCAC_CLASS_DEVICEMANAGER_03m14 \
    OCAC_CLASS_DEVICEMANAGER_03m15 \
    OCAC_CLASS_DEVICEMANAGER_03m16 \
    OCAC_CLASS_DEVICEMANAGER_03m17 \
    OCAC_CLASS_DEVICEMANAGER_03m18 \
    OCAC_CLASS_DEVICEMANAGER_03m19


#ifdef OCAC_OVERRIDEABLE_METHODS


#define OCAC_CLASS_DEVICEMANAGER_XXmXX \
    OCAC_CLASS_DEVICEMANAGER_01m01 \
    OCAC_CLASS_DEVICEMANAGER_01m02 \
    OCAC_CLASS_DEVICEMANAGER_01m03 \
    OCAC_CLASS_DEVICEMANAGER_01m04 \
    OCAC_CLASS_DEVICEMANAGER_01m05 \
    OCAC_CLASS_DEVICEMANAGER_01m06 \
    OCAC_CLASS_DEVICEMANAGER_03mXX

#define OCAC_CLASS_DEVICEMANAGER_NMETHODS_TOTAL (OCAC_CLASS_DEVICEMANAGER_NMETHODS + OCAC_CLASS_MANAGER_NMETHODS_TOTAL)

#else

#define OCAC_CLASS_DEVICEMANAGER_XXmXX \
    OCAC_CLASS_DEVICEMANAGER_03mXX

#define OCAC_CLASS_DEVICEMANAGER_NMETHODS_TOTAL OCAC_CLASS_DEVICEMANAGER_NMETHODS

#endif //OCAC_OVERRIDEABLE_METHODS



#ifndef OCAC_CLASS_DEVICEMANAGER_01p01
#define OCAC_CLASS_DEVICEMANAGER_01p01
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_01p02
#define OCAC_CLASS_DEVICEMANAGER_01p02
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_01p03
#define OCAC_CLASS_DEVICEMANAGER_01p03
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_01p04
#define OCAC_CLASS_DEVICEMANAGER_01p04
#endif
#ifndef OCAC_CLASS_DEVICEMANAGER_01p05
#define OCAC_CLASS_DEVICEMANAGER_01p05
#endif


#define OCAC_CLASS_DEVICEMANAGER_03pXX \
    OCAC_CLASS_DEVICEMANAGER_03p01 \
    OCAC_CLASS_DEVICEMANAGER_03p02 \
    OCAC_CLASS_DEVICEMANAGER_03p03 \
    OCAC_CLASS_DEVICEMANAGER_03p04 \
    OCAC_CLASS_DEVICEMANAGER_03p05


//#define OCAC_CLASS_DEVICEMANAGER_NPROPERTIES_TOTAL (OCAC_CLASS_DEVICEMANAGER_NPROPERTIES + OCAC_CLASS_MANAGER_NPROPERTIES_TOTAL)
#define OCAC_CLASS_DEVICEMANAGER_NPROPERTIES_TOTAL OCAC_CLASS_DEVICEMANAGER_NPROPERTIES


// no events
#define OCAC_CLASS_DEVICEMANAGER_03eXX

#define OCAC_CLASS_DEVICEMANAGER_NEVENTS_TOTAL OCAC_CLASS_DEVICEMANAGER_NEVENTS


#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_MODELGUID
#define OCAC_OBJ_DEVICEMANAGER_DEF_MODELGUID
#else
#define OCAC_OBJ_DEVICEMANAGER_DEF_MODELGUID_USE
#endif
#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_SERIAL
#define OCAC_OBJ_DEVICEMANAGER_DEF_SERIAL
#else
#define OCAC_OBJ_DEVICEMANAGER_DEF_SERIAL_USE
#endif
#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_MODELDESC
#define OCAC_OBJ_DEVICEMANAGER_DEF_MODELDESC
#else
#define OCAC_OBJ_DEVICEMANAGER_DEF_MODELDESC_USE
#endif
#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_DEVICENAME
#define OCAC_OBJ_DEVICEMANAGER_DEF_DEVICENAME
#else
#define OCAC_OBJ_DEVICEMANAGER_DEF_DEVICENAME_USE
#endif
#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_OCAVERSION
#define OCAC_OBJ_DEVICEMANAGER_DEF_OCAVERSION
#else
#define OCAC_OBJ_DEVICEMANAGER_DEF_OCAVERSION_USE
#endif
#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_USERINVENTORYCODE
#define OCAC_OBJ_DEVICEMANAGER_DEF_USERINVENTORYCODE
#else
#define OCAC_OBJ_DEVICEMANAGER_DEF_USERINVENTORYCODE_USE
#endif
#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_ENABLED
#define OCAC_OBJ_DEVICEMANAGER_DEF_ENABLED
#else
#define OCAC_OBJ_DEVICEMANAGER_DEF_ENABLED_USE
#endif
#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_STATE
#define OCAC_OBJ_DEVICEMANAGER_DEF_STATE
#else
#define OCAC_OBJ_DEVICEMANAGER_DEF_STATE_USE
#endif
#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_BUSY
#define OCAC_OBJ_DEVICEMANAGER_DEF_BUSY
#else
#define OCAC_OBJ_DEVICEMANAGER_DEF_BUSY_USE
#endif
#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_RESETCAUSE
#define OCAC_OBJ_DEVICEMANAGER_DEF_RESETCAUSE
#else
#define OCAC_OBJ_DEVICEMANAGER_DEF_RESETCAUSE_USE
#endif
#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_MESSAGE
#define OCAC_OBJ_DEVICEMANAGER_DEF_MESSAGE
#else
#define OCAC_OBJ_DEVICEMANAGER_DEF_MESSAGE_USE
#endif
#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_ROLE
#define OCAC_OBJ_DEVICEMANAGER_DEF_ROLE
#else
#define OCAC_OBJ_DEVICEMANAGER_DEF_ROLE_USE
#endif
#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_MANAGERS
#define OCAC_OBJ_DEVICEMANAGER_DEF_MANAGERS
#else
#define OCAC_OBJ_DEVICEMANAGER_DEF_MANAGERS_USE
#endif
#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_CUSTOM
#define OCAC_OBJ_DEVICEMANAGER_DEF_CUSTOM
#endif

#define OCAC_OBJ_DEVICEMANAGER_DEF \
    OCAC_OBJ_DEVICEMANAGER_DEF_MODELGUID \
    OCAC_OBJ_DEVICEMANAGER_DEF_SERIAL \
    OCAC_OBJ_DEVICEMANAGER_DEF_MODELDESC \
    OCAC_OBJ_DEVICEMANAGER_DEF_DEVICENAME \
    OCAC_OBJ_DEVICEMANAGER_DEF_OCAVERSION \
    OCAC_OBJ_DEVICEMANAGER_DEF_USERINVENTORYCODE \
    OCAC_OBJ_DEVICEMANAGER_DEF_ENABLED \
    OCAC_OBJ_DEVICEMANAGER_DEF_STATE \
    OCAC_OBJ_DEVICEMANAGER_DEF_BUSY \
    OCAC_OBJ_DEVICEMANAGER_DEF_RESETCAUSE \
    OCAC_OBJ_DEVICEMANAGER_DEF_MESSAGE \
    OCAC_OBJ_DEVICEMANAGER_DEF_ROLE \
    OCAC_OBJ_DEVICEMANAGER_DEF_MANAGERS \
    OCAC_OBJ_DEVICEMANAGER_DEF_CUSTOM


/** /AUTO CONFIG **/


/**
 * CLASS/OBJECT DECLARATION
 * You should not need to edit anything.
 */


/** Class type */
OCAC_CLASS_DEF_BEGIN(OcaDeviceManager)
    OCAC_CLASS_DEF_DATA(OCAC_CLASS_DEVICEMANAGER_NMETHODS_TOTAL, OCAC_CLASS_DEVICEMANAGER_NPROPERTIES_TOTAL, OCAC_CLASS_DEVICEMANAGER_NEVENTS_TOTAL)
OCAC_CLASS_DEF_END(OcaDeviceManager)


/** Object type */
OCAC_OBJ_DEF_BEGIN(OcaDeviceManager)
    OCAC_OBJ_ROOT_DEF
    OCAC_OBJ_MANAGER_DEF
    OCAC_OBJ_DEVICEMANAGER_DEF
OCAC_OBJ_DEF_END(OcaDeviceManager)


/** Class object (will be allocated) */
OCAC_CLASS_TYPE(OcaDeviceManager) OCAC_CLASS_NAME(OcaDeviceManager);

/** Object instance (will be allocated) */
OCAC_OBJ_TYPE(OcaDeviceManager) OCAC_OBJ_NAME(OcaDeviceManager);


/** Class methods */
OcaStatus ocac_m_devicemanager_getOcaVersion(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getModelGUID(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getSerialNumber(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getDeviceName(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_setDeviceName(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getModelDescription(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getRole(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_setRole(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getUserInventoryCode(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_setUserInventoryCode(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getEnabled(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_setEnabled(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getState(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_setResetKey(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getResetCause(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_clearResetCause(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getMessage(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_setMessage(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getManagers(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);


/** /CLASS/OBJECT DECLARATION **/


#ifdef DEBUG
void ocac_dump_devicemanager(OCAC_OBJ_BASE * obj);
#endif

#ifdef __cplusplus
}
#endif

#endif //OCAC_IMPL_OCCCLASSES_MANAGERS_DEVICE_H
