//
// Created by Philip Tschiemer on 10.06.20.
//

#ifndef OCAC_OCP1_H
#define OCAC_OCP1_H

#include <ocac/occ/datatypes/eventsubscription.h>
#include "ocac/occ/datatypes/framework.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCP_SYNC_VAL   ((OcaUint8)0x3BU)


typedef enum {
    OcaMessageType_CommandNR    = 0, // Command - no response required
    OcaMessageType_Command      = 1, // Command - response required
    OcaMessageType_Notification = 2, // Notification
    OcaMessageType_Response     = 3, // Response
    OcaMessageType_KeepAlive    = 4  //
} OcaMessageType;

//typedef enum {
//    Ocp1HeartBeatTimeType_Seconds
//    Ocp1HeartBeatTimeType_Milliseconds
//} Ocp1HeartBeatTimeType;

typedef struct {
    OcaUint16       protocolVersion;
    OcaUint32       pduSize;
    OcaMessageType  pduType;
    OcaUint16       messageCount;
} Ocp1Header;

typedef struct {
    OcaUint8    syncVal;
    Ocp1Header  header;
    OcaUint8    data[];
} Ocp1MessagePdu;

typedef struct {
    OcaUint8    parameterCount;
    OcaUint8    parameters[];
} Ocp1Parameters;

typedef struct {
    OcaUint32       commandSize;    // size (in bytes) of complete command segment (incl. commandSize)
    OcaUint32       handle;         // random command id used for responses
    OcaONo          targetONo;
    OcaMethodID     methodID;
    Ocp1Parameters  parameters;
} Ocp1Command;

typedef struct {
    OcaUint32       responseSize;
    OcaUint32       handle;
    OcaStatus       statusCode;
    Ocp1Parameters  parameters;
} Ocp1Response;


typedef struct {
    OcaEvent    event;
    OcaUint8    eventParameters[];
} Ocp1EventData;

typedef struct {
    OcaUint8        parameterCount;
    OcaBlob         context;
    Ocp1EventData   eventData;
} Ocp1NtfParams;

typedef struct {
    OcaUint32       notificationSize;
    OcaONo          targetONo;
    OcaMethodID     methodID;
    Ocp1NtfParams   parameters;
} Ocp1Notification;

typedef union {
    OcaUint16 heartbeatTimeSeconds;
    OcaUint32 heartbeatTimeMilliseconds;
} Ocp1KeepAlive;


typedef struct {
    OcaBlobFixedLen16 sentinel;
    OcaBlobFixedLen8 key;
} Ocp1DeviceResetPdu;

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCP1_H
