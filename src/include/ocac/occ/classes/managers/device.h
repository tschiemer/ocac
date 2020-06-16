//
// Created by Philip Tschiemer on 13.06.20.
//

#ifndef OCAC_OCC_CLASSES_MANAGERS_DEVICE_H
#define OCAC_OCC_CLASSES_MANAGERS_DEVICE_H

#include <ocac/occ/datatypes/management.h>
#include "manager.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCAC_CLASS_DEVICEMANAGER_ID          {3, {1,3,1}}
#define OCAC_CLASS_DEVICEMANAGER_VERSION     1
#define OCAC_OBJ_DEVICEMANAGER_ONO           1


// actually it's one more
#define OCAC_CLASS_DEVICEMANAGER_PROPERTIES_MAX  12
#define OCAC_CLASS_DEVICEMANAGER_PROPERTIES_MIN  7

#ifdef OCAC_CLASS_NO_METHOD_OVERRIDE
#define OCAC_CLASS_DEVICEMANAGER_METHODS_MAX     19
#define OCAC_CLASS_DEVICEMANAGER_METHODS_MIN     9
#else
#define OCAC_CLASS_DEVICEMANAGER_METHODS_MAX     (OCAC_CLASS_MANAGER_METHODS + 19)
#define OCAC_CLASS_DEVICEMANAGER_METHODS_MIN     (OCAC_CLASS_MANAGER_METHODS + 9)
#endif

#define OCAC_CLASS_DEVICEMANAGER_EVENTS      0

#define OCAC_CLASS_DEVICEMANAGER_03p01
#define OCAC_CLASS_DEVICEMANAGER_03p02
#define OCAC_CLASS_DEVICEMANAGER_03p03
#define OCAC_CLASS_DEVICEMANAGER_03p04
#define OCAC_CLASS_DEVICEMANAGER_03p05

#define OCAC_CLASS_DEVICEMANAGER_01pXX       OCAC_CLASS_DEVICEMANAGER_01p01, OCAC_CLASS_DEVICEMANAGER_01p02, OCAC_CLASS_DEVICEMANAGER_01p03, OCAC_CLASS_DEVICEMANAGER_01p04, OCAC_CLASS_DEVICEMANAGER_01p05

#define OCAC_CLASS_DEVICEMANAGER_03m01       {{3,1}, ocac_m_devicemanager_getOcaVersion}
#define OCAC_CLASS_DEVICEMANAGER_03m02       {{3,2}, ocac_m_devicemanager_getModelGUID}
#define OCAC_CLASS_DEVICEMANAGER_03m03       {{3,3}, ocac_m_devicemanager_getSerialNumber}
#define OCAC_CLASS_DEVICEMANAGER_03m04       {{3,4}, ocac_m_devicemanager_getDeviceName}
#define OCAC_CLASS_DEVICEMANAGER_03m05       {{3,5}, ocac_m_devicemanager_setDeviceName}
#define OCAC_CLASS_DEVICEMANAGER_03m06       {{3,6}, ocac_m_devicemanager_getModelDescription}
#define OCAC_CLASS_DEVICEMANAGER_03m07       {{3,7}, ocac_m_devicemanager_getRole}
#define OCAC_CLASS_DEVICEMANAGER_03m08       {{3,8}, ocac_m_devicemanager_setRole}
#define OCAC_CLASS_DEVICEMANAGER_03m09       {{3,9}, ocac_m_devicemanager_getUserInventoryCode}
#define OCAC_CLASS_DEVICEMANAGER_03m10       {{3,10}, ocac_m_devicemanager_setUserInventoryCode}
#define OCAC_CLASS_DEVICEMANAGER_03m11       {{3,11}, ocac_m_devicemanager_getEnabled}
#define OCAC_CLASS_DEVICEMANAGER_03m12       {{3,12}, ocac_m_devicemanager_setEnabled}
#define OCAC_CLASS_DEVICEMANAGER_03m13       {{3,13}, ocac_m_devicemanager_getState}
#define OCAC_CLASS_DEVICEMANAGER_03m14       {{3,14}, ocac_m_devicemanager_setResetKey}
#define OCAC_CLASS_DEVICEMANAGER_03m15       {{3,15}, ocac_m_devicemanager_getResetCause}
#define OCAC_CLASS_DEVICEMANAGER_03m16       {{3,16}, ocac_m_devicemanager_clearResetCause}
#define OCAC_CLASS_DEVICEMANAGER_03m17       {{3,17}, ocac_m_devicemanager_getMessage}
#define OCAC_CLASS_DEVICEMANAGER_03m18       {{3,18}, ocac_m_devicemanager_setMessage}
#define OCAC_CLASS_DEVICEMANAGER_03m19       {{3,19}, ocac_m_devicemanager_getManagers}


#define OCAC_CLASS_DEVICEMANAGER_03mXX_MAX \
    OCAC_CLASS_DEVICEMANAGER_03m01, \
    OCAC_CLASS_DEVICEMANAGER_03m02, \
    OCAC_CLASS_DEVICEMANAGER_03m03, \
    OCAC_CLASS_DEVICEMANAGER_03m04, \
    OCAC_CLASS_DEVICEMANAGER_03m05, \
    OCAC_CLASS_DEVICEMANAGER_03m06, \
    OCAC_CLASS_DEVICEMANAGER_03m07, \
    OCAC_CLASS_DEVICEMANAGER_03m08, \
    OCAC_CLASS_DEVICEMANAGER_03m09, \
    OCAC_CLASS_DEVICEMANAGER_03m10, \
    OCAC_CLASS_DEVICEMANAGER_03m11, \
    OCAC_CLASS_DEVICEMANAGER_03m12, \
    OCAC_CLASS_DEVICEMANAGER_03m13, \
    OCAC_CLASS_DEVICEMANAGER_03m14, \
    OCAC_CLASS_DEVICEMANAGER_03m15, \
    OCAC_CLASS_DEVICEMANAGER_03m16, \
    OCAC_CLASS_DEVICEMANAGER_03m17, \
    OCAC_CLASS_DEVICEMANAGER_03m18, \
    OCAC_CLASS_DEVICEMANAGER_03m19

#define OCAC_CLASS_DEVICEMANAGER_03mXX_MIN \
    OCAC_CLASS_DEVICEMANAGER_03m01, \
    OCAC_CLASS_DEVICEMANAGER_03m02, \
    OCAC_CLASS_DEVICEMANAGER_03m03, \
    OCAC_CLASS_DEVICEMANAGER_03m04, \
    OCAC_CLASS_DEVICEMANAGER_03m06, \
    OCAC_CLASS_DEVICEMANAGER_03m11, \
    OCAC_CLASS_DEVICEMANAGER_03m12, \
    OCAC_CLASS_DEVICEMANAGER_03m13, \
    OCAC_CLASS_DEVICEMANAGER_03m19

#define OCAC_CLASS_DEVICEMANAGER_XXmXX_MAX \
    OCAC_CLASS_DEVICEMANAGER_01mXX \
    OCAC_CLASS_DEVICEMANAGER_03mXX_MAX

#define OCAC_CLASS_DEVICEMANAGER_XXmXX_MIN \
    OCAC_CLASS_DEVICEMANAGER_01mXX \
    OCAC_CLASS_DEVICEMANAGER_03mXX_MIN \

// no events
#define OCAC_CLASS_DEVICEMANAGER_03eXX


#if OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_CUSTOM
#define OCAC_CLASS_DEVICEMANAGER_PROPERTIES OCAC_CLASS_DEVICEMANAGER_PROPERTIES_CUSTOM
#define OCAC_CLASS_DEVICEMANAGER_METHODS OCAC_CLASS_DEVICEMANAGER_METHODS_CUSTOM
#define OCAC_CLASS_DEVICEMANAGER_03mXX OCAC_CLASS_DEVICEMANAGER_01mXX_CUSTOM
#elif OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MIN
#define OCAC_CLASS_DEVICEMANAGER_PROPERTIES OCAC_CLASS_DEVICEMANAGER_PROPERTIES_MIN
#define OCAC_CLASS_DEVICEMANAGER_METHODS OCAC_CLASS_DEVICEMANAGER_METHODS_MIN
#define OCAC_CLASS_DEVICEMANAGER_03mXX OCAC_CLASS_DEVICEMANAGER_01mXX_MIN
#elif OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MAX
#define OCAC_CLASS_DEVICEMANAGER_PROPERTIES OCAC_CLASS_DEVICEMANAGER_PROPERTIES_MAX
#define OCAC_CLASS_DEVICEMANAGER_METHODS OCAC_CLASS_DEVICEMANAGER_METHODS_MAX
#define OCAC_CLASS_DEVICEMANAGER_03mXX OCAC_CLASS_DEVICEMANAGER_03mXX_MAX
#endif


#ifdef OCAC_CLASS_NO_METHOD_OVERRIDE
#define OCAC_CLASS_DEVICEMANAGER_XXmXX \
    OCAC_CLASS_DEVICEMANAGER_03mXX
#else
#define OCAC_CLASS_DEVICEMANAGER_XXmXX \
    OCAC_CLASS_ROOT_01mXX, \
    OCAC_CLASS_DEVICEMANAGER_03mXX
#endif


#ifndef OCAC_CLASS_NO_DEFAULT_DEFINITION
OCAC_CLASS_DEF_BEGIN(OcaDeviceManager)
    OCAC_CLASS_DEF_DATA(OCAC_CLASS_DEVICEMANAGER_PROPERTIES, OCAC_CLASS_DEVICEMANAGER_METHODS, OCAC_CLASS_DEVICEMANAGER_EVENTS)
OCAC_CLASS_DEF_END(OcaDeviceManager)
#endif






#define OCAC_OBJ_DEVICEMANAGER_DEF_MAX \
    OcaModelGUID model_guid; \
    u8_t serial[OCAC_DEVICE_SERIAL_LEN]; \
    OcaModelDescription model_desc; \
    OCAC_STRING(OCAC_OBJ_DEVICEMANAGER_DEVICENAME_MAXLEN) device_name; \
    OcaUint16 oca_version; \
    OCAC_STRING(OCAC_OBJ_DEVICEMANAGER_INVENTORYCODE_MAXLEN) inventory_code; \
    OcaBoolean enabled; \
    OcaDeviceState state; \
    OcaBoolean busy; \
    OcaResetCause reset_cause; \
    OCAC_STRING(OCAC_OBJ_DEVICEMANAGER_MSG_MAXLEN) message; \
//  OcaList<OcaManagerDescriptor> Managers  // 03p13 (does not make so much sense to use this)
// also not using OCAC_STRING(OCAC_OBJ_ROOT_ROLE_MAXLEN) role; is duplicate

#define OCAC_OBJ_DEVICEMANAGER_DEF_MIN \
    OcaModelGUID model_guid; \
    s8_t serial[OCAC_DEVICE_SERIAL_LEN]; \
    OcaModelDescription model_desc; \
    OCAC_STRING(OCAC_OBJ_DEVICEMANAGER_DEVICENAME_MAXLEN) device_name; \
    OcaUint16 oca_version; \
    OcaBoolean enabled; \
    OcaDeviceState state; \
//  OcaList<OcaManagerDescriptor> Managers  // 03p13 (does not make so much sense to use this)


#if OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_CUSTOM
#define OCAC_OBJ_DEVICEMANAGER_DEF \
    OCAC_OBJ_DEVICEMANAGER_DEF_CUSTOM
#elif OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MIN
#define OCAC_OBJ_DEVICEMANAGER_DEF \
    OCAC_OBJ_DEVICEMANAGER_DEF_MIN \
    OCAC_OBJ_DEVICEMANAGER_DEF_CUSTOM
#elif OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MAX
#define OCAC_OBJ_DEVICEMANAGER_DEF \
    OCAC_OBJ_DEVICEMANAGER_DEF_MAX \
    OCAC_OBJ_DEVICEMANAGER_DEF_CUSTOM
#endif

#ifndef OCAC_OBJ_NO_DEFAULT_DEFINITION
OCAC_OBJ_DEF_BEGIN(OcaDeviceManager)
    OCAC_OBJ_ROOT_DEF
    OCAC_OBJ_MANAGER_DEF
    OCAC_OBJ_DEVICEMANAGER_DEF
OCAC_OBJ_DEF_END(OcaDeviceManager)
#endif



#ifndef OCAC_CLASS_NO_DEFAULT_ALLOCATION
extern OCAC_CLASS_TYPE(OcaDeviceManager) OCAC_CLASS_NAME(OcaDeviceManager);
#endif

#ifndef OCAC_OBJ_NO_DEFAULT_ALLOCATION
extern OCAC_OBJ_TYPE(OcaDeviceManager) OCAC_OBJ_NAME(OcaDeviceManager);
#endif


OcaStatus ocac_m_devicemanager_getOcaVersion(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_getModelGUID(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_getSerialNumber(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_getDeviceName(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_setDeviceName(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_getModelDescription(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_getRole(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_setRole(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_getUserInventoryCode(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_setUserInventoryCode(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_getEnabled(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_setEnabled(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_getState(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_setResetKey(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_getResetCause(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_clearResetCause(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_getMessage(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_setMessage(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_devicemanager_getManagers(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);

#ifdef DEBUG
void ocac_dump_devicemanager(OCAC_OBJ_BASE * obj);
#endif

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_CLASSES_MANAGERS_DEVICE_H
