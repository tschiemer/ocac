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


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaPortMode_Input   = 1,
    OcaPortMode_Output  = 2
} PACK_STRUCT_STRUCT OcaPortMode;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



typedef OcaUint32 OcaProtoONo;
typedef OcaUint16 OcaMatrixCoordinate;



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaONo ContainerObjectNumber;
    OcaObjectIdentification MemberObjectIdentification;
} PACK_STRUCT_STRUCT OcaBlockMember;
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
    OcaPortMode Mode;
} PACK_STRUCT_STRUCT OcaPortID;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaPortID ID;
    OcaONo Owner;
    OcaString Name;
} PACK_STRUCT_STRUCT OcaPort;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaPort SourcePort;
    OcaPort SinkPort;
} PACK_STRUCT_STRUCT OcaSignalPath;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaONo ProtoMemberPONo;
} PACK_STRUCT_STRUCT OcaProtoMember;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaClassIdentification ClassIdentification;
    OcaProtoONo PONo;
} PACK_STRUCT_STRUCT OcaProtoObjectIdentification;
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
    OcaPortMode Mode;
} PACK_STRUCT_STRUCT OcaProtoPortID;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaProtoONo Owner;
    OcaProtoPortID ProtoID;
    OcaString Name;
} PACK_STRUCT_STRUCT OcaProtoPort;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaProtoPort SourceProtoPort;
    OcaProtoPort SinkProtoPort;
} PACK_STRUCT_STRUCT OcaProtoSignalPath;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_BLOCKMATRIX_H
