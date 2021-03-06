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
