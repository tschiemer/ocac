//
// Created by Philip Tschiemer on 20.06.20.
//

#include "obj_registry.h"

#include "occclasses/managers/device.h"

#ifdef OCAC_MANAGER_SECURITY
#include "occclasses/managers/security.h"
#endif
#ifdef OCAC_MANAGER_FIRMWARE
#include "occclasses/managers/firmware.h"
#endif
#ifdef OCAC_MANAGER_SUBSCRIPTION
#include "occclasses/managers/subscription.h"
#endif
#ifdef OCAC_MANAGER_POWER
#include "occclasses/managers/power.h"
#endif
#ifdef OCAC_MANAGER_NETWORK
#include "occclasses/managers/network.h"
#endif
#ifdef OCAC_MANAGER_MEDIACLOCK
#include "occclasses/managers/mediaclock.h"
#endif
#ifdef OCAC_MANAGER_LIBRARY
#include "occclasses/managers/library.h"
#endif
#ifdef OCAC_MANAGER_AUDIOPROCESSING
#include "occclasses/managers/audioprocessing.h"
#endif
#ifdef OCAC_MANAGER_DEVICETIME
#include "occclasses/managers/devicetime.h"
#endif
#ifdef OCAC_MANAGER_TASK
#include "occclasses/managers/task.h"
#endif
#ifdef OCAC_MANAGER_CODING
#include "occclasses/managers/coding.h"
#endif
#ifdef OCAC_MANAGER_DIAGNOSTIC
#include "occclasses/managers/diagnostic.h"
#endif

OCAC_OBJ_BASE * ocac_managers[OCAC_MANAGER_COUNT] = {
    (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaDeviceManager),

    #ifdef OCAC_MANAGER_SECURITY
    (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaSecurityManager),
    #endif

    #ifdef OCAC_MANAGER_FIRMWARE
    (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaFirmwareManager),
    #endif

    #ifdef OCAC_MANAGER_SUBSCRIPTION
    (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaSubscriptionManager),
    #endif

    #ifdef OCAC_MANAGER_POWER
    (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaPowerManager),
    #endif

    #ifdef OCAC_MANAGER_NETWORK
    (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaNetworkManager),
    #endif

    #ifdef OCAC_MANAGER_MEDIACLOCK
    (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaMediaClockManager),
    #endif

    #ifdef OCAC_MANAGER_LIBRARY
    (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaLibraryManager),
    #endif

    #ifdef OCAC_MANAGER_AUDIOPROCESSING
    (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaAudioProcessingManager),
    #endif

    #ifdef OCAC_MANAGER_DEVICETIME
    (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaDeviceTimeManager),
    #endif

    #ifdef OCAC_MANAGER_TASK
    (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaTaskManager),
    #endif

    #ifdef OCAC_MANAGER_CODING
    (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaCodingManager),
    #endif

    #ifdef OCAC_MANAGER_DIAGNOSTIC
    (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaDiagnosticManager),
    #endif
};


OCAC_OBJ_BASE * ocac_obj_registry_get_by_id(OcaONo ono)
{
    if (ono < OCAC_RESERVED_ONOS){

        switch(ono){

            case OCAC_OBJ_DEVICEMANAGER_ONO:
                return (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaDeviceManager);

            #ifdef OCAC_MANAGER_SECURITY
            case OCAC_OBJ_SECURITYMANAGER_ONO:
                return (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaSecurityManager);
            #endif

            #ifdef OCAC_MANAGER_FIRMWARE
            case OCAC_OBJ_FIRMWAREMANAGER_ONO:
                return (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaFirmwareManager);
            #endif

            #ifdef OCAC_MANAGER_SUBSCRIPTION
            case OCAC_OBJ_SUBSCRIPTIONMANAGER_ONO:
                return (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaSubscriptionManager);
            #endif

            #ifdef OCAC_MANAGER_POWER
            case OCAC_OBJ_POWERMANAGER_ONO:
                return (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaPowerManager);
            #endif

            #ifdef OCAC_MANAGER_NETWORK
            case OCAC_OBJ_NETWORKMANAGER_ONO:
                return (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaNetworkManager);
            #endif

            #ifdef OCAC_MANAGER_MEDIACLOCK
            case OCAC_OBJ_MEDIACLOCKMANAGER_ONO:
                return (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaMediaClockManager);
            #endif

            #ifdef OCAC_MANAGER_LIBRARY
            case OCAC_OBJ_LIBRARYMANAGER_ONO:
                return (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaLibraryManager);
            #endif

            #ifdef OCAC_MANAGER_AUDIOPROCESSING
            case OCAC_OBJ_AUDIOPROCESSINGMANAGER_ONO:
                return (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaAudioProcessingManager);
            #endif

            #ifdef OCAC_MANAGER_DEVICETIME
            case OCAC_OBJ_DEVICETIMEMANAGER_ONO:
                return (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaDeviceTimeManager);
            #endif

            #ifdef OCAC_MANAGER_TASK
            case OCAC_OBJ_TASKMANAGER_ONO:
                return (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaTaskManager);
            #endif

            #ifdef OCAC_MANAGER_CODING
            case OCAC_OBJ_CODINGMANAGER_ONO:
                return (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaCodingManager);
            #endif

            #ifdef OCAC_MANAGER_DIAGNOSTIC
            case OCAC_OBJ_DIAGNOSTICMANAGER_ONO:
                return (OCAC_OBJ_BASE*) &OCAC_OBJ_NAME(OcaDiagnosticManager);
            #endif

//            case OCAC_OBJ_ROOTBLOCK_ONO:
//                return (OCAC_OBJ_BASE*) *OCAC_OBJ_NAME(OcaRootBlock)

            default:
                return NULL;
        }
    }

    return NULL;
}