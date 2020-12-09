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

#ifndef OCAC_OCC_DATATYPES_FRAMEWORK_H
#define OCAC_OCC_DATATYPES_FRAMEWORK_H

#include "ocac/opt.h"
#include "ocac/occ/datatypes/base.h"
//#include "ocac/occ/datatypes/network.h"
//#include "ocac/occ/datatypes/management.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef OcaBlobFixedLen3 OcaOrganizationID;

typedef struct {
    OcaUint16 Sentinel; // 0xFFFF
    OcaUint8 Reserved; // 0
    OcaOrganizationID OrganizationID;
} PACK_STRUCT_STRUCT OcaClassAuthorityID;

#define OcaClassAuthorityID_Sentinel 0xFFFF

//TODO OcaCLassIDField
/** Either 16bit value or 48bit authority key
 * The Setinel value of 0xFFFF makes the difference.
 **/
typedef OcaUint16 OcaClassIDField_16bit;
typedef OcaClassAuthorityID OcaClassIDField_Authority;

#if OCAC_CLASSIDFIELD_TYPE == OCAC_CLASSIDFIELD_TYPE_16BIT
typedef OcaClassIDField_16bit OcaClassIDField;
#else
typedef OcaClassIDField_Authority OcaClassIDField;
#endif


/**
 * OCA Class ID
 * Defined as descendent line i1 i2 ... in
 */
typedef struct {
    PACK_STRUCT_FIELD(OcaUint16 FieldCount);
    PACK_STRUCT_FIELD(OcaClassIDField Fields[OCAC_OCC_FRAMEWORK_CLASSID_SIZE]);
} PACK_STRUCT_STRUCT OcaClassID;

typedef enum {
    OcaComponent_BootLoader       = 0,

    __OcaComponent__ = 0xFFFF
} PACK_STRUCT_STRUCT OcaComponent;

typedef struct {
    OcaUint32 Major;
    OcaUint32 Minor;
    OcaUint32 Build;
    OcaComponent Component;
} OcaVersion;

typedef OcaUint8 OcaEnumItem;
typedef OcaUint16 OcaEnumItem16;

typedef OcaUint16 OcaBitSet16;

typedef OcaUint16 OcaClassVersionNumber;

typedef struct {
    PACK_STRUCT_FIELD(OcaClassID ClassID);
    PACK_STRUCT_FIELD(OcaClassVersionNumber ClassVersion);
} PACK_STRUCT_STRUCT OcaClassIdentification;

/**
 * OCA Object Number (unique identifier)
 */
// moved to base.h to resolve circular requirement
//typedef OcaUint32 OcaONo;

//
//typedef struct {
//    OcaNetworkHostID HostID;
//    PACK_STRUCT_FIELD(OcaONo ONo);
//} PACK_STRUCT_STRUCT OcaOPath;


/**
 * For reference only
 */
typedef OCAC_LIST(OcaString,0) OcaNamePath;

/**
 * For reference only
 */
typedef OCAC_LIST(OcaONo,0) OcaONoPath;

typedef struct {
    PACK_STRUCT_FIELD(OcaONo ONo);
    PACK_STRUCT_FIELD(OcaClassIdentification ClassIdentification);
} PACK_STRUCT_STRUCT OcaObjectIdentification;


typedef struct {
    PACK_STRUCT_FIELD(OcaUint16 DefLevel);
    PACK_STRUCT_FIELD(OcaUint16 MethodIndex);
} PACK_STRUCT_STRUCT OcaMethodID;

#define OCAC_IS_METHOD(methodid, level, index) (methodid.DefLevel == level && methodid.MethodIndex == index)

typedef struct {
    PACK_STRUCT_FIELD(OcaUint16 DefLevel);
    PACK_STRUCT_FIELD(OcaUint16 PropertyIndex);
} PACK_STRUCT_STRUCT OcaPropertyID;


typedef struct {
    PACK_STRUCT_FIELD(OcaUint16 DefLevel);
    PACK_STRUCT_FIELD(OcaUint16 EventIndex);
} PACK_STRUCT_STRUCT OcaEventID;


typedef struct {
    PACK_STRUCT_FIELD(OcaPropertyID PropertyID);
    PACK_STRUCT_FIELD(OcaBaseDataType BaseDataType);
    PACK_STRUCT_FIELD(OcaMethodID GetterMethodID);
    PACK_STRUCT_FIELD(OcaMethodID SetterMethodID);
} PACK_STRUCT_STRUCT OcaPropertyDescriptor;


typedef struct {
    PACK_STRUCT_FIELD(OcaONo ONo);
    PACK_STRUCT_FIELD(OcaPropertyDescriptor Descriptor);
} PACK_STRUCT_STRUCT OcaProperty;


typedef enum {
    OcaStatus_OK                     = 0,
    OcaStatus_ProtocolVersionError   = 1,
    OcaStatus_DeviceError            = 2,
    OcaStatus_Locked                 = 3,
    OcaStatus_BadFormat              = 4,
    OcaStatus_BadONo                 = 5,
    OcaStatus_ParameterError         = 6,
    OcaStatus_ParameterOutOfRange    = 7,
    OcaStatus_NotImplemented         = 8,
    OcaStatus_InvalidRequest         = 9,
    OcaStatus_ProcessingFailed       = 10,
    OcaStatus_BadMethod              = 11,
    OcaStatus_PartiallySucceeded     = 12,
    OcaStatus_Timeout                = 13,
    OcaStatus_BufferOverflow         = 14,
} PACK_STRUCT_STRUCT OcaStatus;


typedef struct {
    OcaOrganizationID Authority;
    OcaUint32 ID;
} PACK_STRUCT_STRUCT OcaGlobalTypeIdentifier;

typedef OcaBitSet16 OcaParameterMask;

typedef enum {
    OcaStringComparisonType_Exact                       = 0,
    OcaStringComparisonType_Substring                   = 1,
    OcaStringComparisonType_Contains                    = 2,
    OcaStringComparisonType_ExactCaseInsensitive        = 3,
    OcaStringComparisonType_SubstringCaseInsensitive    = 4,
    OcaStringComparisonType_ContainsCaseInsensitive     = 5
} PACK_STRUCT_STRUCT OcaStringComparisonType;

typedef OcaBitSet16 OcaPositionDescriptorFieldFlags;

typedef enum {
    OcaPositionCoordinateSystem_Robotic                         = 1,
    OcaPositionCoordinateSystem_ItuAudioObjectBasedPolar        = 2,
    OcaPositionCoordinateSystem_ItuAudioObjectBasedCartesian    = 3,
    OcaPositionCoordinateSystem_ItuAudioSceneBasedPolar         = 4,
    OcaPositionCoordinateSystem_ItuAudioSceneBasedCartesian     = 5,
    OcaPositionCoordinateSystem_NAV                             = 6,
    OcaPositionCoordinateSystem_ProprietaryBase                 = 128
} PACK_STRUCT_STRUCT OcaPositionCoordinateSystem;

typedef struct {
    OcaPositionCoordinateSystem CoordinateSystem;
    OcaPositionDescriptorFieldFlags FieldFlags;
    OcaUint32 Values[6];
} PACK_STRUCT_STRUCT OcaPositionDescriptor;

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_FRAMEWORK_H