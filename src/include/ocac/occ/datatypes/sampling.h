//
// Created by Philip Tschiemer on 12.06.20.
//

#ifndef OCAC_SAMPLING_H
#define OCAC_SAMPLING_H

#include "ocac/occ/datatypes/worker.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaMediaClockLockStateUndefined     = 0,
    OcaMediaClockLockStateLocked        = 1,
    OcaMediaClockLockStateSynchronizing = 2,
    OcaMediaClockLockStateFreeRun       = 3,
    OcaMediaClockLockStateStopped       = 4
} PACK_STRUCT_STRUCT OcaMediaClockLockState;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaMediaClockTypeNone       = 0,
    OcaMediaClockTypeInternal   = 1,
    OcaMediaClockTypeNetwork    = 2,
    OcaMediaClockTypeExternal   = 3
} PACK_STRUCT_STRUCT OcaMediaClockType;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaFloat32 Accuracy;
    OcaFloat32 JitterMax;
    OcaFrequency NominalRate;
    OcaFrequency PullRange;
} PACK_STRUCT_STRUCT OcaMediaClockRate;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif

#ifdef __cplusplus
}
#endif

#endif //OCAC_SAMPLING_H
