//
// Created by Philip Tschiemer on 11.06.20.
//

#ifndef OCAC_OCC_DATATYPES_EVENTSUBSCRIPTION_H
#define OCAC_OCC_DATATYPES_EVENTSUBSCRIPTION_H

#include "framework.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    OcaONo EmitterONo;
    OcaEventID EventID;
} OcaEvent;

typedef struct {
    OcaMethodID MethodID;
    OcaONo ONo;
} OcaMethod;

typedef OcaEvent OcaEventData;

// TODO OcaObjectListEventData;

typedef enum {
    OcaPropertyChangeType_CurrentChanged = 1,
    OcaPropertyChangeType_MinChanged     = 2,
    OcaPropertyChangeType_MaxChanged     = 3,
    OcaPropertyChangeType_ItemAdded      = 4,
    OcaPropertyChangeType_ItemChanged    = 5,
    OcaPropertyChangeType_ItemDeleted    = 6
} OcaPropertyChangeType;

// TODO OcaPropertyChangedEventData (depends on key+value types)
typedef struct {
    OcaPropertyChangeType ChangeType;
    OcaPropertyID PropertyID;
//    PropertyKey
//    PropertyValue
} OcaPropertyChangedEventData;

typedef struct {
    OcaEvent Event;
    OcaFloat64 Reading;
} OcaObservationEventData;

// TODO OcaObservationListEventData (like w/o List)
typedef struct {
    OcaEvent Event;
    OcaFloat64 Reading[];
} OcaObservationListEventData;

typedef enum {
    OcaGrouperStatusChangeType_CitizenAdded                      = 1,
    OcaGrouperStatusChangeType_CitizenDeleted                    = 2,
    OcaGrouperStatusChangeType_CitizenConnectionLost             = 3,
    OcaGrouperStatusChangeType_CitizenConnectionReEstablished    = 4,
    OcaGrouperStatusChangeType_CitizenError                      = 5,
    OcaGrouperStatusChangeType_Enrollment                        = 6,
    OcaGrouperStatusChangeType_UnEnrollment                      = 7
} OcaGrouperStatusChangeType;

typedef struct {
    OcaGrouperStatusChangeType ChangeType;
    OcaUint16 GroupIndex;
    OcaUint16 CitizenIndex;
} OcaGrouperStatusChangeEventData;

typedef enum {
    OcaNotificationDeliveryMode_Reliable = 1,
    OcaNotificationDeliveryMode_Fast     = 2
} OcaNotificationDeliveryMode;

typedef enum {
    OcaSubscriptionManagerState_Normal           = 1,
    OcaSubscriptionManagerState_EventsDisabled   = 2
} OcaSubscriptionManagerState;

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_EVENTSUBSCRIPTION_H
