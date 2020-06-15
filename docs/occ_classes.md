# OCC Classes

Human readable form of AES70-2-2018 Appendix A (also see [XMI](http://www.aes.org/standards/models/AES70-2-2018-AnnexA.xmi), [EAP](http://www.aes.org/standards/models/AES70-2-2018-AnnexA.eap)) *(extract)*

Required functionality according to AES70-2 Appendix B.

## Overview

Ver | ID | Class | ONo [1] | Required
--- |:--- | :--- | ---: | :---:
2 | 1 | OcaRoot | | (YES)
| |
2 | 1 1 | OcaWorker | | (YES)
2 | 1 1 1 | OcaActuator
2 | 1 1 1 XY | ...
| |
2 | 1 1 2 | OcaSensor
2 | 1 1 2 XY | ...
| |
2 | 1 1 3 | OcaBlock | 100 [2] | YES
2 | 1 1 4 | OcaBlockFactory
2 | 1 1 5 | OcaMatrix
| | 1 1 6 | OcaNetworkSignalChannel *DEPRECATED*
| |
2 | 1 2 | OcaAgent  | | (YES [3,4])
| | 1 2 1 | OcaNetwork *DEPRECATED*
2 | 1 2 2 | OcaGrouper
2 | 1 2 3 | OcaRamper
2 | 1 2 4 | OcaNumericObserver
2 | 1 2 5 | OcaLibrary
| | 1 2 6 | OcaMediaClock *DEPRECATED*
2 | 1 2 7 | OcaPowerSupply
2 | 1 2 8 | OcaEventHandler
2 | 1 2 9 | OcaNumericObserverList
| | 1 2 10 | OcaStreamNetwork *DEPRECATED*
| | 1 2 11 | OcaStreamConnector *DEPRECATED*
1 | 1 2 15 | OcaMediaClock3
1 | 1 2 16 | OcaTimeSource
1 | 1 2 17 | OcaPhysicalPosition
| |
2 | 1 3 | OcaManager | | (YES)
2 | 1 3 1 | OcaDeviceManager | 1 | YES
2 | 1 3 2 | OcaSecurityManager | 2 | YES [3]
2 | 1 3 3 | OcaFirmwareManager | 3 | YES
2 | 1 3 4 | OcaSubscriptionManager | 4 | YES
2 | 1 3 5 | OcaPowerManager | 5
2 | 1 3 6 | OcaNetworkManager | 6 | YES
2 | 1 3 7 | OcaMediaClockManager | 7 | YES [4]
2 | 1 3 8 | OcaLibraryManager | 8
2 | 1 3 9 | OcaAudioProcessingManager | 9
2 | 1 3 10 | OcaDeviceTimeManager | 10
1 | 1 3 11 | OcaTaskManager | 11
1 | 1 3 12 | OcaCodingManager | 12
1 | 1 3 13 | OcaDiagnosticManager | 13
| |
1 | 1 4 | OcaApplicationNetwork | | (YES)
1 | 1 4 1 | OcaControlNetwork | | YES [5]
1 | 1 4 2 | OcaMediaTransportNetwork | | YES [4]

1. iff singleton (manager) or object root
2. Object root is an instance of OcaBlock
3. For secured devices
4. For streaming devices
5.

## OcaRoot
ID 1, Version 2

ID | Declaration | Required
--- | --- | ---
01m01 | GetClassIdentification() -> OcaClassIdentification
01m02 | GetLockable() -> OcaBoolean | YES
01m03 | LockTotal() | YES
01m04 | Unlock() | YES
01m05 | GetRole() -> OcaString
01m06 | LockReadonly()
| |
01p01 | OcaClassID ClassID
01p02 | OcaClassVersionNumber ClassVersion
01p03 | OcaONo ObjectNumber
01p04 | OcaBoolean Lockable
01p05 | OcaString Role
| |
01e01 | PropertyChanged(OcaPropertyChangedEventData)


## OcaWorker
ID 1 1, Version 2

ID | Declaration | Required
--- | --- | ---
02m01 | GetEnabled() -> OcaBoolean | YES
02m02 | SetEnabled(OcaBoolean) | YES
02m03 | AddPort(OcaString, OcaPortMode) -> OcaPortID
02m04 | DeletePort(OcaPortID)
02m05 | GetPorts() -> OcaList<OcaPort> | YES
02m06 | GetPortName(OcaPortID) -> OcaString
02m07 | SetPortName(OcaPortID, OcaString)
02m08 | GetLabel() -> OcaLabel
02m09 | SetLabel(OcaString)
02m10 | GetOwner() -> OcaONo
02m11 | GetLatency() -> OcaTimeInterval
02m12 | SetLatency(OcaTimeInterval)
02m13 | GetPath() -> OcaNamePath, OcaONoPath
| |
02p01 | OcaBoolean Enabled
02p02 | OcaList<OcaPort> Ports
02p03 | OcaString Label
02p04 | OcaONo Owner
02p05 | OcaTimeInterval Latency

### OcaActuator
ID 1 1 1, Version 2

### OcaSensor
ID 1 1 2, Version 2

### OcaBlock
ID 1 1 3, Version 2

ID | Declaration | Required
--- | --- | ---
03m01 | GetType() -> OcaONo
03m02 | ConstructMember(OcaClassID, variant[0..n]) -> OcaONo
03m03 | ConstructMemberUsingFactory(OcaONo) -> OcaOno
03m04 | DeleteMember(OcaONo)
03m05 | GetMembers() -> OcaList<OcaObjectIdentification>
03m06 | GetMembersRecursive() -> OcaList<OcaBlockMember>
03m07 | AddSignalPath(OcaSignalPath OcaUin16
03m08 | DeleteSignalPath(OcaUin16)
03m09 | GetSignalPaths() -> OcaMap<OcaUint16, OcaSignalPath>
03m10 | GetSignalPathsRecursive() -> OcaMap<OcaUint16, OcaSignalPath>
03m11 | GetMostRecentParamSetIdentifier() -> OcaLibVolIdentifier
03m12 | ApplyParamSet() -> OcaLibVolIdentifier
03m13 | GetCurrentParamSetData() -> OcaLibVolData_ParamSet
03m14 | StoreCurrentParamSetData(OcaLibVolIdentifier)
03m15 | GetGlobalType() -> OcaGlobalTypeIdentifier
03m16 | GetONoMap() -> OcaMap<OcaProtoONo, OcaONo>
03m19 | FindObjectsByLabelRecursive(OcaString searchName, OcaStringComparisonType, OcaClassID, OcaObjectSearchResultFlags) -> OcaList<OcaObjectSearchResult>
03m20 | FindObjectsByPath(OcaNamePath, OcaObjectSearchResultFlags) -> OcaList<OcaObjectSearchResult>
03m17 | FindObjectsByRole(OcaString searchName, OcaStringComparisonType, OcaClassID, OcaObjectSearchResultFlags) -> OcaList<OcaObjectSearchResult>
03m18 | FindObjectsByRoleRecursive(OcaString searchName, OcaStringComparisonType, OcaClassID, OcaObjectSearchResultFlags) -> OcaList<OcaObjectSearchResult>
| |
03p01 | OcaONo Type [1]
03p02 | OcaList<OcaObjectIdentification> Members
03p03 | OcaMap<OcaUin16, OcaSignalPath> SignalPaths
03p04 | OcaLibVolIdentifier MostRecentParamSetIdentifier
03p05 | OcaGlobalTypeIdentifier GlobalType
03p06 | OcaMap<OcaProtoONo, OcaONo> ONoMap

1. For root block the value is 1. For dynamically-defined blocks this is the factory ONo. For statically-defined blocks
this value "correspond to the unique configuration of this block".

### OcaBlockFactory
ID 1 1 4, Version 2

### OcaMatrix
ID 1 1 5, Version 2

### OcaNetworkSignalChannel

*DEPRECATED*
ID 1 1 6

ID | Declaration | Required
--- | --- | ---
03m01 | GetIDAdvertised() -> OcaNetworkSignalChannelID
03m02 | SetIDAdvertised(OcaNetworkSignalChannelID)
03m03 | GetNetwork() -> OcaONo
03m04 | SetNetwork(OcaONo)
03m05 | GetConnectorPins() -> OcaMap<OcaNo, OcaStreamConnectorPinIndex>
03m06 | AddToConnector(OcaONo connector, OcaStreamConnectorPinIndex)
03m07 | RemoveFromConnector(OcaONo connector)
03m08 | GetRemoteChannelID() -> OcaNetworkSignalChannelID
03m09 | SetRemoteChannelID(OcaNetworkSignalChannelID)
03m10 | GetSourceOrSink() -> OcaNetworkMediaSourceOrSink
03m11 | GetStatus() -> OcaNetworkSignalChannelStatus
| |
03p01 | OcaNetworkSignalChannelID IDAdvertised
03p02 | OcaONo Network
03p03 | OcaMap<OcaNo, OcaStreamConnectorPinIndex> ConnectorPins
03p04 | OcaNetworkSignalChannelID RemoteChannelID
03p05 | OcaNetworkMediaSourceOrSink SourceOrSink
03p06 | OcaNetworkSignalChannelStatus Status

## OcaAgent
ID 1 2, Version 2

ID | Declaration | Required
--- | --- | ---
02m01 | GetLabel() -> OcaString
02m02 | SetLabel(OcaString)
02m03 | GetOwner() -> OcaONo
02m04 | GetPath() -> OcaNamePath, OcaONoPath
| |
02p01 | OcaString Label
02p02 | OcaONo Owner


### OcaNetwork
*DEPRECATED*

ID 1 2 1

ID | Declaration | Required
--- | --- | ---
03m01 | GetLinkType() -> OcaNetworkLinkType | YES [1]
03m02 | GetIDAdvertised() -> OcaNetworkNodeID | YES [1]
03m03 | SetIDAdvertised(OcaNetworkNodeID) | YES [1]
03m04 | GetControlProtocol() -> OcaNetworkControlProtocol | YES [1]
03m05 | GetMediaProtocol() -> OcaNetworkMediaProtocol | YES [1]
03m06 | GetStatus() -> OcaNetworkStatus | YES [1]
03m07 | GetStatistics() -> OcaNetworkStatistics | YES [1]
03m08 | ResetStatistics() | YES [1]
03m09 | GetSystemInterfaces() -> OcaList<OcaNetworkSystemInterface> | YES [1]
03m10 | SetSystemInterfaces(OcaList<OcaNetworkSystemInterface> | YES [1]
03m11 | GetMediaPorts() -> OcaList<OcaONo> | YES [1]
03m12 | Startup() | YES [1]
03m13 | Shutdown() | YES [1]
| |
03p01 | OcaNetworkLinkType LinkType
03p02 | OcaNetworkNodeID IDAdvertised
03p03 | OcaNetworkControlProtocol ControlProtocol
03p04 | OcaNetworkMediaProtocol MediaProtocol
03p05 | OcaNetworkStatus Status
03p06 | OcaList<OcaNetworkSystemInterface>
03p07 | OcaList<OcaONo> MediaPorts
03p08 | OcaNetworkStatistics Statistics

1. If the OcaNetwork is implemented, all methods (and events) MUST be implemented.

### OcaGrouper
ID 1 2 2, Version 2

### OcaRamper
ID 1 2 3, Version 2

### OcaNumericObserver
ID 1 2 4, Version 2

### OcaLibrary
ID 1 2 5, Version 2

### OcaMediaClock
*DEPRECATED*

ID 1 2 6

ID | Declaration | Required
--- | --- | ---
03m01 | GetType() -> OcaMediaClockType | YES [1]
03m02 | SetType(OcaMediaClockType) | YES [1]
03m03 | GetDomainID() -> OcaUint16 | YES [1]
03m04 | SetDomainID(OcaUint16) | YES [1]
03m05 | GetSupportedRates() -> OcaList<OcaMediaClockRate> | YES [1]
03m06 | GetRate() -> OcaMediaClockRate | YES [1]
03m07 | SetRate(OcaMediaClockRate) | YES [1]
03m08 | GetLockState() -> OcaMediaClockLockState | YES [1]
| |
03p01 | OcaMediaClockType Type
03p02 | OcaUint16 DomainID
03p03 | OcaList<OcaMediaClockRate>
03p04 | OcaMediaClockRate CurrentRate
03p05 | OcaMediaClockLockState LockState

1. If OcaMediaClock is implemented, all methods (and events) must be implemented.

### OcaPowerSupply
ID 1 2 7, Version 2

ID | Declaration | Required
--- | --- | ---
03m01 | GetType() -> OcaPowerSupplyType
03m02 | GetModelInfo() -> OcaString
03m03 | GetState() -> OcaPowerSupplyState
03m04 | SetState(OcaPowerSupplyState)
03m05 | GetCharging() -> OcaBoolean
03m06 | GetLocation() -> OcaPowerSupplyLocation
03m07 | GetStorageFractionAvailable() -> OcaFloat32
03m08 | GetLoadFractionAvailable() -> OcaFloat32
| |
03p01 | OcaPowerSupplyType Type
03p02 | OcaString ModelInfo
03p03 | OcaPowerSupplyState State
03p04 | OcaBoolean Charging
03p05 | OcaFloat32 LoadFractionAvailable
03p06 | OcaFloat32 StorageFractionAvailable
03p07 | OcaPowerSupplyLocation Location

### OcaEventHandler
ID 1 2 8, Version 2

### OcaNumericObserverList
ID 1 2 9, Version 2

### OcaStreamNetwork
*DEPRECATED*

ID 1 2 10

ID | Declaration | Required
--- | --- | ---
03m01 | GetLinkType() -> OcaNetworkLinkType | YES [1]
03m02 | GetIDAdvertised() -> OcaNetworkNodeID | YES [1]
03m03 | SetIDAdvertised(OcaNetworkNodeID) | YES [1]
03m04 | GetControlProtocol() -> OcaNetworkControlProtocol | YES [1]
03m05 | GetMediaProtocol() -> OcaNetworkMediaProtocol | YES [1]
03m06 | GetStatus() -> OcaNetworkStatus | YES [1]
03m07 | GetStatistics() -> OcaNetworkStatistics | YES [1]
03m08 | ResetStatistics() | YES [1]
03m09 | GetSystemInterfaces() -> OcaList<OcaNetworkSystemInterfaceID> | YES [1]
03m10 | SetSystemInterfaces(OcaList<OcaNetworkSystemInterfaceID>) | YES [1]
03m11 | GetStreamConnectorsSource() -> OcaList<OcaONo> | YES [1]
03m12 | SetStreamConnectorsSource(OcaList<OcaONo>) | YES [1]
03m13 | GetStreamConnectorsSink() -> OcaList<OcaONo> | YES [1]
03m14 | SetStreamConnectorsSink(OcaList<OcaONo>) | YES [1]
03m15 | GetSignalChannelsSource() -> OcaList<OcaONo> | YES [1]
03m16 | SetSignalChannelsSource(OcaList<OcaONo>) | YES [1]
03m17 | GetSignalChannelsSink() -> OcaList<OcaONo> | YES [1]
03m18 | SetSignalChannelsSink(OcaList<OcaONo>) | YES [1]
03m19 | Startup() | YES [1]
03m20 | Shutdown() | YES [1]
||
03p01 | OcaNetworkLinkType LinkType
03p02 | OcaNetworkNodeID IDAdvertised
03p03 | OcaNetworkControlProtocol ControlProtocol
03p04 | OcaNetworkMediaProtocol MediaProtocol
03p05 | OcaNetworkStatus Status
03p06 | OcaList<OcaNetworkSystemInterfaceID> SystemInterfaces
03p07 | OcaList<OcaONo> StreamConnectorsSource
03p08 | OcaList<OcaONo> StreamConnectorsSink
03p09 | OcaList<OcaONo> SignalChannelsSource
03p10 | OcaList<OcaONo> SignalChannelsSink
03p11 | OcaNetworkStatistics Statistics

1. If the OcaStreamNetwork is implemented, all methods (and events) MUST be implemented.

### OcaStreamConnector
*DEPRECATED*

ID 1 2 11

ID | Declaration | Required
--- | --- | ---
03m01 | GetOwnerNetwork() -> OcaONo
03m02 | SetOwnerNetwork(OcaONo)
03m03 | GetIDAdvertised() -> OcaStreamConnectorID
03m04 | SetIDAdvertised(OcaStreamConnectorID)
03m05 | GetSourceOrSink() -> OcaNetworkMediaSourceOrSink
03m06 | SetSourceOrSink(OcaNetworkMediaSourceOrSink)
03m07 | ConnectStream(OcaStream) -> OcaStreamIndex
03m08 | DisconnectStream(OcaStreamIndex)
03m09 | GetStreams() -> OcaList<OcaStream>
03m10 | GetPins() -> OcaMap<OcaStreamConnectorPinIndex, OcaONo>
03m11 | GetStatus() -> OcaStreamConnectorStatus
| |
03p01 | OcaONo OwnerNetwork
03p02 | OcaStreamConnectorID IDAdvertised
03p03 | OcaNetworkMediaSourceOrSink SourceOrSink
03p04 | OcaList<OcaStream> Streams
03p05 | OcaMap<OcaStreamConnectorPinIndex, OcaONo> Pins
03p06 | OcaStreamConnectorStatus Status

### OcaMediaClock3
ID 1 2 15, Version 1

ID | Declaration | Required
--- | --- | ---
03m01 | GetAvailability() -> OcaMediaClockAvailability
03m02 | SetAvailability(OcaMediaClockAvailability)
03m03 | GetCurrentRate() -> OcaMediaClockRate, OcaONo
03m04 | SetCurrentRate(OcaMediaClockRate, OcaONo)
03m05 | GetOffset() -> OcaTimePTP
03m06 | SetOffset(OcaTimePTP)
03m07 | GetSupportedRates() -> OcaMap<OcaONo, OcaList<OcaMediaClockRate>>
| |
03p01 | OcaMediaClockAvailability Availability
03p02 | OcaONo TimeSourceONo
03p03 | OcaTimePTP Offset
03p04 | OcaMediaClockRate CurrentRate
03p05 | OcaMap<OcaONo, OcaList<OcaMediaClockRate>> SupportedRates


### OcaTimeSource
ID 1 2 16, Version 1

ID | Declaration | Required
--- | --- | ---
03m01 | GetAvailability() -> OcaTimeSourceAvailability
03m02 | GetProtocol() -> OcaTimeProtocol
03m03 | SetProtocol(OcaTimeProtocol)
03m04 | GetParameters() -> OcaSDPString
03m05 | SetParameters(OcaSDPString)
03m06 | GetReferenceType() -> OcaTimeReferenceType
03m07 | SetReferenceType(OcaTimeReferenceType)
03m08 | GetReferenceID() -> OcaString
03m09 | SetReferenceID(OcaString)
03m10 | GetSyncStatus() -> OcaTimeSourceSyncStatus
03m11 | Reset()
| |
03p01 | OcaTimeSourceAvailability Availability
03p02 | OcaTimeProtocol Protocol
03p03 | OcaSDPString Parameters
03p04 | OcaTimeReferenceType ReferenceType
03p05 | OcaString ReferenceID
03p06 | OcaTimeSourceSyncStatus SyncStatus

### OcaPhysicalPosition
ID 1 2 17, Version 1

ID | Declaration | Required
--- | --- | ---
03m01 | GetCoordinateSystem() -> OcaPositionCoordinateSystem
03m02 | GetPositionDescriptorFieldFlags() -> OcaPositionDescriptorFieldFlags
03m03 | GetPositionDescriptor() -> OcaPositionDescriptor pos, OcaPositionDescriptor minPos, OcaPositionDescriptor maxPos
03m04 | SetPositionDescriptor(OcaPositionDescriptor)
| |
03p01 | OcaPositionCoordinateSystem CoordinateSystem
03p02 | PositionDescriptorFieldFlags PositionDescriptorFieldFlags
03p03 | OcaPositionDescriptor PositionDescriptor

## OcaManager
ID 1 3, Version 2

No new methods, properties or events.

### OcaDeviceManager
ID 1 3 1, Version 2, ONo 1

ID | Declaration | Required
--- | --- | ---
03m01 | GetOcaVersion() -> OcaUint16 | YES
03m02 | GetModelGUID() -> OcaModelDescription| YES
03m03 | GetSerialNumber() -> OcaString | YES
03m04 | GetDeviceName() -> OcaString | YES
03m05 | SetDeviceName(OcaString)
03m06 | GetModelDescription() -> OcaModelDescription | YES
03m07 | GetRole() -> OcaString
03m08 | SetRole(OcaString)
03m09 | GetUserInventoryCode() -> OcaString
03m10 | SetUserInventoryCode(OcaString)
03m11 | GetEnabled() -> OcaBoolean | YES
03m12 | SetEnabled(OcaBoolean) | YES
03m13 | GetState() -> OcaDeviceState | YES
03m14 | SetResetKey(OcaBlobFixedLen<16> key, OcaNetworkAddress)
03m15 | GetResetCause() -> OcaResetCause
03m16 | ClearResetCause()
03m17 | GetMessage() -> OcaString
03m18 | SetMessage(OcaString)
03m19 | GetManagers() -> OcaList<OcaManagerDescriptor> | YES
03m20 | GetDeviceRevisionID() -> OcaString
| |
03p01 | OcaModelGUID ModelGUID
03p02 | OcaString SerialNumber
03p03 | OcaModelDescription
03p04 | OcaString DeviceName
03p05 | OcaUint16 OcaVersion
03p06 | OcaString Role[1]
03p07 | OcaString UserInventoryCode
03p08 | OcaBoolean Enabled
03p09 | OcaDeviceState State
03p10 | OcaBoolean Busy
03p11 | OcaResetCause ResetCause
03p12 | OcaString Message
03p13 | OcaList<OcaManagerDescriptor> Managers
03p14 | OcaString DeviceRevisionID

1. It is somewhat unclear why the role was redefined? see 01p05


### OcaSecurityManager
ID 1 3 2, Version 2, ONo 2

ID | Declaration | Required
--- | --- | ---
03m01 | EnableControlSecurity() | YES [1]
03m02 | DisableControlSecurity() | YES [1]
03m03 | ChangePreSharedKey(OcaString identity, OcaBlob key ) | YES [1]
03m04 | AddPreSharedKey(OcaString identity, OcaBlob newKey ) | YES [1]
03m05 | DeletePreSharedKey(OcaString identity) | YES [1]
| |
03p01 | OcaBoolean secureControlData

1. Required iff secure


### OcaFirmwareManager
ID 1 3 3, Version 2, ONo 3

ID | Declaration | Required
--- | --- | ---
03m01 | GetComponentVersions() -> OcaList<OcaVersion> | YES
03m02 | StartUpdateProcess()  | YES [1]
03m03 | BeginActiveImageUpdate(OcaComponent) | YES [1]
03m04 | AddImageData(OcaUint32 id, OcaBlob imageData) | YES [1]
03m05 | VerifyImage(OcaBlob verifyData) | YES [1]
03m06 | EndActiveImageUpdate() | YES [1]
03m07 | BeginPassiveComponentUpdate(OcaComponent, OcaNetworkAddress server, OcaString updateFileName) | YES [1]
03m08 | EndUpdateProcess() | YES [1]
| |
03p01 | OcaList<OcaVersion> ComponentVersions

1. If firmware updates are supported the manager must implement all methods.

### OcaSubscriptionManager
ID 1 3 4, Version 2, ONo 4

ID | Declaration | Required
--- | --- | ---
03m01 | AddSubscription(OcaEvent, OcaMethod, OcaBlob context, OcaNotificationDeliveryMode, OcaNetworkAddress ) | YES
03m02 | RemoveSubsription(OcaEvent, OcaMethod) | YES
03m03 | DisableNotifications()
03m04 | ReEnableNotifications()
| |
01p01 | OcaSubscriptionmanagerState State
| |
03e01 | NotificationsDisabled(OcaEvendData)
03e02 | SynchronizeState(OcaObjectListEventData)


### OcaPowerManager
ID 1 3 5, Version 2, ONo 5

ID | Declaration | Required
--- | --- | ---
03m01 | GetState() -> OcaPowerState
03m02 | SetState(OcaPowerState)
03m03 | GetPowerSupplies() -> OcaList<OcaONo>
03m04 | ExchangePowerSupply(OcaONo oldPsu, OcaONo newPsu, OcaBoolean powerOffOld)
03m05 | GetActivePowerSupplies() -> OcaList<OcaONo>
03m06 | GetAutoState() -> OcaBoolean
| |
03p01 | OcaPowerState State
03p02 | OcaList<OcaONo> PowerSupplies
03p03 | OcaList<OcaONo> ActivePowerSupplies
03p04 | OcaBoolean AutoState
03p05 | OcaPowerStateTargetState



### OcaNetworkManager
ID 1 3 6, Version 2, ONo 6

ID | Declaration | Required
--- | --- | ---
03m01 | *DEPRECATED* GetNetworks() -> OcaList<OcaONo> | YES
03m02 | *DEPRECATED* GetStreamNetworks() -> OcaList<OcaONo> | YES
03m03 | GetControlNetworks() -> OcaList<OcaONo> | YES
03m04 | GetMediaTransportNetworks() -> OcaList<OcaONo> | YES
| |
03p01 | *DEPRECATED* Networks
03p02 | *DEPRECATED* StreamNetworks
03p03 | OcaList<OcaONo> ControlNetworks
03p04 | OcaList<OcaONo> MediaTransportNetworks


### OcaMediaClockManager
ID 1 3 7, Version 2, ONo 7

ID | Declaration | Required
--- | --- | ---
03m01 | *DEPRECATED* GetClocks() -> OcaList<OcaONo> | YES [1]
03m02 | *DEPRECATED* GetMediaClockTypesSupported() -> OcaList<OcaMediaClockType> | YES [1]
03m03 | GetClock3s() -> OcaList<OcaONo> | YES [1]
| |
03p01 | *DEPRECATED* OcaList<OcaMediaClockType> ClockSourceTypesSupported
03p02 | *DEPRECATED* OcaList<OcaONo> Clocks
03p03 | OcaList<OcaONo> Clock3s

1. If class is implemented, all methods MUST be supported (well, makes sense).

### OcaLibraryManager
ID 1 3 8, Version 2, ONo 8

ID | Declaration | Required
--- | --- | ---
03m01 | AddLibrary(OcaLibraryType) -> OcaONo libraryIdentifier
03m02 | DeleteLibrary(OcaONo libraryIdentifier)
03m03 | GetLibraryCount(OcaLibraryType) -> OcaUint16
03m04 | GetLibraryList(OcaLibraryType) -> OcaList<OcaONo>
03m05 | GetCurrentPatch() -> OcaLibVolIdentifier
03m06 | SetCurrentPatch(OcaLibVolIdentifier)
| |
03p01 | OcaList<OcaLibIdentifier>
03p02 | OcaLibVolIdentifier CurrentPatch


### OcaAudioProcessingManager
ID 1 3 9, Version 2, ONo 9

No definitions


### OcaDeviceTimeManager
ID 1 3 10, Version 2, ONo 10

ID | Declaration | Required
--- | --- | ---
03m01 | *DEPRECATED* GetDeviceTimeNTP() -> OcaTimeNTP
03m02 | *DEPRECATED* SetDeviceTimeNTP(OcaTimeNTP)
03m03 | GetTimeSources() -> OcaList<OcaONo>
03m04 | GetCurrentDeviceTimeSource() -> OcaONo
03m05 | GetDeviceTimePTP() -> OcaTimePTP
03m06 | SetDeviceTimePTP(OcaTimePTP)
| |
03p01 | OcaList<OcaONo>TimeSources
03p02 | OcaONo CurrentDeviceTimeSource

### OcaTaskManager
ID 1 3 11, Version 1, ONo 11

ID | Declaration | Required
--- | --- | ---
03m01 | Enable(OcaBoolean)
03m02 | ControlAllTasks(OcaTaskCommand, OcaBlob)
03m03 | ControlTaskGroup(OcaTaskGroupID, OcaTaskCommand, OcaBlob)
03m04 | ControlTask(OcaTaskID, OcaTaskCommand, OcaBlob)
03m05 | GetState() -> OcaTaskManagerState
03m06 | GetTaskStatus(OcaTaskID) -> OcaTaskStatus
03m07 | GetTaskStatuses() ->OcaTaskStatus
03m08 | AddTask(OcaTask)
03m09 | GetTask(OcaTaskID) -> OcaTask
03m10 | GetTasks() -> OcaMap<OcaTaskID, OcaTask>
03m11 | SetTask(OcaTaskID, OcaTask)
03m12 | DeleteTask(OcaTaskID)
| |
03p01 | OcaTaskManagerState State
03p02 | OcaMap<OcaTaskID, OcaTask> Tasks
| |
03e01 | TaskStateChanged -> OcaTaskStateChangedEventData


### OcaTaskManager
ID 1 3 12, Version 1, ONo 12

ID | Declaration | Required
--- | --- | ---
03m01 | GetAvailableEncodingSchemes() -> OcaMap<OcaMediaCodingSchemeID,OcaString>
03m02 | GetAvailableDecodingSchemes() -> OcaMap<OcaMediaCodingSchemeID,OcaString>
| |
03p01 | OcaMap<OcaMediaCodingSchemeID,OcaString> AvailableEncodingSchemes
03p02 | OcaMap<OcaMediaCodingSchemeID,OcaString> AvailableDecodingSchemes


### OcaDiagnosticManager
ID 1 3 13, Version 1, ONo 13

ID | Declaration | Required
--- | --- | ---
03m01 | GetLockStatus(OcaONo) -> OcaString


## OcaApplicationNetwork
ID 1 4, Version 1

ID | Declaration | Required
--- | --- | ---
02m01 | GetLabel() -> OcaString
02m02 | SetLabel(OcaString)
02m03 | GetOwner() -> OcaONo
02m04 | GetServiceID() -> OcaApplicationNetworkServiceID
02m05 | SetServiceID(OcaApplicationNetworkServiceID)
02m06 | GetSystemInterfaces() -> OcaList<OcaNetworkSystemInterfaceDescriptor>
02m07 | SetSystemInterfaces(OcaList<OcaNetworkSystemInterfaceDescriptor>)
02m08 | GetState() -> OcaApplicationNetworkState
02m09 | GetErrorCode() -> OcaUint16
02m10 | Control(OcaApplicationNetworkCommand)
02m11 | GetPath() -> OcaNamePath, OcaONoPath
| |
02p01 | OcaString Label
02p02 | OcaONo Owner
02p03 | OcaApplicationNetworkServiceID ServiceID
02p04 | OcaList<OcaNetworkSystemInterfaceDescriptor> SystemInterfaces
02p05 | OcaApplicationNetworkState State
02p06 | OcaUint16 ErrorCode

### OcaControlNetwork
ID 1 4 1, Version 1

ID | Declaration | Required
--- | --- | ---
03m01 | GetControlProtocol() -> OcaNetworkControlProtocol
| |
03p01 | OcaNetworkControlProtocol Protocol


### OcaControlNetwork
ID 1 4 1, Version 1

ID | Declaration | Required
--- | --- | ---
03m01 | GetMediaProtocol) -> OcaNetworkMediaProtocol
03m02 | GetPorts() -> OcaList<OcaPort>
03m03 | GetPortName(OcaPortID) -> OcaString
03m04 | SetPortName(OcaPortID, OcaString)
03m05 | GetMaxSourceConnectors() -> OcaUint16
03m06 | GetMaxSinkConnectors() -> OcaUint16
03m07 | GetMaxPinsPerConnector() -> OcaUint16
03m08 | GetMaxPortsPerPin() -> OcaUint16
03m09 | GetSourceConnectors() -> OcaList<OcaMediaSourceConnector>
03m10 | GetSourceConnector(OcaMediaConnectorID) -> OcaMediaSourceConnector
03m11 | GetSinkConnectors() -> OcaList<OcaMediaSinkConnector>
03m12 | GetSinkConnector(OcaMediaConnectorID) -> OcaMediaSinkConnector
03m13 | GetConnectorsStatuses() -> OcaList<OcaMediaConnectorStatus>
03m14 | GetConnectorStatus(OcaMediaConnectorID) -> OcaMediaConnectorStatus
03m15 | AddSourceConnector(OcaMediaSourceConnector, OcaMediaConnectorState)
03m16 | AddSinkConnector(OcaMediaConnectorStatus initial, OcaMediaSinkConnector)
03m17 | ControlConnector(OcaMediaConnectorID, OcaMediaConnectorCommand)
03m18 | SetSourceConnectorPinMap(OcaMediaConnectorID, OcaMultiMap<OcaUint16, OcaPortID>)
03m19 | SetSinkConnectorPinMap(OcaMediaConnectorID, OcaMultiMap<OcaUint16, OcaPortID>)
03m20 | SetConnectorConnection(OcaMediaConnectorID, OcaMediaConnection)
03m21 | SetConnectorCoding(OcaMediaConnectorID, OcaMediaCoding)
03m22 | SetConnectorAlignmentLevel(OcaMediaConnectorID, OcaDBFS)
03m23 | SetConnectorAlignmentGain(OcaMediaConnectorID, OcaMediaCoding)
03m24 | DeleteConnector(OcaMediaConnectorID)
03m25 | GetAlignmentLevel) -> OcaDBFS level, OcaDBFS minLevel, OcaDBFS maxLevel
03m26 | GetAlignmentGain() -> OcaDB gain, OcaDB minGain, OcaDB maxGain
| |
03p01 | OcaNetworkMediaProtocol Protocol
03p02 | OcaList<OcaPort> Ports
03p03 | OcaUint16 MaxSourceConnectors
03p04 | OcaUint16 MaxSinkConnectors
03p05 | OcaUint16 MaxPinsPerConnector
03p06 | OcaUint16 MaxPortsPerPin
03p07 | OcaDBFS AlignmentLevel
03p08 | OcaDB AlignementGain
| |
03e01 | SourceConnectorChanged -> OcaMediaSourceConnectorChangedEventData
03e02 | SinkConnectorChanged -> OcaMediaSinkConnectorChangedEventData
03e03 | ConnectorStatusChanged -> OcaMediaConnectorStatusChangedEventData
