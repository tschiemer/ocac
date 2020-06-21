//
// Created by Philip Tschiemer on 12.06.20.
//

#ifndef OCAC_OCC_DATATYPESLIBRARY_H
#define OCAC_OCC_DATATYPESLIBRARY_H

#include "ocac/occ/datatypes/framework.h"
#include "ocac/occ/datatypes/worker.h"
#include "ocac/occ/datatypes/time.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    OcaLibVolStandardTypeID_None        = 0,
    OcaLibVolStandardTypeID_ParamSet    = 1,
    OcaLibVolStandardTypeID_Patch       = 2,
    OcaLibVolStandardTypeID_Program     = 3
} PACK_STRUCT_STRUCT OcaLibVolStandardTypeID;

typedef struct {
    OcaOrganizationID Authority;
    OcaUint32 ID;
} PACK_STRUCT_STRUCT OcaLibVolType;


typedef struct {
    OcaLibVolType Type;
    OcaONo ONo;
} PACK_STRUCT_STRUCT OcaLibraryIdentifier;


typedef OcaUint32 OcaLibVolID;

typedef struct {
    OcaONo Library;
    OcaLibVolID ID;
} PACK_STRUCT_STRUCT OcaLibVolIdentifier;


typedef enum {
    OcaLibAccess_None       = 0,
    OcaLibAccess_ReadOnly   = 1,
    OcaLibAccess_ReadExpand = 2,
    OcaLibAccess_Full       = 3
} PACK_STRUCT_STRUCT OcaLibAccess;



// TODO OcaLibVolMetadata (multiple strings...)
typedef struct {
    OCAC_STRING(OCAC_OCC_LIBRARY_LIBVOLMETADATA_NAME_MAXLEN) Name;
    OcaLibVolType Type;
    OcaLibAccess Access;
    OcaUint32 Version;
    OCAC_STRING(OCAC_OCC_LIBRARY_LIBVOLMETADATA_CREATOR_MAXLEN) Creator;
    OcaTimePTP UpDate;
} PACK_STRUCT_STRUCT OcaLibVolMetadata;

// TODO OcaLibVol
//typedef struct {
//    OcaLibVolMetadata Metadata;
//    OcaBlob Data;
//} OcaLibVol;

typedef struct {
    OcaONo TargetBlockType;
    OcaBlob ParData;
} PACK_STRUCT_STRUCT OcaLibVolData_ParamSet;

typedef struct {
    OcaLibVolIdentifier ParamSetIdentifier;
    OcaONo TargetBlockONo;
} PACK_STRUCT_STRUCT OcaLibParamSetAssignment;

// TODO OcaLibVolData_Patch
typedef struct {
    OCAC_LIST(OcaLibParamSetAssignment,) Assignments;
} PACK_STRUCT_STRUCT OcaLibVolData_Patch;

typedef struct {
    OcaBlob ProgramContent;
} PACK_STRUCT_STRUCT OcaLiobVolData_Program;

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPESLIBRARY_H
