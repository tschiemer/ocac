//
// Created by Philip Tschiemer on 12.06.20.
//

#ifndef OCAC_OCC_DATATYPESLIBRARY_H
#define OCAC_OCC_DATATYPESLIBRARY_H

#include "base.h"
#include "framework.h"
#include "worker.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    OcaLibVolType_None      = 0,
    OcaLibVolType_ParamSet  = 1,
    OcaLibVolType_Patch     = 2
} OcaLibVolType;

typedef OcaUint32 OcaLibVolID;

typedef struct {
    OcaLibVolID ID;
    OcaONo Library;
} OcaLibVolIdentifier;

typedef enum {
    OcaLibAccess_None       = 0,
    OcaLibAccess_ReadOnly   = 1,
    OcaLibAccess_ReadExpand = 2,
    OcaLibAccess_Full       = 3
} OcaLibAccess;

// TODO OcaLibVolMetadata (multiple strings...)
typedef struct {
    OcaLibAccess Access;
    OcaString Creator;
    OcaString Name;
    OcaLibVolType Type;
    OcaTimeOfDay UpDate;
    OcaUint32 Version;
} OcaLibVolMetadata;

// TODO OcaLibVol

typedef struct {
    OcaONo TargetBlockType;
    OcaBlob ParData;
} OcaLibVolData_ParamSet;

// TODO OcaLibVolData_Patch

typedef struct {
    OcaONo TargetBlockONo;
    OcaLibVolIdentifier ParamSetIdentifier;
} OcaLibParamSetAssignment;

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPESLIBRARY_H
