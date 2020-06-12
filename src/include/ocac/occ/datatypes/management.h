//
// Created by Philip Tschiemer on 11.06.20.
//

#ifndef OCAC_OCC_DATATYPES_MANAGEMENT_H
#define OCAC_OCC_DATATYPES_MANAGEMENT_H

#include "base.h"
#include "framework.h"

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
} OcaPowerState PACK_STRUCT_END;
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
} OcaDeviceState PACK_STRUCT_END;
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaResetCausePowerOn            = 0
    OcaResetCauseInternalError      = 1,
    OcaResetCauseUpgrade            = 2,
    OcaResetCauseExternalRequest    = 3
} OcaResetCause PACK_STRUCT_END;
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif

#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaComponentBootLoader       = 0
} OcaComponent PACK_STRUCT_END;
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
} OcaManagerDescriptor PACK_STRUCT_END;
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
} OcaManagerDefaultObjectNumber PACK_STRUCT_END;
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
} OcaModelGUID PACK_STRUCT_END;
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaString Manufacturer);
    PACK_STRUCT_FIELD(OcaString Name);
    PACK_STRUCT_FIELD(OcaString Version);
} OcaModelDescriptor PACK_STRUCT_END;
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_MANAGEMENT_H
