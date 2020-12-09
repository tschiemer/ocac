/**
 * MIT License
 *
 * Copyright (c) 2020 Philip Tschiemer, https://github.com/tschiemer/ocac
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

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
