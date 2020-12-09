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
