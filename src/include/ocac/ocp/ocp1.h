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

#include <ocac/occ/datatypes/framework.h>
#include <ocac/occ/datatypes/eventsubscription.h>
#include "ocac/occ/datatypes/framework.h"
#include "ocac/occ/datatypes/eventsubscription.h"
#include "ocac/def.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCP_SYNC_VAL   ((OcaUint8)0x3B)



typedef enum {
    OcaMessageType_CommandNR    = 0, // Command - no response required
    OcaMessageType_Command      = 1, // Command - response required
    OcaMessageType_Notification = 2, // Notification
    OcaMessageType_Response     = 3, // Response
    OcaMessageType_KeepAlive    = 4  // Heartbeat message
} PACK_STRUCT_STRUCT OcaMessageType;

#define OcaMessageType_ISVALID(__type__) ( \
    (__type__) == OcaMessageType_CommandNR || \
    (__type__) == OcaMessageType_Command || \
    (__type__) == OcaMessageType_Notification || \
    (__type__) == OcaMessageType_Response || \
    (__type__) == OcaMessageType_KeepAlive \
    )


typedef enum {
    Ocp1HeartBeatTimeType_Seconds       = sizeof(OcaUint16),
    Ocp1HeartBeatTimeType_Milliseconds  = sizeof(OcaUint32),
} PACK_STRUCT_STRUCT Ocp1HeartBeatTimeType;

#define Ocp1HeartBeatTimeType_ISVALID(__type__) (\
    (__type__) == Ocp1HeartBeatTimeType_Seconds || \
    (__type__) == Ocp1HeartBeatTimeType_Milliseconds \
    )

inline u32_t ocac_ocp1_heartbeat_timeout(u32_t msec)
{
    return 3 * msec; // constant as defined in standard (AES70-3-2018 5.3)
}


typedef struct {
    OcaUint16       protocolVersion;
    OcaUint32       pduSize;
    OcaMessageType  pduType;
    OcaUint16       messageCount;
} PACK_STRUCT_STRUCT Ocp1Header;

#define OCAC_OCP1_HEADER_SIZE   9

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
    OcaUint32       responseSize;
    OcaUint32       handle;
    OcaStatus       statusCode;
    struct {
        OcaUint8    parameterCount;
        OcaUint8 *  parameters;
    } PACK_STRUCT_STRUCT parameters;
} PACK_STRUCT_STRUCT Ocp1ResponseRef;



typedef struct {
    OcaEvent    event;
    OcaUint8    eventParameters[];
} PACK_STRUCT_STRUCT Ocp1EventData;



typedef struct {
    OcaUint8            parameterCount;
    OCAC_BLOB_REFTYPE   context;
    Ocp1EventData       eventData;
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


inline void ocac_ocp1_header_write(u8_t * bytes, Ocp1Header * header)
{
    *(u16_t*)(&bytes[0]) = ocac_htons(header->protocolVersion);
    *(u32_t*)(&bytes[2]) = ocac_htonl(header->pduSize);
    *(u8_t*)(&bytes[6]) = header->pduType;
    *(u16_t*)(&bytes[7]) = ocac_htons(header->messageCount);
}

inline void ocac_ocp1_header_read(Ocp1Header * header, u8_t * bytes)
{
    header->protocolVersion = ocac_ntohs(*(u16_t*)(&bytes[0]));
    header->pduSize = ocac_ntohl(*(u32_t*)(&bytes[2]));
    header->pduType = bytes[6];
    header->messageCount = ocac_ntohs(*(u16_t*)(&bytes[7]));
}

inline void ocac_ocp1_responseref_read(Ocp1ResponseRef * response, u8_t * bytes)
{
    response->responseSize = ocac_ntohl(*(u32_t *) (&bytes[0]));
    response->handle = ocac_ntohl(*(u32_t *) (&bytes[4]));
    response->statusCode = bytes[8];
    response->parameters.parameterCount = bytes[9];
    response->parameters.parameterCount = bytes[9];
}

inline u8_t ocac_ocp1_notification_read(Ocp1Notification * notification, u8_t * bytes)
{
    notification->notificationSize = ocac_ntohl(*(u32_t *) (&bytes[0]));
    notification->targetONo = ocac_ntohl(*(u32_t *) (&bytes[4]));
    notification->methodID.DefLevel = ocac_ntohs(*(u16_t *) (&bytes[8]));
    notification->methodID.MethodIndex = ocac_ntohs(*(u16_t *) (&bytes[10]));
    notification->parameters.parameterCount = bytes[12];
    notification->parameters.context.DataSize = ocac_ntohs(*(u16_t *) (&bytes[13]));

    u16_t p = 15;

    // if there is no actual context data, set pointer to NULL, otherwise jump over data
    if (notification->parameters.context.DataSize == 0) {
        notification->parameters.context.Data = NULL;
    }
    // sanity check (is there more data than there should be?)
    else if ( p + notification->parameters.context.DataSize > notification->notificationSize){
        return 1;
    }
    else {
        notification->parameters.context.Data = &bytes[15];
        p += notification->parameters.context.DataSize;
    }

    notification->parameters.eventData.event.EmitterONo = ocac_ntohl(*(u32_t*)(&bytes[p]));
    p += sizeof(OcaUint32);

    notification->parameters.eventData.event.EventID.DefLevel = ocac_ntohs(*(u16_t*)(&bytes[p]));
    p += sizeof(OcaUint16);

    notification->parameters.eventData.event.EventID.EventIndex = ocac_ntohs(*(u16_t*)(&bytes[p]));

    return 0;
}

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCP1_H
