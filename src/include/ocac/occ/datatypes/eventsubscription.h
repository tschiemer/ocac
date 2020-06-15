//
// Created by Philip Tschiemer on 11.06.20.
//

#ifndef OCAC_OCC_DATATYPES_EVENTSUBSCRIPTION_H
#define OCAC_OCC_DATATYPES_EVENTSUBSCRIPTION_H

#include "ocac/occ/datatypes/framework.h"
#include "ocac/occ/datatypes/library.h"

#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
    OcaONo EmitterONo;
    OcaEventID EventID;
} PACK_STRUCT_STRUCT OcaEvent;


typedef struct {
    OcaONo ONo;
    OcaMethodID MethodID;
} PACK_STRUCT_STRUCT OcaMethod;

typedef OcaEvent OcaEventData;

typedef enum {
    OcaPropertyChangeType_CurrentChanged = 1,
    OcaPropertyChangeType_MinChanged     = 2,
    OcaPropertyChangeType_MaxChanged     = 3,
    OcaPropertyChangeType_ItemAdded      = 4,
    OcaPropertyChangeType_ItemChanged    = 5,
    OcaPropertyChangeType_ItemDeleted    = 6
} PACK_STRUCT_STRUCT OcaPropertyChangeType;

typedef struct {
    OcaLibVolID VolumeID;
    OcaPropertyChangeType ChangeType;
} PACK_STRUCT_STRUCT OcaLibVolChangedEventData;

#define OCAC_PROPERTYCHANGED_EVENTDATA(type) \
    struct { \
        OcaPropertyID PropertyID; \
        type PropertyValue; \
        OcaPropertyChangeType ChangeType; \
    } PACK_STRUCT_STRUCT

// TODO OcaMediaConnectorElement
//typedef OcaBitSet OcaMediaConnectorElement;

typedef struct {
    OcaMediaConnectorStatus ConnectorStatus;
} PACK_STRUCT_STRUCT OcaMediaConnectorStatusChangedEventData;

typedef struct {
    OcaTaskID TaskID;
    OcaLibVolIdentifier ProgramID;
    OcaTaskStatus Status;
} PACK_STRUCT_STRUCT OcaTaskStatusChangedEventData;

typedef struct {
    OcaMediaSourceConnector SourceConnector;
    OcaPropertyChangeType ChangeType;
    OcaMediaConnectorElement ChangedElement;
} PACK_STRUCT_STRUCT OcaMediaSourceConnectorChangedEventData;

typedef struct {
    OcaMediaSinkConnector SourceConnector;
    OcaPropertyChangeType ChangeType;
    OcaMediaConnectorElement ChangedElement;
} PACK_STRUCT_STRUCT OcaMediaSinkConnectorChangedEventData;


#define OCAC_OBJECTLIST_EVENTDATA(len) \
    OCAC_LIST(OcaONo,len)

typedef OCAC_OBJECTLIST_EVENTDATA() OcaObjetListEventData;


typedef struct {
    OcaEvent Event;
    OcaFloat64 Reading;
} PACK_STRUCT_STRUCT OcaObservationEventData;


#define OCAC_OBSERVATIONLIST_EVENTDATA(len) \
    OCAC_LIST(OcaFloat64, len)

typedef OCAC_OBSERVATIONLIST_EVENTDATA() OcaObservationListEventData;


typedef enum {
    OcaGrouperStatusChangeType_CitizenAdded                      = 1,
    OcaGrouperStatusChangeType_CitizenDeleted                    = 2,
    OcaGrouperStatusChangeType_CitizenConnectionLost             = 3,
    OcaGrouperStatusChangeType_CitizenConnectionReEstablished    = 4,
    OcaGrouperStatusChangeType_CitizenError                      = 5,
    OcaGrouperStatusChangeType_Enrollment                        = 6,
    OcaGrouperStatusChangeType_UnEnrollment                      = 7
} PACK_STRUCT_STRUCT OcaGrouperStatusChangeType;

typedef struct {
    OcaGrouperStatusChangeType ChangeType;
    OcaUint16 GroupIndex;
    OcaUint16 CitizenIndex;
} PACK_STRUCT_STRUCT OcaGrouperStatusChangeEventData;

typedef enum {
    OcaNotificationDeliveryMode_Reliable = 1,
    OcaNotificationDeliveryMode_Fast     = 2
} PACK_STRUCT_STRUCT OcaNotificationDeliveryMode;

typedef enum {
    OcaSubscriptionManagerState_Normal           = 1,
    OcaSubscriptionManagerState_EventsDisabled   = 2
} PACK_STRUCT_STRUCT OcaSubscriptionManagerState;


#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_EVENTSUBSCRIPTION_H
