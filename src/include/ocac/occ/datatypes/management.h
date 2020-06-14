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
    OcaPowerStateNone       = 0,
    OcaPowerStateWorking    = 1,
    OcaPowerStateStandby    = 2,
    OcaPowerStateOff        = 3
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
    OcaDeviceStateOperational       = 0x0001,
    OcaDeviceStateError             = 0x0002,
    OcaDeviceStateDisabled          = 0x0004,
    OcaDeviceStateInitializing      = 0x0008,
    OcaDeviceStateUpdating          = 0x0010,
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
    OcaResetCausePowerOn            = 0,
    OcaResetCauseInternalError      = 1,
    OcaResetCauseUpgrade            = 2,
    OcaResetCauseExternalRequest    = 3
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
    OcaComponentBootLoader       = 0
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
    PACK_STRUCT_FIELD(OCAC_STRING(OCAC_OCC_MANAGEMENT_MODEL_MANUFACTURER_MAXLEN) Manufacturer);
    PACK_STRUCT_FIELD(OCAC_STRING(OCAC_OCC_MANAGEMENT_MODEL_NAME_MAXLEN) Name);
    PACK_STRUCT_FIELD(OCAC_STRING(OCAC_OCC_MANAGEMENT_MODEL_VERSION_MAXLEN) Version);
} PACK_STRUCT_STRUCT OcaModelDescription;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_MANAGEMENT_H
