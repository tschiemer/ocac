//
// Created by Philip Tschiemer on 11.06.20.
//

#ifndef OCAC_OCC_DATATYPES_BASE_H
#define OCAC_OCC_DATATYPES_BASE_H

#include "ocac/arch.h"

#ifdef __cplusplus
extern "C" {
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaBaseDataType_None             = 0,
    OcaBaseDataType_Boolean          = 1,
    OcaBaseDataType_Int8             = 2,
    OcaBaseDataType_Int16            = 3,
    OcaBaseDataType_Int32            = 4,
    OcaBaseDataType_Int64            = 5,
    OcaBaseDataType_Uint8            = 6,
    OcaBaseDataType_Uint16           = 7,
    OcaBaseDataType_Uint32           = 8,
    OcaBaseDataType_Uint64           = 9,
    OcaBaseDataType_Float32          = 10,
    OcaBaseDataType_Float64          = 11,
    OcaBaseDataType_String           = 12,
    OcaBaseDataType_BitString        = 13,
    OcaBaseDataType_Blob             = 14,
    OcaBaseDataType_BlobFixedLen     = 15

} PACK_STRUCT_STRUCT OcaBaseDataType;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif

typedef u8_t OcaBoolean;

typedef u8_t OcaUint8;
typedef u16_t OcaUint16;
typedef u32_t OcaUint32;
typedef u64_t OcaUint64;

typedef s8_t OcaInt8;
typedef s16_t OcaInt16;
typedef s32_t OcaInt32;
typedef s64_t OcaInt64;

typedef float OcaFloat32;
typedef double OcaFloat64;

//typedef u8_t OcaChar;

#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaUint16 Len);
    PACK_STRUCT_FIELD(u8_t Value[]);
} PACK_STRUCT_STRUCT OcaString;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#define OCAC_STRING(maxlen) \
    struct { \
        PACK_STRUCT_FIELD(OcaUint16 Len); \
        PACK_STRUCT_FIELD(u8_t Value[maxlen]); \
    } PACK_STRUCT_STRUCT

#define OCAC_STRING_STR(str) \
    struct { \
        PACK_STRUCT_FIELD(OcaUint16 Len); \
        PACK_STRUCT_FIELD(u8_t Value[sizeof(str)]); \
    } PACK_STRUCT_STRUCT


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaUint16 NrBits);
    PACK_STRUCT_FIELD(u8_t Bitstring[]);
} PACK_STRUCT_STRUCT OcaBitString;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaUint16 DataSize);
    PACK_STRUCT_FIELD(u8_t Data[]);
} PACK_STRUCT_STRUCT OcaBlob;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif

#define OCAC_BLOB(maxlen) \
    struct { \
        OcaUint16 DataSize; \
        u8_t Data[maxlen]; \
    }

//typedef OcaBlob OcaBlobFixedLen;
typedef u8_t OcaBlobFixedLen1[1];
typedef u8_t OcaBlobFixedLen2[2];
typedef u8_t OcaBlobFixedLen3[3];
typedef u8_t OcaBlobFixedLen4[4];
typedef u8_t OcaBlobFixedLen8[8];
typedef u8_t OcaBlobFixedLen16[16];

// TODO OcaList
// TODO OcaList2D
// TODO OcaMap
// TODO OcaMapItem




/**
 * OCA Object Number (unique identifier)
 * (moved here to resolve circular dependency)
 */
typedef OcaUint32 OcaONo;

#ifdef DEBUG

void ocac_dump_string( OcaString * string );
void ocac_dump_blob( OcaBlob * blob );
void ocac_dump_blobfixedlen( u8_t * blob, size_t len );

#endif

#ifdef __cplusplus
}
#endif


#endif //OCAC_OCC_DATATYPES_BASE_H
