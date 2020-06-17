//
// Created by Philip Tschiemer on 13.06.20.
//

#include <ocac/def.h>
#include <ocac/occ/datatypes/management.h>
#include "occclasses/managers/devicemanager.h"


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
    .ono = 1,
    .class_ptr = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaDeviceManager),
    .name = "DeviceManager",
    .model_guid = {
        .MfrCode = OCAC_DEVICE_MANUFACTURER_CODE,
        .ModelCode = OCAC_DEVICE_MODEL_CODE,
        .Reserved = {0}
    },
    .serial = OCAC_DEVICE_SERIAL_DEFAULT,
    .model_desc = {
        .Manufacturer = OCAC_DEVICE_MANUFACTURER_NAME,
        .Name = OCAC_DEVICE_MODEL_NAME,
        .Version = OCAC_DEVICE_MODEL_VERSION
    },
	.oca_version = OCAC_OCA_VERSION,
	.inventory_code = OCAC_OBJ_DEVICEMANAGER_USERINVENTORYCODE_DEFAULT,
    .state = OcaDeviceState_Initializing,
	.enabled = false,
	.busy = false,
    .reset_cause = OcaResetCause_PowerOn,
    .message = OCAC_OBJ_DEVICEMANAGER_MESSAGE_DEFAULT
};


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


    OCAC_OBJ_TYPE(OcaDeviceManager) * dm = OCAC_OBJ_CAST(OcaDeviceManager, obj);
    OCAC_CLASS_TYPE(OcaDeviceManager) * class_ptr = OCAC_CLASS_CAST(OcaDeviceManager, dm->class_ptr);


    printf(" ModelDescription\n");
    printf("  Manufacturer = %s\n", dm->model_desc.Manufacturer);
    printf("  Name = %s\n", dm->model_desc.Name);
    printf("  Version = %s\n", dm->model_desc.Version);

    printf(" ModelGUID\n");
    printf("  MfrCode = %02X%02X%02X\n", dm->model_guid.MfrCode.bytes[0], dm->model_guid.MfrCode.bytes[1], dm->model_guid.MfrCode.bytes[2]);
    printf("  ModelCode = %02X%02X%02X%02X\n", dm->model_guid.ModelCode.bytes[0], dm->model_guid.ModelCode.bytes[1], dm->model_guid.ModelCode.bytes[2], dm->model_guid.ModelCode.bytes[3]);
    printf("  Reserved = %02X\n", dm->model_guid.Reserved.bytes[0]);

    printf(" Serial = %02X", dm->serial[0]);
    for(int i = 1; i < sizeof(dm->serial); i++){
        printf("%02X", dm->serial[i]);
    }
    printf("\n");

    printf(" OcaVersion = %d\n", dm->oca_version);

    printf(" State = %d\n", dm->state);
    printf(" Enabled = %d\n", dm->enabled);
    printf(" Busy = %d\n", dm->busy);
    printf(" Reset cause = %d\n", dm->reset_cause);

    printf(" Inventory Code (%d) = %s\n", dm->inventory_code.Len, dm->inventory_code.Value);

    printf(" Message (%d) = %s\n", dm->message.Len, dm->message.Value);



}
#endif