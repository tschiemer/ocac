//
// Created by Philip Tschiemer on 12.06.20.
//

#ifndef OCAC_OCC_DATATYPESLIBRARY_H
#define OCAC_OCC_DATATYPESLIBRARY_H

#include "ocac/occ/datatypes/framework.h"
#include "ocac/occ/datatypes/worker.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaLibVolType_None      = 0,
    OcaLibVolType_ParamSet  = 1,
    OcaLibVolType_Patch     = 2
} PACK_STRUCT_STRUCT OcaLibVolType;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaLibAccess_None       = 0,
    OcaLibAccess_ReadOnly   = 1,
    OcaLibAccess_ReadExpand = 2,
    OcaLibAccess_Full       = 3
} PACK_STRUCT_STRUCT OcaLibAccess;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


typedef OcaUint32 OcaLibVolID;


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaLibVolID ID;
    OcaONo Library;
} PACK_STRUCT_STRUCT OcaLibVolIdentifier;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
// TODO OcaLibVolMetadata (multiple strings...)
typedef struct {
    OcaLibAccess Access;
    OcaString Creator;
    OcaString Name;
    OcaLibVolType Type;
    OcaTimeOfDay UpDate;
    OcaUint32 Version;
} PACK_STRUCT_STRUCT OcaLibVolMetadata;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif

// TODO OcaLibVol


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaONo TargetBlockType;
    OcaBlob ParData;
} PACK_STRUCT_STRUCT OcaLibVolData_ParamSet;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif

// TODO OcaLibVolData_Patch


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaONo TargetBlockONo;
    OcaLibVolIdentifier ParamSetIdentifier;
} PACK_STRUCT_STRUCT OcaLibParamSetAssignment;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPESLIBRARY_H
