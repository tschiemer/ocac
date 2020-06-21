//
// Created by Philip Tschiemer on 12.06.20.
//

#ifndef OCAC_OCC_DATATYPES_BLOCKMATRIX_H
#define OCAC_OCC_DATATYPES_BLOCKMATRIX_H


#include "ocac/occ/datatypes/framework.h"
#include "ocac/occ/datatypes/network.h"


#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
    OcaObjectIdentification MemberObjectIdentification;
    OcaONo ContainerObjectNumber;
} PACK_STRUCT_STRUCT OcaBlockMember;


typedef enum {
    OcaPortMode_Input   = 1,
    OcaPortMode_Output  = 2
} PACK_STRUCT_STRUCT OcaPortMode;

typedef struct {
    OcaPortMode Mode;
    OcaUint16 Index;
} PACK_STRUCT_STRUCT OcaPortID;


//typedef struct {
//    OcaONo Owner;
//    OcaPortID ID;
//    OcaString Name;
//} PACK_STRUCT_STRUCT OcaPort;

#define OCAC_PORT(len) \
     struct { \
        OcaONo Owner; \
        OcaPortID ID; \
        OCAC_STRING(len) Name; \
    } PACK_STRUCT_STRUCT

/**
 * For reference only
 */
typedef OCAC_PORT(0) OcaPort;

typedef struct {
    OcaPort SourcePort;
    OcaPort SinkPort;
} PACK_STRUCT_STRUCT OcaSignalPath;



typedef OcaUint32 OcaProtoONo;


typedef struct {
    OcaONo ProtoMemberPONo;
} PACK_STRUCT_STRUCT OcaProtoMember;


typedef struct {
    OcaProtoONo PONo;
    OcaClassIdentification ClassIdentification;
} PACK_STRUCT_STRUCT OcaProtoObjectIdentification;

typedef struct {
    OcaPortMode Mode;
    OcaUint16 Index;
} PACK_STRUCT_STRUCT OcaProtoPortID;

/**
 * For reference only
 */
typedef struct {
    OcaProtoONo Owner;
    OcaProtoPortID ProtoID;
    OCAC_STRING(0) Name;
} PACK_STRUCT_STRUCT OcaProtoPort;

typedef struct {
    OcaProtoPort SourceProtoPort;
    OcaProtoPort SinkProtoPort;
} PACK_STRUCT_STRUCT OcaProtoSignalPath;

typedef OcaUint16 OcaMatrixCoordinate;

/**
 * For reference only
 */
typedef struct {
    OcaONo ONo;
    OcaClassIdentification ClassIdentification;
    OcaONoPath ContainerPath;
    OCAC_STRING(0) Role;
    OCAC_STRING(0) Label;
} OcaObjectSearchResult;

// TODO OcaObjectSearchResultFlags
// #define OcaObjectSearchResultFlags_ONo                   0b1000000000000000 // 1
// #define OcaObjectSearchResultFlags_ClassIdentification   0b0100000000000000 // 2
// #define OcaObjectSearchResultFlags_ContainerPath         0b0010000000000000 // 3
// #define OcaObjectSearchResultFlags_Role                  0b0001000000000000 // 4
// #define OcaObjectSearchResultFlags_Label                 0b0000100000000000 // 5
// #define OcaObjectSearchResultFlags_Unused                0b0000011111111111
//#define OcaObjectSearchResultFlags 0x00

typedef OcaUint16 OcaObjectSearchResultFlags;

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_BLOCKMATRIX_H
