//
// Created by Philip Tschiemer on 12.06.20.
//

#ifndef OCAC_OCC_DATATYPES_BLOCKMATRIX_H
#define OCAC_OCC_DATATYPES_BLOCKMATRIX_H

#include "base.h"
#include "framework.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    OcaONo ContainerObjectNumber;
    OcaObjectIdentification MemberObjectIdentification;
} OcaBlockMember;


typedef enum {
    OcaPortMode_Input   = 1,
    OcaPortMode_Output  = 2
} OcaPortMode;

typedef struct {
    OcaUint16 Index;
    OcaPortMode Mode;
} OcaPortID;

typedef struct {
    OcaPortID ID;
    OcaONo Owner;
    OcaString Name;
} OcaPort;

typedef struct {
    OcaPort SourcePort;
    OcaPort SinkPort;
} OcaSignalPath;

typedef OcaUint32 OcaProtoONo;

typedef struct {
    OcaONo ProtoMemberPONo;
} OcaProtoMember;

typedef struct {
    OcaClassIdentification ClassIdentification;
    OcaProtoONo PONo;
} OcaProtoObjectIdentification;

typedef struct {
    OcaUint16 Index;
    OcaPortMode Mode;
} OcaProtoPortID;

typedef struct {
    OcaProtoONo Owner;
    OcaProtoPortID ProtoID;
    OcaString Name;
} OcaProtoPort;

typedef struct {
    OcaProtoPort SourceProtoPort;
    OcaProtoPort SinkProtoPort;
} OcaProtoSignalPath;

typedef OcaUint16 OcaMatrixCoordinate;

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_BLOCKMATRIX_H
