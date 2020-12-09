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

#ifndef OCAC_OCC_DATATYPES_NETWORK_H
#define OCAC_OCC_DATATYPES_NETWORK_H

#include "ocac/opt.h"
#include "ocac/occ/datatypes/worker.h"
#include "blockmatrix.h"


#ifdef __cplusplus
extern "C" {
#endif


typedef OCAC_BLOB(OCAC_OCC_NETWORK_ADDR_MAXLEN) OcaNetworkAddress;

typedef enum {
    OcaNetworkLinkType_None             = 0,
    OcaNetworkLinkType_EthernetWired    = 1,
    OcaNetworkLinkType_EthernetWireless = 2,
    OcaNetworkLinkType_USB              = 3,
    OcaNetworkLinkType_SerialP2P        = 4
} PACK_STRUCT_STRUCT OcaNetworkLinkType;


typedef OcaBlob OcaApplicationNetworkServiceID;


typedef struct {
    OCAC_BLOB(OCAC_OCC_NETWORK_SYSTEMINTERFACEPARAMETERS_MAXLEN) SystemInterfaceParameters;
    OcaNetworkAddress MyNetworkAddress;
} PACK_STRUCT_STRUCT OcaNetworkSystemInterfaceDescriptor;

typedef enum {
    OcaApplicationNetworkState_Unknown  = 0,
    OcaApplicationNetworkState_NotReady = 1,
    OcaApplicationNetworkState_Readying = 2,
    OcaApplicationNetworkState_Ready    = 3,
    OcaApplicationNetworkState_Running  = 4,
    OcaApplicationNetworkState_Paused   = 5,
    OcaApplicationNetworkState_Stopping = 6,
    OcaApplicationNetworkState_Stopped  = 7,
    OcaApplicationNetworkState_Fault    = 8
} PACK_STRUCT_STRUCT OcaApplicationNetworkState;

typedef enum {
    OcaApplicationNetworkCommand_None       = 0,
    OcaApplicationNetworkCommand_Prepare    = 1,
    OcaApplicationNetworkCommand_Start      = 2,
    OcaApplicationNetworkCommand_Pause      = 3,
    OcaApplicationNetworkCommand_Stop       = 4,
    OcaApplicationNetworkCommand_Reset      = 5
} PACK_STRUCT_STRUCT OcaApplicationNetworkCommand;


typedef enum {
    OcaNetworkMediaProtocol_None        = 0,
    OcaNetworkMediaProtocol_AV3         = 1,
    OcaNetworkMediaProtocol_AVBTP       = 2,
    OcaNetworkMediaProtocol_Dante       = 3,
    OcaNetworkMediaProtocol_Cobranet    = 4,
    OcaNetworkMediaProtocol_AES67       = 5,
    OcaNetworkMediaProtocol_SMPTEAudio  = 6,
    OcaNetworkMediaProtocol_LiveWire    = 7,
    OcaNetworkMediaProtocol_ExtensionPoint  = 65
} PACK_STRUCT_STRUCT OcaNetworkMediaProtocol;


typedef enum {
    OcaNetworkControlProtocol_None  = 0,
    OcaNetworkControlProtocol_OCP01 = 1,
    OcaNetworkControlProtocol_OCP02 = 2,
    OcaNetworkControlProtocol_OCP03 = 3
} PACK_STRUCT_STRUCT OcaNetworkControlProtocol;

typedef OcaUint16 OcaMediaCodingSchemeID;

typedef struct {
    OcaMediaCodingSchemeID CodingSchemeID;
    OCAC_STRING(OCAC_OCC_NETWORK_CODECPARAMETERS_MAXLEN) CodecParameters;
    OcaONo ClockONo;
} PACK_STRUCT_STRUCT OcaMediaCoding;

typedef OcaString OcaSDPString;

typedef enum {
    OcaMediaStreamCastMode_None         = 0,
    OcaMediaStreamCastMode_Unicast      = 1,
    OcaMediaStreamCastMode_Multicast    = 2
} PACK_STRUCT_STRUCT OcaMediaStreamCastMode;

typedef OCAC_BLOB(OCAC_OCC_NETWORK_MEDIASTREAMPARAMETERS_MAXLEN) OcaMediaStreamParameters;

typedef struct {
    OcaBoolean Secure;
    OcaMediaStreamParameters StreamParameters;
    OcaMediaStreamCastMode StreamCastMode;
    OcaUint16 StreamChannelCount;
} PACK_STRUCT_STRUCT OcaMediaConnection;

typedef struct {
    OcaUint16 Index;
} PACK_STRUCT_STRUCT OcaMediaConnectorID;

/**
 * For reference only
 */
typedef struct {
    OcaMediaConnectorID IDInternal;
    OCAC_STRING(0) IDExternal;
    OcaMediaConnection Connection;
    OCAC_LIST(OcaMediaCoding,0) AvailableCodings;
    OcaMediaCoding CurrentCoding;
    OcaUint16 PinCount;
    OCAC_MULTIMAP(OcaUint16, OcaPortID, 0) ChannelPinMap;
    OcaDBFS AlignmentLevel;
    OcaDB AlignmentGain;
} PACK_STRUCT_STRUCT OcaMediaSinkConnector;

/**
 * For reference only
 */
typedef struct {
    OcaMediaConnectorID IDInternal;
    OCAC_STRING(0) IDExternal;
    OcaMediaConnection Connection;
    OCAC_LIST(OcaMediaCoding,0) AvailableCodings;
    OcaMediaCoding CurrentCoding;
    OcaUint16 PinCount;
    OCAC_MULTIMAP(OcaUint16, OcaPortID,0) ChannelPinMap;
} PACK_STRUCT_STRUCT OcaMediaSourceConnector;

typedef enum {
    OcaMediaConnectorState_Stopped      = 0,
    OcaMediaConnectorState_SettingUp    = 1,
    OcaMediaConnectorState_Running      = 2,
    OcaMediaConnectorState_Paused       = 3,
    OcaMediaConnectorState_Fault        = 4
} PACK_STRUCT_STRUCT OcaMediaConnectorState;

typedef struct {
    OcaMediaConnectorID ConnectorID;
    OcaMediaConnectorState State;
    OcaUint16 ErrorCode;
} PACK_STRUCT_STRUCT OcaMediaConnectorStatus;

typedef enum {
    OcaMediaConnectorCommand_None   = 0,
    OcaMediaConnectorCommand_Start  = 1,
    OcaMediaConnectorCommand_Pause  = 2
} PACK_STRUCT_STRUCT OcaMediaConnectorCommand;


// is deprecated according to EAP?
typedef OCAC_BLOB(OCAC_OCC_NETWORK_HOSTID_MAXLEN) OcaNetworkHostID;

typedef struct {
    OcaNetworkHostID HostID;
    PACK_STRUCT_FIELD(OcaONo ONo);
} PACK_STRUCT_STRUCT OcaOPath;



//typedef struct {
//    OcaNetworkAddress MyNetworkAddress;
//    OcaBlob SystemInterfaceHandle;
//} PACK_STRUCT_STRUCT OcaNetworkSystemInterfaceID;

//typedef enum {
//    OcaEncoding_None    = 0,
//    OcaEncoding_Pcm16   = 1,
//    OcaEncoding_Pcm24   = 2,
//    OcaEncoding_Pcm32   = 3
//} PACK_STRUCT_STRUCT OcaEncoding;




//typedef OCAC_BLOB(OCAC_OCC_NETWORK_NODEID_MAXLEN) OcaNetworkNodeID;




//typedef OCAC_BLOB(OCAC_OCC_NETWORK_STREAMID_MAXLEN) OcaStreamID;

//typedef OcaUint16 OcaStreamIndex;

//typedef OCAC_BLOB(OCAC_OCC_NETWORK_STREAMPARAM_MAXLEN) OcaStreamParameters;

//typedef OCAC_BLOB(OCAC_OCC_NETWORK_STREAMCONNID_MAXLEN) OcaStreamConnectorID;




#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_NETWORK_H
