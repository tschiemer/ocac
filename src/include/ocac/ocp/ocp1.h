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

#ifndef OCAC_OCP1_H
#define OCAC_OCP1_H

#include "ocac/occ/datatypes/framework.h"
#include "ocac/occ/datatypes/eventsubscription.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCP_SYNC_VAL   ((OcaUint8)0x3BU)



typedef enum {
    OcaMessageType_CommandNR    = 0, // Command - no response required
    OcaMessageType_Command      = 1, // Command - response required
    OcaMessageType_Notification = 2, // Notification
    OcaMessageType_Response     = 3, // Response
    OcaMessageType_KeepAlive    = 4  // Heartbeat message
} PACK_STRUCT_STRUCT OcaMessageType;



typedef enum {
    Ocp1HeartBeatTimeType_Seconds       = sizeof(OcaUint16),
    Ocp1HeartBeatTimeType_Milliseconds  = sizeof(OcaUint32),
} PACK_STRUCT_STRUCT Ocp1HeartBeatTimeType;


typedef struct {
    OcaUint16       protocolVersion;
    OcaUint32       pduSize;
    OcaMessageType  pduType;
    OcaUint16       messageCount;
} PACK_STRUCT_STRUCT Ocp1Header;


typedef struct {
    OcaUint8    syncVal;
    Ocp1Header  header;
    OcaUint8    data[];
} PACK_STRUCT_STRUCT Ocp1MessagePdu;



typedef struct {
    OcaUint8    parameterCount;
    OcaUint8    parameters[];
} PACK_STRUCT_STRUCT Ocp1Parameters;


typedef struct {
    OcaUint32       commandSize;    // size (in bytes) of complete command segment (incl. commandSize)
    OcaUint32       handle;         // random command id used for responses
    OcaONo          targetONo;
    OcaMethodID     methodID;
    Ocp1Parameters  parameters;
} PACK_STRUCT_STRUCT Ocp1Command;



typedef struct {
    OcaUint32       responseSize;
    OcaUint32       handle;
    OcaStatus       statusCode;
    Ocp1Parameters  parameters;
} PACK_STRUCT_STRUCT Ocp1Response;



typedef struct {
    OcaEvent    event;
    OcaUint8    eventParameters[];
} PACK_STRUCT_STRUCT Ocp1EventData;


/**
 * For reference only
 */
typedef struct {
    OcaUint8        parameterCount;
    OCAC_BLOB(0)         context;
    Ocp1EventData   eventData;
} PACK_STRUCT_STRUCT Ocp1NtfParams;


typedef struct {
    OcaUint32       notificationSize;
    OcaONo          targetONo;
    OcaMethodID     methodID;
    Ocp1NtfParams   parameters;
} PACK_STRUCT_STRUCT Ocp1Notification;



typedef union {
    OcaUint16 heartbeatTimeSeconds;
    OcaUint32 heartbeatTimeMilliseconds;
} PACK_STRUCT_STRUCT Ocp1KeepAlive;


typedef struct {
    OcaBlobFixedLen16 sentinel;
    OcaBlobFixedLen8 key;
} PACK_STRUCT_STRUCT Ocp1DeviceResetPdu;


#ifdef __cplusplus
}
#endif

#endif //OCAC_OCP1_H
