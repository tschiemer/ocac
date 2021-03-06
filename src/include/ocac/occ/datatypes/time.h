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

#ifndef OCAC_OCC_DATATYPES_TIME_H
#define OCAC_OCC_DATATYPES_TIME_H

#include "ocac/occ/datatypes/framework.h"
#include "ocac/occ/datatypes/worker.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    OcaMediaClockAvailability_Unavailable   = 0,
    OcaMediaClockAvailability_Available     = 1
} PACK_STRUCT_STRUCT OcaMediaClockAvailability;

typedef struct {
    OcaFrequency NominalRate;
    OcaFrequency PullRange;
    OcaFloat32 Accuracy;
    OcaFloat32 JitterMax;
} PACK_STRUCT_STRUCT OcaMediaClockRate;

typedef enum {
    OcaTimeReferenceType_Undefined  = 0,
    OcaTimeReferenceType_Local      = 1,
    OcaTimeReferenceType_Private    = 2,
    OcaTimeReferenceType_GPS        = 3,
    OcaTimeReferenceType_Galileo    = 4,
    OcaTimeReferenceType_GLONASS    = 5
} PACK_STRUCT_STRUCT OcaTimeReferenceType;

typedef enum {
    OcaTimeProtocol_Undefined       = 0,
    OcaTimeProtocol_None            = 1,
    OcaTimeProtocol_Private         = 2,
    OcaTimeProtocol_NTP             = 3,
    OcaTimeProtocol_SNTP            = 4,
    OcaTimeProtocol_IEEE1588_2002   = 5,
    OcaTimeProtocol_IEEE1588_2008   = 6,
    OcaTimeProtocol_IEEE_AVB        = 7,
    OcaTimeProtocol_AES11           = 8,
    OcaTimeProtocol_Genlock         = 9,
//    OcaTimeProtocol_IEEE1588_2019   = 10 ???
} PACK_STRUCT_STRUCT OcaTimeProtocol;

typedef enum {
    OcaTimeSourceAvailability_Unavailable   = 0,
    OcaTimeSourceAvailability_Available     = 1
} PACK_STRUCT_STRUCT OcaTimeSourceAvailability;

typedef enum {
    OcaTimeMode_Absolute    = 1,
    OcaTimeMode_Relative    = 2
} PACK_STRUCT_STRUCT OcaTimeMode;

typedef enum {
    OcaTimeSourceSyncStatus_Undefined       = 0,
    OcaTimeSourceSyncStatus_Unsynchronized  = 1,
    OcaTimeSourceSyncStatus_Synchronizing   = 2,
    OcaTimeSourceSyncStatus_Synchronized    = 3
} PACK_STRUCT_STRUCT OcaTimeSourceSyncStatus;

typedef enum {
    OcaTimeUnits_Seconds    = 1,
    OcaTimeUnits_Samples    = 2
} PACK_STRUCT_STRUCT OcaTimeUnits;

typedef OcaUint64 OcaTimePTPSeconds;

typedef struct {
    OcaBoolean Negative;
    OcaTimePTPSeconds Seconds;
    OcaUint32 Nanoseconds;
} PACK_STRUCT_STRUCT OcaTimePTP;

typedef OcaFloat32 OcaTimeInterval; // in seconds

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_TIME_H
