//
// Created by Philip Tschiemer on 15.06.20.
//

#ifndef OCAC_OCC_DATATYPES_TASK_H
#define OCAC_OCC_DATATYPES_TASK_H

#include "ocac/occ/datatypes/framework.h"
#include "ocac/occ/datatypes/library.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef OcaUint32 OcaTaskID;
typedef OcaUint16 OcaTaskGroupID;

typedef enum {
    OcaTaskState_None           = 0,
    OcaTaskState_NotPrepared    = 1,
    OcaTaskState_Disabled       = 2,
    OcaTaskState_Enabled        = 3,
    OcaTaskState_Running        = 4,
    OcaTaskState_Completed      = 5,
    OcaTaskState_Failed         = 6,
    OcaTaskState_Stopped        = 7,
    OcaTaskState_Aborted        = 8
} PACK_STRUCT_STRUCT OcaTaskState;

typedef struct {
    OcaTaskID ID;
    OcaTaskState State;
    OcaUint16 ErrorCode;
} PACK_STRUCT_STRUCT OcaTaskStatus;

/**
 * For reference only
 */
typedef struct {
    OcaTaskID ID;
    OCAC_STRING(0) Label;
    OcaLibVolIdentifier OcaProgramID;
    OcaTaskGroupID GroupID;
    OcaTimeMode TimeMode;
    //TODO TimeUnits;
    OcaONo ClockONo;
    //TODO StartTime;timeunits
    OcaTimeInterval Duration;
    OcaBlob ApplicationSpecificParameters;
} PACK_STRUCT_STRUCT OcaTask;

typedef enum {
    OcaTaskCommand_None     = 0,
    OcaTaskCommand_Prepare  = 1,
    OcaTaskCommand_Enable   = 2,
    OcaTaskCommand_Start    = 3,
    OcaTaskCommand_Stop     = 4,
    OcaTaskCommand_Abort    = 5,
    OcaTaskCommand_Disable  = 6,
    OcaTaskCommand_Clear    = 7
} PACK_STRUCT_STRUCT OcaTaskCommand;

typedef enum {
    OcaTaskManagerState_None        = 0,
    OcaTaskManagerState_Enabled     = 1,
    OcaTaskManagerState_Disabled    = 2
} PACK_STRUCT_STRUCT OcaTaskManagerState;

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_TASK_H
