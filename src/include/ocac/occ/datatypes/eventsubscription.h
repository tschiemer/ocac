//
// Created by Philip Tschiemer on 11.06.20.
//

#ifndef OCAC_OCC_DATATYPES_EVENTSUBSCRIPTION_H
#define OCAC_OCC_DATATYPES_EVENTSUBSCRIPTION_H

#include "framework.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaPropertyChangeType_CurrentChanged = 1,
    OcaPropertyChangeType_MinChanged     = 2,
    OcaPropertyChangeType_MaxChanged     = 3,
    OcaPropertyChangeType_ItemAdded      = 4,
    OcaPropertyChangeType_ItemChanged    = 5,
    OcaPropertyChangeType_ItemDeleted    = 6
} PACK_STRUCT_STRUCT OcaPropertyChangeType;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaGrouperStatusChangeType_CitizenAdded                      = 1,
    OcaGrouperStatusChangeType_CitizenDeleted                    = 2,
    OcaGrouperStatusChangeType_CitizenConnectionLost             = 3,
    OcaGrouperStatusChangeType_CitizenConnectionReEstablished    = 4,
    OcaGrouperStatusChangeType_CitizenError                      = 5,
    OcaGrouperStatusChangeType_Enrollment                        = 6,
    OcaGrouperStatusChangeType_UnEnrollment                      = 7
} PACK_STRUCT_STRUCT OcaGrouperStatusChangeType;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaNotificationDeliveryMode_Reliable = 1,
    OcaNotificationDeliveryMode_Fast     = 2
} PACK_STRUCT_STRUCT OcaNotificationDeliveryMode;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaSubscriptionManagerState_Normal           = 1,
    OcaSubscriptionManagerState_EventsDisabled   = 2
} PACK_STRUCT_STRUCT OcaSubscriptionManagerState;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaONo EmitterONo;
    OcaEventID EventID;
} PACK_STRUCT_STRUCT OcaEvent;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


typedef OcaEvent OcaEventData;


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaMethodID MethodID;
    OcaONo ONo;
} PACK_STRUCT_STRUCT OcaMethod;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


// TODO OcaObjectListEventData;

#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
// TODO OcaPropertyChangedEventData (depends on key+value types)
typedef struct {
    OcaPropertyChangeType ChangeType;
    OcaPropertyID PropertyID;
//    PropertyKey
//    PropertyValue
} PACK_STRUCT_STRUCT OcaPropertyChangedEventData;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaEvent Event;
    OcaFloat64 Reading;
} PACK_STRUCT_STRUCT OcaObservationEventData;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
// TODO OcaObservationListEventData (like w/o List)
typedef struct {
    OcaEvent Event;
    OcaFloat64 Reading[];
} PACK_STRUCT_STRUCT OcaObservationListEventData;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaGrouperStatusChangeType ChangeType;
    OcaUint16 GroupIndex;
    OcaUint16 CitizenIndex;
} PACK_STRUCT_STRUCT OcaGrouperStatusChangeEventData;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_EVENTSUBSCRIPTION_H
