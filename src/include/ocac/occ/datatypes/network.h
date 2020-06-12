//
// Created by Philip Tschiemer on 12.06.20.
//

#ifndef OCAC_OCC_DATATYPES_NETWORK_H
#define OCAC_OCC_DATATYPES_NETWORK_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef OcaBlob OcaNetworkHostID;

typedef OcaBlob OcaNetworkNodeID;

typedef OcaBlob OcaNetworkAddress;

typedef struct {
    OcaNetworkAddress MyNetworkAddress;
    OcaBlob SystemInterfaceHandle;
} OcaNetworkSystemInterfaceID;

typedef OcaBlob OcaStreamID;

typedef OcaUint16 OcaStreamIndex;

typedef OcaBlob OcaStreamParameters;

typedef OcaBlob OcaStreamConnectorID;

typedef struct {
    OcaNetworkHostID HostID;
    OcaNetworkAddress NetworkAddress;
    OcaNetworkNodeID NodeID;
    OcaStreamConnectorID StreamConnectorID;
} OcaStreamConnectorIdentification;

typedef OcaUint16 OcaStreamConnectorPinIndex;

typedef OcaBlob OcaNetworkSignalChannelID;

typedef struct {
    u32_t rxPacketErrors;
    u32_t txPacketErrors;
} OcaNetworkStatistics;

typedef enum {
    OcaEncoding_None    = 0,
    OcaEncoding_Pcm16   = 1,
    OcaEncoding_Pcm24   = 2,
    OcaEncoding_Pcm32   = 3
} OcaEncoding;

typedef enum {
    OcaNetworkStatus_Unknown    = 0,
    OcaNetworkStatus_Ready      = 1,
    OcaNetworkStatus_StartingUp = 2,
    OcaNetworkStatus_Stopped    = 3
} OcaNetworkStatus;

typedef enum {
    OcaNetworkLinkType_None             = 0,
    OcaNetworkLinkType_EthernetWired    = 1,
    OcaNetworkLinkType_EthernetWireless = 2,
    OcaNetworkLinkType_USB              = 3,
    OcaNetworkLinkType_SerialP2P        = 4
} OcaNetworkLinkType;

typedef enum {
    OcaNetworkMediaProtocol_None        = 0,
    OcaNetworkMediaProtocol_AV3         = 1,
    OcaNetworkMediaProtocol_AVBTP       = 2,
    OcaNetworkMediaProtocol_Dante       = 3,
    OcaNetworkMediaProtocol_Cobranet    = 4,
    OcaNetworkMediaProtocol_AES67       = 5,
    OcaNetworkMediaProtocol_SMPTEAudio  = 6,
    OcaNetworkMediaProtocol_LiveWire    = 7
} OcaNetworkMediaProtocol;

typedef enum {
    OcaNetworkControlProtocol_None  = 0,
    OcaNetworkControlProtocol_OCP01 = 1,
    OcaNetworkControlProtocol_OCP02 = 2,
    OcaNetworkControlProtocol_OCP03 = 3
} OcaNetworkControlProtocol;

typedef enum {
    OcaStreamType_None      = 0,
    OcaStreamType_Unicast   = 1,
    OcaStreamType_Multicast = 2
} OcaStreamType;

typedef enum {
    OcaStreamStatus_NotConnected    = 0,
    OcaStreamStatus_Connected       = 1,
    OcaStreamStatus_Paused          = 2
} OcaStreamStatus;

typedef enum {
    OcaStreamConnectorStatus_NotAvailable   = 0,
    OcaStreamConnectorStatus_Idle           = 1,
    OcaStreamConnectorStatus_Connected      = 2,
    OcaStreamConnectorStatus_Paused         = 3
} OcaStreamConnectorStatus;

typedef enum {
    OcaNetworkSignalChannelStatus_NotConnected  = 0,
    OcaNetworkSignalChannelStatus_Connected     = 1,
    OcaNetworkSignalChannelStatus_Muted         = 2
} OcaNetworkSignalChannelStatus;

typedef enum {
    OcaNetworkMediaSourceOrSink_None    = 0,
    OcaNetworkMediaSourceOrSink_Source  = 1,
    OcaNetworkMediaSourceOrSink_Sink    = 2
} OcaNetworkMediaSourceOrSink;

typedef struct {
    OcaUint16 ErrorNumber;
    OcaStreamID IDAdvertised;
    OcaStreamIndex Index;
    OcaONo LocalConnectorONo;
    OcaUint16 Priority;
    OcaStreamConnectorIdentification RemoteConnectorIdentification;
    OcaBoolean Secure;
    OcaStreamStatus Status;
    OcaStreamType StreamType;
    OcaStreamParameters StreamParameters;
    OcaString Label;
} OcaStream;


#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_NETWORK_H
