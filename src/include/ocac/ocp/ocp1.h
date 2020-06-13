//
// Created by Philip Tschiemer on 10.06.20.
//

#ifndef OCAC_OCP1_H
#define OCAC_OCP1_H

#include "ocac/occ/datatypes/framework.h"
#include "ocac/occ/datatypes/eventsubscription.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCP_SYNC_VAL   ((OcaUint8)0x3BU)



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaMessageType_CommandNR    = 0, // Command - no response required
    OcaMessageType_Command      = 1, // Command - response required
    OcaMessageType_Notification = 2, // Notification
    OcaMessageType_Response     = 3, // Response
    OcaMessageType_KeepAlive    = 4  //
} PACK_STRUCT_STRUCT OcaMessageType;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    Ocp1HeartBeatTimeType_Seconds       = sizeof(OcaUint16),
    Ocp1HeartBeatTimeType_Milliseconds  = sizeof(OcaUint32),
} Ocp1HeartBeatTimeType;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaUint16       protocolVersion;
    OcaUint32       pduSize;
    OcaMessageType  pduType;
    OcaUint16       messageCount;
} Ocp1Header;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaUint8    syncVal;
    Ocp1Header  header;
    OcaUint8    data[];
} Ocp1MessagePdu;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaUint8    parameterCount;
    OcaUint8    parameters[];
} Ocp1Parameters;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaUint32       commandSize;    // size (in bytes) of complete command segment (incl. commandSize)
    OcaUint32       handle;         // random command id used for responses
    OcaONo          targetONo;
    OcaMethodID     methodID;
    Ocp1Parameters  parameters;
} Ocp1Command;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaUint32       responseSize;
    OcaUint32       handle;
    OcaStatus       statusCode;
    Ocp1Parameters  parameters;
} Ocp1Response;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif




#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaEvent    event;
    OcaUint8    eventParameters[];
} Ocp1EventData;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaUint8        parameterCount;
    OcaBlob         context;
    Ocp1EventData   eventData;
} Ocp1NtfParams;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaUint32       notificationSize;
    OcaONo          targetONo;
    OcaMethodID     methodID;
    Ocp1NtfParams   parameters;
} Ocp1Notification;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef union {
    OcaUint16 heartbeatTimeSeconds;
    OcaUint32 heartbeatTimeMilliseconds;
} Ocp1KeepAlive;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif




#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef struct {
    OcaBlobFixedLen16 sentinel;
    OcaBlobFixedLen8 key;
} Ocp1DeviceResetPdu;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef __cplusplus
}
#endif

#endif //OCAC_OCP1_H
