//
// Created by Philip Tschiemer on 13.06.20.
//

#include "occclasses/managers/device.h"

#include "ocac/def.h"
#include "ocac/occ/datatypes/management.h"
#include "ocac/utf8.h"
#include "ocac/reset.h"

#include "obj_registry.h"



static OcaStatus marshall_ManagerDescriptor(OCAC_OBJ_TYPE(OcaManager) * mngr, u8_t * dst, u16_t * len, u16_t maxlen);

OCAC_CLASS_TYPE(OcaDeviceManager) OCAC_CLASS_NAME(OcaDeviceManager) = {

    .class_identification = {
        .ClassID = OCAC_CLASS_DEVICEMANAGER_ID,
        .ClassVersion = OCAC_CLASS_DEVICEMANAGER_VERSION
    },

    .parent = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaManager),

    .method_count = OCAC_CLASS_DEVICEMANAGER_NMETHODS_TOTAL,
    .methods = {
        OCAC_CLASS_DEVICEMANAGER_XXmXX
    },

    #ifndef OCAC_NO_PROPERTIES
    .property_count = OCAC_CLASS_DEVICEMANAGER_NPROPERTIES_TOTAL,
    .properties = {
            OCAC_CLASS_DEVICEMANAGER_03pXX
    },
    #endif

    #ifndef OCAC_NO_EVENTS
    .event_count = OCAC_CLASS_DEVICEMANAGER_NEVENTS_TOTAL,
    .events = {
            OCAC_CLASS_ROOT_01eXX
    },
    #endif

    #if DEBUG
    .dump = ocac_dump_devicemanager
    #endif

} OCAC_CLASS_DEVICEMANAGER_ATTRIBUTES;


OCAC_OBJ_TYPE(OcaDeviceManager) OCAC_OBJ_NAME(OcaDeviceManager) = {
    .ono = OCAC_OBJ_DEVICEMANAGER_ONO,
    .class_ptr = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaDeviceManager),

    #ifdef OCAC_OBJ_ROOT_DEF_ROLE_USE
    .role = {7,"DevMngr"},
    #endif

    .mngr_name = {13,"DeviceManager"},

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_MODELGUID_USE
    .model_guid = {
        .MfrCode = OCAC_DEVICE_MANUFACTURER_CODE,
        .ModelCode = OCAC_DEVICE_MODEL_CODE,
        .Reserved = {0}
    },
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_SERIAL_USE
    .serial = {OCAC_DEVICE_SERIAL_UTF8_LEN, OCAC_DEVICE_SERIAL_DEFAULT},
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_MODELDESC_USE
    .model_desc = {
        .Manufacturer = {OCAC_DEVICE_MANUFACTURER_NAME_UTF8_LEN,OCAC_DEVICE_MANUFACTURER_NAME},
        .Name = {OCAC_DEVICE_MODEL_NAME_UTF8_LEN,OCAC_DEVICE_MODEL_NAME},
        .Version = {OCAC_DEVICE_MODEL_VERSION_UTF8_LEN,OCAC_DEVICE_MODEL_VERSION}
    },
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_OCAVERSION_USE
	.oca_version = OCAC_OCA_VERSION,
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_DEVICENAME_USE
    .device_name = OCAC_OBJ_DEVICEMANAGER_DEVICENAME_DEFAULT,
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_USERINVENTORYCODE_USE
	.user_inventory_code = OCAC_OBJ_DEVICEMANAGER_USERINVENTORYCODE_DEFAULT,
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_STATE_USE
    .state = OcaDeviceState_Initializing,
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_ENABLED_USE
	.enabled = false,
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_BUSY_USE
	.busy = false,
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_RESETCAUSE_USE
    .reset_cause = OcaResetCause_PowerOn,
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_MESSAGE_USE
    .message = OCAC_OBJ_DEVICEMANAGER_MESSAGE_DEFAULT,
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_REVISIONID_USE
    .revision_id = {sizeof(OCAC_OBJ_DEVICEMANAGER_REVISIONID_DEFAULT)-1, OCAC_OBJ_DEVICEMANAGER_REVISIONID_DEFAULT},
    #endif
};


OcaStatus ocac_m_devicemanager_getOcaVersion(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    if (0 < maxrsplen && maxrsplen < sizeof(OcaUint16)){
        return OcaStatus_BufferOverflow;
    }

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_OCAVERSION_USE
    *(OcaUint16*)rsp = ocac_htons(OCAC_OBJ_CAST(OcaDeviceManager,obj)->oca_version);
    #else
    OCAC_ASSERT("Not implemented", false):
    #endif

    *rsplen = sizeof(OcaUint16);

	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getModelGUID(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    if (0 < maxrsplen && maxrsplen < sizeof(OcaModelGUID)){
        return OcaStatus_BufferOverflow;
    }

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_MODELGUID_USE
    ocac_memcpy(rsp, &OCAC_OBJ_CAST(OcaDeviceManager,obj)->model_guid, sizeof(OcaModelGUID));
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif

    *rsplen = sizeof(OcaModelGUID);

    return OcaStatus_OK;
}

OcaStatus ocac_m_devicemanager_getSerialNumber(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_SERIAL_USE
    if (0 < maxrsplen && maxrsplen < sizeof(OcaUint16)){
        return OcaStatus_BufferOverflow;
    }

    s32_t bytes = ocac_utf8_cpyn( &rsp[2], OCAC_OBJ_CAST(OcaDeviceManager,obj)->serial.Value, OCAC_OBJ_CAST(OcaDeviceManager,obj)->serial.Len, maxrsplen - sizeof(OcaUint16) );

    // should never occur (internal state should always be valid)
    OCAC_ASSERT("bytes != OCAC_UTF8_INVALID", bytes != OCAC_UTF8_INVALID);

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16*)rsp =  ocac_htons(OCAC_OBJ_CAST(OcaDeviceManager,obj)->serial.Len);

    *rsplen = sizeof(OcaUint16) + bytes;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_getDeviceName(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_DEVICENAME_USE
    if (0 < maxrsplen && maxrsplen < sizeof(OcaUint16)){
        return OcaStatus_BufferOverflow;
    }

    s32_t bytes = ocac_utf8_cpyn( &rsp[2], OCAC_OBJ_CAST(OcaDeviceManager,obj)->device_name.Value, OCAC_OBJ_CAST(OcaDeviceManager,obj)->device_name.Len, maxrsplen - sizeof(OcaUint16) );

    // should never occur (internal state should always be valid)
    OCAC_ASSERT("bytes != OCAC_UTF8_INVALID", bytes != OCAC_UTF8_INVALID);

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16*)rsp =  ocac_htons(OCAC_OBJ_CAST(OcaDeviceManager,obj)->device_name.Len);

    *rsplen = sizeof(OcaUint16) + bytes;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_setDeviceName(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_DEVICENAME_USE

    u16_t len = *(OcaUint16*)req;

    s32_t bytes = ocac_utf8_cpyn( OCAC_OBJ_CAST(OcaDeviceManager,obj)->device_name.Value, &req[2], len, sizeof(OCAC_OBJ_CAST(OcaDeviceManager,obj)->device_name.Value) );

    // should never occur (internal state should always be valid)
    if (bytes == OCAC_UTF8_INVALID){
        return OcaStatus_BadFormat;
    }

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    OCAC_OBJ_CAST(OcaDeviceManager,obj)->device_name.Len = len;

    *rsplen = 0;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_getModelDescription(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_ROLE_USE

    if (0 < maxrsplen && maxrsplen < 3*sizeof(OcaUint16)){
        return OcaStatus_BufferOverflow;
    }

    // 1) manufacturer name
    u32_t bytes = ocac_utf8_cpyn( &rsp[2], OCAC_OBJ_CAST(OcaDeviceManager,obj)->model_desc.Manufacturer.Value, OCAC_OBJ_CAST(OcaDeviceManager,obj)->model_desc.Manufacturer.Len, maxrsplen - sizeof(OcaUint16) );

    // should never occur (internal state should always be valid)
    OCAC_ASSERT("bytes != OCAC_UTF8_INVALID", bytes != OCAC_UTF8_INVALID);

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16 *)rsp = ocac_htons(OCAC_OBJ_CAST(OcaDeviceManager,obj)->model_desc.Manufacturer.Len);

    s32_t size = sizeof(OcaUint16) + bytes;


    // 2) model name
    bytes = ocac_utf8_cpyn( &rsp[size+2], OCAC_OBJ_CAST(OcaDeviceManager,obj)->model_desc.Name.Value, OCAC_OBJ_CAST(OcaDeviceManager,obj)->model_desc.Name.Len, maxrsplen - size - sizeof(OcaUint16) );

    // should never occur (internal state should always be valid)
    OCAC_ASSERT("bytes != OCAC_UTF8_INVALID", bytes != OCAC_UTF8_INVALID);

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16 *)&rsp[size] = ocac_htons(OCAC_OBJ_CAST(OcaDeviceManager,obj)->model_desc.Name.Len);

    size += sizeof(OcaUint16) + bytes;


    // 3) version
    bytes = ocac_utf8_cpyn( &rsp[size+2], OCAC_OBJ_CAST(OcaDeviceManager,obj)->model_desc.Version.Value, OCAC_OBJ_CAST(OcaDeviceManager,obj)->model_desc.Version.Len, maxrsplen - size - sizeof(OcaUint16) );

    // should never occur (internal state should always be valid)
    OCAC_ASSERT("bytes != OCAC_UTF8_INVALID", bytes != OCAC_UTF8_INVALID);

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16 *)&rsp[size] = ocac_htons(OCAC_OBJ_CAST(OcaDeviceManager,obj)->model_desc.Version.Len);

    size += sizeof(OcaUint16) + bytes;

    *rsplen = size;

    return OcaStatus_OK;

    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_getRole(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_ROLE_USE
    if (0 < maxrsplen && maxrsplen < sizeof(OcaUint16)){
        return OcaStatus_BufferOverflow;
    }

    u32_t bytes = ocac_utf8_cpyn( &rsp[2], OCAC_OBJ_CAST(OcaDeviceManager,obj)->dm_role.Value, OCAC_OBJ_CAST(OcaDeviceManager,obj)->dm_role.Len, maxrsplen - sizeof(OcaUint16) );

    // should never occur (internal state should always be valid)
    OCAC_ASSERT("bytes != OCAC_UTF8_INVALID", bytes != OCAC_UTF8_INVALID);

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16 *)rsp = ocac_htons(OCAC_OBJ_CAST(OcaDeviceManager,obj)->dm_role.Len);

    *rsplen = sizeof(OcaUint16) + bytes;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_setRole(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_DEVICENAME_USE

    u16_t len = *(OcaUint16*)req;

    s32_t bytes = ocac_utf8_cpyn( OCAC_OBJ_CAST(OcaDeviceManager,obj)->dm_role.Value, &req[2], len, sizeof(OCAC_OBJ_CAST(OcaDeviceManager,obj)->dm_role.Value) );

    if (bytes == OCAC_UTF8_INVALID){
        return OcaStatus_BadFormat;
    }

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    OCAC_OBJ_CAST(OcaDeviceManager,obj)->dm_role.Len = len;

    *rsplen = 0;

    return OcaStatus_OK;

    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_getUserInventoryCode(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_USERINVENTORYCODE_USE
    if (0 < maxrsplen && maxrsplen < sizeof(OcaUint16)){
        return OcaStatus_BufferOverflow;
    }

    u32_t bytes = ocac_utf8_cpyn( &rsp[2], OCAC_OBJ_CAST(OcaDeviceManager,obj)->user_inventory_code.Value, OCAC_OBJ_CAST(OcaDeviceManager,obj)->user_inventory_code.Len, maxrsplen - sizeof(OcaUint16) );

    // should never occur (internal state should always be valid)
    OCAC_ASSERT("bytes != OCAC_UTF8_INVALID", bytes != OCAC_UTF8_INVALID);

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16 *)rsp = ocac_htons(OCAC_OBJ_CAST(OcaDeviceManager,obj)->user_inventory_code.Len);

    *rsplen = sizeof(OcaUint16) + bytes;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_setUserInventoryCode(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_USERINVENTORYCODE_USE

    u16_t len = *(OcaUint16*)req;

    s32_t bytes = ocac_utf8_cpyn( OCAC_OBJ_CAST(OcaDeviceManager,obj)->user_inventory_code.Value, &req[2], len, sizeof(OCAC_OBJ_CAST(OcaDeviceManager,obj)->user_inventory_code.Value) );

    if (bytes == OCAC_UTF8_INVALID){
        return OcaStatus_BadFormat;
    }

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    OCAC_OBJ_CAST(OcaDeviceManager,obj)->user_inventory_code.Len = len;

    *rsplen = 0;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_getEnabled(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_ENABLED_USE

    *(OcaBoolean*)rsp = ((OCAC_OBJ_TYPE(OcaDeviceManager)*)obj)->enabled;
    *rsplen = sizeof(OcaBoolean);

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_setEnabled(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    if (reqlen != sizeof(OcaBoolean)){
        return OcaStatus_InvalidRequest;
    }

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_ENABLED_USE

    ((OCAC_OBJ_TYPE(OcaDeviceManager)*)obj)->enabled = (*(OcaBoolean*)req) == false;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_getState(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_STATE_USE

    *(OcaDeviceState*)rsp = ((OCAC_OBJ_TYPE(OcaDeviceManager)*)obj)->state;
    *rsplen = sizeof(OcaDeviceState);

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_setResetKey(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    // minimal required length command payload
    if (reqlen < sizeof(OcaBlobFixedLen16) + sizeof(OcaUint16) + 7){
        return OcaStatus_InvalidRequest;
    }

    struct ocac_net_addr addr;

    // validate string...
    u16_t l = ocac_utf8_strlen(&req[sizeof(OcaBlobFixedLen16) + sizeof(OcaUint16)], reqlen - sizeof(OcaBlobFixedLen16) + sizeof(OcaUint16));

    if (l != *(u16_t*)&req[sizeof(OcaBlobFixedLen16)]){
        return OcaStatus_BadFormat;
    }

    if (ocac_net_str2addr(&addr, (OcaString*)&req[sizeof(OcaBlobFixedLen16)]) == false){
        return OcaStatus_BadFormat;
    }

    u8_t result = ocac_reset_add_key(session, &addr, (OcaBlobFixedLen16*)req);

    if (result == OCAC_RESET_NO_MEM){
        return OcaStatus_BufferOverflow;
    }
    if (result != OCAC_RESET_OK){
        return OcaStatus_DeviceError;
    }

    return OcaStatus_OK;
}

OcaStatus ocac_m_devicemanager_getResetCause(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_ENABLED_USE

    *(OcaResetCause*)rsp = ((OCAC_OBJ_TYPE(OcaDeviceManager)*)obj)->reset_cause;
    *rsplen = sizeof(OcaResetCause);

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_clearResetCause(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    if (reqlen != 0){
        return OcaStatus_InvalidRequest;
    }

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_ENABLED_USE

    ((OCAC_OBJ_TYPE(OcaDeviceManager)*)obj)->reset_cause = OcaResetCause_PowerOn;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_getMessage(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_MESSAGE_USE
    if (0 < maxrsplen && maxrsplen < sizeof(OcaUint16)){
        return OcaStatus_BufferOverflow;
    }

    u32_t bytes = ocac_utf8_cpyn( &rsp[2], OCAC_OBJ_CAST(OcaDeviceManager,obj)->message.Value, OCAC_OBJ_CAST(OcaDeviceManager,obj)->message.Len, maxrsplen - sizeof(OcaUint16) );

    // should never occur (internal state should always be valid)
    OCAC_ASSERT("bytes != OCAC_UTF8_INVALID", bytes != OCAC_UTF8_INVALID);

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16 *)rsp = ocac_htons(OCAC_OBJ_CAST(OcaDeviceManager,obj)->message.Len);

    *rsplen = sizeof(OcaUint16) + bytes;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_setMessage(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_MESSAGE_USE

    u16_t len = *(OcaUint16*)req;

    s32_t bytes = ocac_utf8_cpyn( OCAC_OBJ_CAST(OcaDeviceManager,obj)->message.Value, &req[2], len, sizeof(OCAC_OBJ_CAST(OcaDeviceManager,obj)->message.Value) );

    if (bytes == OCAC_UTF8_INVALID){
        return OcaStatus_BadFormat;
    }

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    OCAC_OBJ_CAST(OcaDeviceManager,obj)->message.Len = len;

    *rsplen = 0;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus marshall_ManagerDescriptor(OCAC_OBJ_TYPE(OcaManager) * mngr, u8_t * dst, u16_t * len, u16_t maxlen)
{
    OCAC_ASSERT("mngr != NULL", mngr != NULL);
    OCAC_ASSERT("dst != NULL", dst != NULL);
    OCAC_ASSERT("dst != NULL", dst != NULL);
    OCAC_ASSERT("dst != NULL", dst != NULL);

    // name: 1 (len) OcaUint16 + var string
    // classid : 1 (len) + 3 (id) OcaUint16
    if (0 < maxlen && maxlen < (sizeof(OcaONo) + 5*sizeof(OcaUint16) + sizeof(OcaClassVersionNumber))){
        return OcaStatus_BufferOverflow;
    }


    *(OcaONo*)dst = ocac_htonl(mngr->ono);

    u16_t size = sizeof(OcaONo) + sizeof(OcaUint16);

    u32_t bytes = ocac_utf8_cpyn( &dst[size], mngr->mngr_name.Value, mngr->mngr_name.Len, maxlen - size);

    // should ever occur
    OCAC_ASSERT("bytes != OCAC_UTF8_INVALID", bytes != OCAC_UTF8_INVALID);

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16 *)&dst[sizeof(OcaONo)] = ocac_htons(mngr->mngr_name.Len);

    size += bytes;

    OCAC_ASSERT("mngr->class_ptr != NULL", mngr->class_ptr != NULL);

    if  (0 < maxlen && size < maxlen && maxlen - size < sizeof(OcaUint16) * (mngr->class_ptr->class_identification.ClassID.FieldCount + 2)){
        return OcaStatus_BufferOverflow;
    }

    // TODO
    // should always be 3 unless you are using a custom manager..
    u16_t f = mngr->class_ptr->class_identification.ClassID.FieldCount;

    OCAC_ASSERT("f != OcaClassAuthorityID_Sentinel", f != OcaClassAuthorityID_Sentinel);

    *(OcaUint16*)&dst[size] = ocac_htons(f);
    size += sizeof(OcaUint16);

    for (u16_t i = 0; i < f; i++){
        *(OcaUint16*)&dst[size] = ocac_htons(mngr->class_ptr->class_identification.ClassID.Fields[i]);
        size += sizeof(OcaUint16);
    }


    *(OcaUint16*)&dst[size] = ocac_htons(mngr->class_ptr->class_identification.ClassVersion);
    size += sizeof(OcaUint16);

    *len = size;

    return OcaStatus_OK;
}

OcaStatus ocac_m_devicemanager_getManagers(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    if (0 < maxrsplen && maxrsplen < sizeof(OcaUint16)){
        return OcaStatus_BufferOverflow;
    }


    *(OcaUint16*)rsp = ocac_htons(OCAC_MANAGER_COUNT);

    u16_t tsize = sizeof(OcaUint16);

    for(u8_t i = 0; i < OCAC_MANAGER_COUNT; i++){
        u16_t size = 0;
        OcaStatus status = marshall_ManagerDescriptor( (OCAC_OBJ_TYPE(OcaManager)*)ocac_managers[i], &rsp[tsize], &size, maxrsplen - tsize);

        if (status != OcaStatus_OK){
            return status;
        }

        tsize += size;
    }

    *rsplen = tsize;

    return OcaStatus_OK;
}

OcaStatus ocac_m_devicemanager_getRevisionID(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_REVISIONID_USE
    if (0 < maxrsplen && maxrsplen < sizeof(OcaUint16)){
        return OcaStatus_BufferOverflow;
    }

    u32_t bytes = ocac_utf8_cpyn( &rsp[2], OCAC_OBJ_CAST(OcaDeviceManager,obj)->revision_id.Value, OCAC_OBJ_CAST(OcaDeviceManager,obj)->revision_id.Len, maxrsplen - sizeof(OcaUint16) );

    // should never occur (internal state should always be valid)
    OCAC_ASSERT("bytes != OCAC_UTF8_INVALID", bytes != OCAC_UTF8_INVALID);

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16 *)rsp = ocac_htons(OCAC_OBJ_CAST(OcaDeviceManager,obj)->revision_id.Len);

    *rsplen = sizeof(OcaUint16) + bytes;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

#ifdef DEBUG
void ocac_dump_devicemanager(OCAC_OBJ_BASE * obj)
{
    ocac_dump_manager(obj);


    OCAC_OBJ_TYPE(OcaDeviceManager) * dm = OCAC_OBJ_CAST(OcaDeviceManager, obj);
    OCAC_CLASS_TYPE(OcaDeviceManager) * class_ptr = OCAC_CLASS_CAST(OcaDeviceManager, dm->class_ptr);

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_MODELDESC_USE
    printf(" ModelDescription\n");

    printf("  Manufacturer = ");
    ocac_dump_string( (OcaString*)&dm->model_desc.Manufacturer );
    printf("\n");
    printf("  Name = ");
    ocac_dump_string( (OcaString*)&dm->model_desc.Name );
    printf("\n");
    printf("  Version = ");
    ocac_dump_string( (OcaString*)&dm->model_desc.Version );
    printf("\n");
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_MODELGUID_USE
    printf(" ModelGUID\n");
    printf("  MfrCode = %02X%02X%02X\n", dm->model_guid.MfrCode.bytes[0], dm->model_guid.MfrCode.bytes[1], dm->model_guid.MfrCode.bytes[2]);
    printf("  ModelCode = %02X%02X%02X%02X\n", dm->model_guid.ModelCode.bytes[0], dm->model_guid.ModelCode.bytes[1], dm->model_guid.ModelCode.bytes[2], dm->model_guid.ModelCode.bytes[3]);
    printf("  Reserved = %02X\n", dm->model_guid.Reserved.bytes[0]);
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_SERIAL_USE
    printf(" Serial = ");
    ocac_dump_string( (OcaString*)&dm->serial );
    printf("\n");
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_OCAVERSION_USE
    printf(" OcaVersion = %d\n", dm->oca_version);
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_ROLE_USE
    printf(" DM Role = ");
    ocac_dump_string((OcaString*)&dm->dm_role);
    printf("\n");
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_DEVICENAME_USE
    printf(" Device Name = ");
    ocac_dump_string((OcaString*)&dm->device_name);
    printf("\n");
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_STATE_USE
    printf(" State = %d\n", dm->state);
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_ENABLED_USE
    printf(" Enabled = %d\n", dm->enabled);
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_BUSY_USE
    printf(" Busy = %d\n", dm->busy);
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_RESETCAUSE_USE
    printf(" Reset cause = %d\n", dm->reset_cause);
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_USERINVENTORYCODE_USE
    printf(" User Inventory Code = ");
    ocac_dump_string((OcaString*)&dm->user_inventory_code);
    printf("\n");
    #endif

    #ifdef OCAC_OBJ_DEVICEMANAGER_DEF_MESSAGE_USE
    printf(" Message = ");
    ocac_dump_string((OcaString*)&dm->message);
    printf("\n");
    #endif



}
#endif