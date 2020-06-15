//
// Created by Philip Tschiemer on 12.06.20.
//

#ifndef OCAC_OCC_DATATYPES_NETWORK_H
#define OCAC_OCC_DATATYPES_NETWORK_H

#include "ocac/occ/datatypes/base.h"
#include "ocac/opt.h"

#ifdef __cplusplus
extern "C" {
#endif



#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaEncoding_None    = 0,
    OcaEncoding_Pcm16   = 1,
    OcaEncoding_Pcm24   = 2,
    OcaEncoding_Pcm32   = 3
} PACK_STRUCT_STRUCT OcaEncoding;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/bpstruct.h"
//#endif
//PACK_STRUCT_BEGIN
//typedef enum {
//    OcaNetworkStatus_Unknown    = 0,
//    OcaNetworkStatus_Ready      = 1,
//    OcaNetworkStatus_StartingUp = 2,
//    OcaNetworkStatus_Stopped    = 3
//} PACK_STRUCT_STRUCT OcaNetworkStatus;
//PACK_STRUCT_END
//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/epstruct.h"
//#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaNetworkLinkType_None             = 0,
    OcaNetworkLinkType_EthernetWired    = 1,
    OcaNetworkLinkType_EthernetWireless = 2,
    OcaNetworkLinkType_USB              = 3,
    OcaNetworkLinkType_SerialP2P        = 4
} PACK_STRUCT_STRUCT OcaNetworkLinkType;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaNetworkMediaProtocol_None        = 0,
    OcaNetworkMediaProtocol_AV3         = 1,
    OcaNetworkMediaProtocol_AVBTP       = 2,
    OcaNetworkMediaProtocol_Dante       = 3,
    OcaNetworkMediaProtocol_Cobranet    = 4,
    OcaNetworkMediaProtocol_AES67       = 5,
    OcaNetworkMediaProtocol_SMPTEAudio  = 6,
    OcaNetworkMediaProtocol_LiveWire    = 7
} PACK_STRUCT_STRUCT OcaNetworkMediaProtocol;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/bpstruct.h"
#endif
PACK_STRUCT_BEGIN
typedef enum {
    OcaNetworkControlProtocol_None  = 0,
    OcaNetworkControlProtocol_OCP01 = 1,
    OcaNetworkControlProtocol_OCP02 = 2,
    OcaNetworkControlProtocol_OCP03 = 3
} PACK_STRUCT_STRUCT OcaNetworkControlProtocol;
PACK_STRUCT_END
#ifdef PACK_STRUCT_USE_INCLUDES
#  include "arch/epstruct.h"
#endif


//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/bpstruct.h"
//#endif
//PACK_STRUCT_BEGIN
//typedef enum {
//    OcaStreamType_None      = 0,
//    OcaStreamType_Unicast   = 1,
//    OcaStreamType_Multicast = 2
//} PACK_STRUCT_STRUCT OcaStreamType;
//PACK_STRUCT_END
//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/epstruct.h"
//#endif
//
//
//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/bpstruct.h"
//#endif
//PACK_STRUCT_BEGIN
//typedef enum {
//    OcaStreamStatus_NotConnected    = 0,
//    OcaStreamStatus_Connected       = 1,
//    OcaStreamStatus_Paused          = 2
//} PACK_STRUCT_STRUCT OcaStreamStatus;
//PACK_STRUCT_END
//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/epstruct.h"
//#endif


//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/bpstruct.h"
//#endif
//PACK_STRUCT_BEGIN
//typedef enum {
//    OcaStreamConnectorStatus_NotAvailable   = 0,
//    OcaStreamConnectorStatus_Idle           = 1,
//    OcaStreamConnectorStatus_Connected      = 2,
//    OcaStreamConnectorStatus_Paused         = 3
//} PACK_STRUCT_STRUCT OcaStreamConnectorStatus;
//PACK_STRUCT_END
//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/epstruct.h"
//#endif


//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/bpstruct.h"
//#endif
//PACK_STRUCT_BEGIN
//typedef enum {
//    OcaNetworkSignalChannelStatus_NotConnected  = 0,
//    OcaNetworkSignalChannelStatus_Connected     = 1,
//    OcaNetworkSignalChannelStatus_Muted         = 2
//} PACK_STRUCT_STRUCT OcaNetworkSignalChannelStatus;
//PACK_STRUCT_END
//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/epstruct.h"
//#endif


//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/bpstruct.h"
//#endif
//PACK_STRUCT_BEGIN
//typedef enum {
//    OcaNetworkMediaSourceOrSink_None    = 0,
//    OcaNetworkMediaSourceOrSink_Source  = 1,
//    OcaNetworkMediaSourceOrSink_Sink    = 2
//} PACK_STRUCT_STRUCT OcaNetworkMediaSourceOrSink;
//PACK_STRUCT_END
//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/epstruct.h"
//#endif


//typedef OCAC_BLOB(OCAC_OCC_NETWORK_HOSTID_MAXLEN) OcaNetworkHostID;

//typedef OCAC_BLOB(OCAC_OCC_NETWORK_NODEID_MAXLEN) OcaNetworkNodeID;

typedef OCAC_BLOB(OCAC_OCC_NETWORK_ADDR_MAXLEN) OcaNetworkAddress;


//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/bpstruct.h"
//#endif
//PACK_STRUCT_BEGIN
//typedef struct {
//    OcaNetworkAddress MyNetworkAddress;
//    OcaBlob SystemInterfaceHandle;
//} PACK_STRUCT_STRUCT OcaNetworkSystemInterfaceID;
//PACK_STRUCT_END
//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/epstruct.h"
//#endif

//typedef OCAC_BLOB(OCAC_OCC_NETWORK_STREAMID_MAXLEN) OcaStreamID;

//typedef OcaUint16 OcaStreamIndex;

//typedef OCAC_BLOB(OCAC_OCC_NETWORK_STREAMPARAM_MAXLEN) OcaStreamParameters;

//typedef OCAC_BLOB(OCAC_OCC_NETWORK_STREAMCONNID_MAXLEN) OcaStreamConnectorID;


//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/bpstruct.h"
//#endif
//PACK_STRUCT_BEGIN
//typedef struct {
//    OcaNetworkHostID HostID;
//    OcaNetworkAddress NetworkAddress;
//    OcaNetworkNodeID NodeID;
//    OcaStreamConnectorID StreamConnectorID;
//} PACK_STRUCT_STRUCT OcaStreamConnectorIdentification;
//PACK_STRUCT_END
//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/epstruct.h"
//#endif

//typedef OcaUint16 OcaStreamConnectorPinIndex;

//typedef OcaBlob OcaNetworkSignalChannelID;


//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/bpstruct.h"
//#endif
//PACK_STRUCT_BEGIN
//typedef struct {
//    u32_t rxPacketErrors;
//    u32_t txPacketErrors;
//} PACK_STRUCT_STRUCT OcaNetworkStatistics;
//PACK_STRUCT_END
//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/epstruct.h"
//#endif


//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/bpstruct.h"
//#endif
//PACK_STRUCT_BEGIN
//typedef struct {
//    OcaUint16 ErrorNumber;
//    OcaStreamID IDAdvertised;
//    OcaStreamIndex Index;
//    OcaONo LocalConnectorONo;
//    OcaUint16 Priority;
//    OcaStreamConnectorIdentification RemoteConnectorIdentification;
//    OcaBoolean Secure;
//    OcaStreamStatus Status;
//    OcaStreamType StreamType;
//    OcaStreamParameters StreamParameters;
//    OcaString Label;
//} PACK_STRUCT_STRUCT OcaStream;
//PACK_STRUCT_END
//#ifdef PACK_STRUCT_USE_INCLUDES
//#  include "arch/epstruct.h"
//#endif


#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_NETWORK_H
