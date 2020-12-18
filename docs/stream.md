# Media/Streams: Connection Management v3 (CM3)

A device supporting media streaming (ie implementing an `OcaMediaTransportNetwork`) must implement the following managers (a.s. figure 1):

1. OcaNetworkManager (required anyways)
2. OcaMediaClockManager
3. OcaSubscriptionManager

In particular there must be at least lightweight subscriptions (see `subscriptions.md`) supported by the device for the respective required events of `OcaMediaTransportNetwork` (see `occ_classes.md`).

| ![Required managers](stream_managers.png "Required managers") |
|:--:|
| Fig 1. Required managers |

See figures 2 - 4 for the core datatypes and classes used to describe and change stream parameters.

| ![OcaMediaTransportNetwork](stream_mediatransportnetwork.png "OcaMediaTransportNetwork") |
|:--:|
| Fig 2. `OcaMediaTransportNetwork` |

| ![Support datatypes](stream_support.png "Support datatypes") |
|:--:|
| Fig 3. Support datatypes (non-exhaustive) |

| ![Notifications](stream_notifications.png "Notifications") |
|:--:|
| Fig 4. Notifications |
