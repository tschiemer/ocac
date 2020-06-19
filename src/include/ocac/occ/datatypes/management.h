//
// Created by Philip Tschiemer on 11.06.20.
//

#ifndef OCAC_OCC_DATATYPES_MANAGEMENT_H
#define OCAC_OCC_DATATYPES_MANAGEMENT_H

#include "ocac/occ/datatypes/framework.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
    OcaONo ObjectNumber;
    OcaString Name;
    OcaClassID ClassID;
    OcaClassVersionNumber ClassVersion;
} PACK_STRUCT_STRUCT OcaManagerDescriptor;



typedef struct {
    PACK_STRUCT_FIELD(OcaONo DeviceManager);            // 1
    PACK_STRUCT_FIELD(OcaONo SecurityManager);          // 2
    PACK_STRUCT_FIELD(OcaONo FirmwareManager);          // 3
    PACK_STRUCT_FIELD(OcaONo SubscriptionManager);      // 4
    PACK_STRUCT_FIELD(OcaONo PowerManager);             // 5
    PACK_STRUCT_FIELD(OcaONo NetworkManager);           // 6
    PACK_STRUCT_FIELD(OcaONo MediaClockManager);        // 7
    PACK_STRUCT_FIELD(OcaONo LibraryManager);           // 8
    PACK_STRUCT_FIELD(OcaONo AudioProcessingManager);   // 9
    PACK_STRUCT_FIELD(OcaONo DeviceTimeManager);        // 10
    PACK_STRUCT_FIELD(OcaONo TaskManager);              // 11
    PACK_STRUCT_FIELD(OcaONo CodingManager);            // 12
    PACK_STRUCT_FIELD(OcaONo DiagnosticManager);        // 13
} PACK_STRUCT_STRUCT OcaManagerDefaultObjectNumber;


// TODO OcaDeviceState (unclear)
typedef enum {
    OcaDeviceState_Operational       = 0x0001,
    OcaDeviceState_Error             = 0x0002,
    OcaDeviceState_Disabled          = 0x0004,
    OcaDeviceState_Initializing      = 0x0008,
    OcaDeviceState_Updating          = 0x0010,

    __OcaDeviceState__               = 0xFFFF
} PACK_STRUCT_STRUCT OcaDeviceState;

//#define OcaDeviceState_Operational  0b1000000000000000
//#define OcaDeviceState_Disabled     0b0100000000000000
//#define OcaDeviceState_Error        0b0010000000000000
//#define OcaDeviceState_Initializing 0b0001000000000000
//#define OcaDeviceState_Updating     0b0000100000000000
//#define OcaDeviceState_Unused       0b0000011111111111
//
//typedef OcaBitSet16 OcaDeviceState;


typedef struct {
    PACK_STRUCT_FIELD(OcaBlobFixedLen1 Reserved); // 0
    PACK_STRUCT_FIELD(OcaBlobFixedLen3 MfrCode); // According to AES70-2 Appendix A this is the IEEE manufacturer code for which you pay ~800$, for valid values see: http://standards-oui.ieee.org/manid/manid.txt
    PACK_STRUCT_FIELD(OcaBlobFixedLen4 ModelCode);
} PACK_STRUCT_STRUCT OcaModelGUID;


typedef struct {
    OCAC_STRING(OCAC_DEVICE_MANUFACTURER_NAME_LEN) Manufacturer;
    OCAC_STRING(OCAC_DEVICE_MODEL_NAME_LEN) Name;
    OCAC_STRING(OCAC_DEVICE_MODEL_VERSION_LEN) Version;
} PACK_STRUCT_STRUCT OcaModelDescription;


typedef enum {
    OcaResetCause_PowerOn            = 0,
    OcaResetCause_InternalError      = 1,
    OcaResetCause_Upgrade            = 2,
    OcaResetCause_ExternalRequest    = 3
} PACK_STRUCT_STRUCT OcaResetCause;





typedef enum {
    OcaPowerState_None       = 0,
    OcaPowerState_Working    = 1,
    OcaPowerState_Standby    = 2,
    OcaPowerState_Off        = 3
} PACK_STRUCT_STRUCT OcaPowerState;



#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_MANAGEMENT_H
