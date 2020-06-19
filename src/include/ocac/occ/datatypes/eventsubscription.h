//
// Created by Philip Tschiemer on 11.06.20.
//

#ifndef OCAC_OCC_DATATYPES_EVENTSUBSCRIPTION_H
#define OCAC_OCC_DATATYPES_EVENTSUBSCRIPTION_H

#include "ocac/occ/datatypes/framework.h"
#include "ocac/occ/datatypes/library.h"
#include "ocac/occ/datatypes/network.h"
#include "ocac/occ/datatypes/task.h"

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

typedef enum {
    OcaMediaConnectorElement_Pinmap         = 1,
    OcaMediaConnectorElement_Connection     = 2,
    OcaMediaConnectorElement_Coding         = 4,
    OcaMediaConnectorElement_AlignmentLevel = 8,
    OcaMediaConnectorElement_AlignmentGain  = 16,

//    OcaMediaConnectorElement_Added          = (OcaMediaConnectorElement_Pinmap | OcaMediaConnectorElement_Connection), // according to https://github.com/OCAAlliance/OcaToolsAndDemos/blob/master/OCAMicro/OCAMicro/Src/common/OCALite/OCC/ControlDataTypes/OcaLiteNetworkDataTypes.h
//    OcaMediaConnectorElement_Deleted        = (OcaMediaConnectorElement_Pinmap | OcaMediaConnectorElement_Connection),

    __OcaMediaConnectorElement__            = 0xFFFF
} PACK_STRUCT_STRUCT OcaMediaConnectorElement;


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
