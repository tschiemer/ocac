# ocac
AES70/OCA device framework (for embedded devices) C99


**WORK IN PROGRESS**


AES70/Open Control Architecture (OCA) defines a standard for device control and connection management of
(networked) audio devices and is ment to allow for vendor independent control interfaces.

This framework aims to provide a skeleton of the class structure and implementations of core functionalities to be
integrated into devices.

The library core resides in directory `src` and likely will not require any modifications - although it can be configured
using a provided `ocacopts.h` file. The class structure (or skeleton) resides in directory `impl` and requires customization
to interface with a device's architecture; class data members can be made use of or, if preferred, just the class methods
that thus would act like protocol callbacks.

For every target platform some basic functionality must be implemented, also see interfaces in `src/include/ocac/host/`.

## Very short and simple intro to AES70

AES70 is an object-oriented protocol which means that it more or less works like a remote API or RPC framework
with a predefined basic class structure for common use cases but allows for custom derivations. More precisely speaking,
any command targets specific objects and specific functions thereof.

The predefined classes cover a wide range of necessary interfaces like security, network, firmware or power managers and possible
objects like actuators and sensors. Somewhat with networked audio devices in mind it entails interfaces for clock and
signal/stream management amongst others, structures suitable for DSP architectures (object matrices) and has many datatypes
relating to audio metrics.

As a major feature aside from a command interface it also provides an (optional) subscription mechanism for events, (typically)
*data change* events.

The currently specified protocol interfaces use either UDP (suggested for small, non-critical devices), TCP, secure TCP (TLS),
and websockets.

At this time the standard does not suggest any means of service description or device categorization.

## Service Discovery

For discovery of AES70 devices common mDNS service discovery is used.

Protocol | Service name | Text record data
--- | --- | ---
TCP | `_oca._tcp` | `txtvers=1` [1] `protovers=V` [2]
Secure TCP (TLS) | `_ocasec._tcp` | `txtvers=1` `protovers=V`
UDP | `_oca._udp` | `txtvers=1` `protovers=V`
Websockets | `_ocaws._tcp` | `txtvers=1` `protovers=V`, optional: `path=XYZ` [3]

1. OCA service registration version
2. decimal AES70 version as specified in the device's `OcaDeviceManager` object
3. base path or websocket, if missing `/` is assumed

Also see header `src/include/ocac/mdns.h`.


## Connection Management (audio streams)

TODO


## Resources & Related
- [AES Standard Models](http://www.aes.org/standards/models/)
- [AES70-1-2018 (Part1: Framework (OCF))](http://www.aes.org/publications/standards/search.cfm?docID=101)
- [AES70-2-2018 (Part2: Class structure (OCC)](http://www.aes.org/publications/standards/search.cfm?docID=102)
- [AES70-3-2018 (Part3: Protocol for IP Networks (OCP1))](http://www.aes.org/publications/standards/search.cfm?docID=103)
- [OCA Alliance docs](https://ocaalliance.github.io/)
- [Official *Tools and Demos* CPP Implementation](https://github.com/OCAAlliance/OcaToolsAndDemos/)
- [More on github](https://github.com/topics/aes70)


In the future [ANEMAN](https://www.aneman.net/) - a free connection management tool - is ment to support AES70 and would seem promising.
