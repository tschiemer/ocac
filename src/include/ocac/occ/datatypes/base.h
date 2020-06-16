//
// Created by Philip Tschiemer on 11.06.20.
//

#ifndef OCAC_OCC_DATATYPES_BASE_H
#define OCAC_OCC_DATATYPES_BASE_H

#include "ocac/arch.h"

#ifdef __cplusplus
extern "C" {
#endif


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
    OcaBaseDataType_BlobFixedLen     = 15,
    OcaBaseDataType_Bit              = 16

} PACK_STRUCT_STRUCT OcaBaseDataType;

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



#define OCAC_STRING(len) \
    struct { \
        PACK_STRUCT_FIELD(OcaUint16 Len); \
        PACK_STRUCT_FIELD(u8_t Value[len]); \
    } PACK_STRUCT_STRUCT

#define OCAC_STRING_INIT(str) {sizeof(str), str}

typedef OCAC_STRING() OcaString;


#define OCAC_STRINGFIXEDLEN(len) \
    struct { \
        u8_t string[len]; \
    } PACK_STRUCT_STRUCT

#define OCAC_STRINGFIXEDLEN_INIT(str) { str }


typedef OCAC_STRING() OcaBitString;


#define OCAC_BLOB(len) \
    struct { \
        OcaUint16 DataSize; \
        u8_t Data[len]; \
    } PACK_STRUCT_STRUCT

#define OCAC_BLOB_INIT(data) {sizeof(data), data}

typedef OCAC_BLOB() OcaBlob;

#define OCAC_BLOBFIXEDLEN(len) \
    struct { \
        u8_t bytes[len]; \
    } PACK_STRUCT_STRUCT

#define OCAC_BLOBFIXEDLEN_INIT(data) {data}

typedef OCAC_BLOBFIXEDLEN(1) OcaBlobFixedLen1;
typedef OCAC_BLOBFIXEDLEN(3) OcaBlobFixedLen3;
typedef OCAC_BLOBFIXEDLEN(4) OcaBlobFixedLen4;
typedef OCAC_BLOBFIXEDLEN(8) OcaBlobFixedLen8;
typedef OCAC_BLOBFIXEDLEN(16) OcaBlobFixedLen16;



#define OCAC_LIST(type, len) \
    struct { \
        OcaUint16 Count; \
        type Items[len]; \
    } PACK_STRUCT_STRUCT


#define OCAC_LIST2D(type, xn, yn) \
    struct { \
        OcaUint16 nX; \
        OcaUint16 nY; \
        type Items[xn*yn]; \
    } PACK_STRUCT_STRUCT

#define OCAC_LIST2D_ITEM(list_ptr, xN, yN) (list_ptr->Items[list_ptr->nX * ny + nx])


#define OCAC_MAP_ITEM(keytype, valuetype) \
    struct { \
        keytype Key; \
        valuetype Value; \
    } PACK_STRUCT_STRUCT

// Maps have unique keys
#define OCAC_MAP(keytype, valuetype, len) \
    OCAC_LIST(OCAC_MAP_ITEM(keytype,valuetype), len)

// MultiMaps can have multiple identical keys
#define OCAC_MULTIMAP(keytype, valuetype, len) \
    OCAC_MAP(keytype, valuetype, len)


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
