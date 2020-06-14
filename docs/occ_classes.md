# OCC Classes

Human readable form of AES70-2 Appendix A *(extract)*.

Required functionality according to AES70-2 Appendix B.

## Overview

ID | Class | ONo [1] | Required
:--- | :--- | ---: | :---:
1 | OcaRoot | | (YES)
| |
1 1 | OcaWorker | | (YES)
1 1 1 | OcaActuator
1 1 1 XY | ...
| |
1 1 2 | OcaSensor
1 1 2 XY | ...
| |
1 1 3 | OcaBlock | 100 [2] | YES
1 1 4 | OcaBlockFactory
1 1 5 | OcaMatrix
1 1 6 | OcaNetworkSignalChannel
| |
1 2 | OcaAgent  | | (YES [3,4])
1 2 1 | OcaNetwork *DEPRECATED*
1 2 2 | OcaGrouper
1 2 3 | OcaRamper
1 2 4 | OcaNumericObserver
1 2 5 | OcaLibrary
1 2 6 | OcaMediaClock |  | YES [4]
1 2 7 | OcaPowerSupply
1 2 8 | OcaEventHandler
1 2 9 | OcaNumericObserverList
1 2 10 | OcaStreamNetwork | | YES [3]
1 2 11 | OcaStreamConnector | | YES [3]
| |
1 3 | OcaManager | | (YES)
1 3 1 | OcaDeviceManager | 1 | YES
1 3 2 | OcaSecurityManager | 2 | YES [3]
1 3 3 | OcaFirmwareManager | 3 | YES
1 3 4 | OcaSubscriptionManager | 4 | YES
1 3 5 | OcaPowerManager | 5
1 3 6 | OcaNetworkManager | 6 | YES
1 3 7 | OcaMediaClockManager | 7 | YES [4]
1 3 8 | OcaLibraryManager | 8
1 3 9 | OcaAudioProcessingManager | 9
1 3 10 | OcaDeviceTimeManager | 10

1. iff singleton (manager) or object root
2. Object root is an instance of OcaBlock
3. For secured devices
4. For streaming devices

## OcaRoot
ID 1

ID | Declaration | Required
--- | --- | :---:
01m01 | GetClassIdentification() -> OcaClassIdentification
01m02 | GetLockable() -> OcaBoolean | YES
01m03 | Lock() | YES
01m04 | Unlock() | YES
01m05 | GetRole() -> OcaString
| |
01p01 | OcaClassID ClassID
01p02 | OcaClassVersionNumber ClassVersion
01p03 | OcaONo ObjectNumber
01p04 | OcaBoolean Lockable
01p05 | OcaString Role
| |
01e01 | PropertyChanged(OcaPropertyChangedEventData)


## OcaWorker
ID 1 1

ID | Declaration | Required
--- | --- | :---:
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
| |
02p01 | OcaBoolean Enabled
02p02 | OcaList<OcaPort> Ports
02p03 | OcaString Label
02p04 | OcaONo Owner
02p05 | OcaTimeInterval Latency

### OcaActuator
ID 1 1 1

### OcaSensor
ID 1 1 2

### OcaBlock
ID 1 1 3

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
| |
03p01 | OcaONo Type [1]
03p02 | OcaList<OcaObjectIdentification> Members
03p03 | OcaMap<OcaUin16, OcaSignalPath> SignalPaths
03p04 | OcaLibVolIdentifier MostRecentParamSetIdentifier

1. For root block the value is 1. For dynamically-defined blocks this is the factory ONo. For statically-defined blocks
this value "correspond to the unique configuration of this block".

### OcaBlockFactory
ID 1 1 4

### OcaMatrix
ID 1 1 5

### OcaNetworkSignalChannel
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
ID 1 2

ID | Declaration | Required
--- | --- | ---
02m01 | GetLabel() -> OcaString
02m02 | SetLabel(OcaString)
02m03 | GetOwner() -> OcaONo
| |
02p01 | OcaString Label
02p02 | OcaONo Owner


### OcaNetwork *DEPRECATED*
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
03p03 | OcaNetworkControlProtocol ControlProtocol
03p02 | OcaNetworkNodeID IDAdvertised
03p01 | OcaNetworkLinkType LinkType
03p07 | OcaList<OcaONo> MediaPorts
03p04 | OcaNetworkMediaProtocol MediaProtocol
03p08 | OcaNetworkStatistics Statistics
03p05 | OcaNetworkStatus Status
03p06 | OcaList<OcaNetworkSystemInterface>

1. If the OcaNetwork is implemented, all methods (and events) MUST be implemented.

### OcaGrouper
ID 1 2 2

### OcaRamper
ID 1 2 3

### OcaNumericObserver
ID 1 2 4

### OcaLibrary
ID 1 2 5

### OcaMediaClock
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
ID 1 2 7

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
ID 1 2 8

### OcaNumericObserverList
ID 1 2 9

### OcaStreamNetwork
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


## OcaManager
ID 1 3

No new methods, properties or events.

### OcaDeviceManager
ID 1 3 1, ONo 1

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
| |
03p01 | OcaModelGUID ModelGUID
03p01 | OcaString SerialNumber
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

1. It is somewhat unclear why the role was redefined? see 01p05


### OcaSecurityManager
ID 1 3 2, ONo 2

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
ID 1 3 3, ONo 3

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
ID 1 3 4, ONo 4

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
ID 1 3 5, ONo 5

**NOTE** GetActivePowerSupplies() and ExchangePowerSupply(..) both have the ID 03m04 (obviously a mistake)

ID | Declaration | Required
--- | --- | ---
03m01 | GetState() -> OcaPowerState
03m02 | SetState(OcaPowerState)
03m03 | GetPowerSupplies() -> OcaList<OcaONo>
03m0? | GetActivePowerSupplies() -> OcaList<OcaONo>
03m0? | ExchangePowerSupply(OcaONo oldPsu, OcaONo newPsu, OcaBoolean powerOffOld)
03m05 | GetAutoState() -> OcaBoolean
| |
03p01 | OcaPowerState State
03p02 | OcaList<OcaONo> PowerSupplies
03p03 | OcaList<OcaONo> ActivePowerSupplies
03p04 | OcaBoolean AutoState
03p05 | OcaPowerStateTargetState



### OcaNetworkManager
ID 1 3 6, ONo 6

ID | Declaration | Required
--- | --- | ---
03m01 | GetNetworks() -> OcaList<OcaONo> | YES
03m02 | GetStreamNetworks() -> OcaList<OcaONo> | YES
| |
03p01 | Networks
03p02 | StreamNetworks


### OcaMediaClockManager
ID 1 3 7, ONo 7

ID | Declaration | Required
--- | --- | ---
03m01 | GetClocks() -> OcaList<OcaONo> | YES [1]
03m02 | GetMediaClockTypesSupported() -> OcaList<OcaMediaClockType> | YES [1]
| |
03p01 | OcaList<OcaMediaClockType> ClockSourceTypesSupported
03p02 | OcaList<OcaONo>

1. If class is implemented, all methods MUST be supported (well, makes sense).

### OcaLibraryManager
ID 1 3 8, ONo 8

ID | Declaration | Required
--- | --- | ---
03m01 | AddLibrary(OcaLibraryType) -> OcaONo
03m02 | DeleteLibrary(OcaONo)
03m03 | GetLibraryCount(OcaLibraryType) -> OcaUint16
03m04 | GetLibraryList(OcaLibraryType) -> OcaList<OcaONo>
03m05 | GetCurrentPatch() -> OcaLibVolIdentifier
03m06 | SetCurrentPatch(OcaLibVolIdentifier)


### OcaAudioProcessingManager
ID 1 3 9, ONo 9

No definitions


### OcaDeviceTimeManager
ID 1 3 10, ONo 10

ID | Declaration | Required
--- | --- | ---
03m01 | GetDeviceTime() -> OcaTimeOfDay
03m02 | SetDeviceTime(OcaTimeOfDay)
