//
// Created by Philip Tschiemer on 12.06.20.
//

#ifndef OCAC_OCC_DATATYPES_AGENT_H
#define OCAC_OCC_DATATYPES_AGENT_H

#include "framework.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaRamperInterpolationLaw_Linear        = 1,
    OcaRamperInterpolationLaw_ReverseLinear = 2,
    OcaRamperInterpolationLaw_Sine          = 3,
    OcaRamperInterpolationLaw_Exponential   = 4
} PACK_STRUCT_STRUCT OcaRamperInterpolationLaw;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaRamperTimeMode_Absolute  = 1,
    OcaRamperTimeMode_Relative  = 2
} PACK_STRUCT_STRUCT OcaRamperTimeMode;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaRamperRunCommand_Enable  = 1,
    OcaRamperRunCommand_Start   = 2,
    OcaRamperRunCommand_Halt    = 3
} OcaRamperRunCommand;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaRamperState_NotInitialized   = 1,
    OcaRamperState_Initialized      = 2,
    OcaRamperState_Scheduled        = 3,
    OcaRamperState_Enabled          = 4,
    OcaRamperState_Ramping          = 5
} PACK_STRUCT_STRUCT OcaRamperState;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaObserverState_NotTriggered   = 0,
    OcaObserverState_Triggered      = 1,
} PACK_STRUCT_STRUCT OcaObserverState;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaRelationalOperator_None                  = 0,
    OcaRelationalOperator_Equality              = 1,
    OcaRelationalOperator_Inequality            = 2,
    OcaRelationalOperator_GreaterThan           = 3,
    OcaRelationalOperator_GreaterThanOrEqual    = 4,
    OcaRelationalOperator_LessThan              = 5,
    OcaRelationalOperator_LessThanOrEqual       = 6
} PACK_STRUCT_STRUCT OcaRelationalOperator;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaPowerSupplyType_None     = 0,
    OcaPowerSupplyType_Mains    = 1,
    OcaPowerSupplyType_Battery  = 2,
    OcaPowerSupplyType_Phantom  = 3,
    OcaPowerSupplyType_Solar    = 4
} PACK_STRUCT_STRUCT OcaPowerSupplyType;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaPowerSupplyLocation_Unspecified  = 1,
    OcaPowerSupplyLocation_Internal     = 2,
    OcaPowerSupplyLocation_External     = 3
} PACK_STRUCT_STRUCT OcaPowerSupplyLocation;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaPowerSupplyState_Off         = 1,
    OcaPowerSupplyState_Unavailable = 2,
    OcaPowerSupplyState_Available   = 3,
    OcaPowerSupplyState_Active      = 4
} PACK_STRUCT_STRUCT OcaPowerSupplyState;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaGrouperMode_MasterSlave  = 1,
    OcaGrouperMode_PeerToPeer   = 2
} PACK_STRUCT_STRUCT OcaGrouperMode;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaUint16 Index;
    OcaONo ProxyONo;
    OcaString Name;
} PACK_STRUCT_STRUCT OcaGrouperGroup;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaUint16 Index;
    OcaOPath ObjectPath;
    OcaBoolean Online;
} PACK_STRUCT_STRUCT OcaGrouperCitizen;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaUint16 CitizenIndex;
    OcaUint16 GroupIndex;
} PACK_STRUCT_STRUCT OcaGrouperEnrollment;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaFloat64 Reading;
} PACK_STRUCT_STRUCT OcaObservationEventData;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_AGENT_H
