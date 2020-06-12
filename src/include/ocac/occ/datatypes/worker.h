//
// Created by Philip Tschiemer on 12.06.20.
//

#ifndef OCAC_OCC_DATATYPES_WORKER_H
#define OCAC_OCC_DATATYPES_WORKER_H

#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef OcaFloat32 OcaDB;
typedef OcaDB OcaDBV;
typedef OcaDB OcaDBu;
typedef OcaDB OcaDBFS;
typedef OcaDB OcaDBz;

typedef struct {
    OcaDBz Ref;
    OcaDB Value;
} OcaDBr;

typedef enum {
    OcaMuteState_Muted   = 1;
    OcaMuteState_Unmuted = 2;
} OcaMuteState;

typedef enum {
    OcaPolarityState_NonInverted = 1,
    OcaPolarityState_Inverted    = 2
} OcaPolarityState;

typedef enum {
    OcaDelayUnit_Time            = 1,
    OcaDelayUnit_Distance        = 2,
    OcaDelayUnit_Samples         = 3,
    OcaDelayUnit_Microseconds    = 4,
    OcaDelayUnit_Milliseconds    = 5,
    OcaDelayUnit_Centimeters     = 6,
    OcaDelayUnit_Inches          = 7,
    OcaDelayUnit_Feet            = 8
} OcaDelayUnit;

typedef struct {
    OcaDelayUnit DelayUnit;
    OcaFloat32 DelayValue;
} OcaDelayValue;

typedef OcaFloat32 OcaFrequency;

// TODO OcaFrequencyResponse (depends on OcaMap)

// TODO OcaTransferFunction (depends on OcaList)

typedef OcaUint64 OcaTimeOfDay;
typedef OcaFloat32 OcaTimeInterval;
typedef OcaUint32 OcaPeriod;

typedef enum {
    OcaClassicalFilterShape_Butterworth      = 1,
    OcaClassicalFilterShape_Bessel           = 2,
    OcaClassicalFilterShape_Chebyshev        = 3,
    OcaClassicalFilterShape_LinkwitzRiley    = 4
} OcaClassicalFilterShape;

typedef enum {
    OcaFilterPassBand_HiPass     = 1,
    OcaFilterPassBand_LowPass    = 2,
    OcaFilterPassBand_BandPass   = 3,
    OcaFilterPassBand_BandReject = 4,
    OcaFilterPassBand_AllPass    = 5
} OcaFilterPassBand;

typedef enum {
    OcaParametricEQShape_PEQ                     = 1,
    OcaParametricEQShape_LowShelv                = 2,
    OcaParametricEQShape_HighShelv               = 3,
    OcaParametricEQShape_LowPass                 = 4,
    OcaParametricEQShape_HighPass                = 5,
    OcaParametricEQShape_BandPass                = 6,
    OcaParametricEQShape_AllPass                 = 7,
    OcaParametricEQShape_Notch                   = 8,
    OcaParametricEQShape_ToneControlLowFixed     = 9,
    OcaParametricEQShape_ToneControlLowSliding   = 10,
    OcaParametricEQShape_ToneControlHighFixed    = 11,
    OcaParametricEQShape_ToneControlHighSliding  = 12
} OcaParametricEQShape;

typedef enum {
    OcaDynamicsFunction_None     = 0,
    OcaDynamicsFunction_Compress = 1,
    OcaDynamicsFunction_Limit    = 2,
    OcaDynamicsFunction_Expand   = 3,
    OcaDynamicsFunction_Gate     = 4,
    OcaDynamicsFunction_AGC      = 5
} OcaDynamicsFunction;

typedef struct {
    OcaFrequency Frequency;
    OcaPeriod PollInterval;
    OcaDBr Threshold;
} OcaPilotToneDetectorSpec;

typedef enum {
    OcaWaveformType_None         = 0,
    OcaWaveformType_DC           = 1,
    OcaWaveformType_Sine         = 2,
    OcaWaveformType_Square       = 3,
    OcaWaveformType_Impulse      = 4,
    OcaWaveformType_NoisePink    = 5,
    OcaWaveformType_NoiseWhite   = 6,
    OcaWaveformType_PolarityTest = 7
} OcaWaveformType;

typedef enum {
    OcaSweepType_None        = 0,
    OcaSweepType_Linear      = 1,
    OcaSweepType_Logarithmic = 2
} OcaSweepType;

typedef enum {
    OcaUnitOfMeasure_None            = 0,
    OcaUnitOfMeasure_Hertz           = 1,
    OcaUnitOfMeasure_DegreeCelsius   = 2,
    OcaUnitOfMeasure_Volt            = 3,
    OcaUnitOfMeasure_Ampere          = 4,
    OcaUnitOfMeasure_Ohm             = 5
} OcaUnitOfMeasure;

typedef enum {
    OcaPresentationUnit_dBu  = 0,
    OcaPresentationUnit_dBV  = 1,
    OcaPresentationUnit_V    = 2
} OcaPresentationUnit;

typedef OcaFloat32 OcaTemperature;

typedef enum {
    OcaLevelDetectionLaw_None    = 0,
    OcaLevelDetectionLaw_RMS     = 1,
    OcaLevelDetectionLaw_Peak    = 2
} OcaLevelDetectionLaw;

typedef enum {
    OcaSensorReadingState_Unknown    = 0,
    OcaSensorReadingState_Valid      = 1,
    OcaSensorReadingState_Underrange = 2,
    OcaSensorReadingState_Overrange  = 3
    OcaSensorReadingState_Error      = 4
} OcaSensorReadingState;

typedef enum {
    OcaLevelMeterLaw_VU          = 1,
    OcaLevelMeterLaw_StandardVU  = 2,
    OcaLevelMeterLaw_PPM1        = 3,
    OcaLevelMeterLaw_PPM2        = 4,
    OcaLevelMeterLaw_LKFS        = 5,
    OcaLevelMeterLaw_RMS         = 6,
    OcaLevelMeterLaw_Peak        = 7
} OcaLevelMeterLaw;

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_DATATYPES_WORKER_H
