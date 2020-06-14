//
// Created by Philip Tschiemer on 13.06.20.
//

#include "ocac/occ/classes/managers/device.h"

#ifndef OCAC_CLASS_NO_DEFAULT_ALLOCATION
OCAC_CLASS_TYPE(OcaDeviceManager) OCAC_CLASS_NAME(OcaDeviceManager) = {
    .class_identification = {
        .ClassID = OCAC_CLASS_DEVICEMANAGER_ID,
        .ClassVersion = OCAC_CLASS_DEVICEMANAGER_VERSION
    },
    .parent = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaManager),
    .property_count = OCAC_CLASS_DEVICEMANAGER_PROPERTIES,
    .method_count = OCAC_CLASS_DEVICEMANAGER_METHODS,
    .event_count = OCAC_CLASS_DEVICEMANAGER_EVENTS,
    .methods = {
        OCAC_CLASS_DEVICEMANAGER_XXmXX
    },
    .properties = {
//        OCAC_CLASS_ROOT_01pXX
    },
    .events = {
        OCAC_CLASS_ROOT_01eXX
    },

#if DEBUG
    .dump = ocac_dump_root
#endif

} OCAC_CLASS_ROOT_ATTRIBUTE;
#endif //OCAC_CLASS_NO_DEFAULT_ALLOCATION


#ifndef OCAC_OBJ_NO_DEFAULT_ALLOCATION
OCAC_OBJ_TYPE(OcaDeviceManager) OCAC_OBJ_NAME(OcaDeviceManager) = {
    .class_ptr = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaDeviceManager)
};
#endif


OcaStatus ocac_m_devicemanager_getOcaVersion(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getModelGUID(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getSerialNumber(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getDeviceName(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_setDeviceName(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getModelDescription(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getRole(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_setRole(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getUserInventoryCode(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_setUserInventoryCode(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getEnabled(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_setEnabled(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getState(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_setResetKey(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getResetCause(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_clearResetCause(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getMessage(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_setMessage(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getManagers(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
	return OcaStatus_NotImplemented;
}



#ifdef DEBUG
void ocac_dump_devicemanager(OCAC_OBJ_BASE * obj)
{
    ocac_dump_manager(obj);


    OCAC_OBJ_TYPE(OcaDeviceManager) * devicemanager = OCAC_OBJ_CAST(OcaDeviceManager, obj);
    OCAC_CLASS_TYPE(OcaDeviceManager) * class_ptr = OCAC_CLASS_CAST(OcaDeviceManager, devicemanager->class_ptr);


}
#endif