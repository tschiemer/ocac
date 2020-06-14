//
// Created by Philip Tschiemer on 11.06.20.
//

#ifndef OCAC_OCC_DATATYPES_MANAGEMENT_H
#define OCAC_OCC_DATATYPES_MANAGEMENT_H

#include "ocac/occ/datatypes/framework.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaPowerState_None       = 0,
    OcaPowerState_Working    = 1,
    OcaPowerState_Standby    = 2,
    OcaPowerState_Off        = 3
} PACK_STRUCT_STRUCT OcaPowerState;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaDeviceState_Operational       = 0x0001,
    OcaDeviceState_Error             = 0x0002,
    OcaDeviceState_Disabled          = 0x0004,
    OcaDeviceState_Initializing      = 0x0008,
    OcaDeviceState_Updating          = 0x0010,
} PACK_STRUCT_STRUCT OcaDeviceState;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaResetCause_PowerOn            = 0,
    OcaResetCause_InternalError      = 1,
    OcaResetCause_Upgrade            = 2,
    OcaResetCause_ExternalRequest    = 3
} PACK_STRUCT_STRUCT OcaResetCause;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif

#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaComponent_BootLoader       = 0
} PACK_STRUCT_STRUCT OcaComponent;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaClassID ClassID;
    OcaClassVersionNumber ClassVersion;
    OcaONo ObjectNumber;
    OcaString Name;
} PACK_STRUCT_STRUCT OcaManagerDescriptor;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaONo DeviceManager);
    PACK_STRUCT_FIELD(OcaONo SecurityManager);
    PACK_STRUCT_FIELD(OcaONo FirmwareManager);
    PACK_STRUCT_FIELD(OcaONo Subscriptionmanager);
    PACK_STRUCT_FIELD(OcaONo PowerManager);
    PACK_STRUCT_FIELD(OcaONo NetworkManager);
    PACK_STRUCT_FIELD(OcaONo MediaClockManager);
    PACK_STRUCT_FIELD(OcaONo LibraryManager);
    PACK_STRUCT_FIELD(OcaONo OcaDeviceTimeManager);
} PACK_STRUCT_STRUCT OcaManagerDefaultObjectNumber;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaBlobFixedLen3 MfrCode);
    PACK_STRUCT_FIELD(OcaBlobFixedLen4 ModelCode);
    PACK_STRUCT_FIELD(OcaBlobFixedLen1 Reserved);
} PACK_STRUCT_STRUCT OcaModelGUID;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(s8_t Manufacturer[OCAC_DEVICE_MANUFACTURER_NAME_LEN]);
    PACK_STRUCT_FIELD(s8_t Name[OCAC_DEVICE_MODEL_NAME_LEN]);
    PACK_STRUCT_FIELD(s8_t Version[OCAC_DEVICE_MODEL_VERSION_LEN]);
} PACK_STRUCT_STRUCT OcaModelDescription;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_MANAGEMENT_H
