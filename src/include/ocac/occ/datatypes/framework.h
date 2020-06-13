//
// Created by Philip Tschiemer on 11.06.20.
//

#ifndef OCAC_OCC_DATATYPES_FRAMEWORK_H
#define OCAC_OCC_DATATYPES_FRAMEWORK_H

#include "ocac/occ/datatypes/base.h"
#include "ocac/occ/datatypes/network.h"

#ifdef __cplusplus
extern "C" {
#endif




#ifndef OCA_CLASS_ID_SIZE
/** The maximum depth of the class ID */
#define OCA_CLASS_ID_SIZE 8
#endif //OCA_CLASS_ID_SIZE



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
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
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


/**
 * OCA Class ID
 * Defined as descendent line i1 i2 ... in
 */
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaUint16 FieldCount);
    PACK_STRUCT_FIELD(OcaUint16 Fields[OCA_CLASS_ID_SIZE]);
} PACK_STRUCT_STRUCT OcaClassID;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif

typedef OcaUint16 OcaClassVersionNumber;

#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaClassID ClassID);
    PACK_STRUCT_FIELD(OcaClassVersionNumber ClassVersion);
} PACK_STRUCT_STRUCT OcaClassIdentification;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif

/**
 * OCA Object Number (unique identifier)
 */
// moved to base.h to resolve circular requirement
//typedef OcaUint32 OcaONo;


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaNetworkHostID HostID;
    PACK_STRUCT_FIELD(OcaONo ONo);
} PACK_STRUCT_STRUCT OcaOPath;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaClassIdentification ClassIdentification);
    PACK_STRUCT_FIELD(OcaONo ONo);
} PACK_STRUCT_STRUCT OcaObjectIdentification;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaUint16 DefLevel);
    PACK_STRUCT_FIELD(OcaUint16 MethodIndex);
} PACK_STRUCT_STRUCT OcaMethodID;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaUint16 DefLevel);
    PACK_STRUCT_FIELD(OcaUint16 PropertyIndex);
} PACK_STRUCT_STRUCT OcaPropertyID;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaUint16 DefLevel);
    PACK_STRUCT_FIELD(OcaUint16 EventIndex);
} PACK_STRUCT_STRUCT OcaEventID;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif

#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaBaseDataType BaseDataType);
    PACK_STRUCT_FIELD(OcaMethodID GetterMethodID);
    PACK_STRUCT_FIELD(OcaPropertyID PropertyID);
    PACK_STRUCT_FIELD(OcaMethodID SetterMethodID);
} PACK_STRUCT_STRUCT OcaPropertyDescriptor;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif

#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    PACK_STRUCT_FIELD(OcaPropertyDescriptor Descriptor);
    PACK_STRUCT_FIELD(OcaONo ONo);
} PACK_STRUCT_STRUCT OcaProperty ;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_FRAMEWORK_H