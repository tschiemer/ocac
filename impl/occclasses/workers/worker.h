//
// Created by Philip Tschiemer on 19.06.20.
//

#ifndef OCAC_IMPL_OCCCLASSES_WORKERS_ABSTRACT_H
#define OCAC_IMPL_OCCCLASSES_WORKERS_ABSTRACT_H

#include "occclasses/root.h"
#include "ocac/occ/datatypes/time.h"
#include "ocac/occ/datatypes/worker.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * CONSTANTS
 * Don't change!
 */


#define OCAC_CLASS_WORKER_ID          {2, {1,1}}
#define OCAC_CLASS_WORKER_VERSION     2

#define OCAC__Worker_DefLevel  2

#define OCAC__Worker_m_getEnabled  1
#define OCAC__Worker_m_setEnabled  2
#define OCAC__Worker_m_addPort     3
#define OCAC__Worker_m_deletePort  4
#define OCAC__Worker_m_getPorts    5
#define OCAC__Worker_m_getPortName 6
#define OCAC__Worker_m_setPortName 7
#define OCAC__Worker_m_getLabel    8
#define OCAC__Worker_m_setLabel    9
#define OCAC__Worker_m_getOwner    10
#define OCAC__Worker_m_getLatency  11
#define OCAC__Worker_m_setLatency  12
#define OCAC__Worker_m_getPath     13

#define OCAC__Worker_p_enabled     1
#define OCAC__Worker_p_ports       2
#define OCAC__Worker_p_label       3
#define OCAC__Worker_p_owner       4
#define OCAC__Worker_p_latency     5

/**
 * CONFIGURATION
 * Edit here if wanted.
 *
 * To enable/disable a method/property/event define/undefine given method/property/event AND set the number of
 * methods/properties/events accordingly
 */

#define OCAC_CLASS_WORKER_NMETHODS     13
#define OCAC_CLASS_WORKER_NPROPERTIES  5
#define OCAC_CLASS_WORKER_NEVENTS      0

#define OCAC_CLASS_WORKER_02m01       {{3,1}, ocac_m_devicemanager_getEnabled},
#define OCAC_CLASS_WORKER_02m02       {{3,2}, ocac_m_devicemanager_setEnabled},
#define OCAC_CLASS_WORKER_02m03       {{3,3}, ocac_m_devicemanager_addPort},
#define OCAC_CLASS_WORKER_02m04       {{3,4}, ocac_m_devicemanager_deletePort},
#define OCAC_CLASS_WORKER_02m05       {{3,5}, ocac_m_devicemanager_getPorts},
#define OCAC_CLASS_WORKER_02m06       {{3,6}, ocac_m_devicemanager_getPortName},
#define OCAC_CLASS_WORKER_02m07       {{3,7}, ocac_m_devicemanager_setPortName},
#define OCAC_CLASS_WORKER_02m08       {{3,8}, ocac_m_devicemanager_getLabel},
#define OCAC_CLASS_WORKER_02m09       {{3,9}, ocac_m_devicemanager_setLabel},
#define OCAC_CLASS_WORKER_02m10       {{3,10}, ocac_m_devicemanager_getOwner},
#define OCAC_CLASS_WORKER_02m11       {{3,11}, ocac_m_devicemanager_getLatency},
#define OCAC_CLASS_WORKER_02m12       {{3,12}, ocac_m_devicemanager_setLatency},
#define OCAC_CLASS_WORKER_02m13       {{3,13}, ocac_m_devicemanager_getPath},

#define OCAC_CLASS_WORKER_02p01
#define OCAC_CLASS_WORKER_02p02
#define OCAC_CLASS_WORKER_02p03
#define OCAC_CLASS_WORKER_02p04
#define OCAC_CLASS_WORKER_02p05

#ifdef OCAC_OVERRIDEABLE_METHODS
#define OCAC_CLASS_WORKER_01m01       {{1,1}, ocac_m_root_getClassIdentification},
#define OCAC_CLASS_WORKER_01m02       {{1,2}, ocac_m_root_getLockable},
#define OCAC_CLASS_WORKER_01m03       {{1,3}, ocac_m_root_lock},
#define OCAC_CLASS_WORKER_01m04       {{1,4}, ocac_m_root_unlock},
#define OCAC_CLASS_WORKER_01m05       {{1,5}, ocac_m_root_getRole},
#define OCAC_CLASS_WORKER_01m06       {{1,5}, ocac_m_root_lockReadonly},
#endif

#define OCAC_OBJ_WORKER_DEF_ENABLED     OcaBoolean enabled;
//TODO
#define OCAC_OBJ_WORKER_DEF_PORTS       // TODO
#define OCAC_OBJ_WORKER_DEF_LABEL       OCAC_STRING(OCAC_OBJ_WORKER_DEF_LABEL_LEN) label;
#define OCAC_OBJ_WORKER_DEF_OWNER       OcaONo owner;
#define OCAC_OBJ_WORKER_DEF_LATENCY     OcaTimeInterval latency;

// Add your own definitions if desired
#define OCAC_OBJ_WORKER_DEF_CUSTOM



/** /CONFIGURATION **/


/**
 * AUTO CONFIG
 * You should not need to change anything.
 */

#ifndef OCAC_CLASS_WORKER_02m01
#define OCAC_CLASS_WORKER_02m01
#endif
#ifndef OCAC_CLASS_WORKER_02m02
#define OCAC_CLASS_WORKER_02m02
#endif
#ifndef OCAC_CLASS_WORKER_02m03
#define OCAC_CLASS_WORKER_02m03
#endif
#ifndef OCAC_CLASS_WORKER_02m04
#define OCAC_CLASS_WORKER_02m04
#endif
#ifndef OCAC_CLASS_WORKER_02m05
#define OCAC_CLASS_WORKER_02m05
#endif
#ifndef OCAC_CLASS_WORKER_02m06
#define OCAC_CLASS_WORKER_02m06
#endif
#ifndef OCAC_CLASS_WORKER_02m07
#define OCAC_CLASS_WORKER_02m07
#endif
#ifndef OCAC_CLASS_WORKER_02m08
#define OCAC_CLASS_WORKER_02m08
#endif
#ifndef OCAC_CLASS_WORKER_02m09
#define OCAC_CLASS_WORKER_02m09
#endif
#ifndef OCAC_CLASS_WORKER_02m10
#define OCAC_CLASS_WORKER_02m10
#endif
#ifndef OCAC_CLASS_WORKER_02m11
#define OCAC_CLASS_WORKER_02m11
#endif
#ifndef OCAC_CLASS_WORKER_02m12
#define OCAC_CLASS_WORKER_02m12
#endif
#ifndef OCAC_CLASS_WORKER_02m13
#define OCAC_CLASS_WORKER_02m13
#endif

#define OCAC_CLASS_WORKER_02mXX \
    OCAC_CLASS_WORKER_02m01 \
    OCAC_CLASS_WORKER_02m02 \
    OCAC_CLASS_WORKER_02m03 \
    OCAC_CLASS_WORKER_02m04 \
    OCAC_CLASS_WORKER_02m05 \
    OCAC_CLASS_WORKER_02m06 \
    OCAC_CLASS_WORKER_02m07 \
    OCAC_CLASS_WORKER_02m08 \
    OCAC_CLASS_WORKER_02m09 \
    OCAC_CLASS_WORKER_02m10 \
    OCAC_CLASS_WORKER_02m11 \
    OCAC_CLASS_WORKER_02m12 \
    OCAC_CLASS_WORKER_02m13


#ifdef OCAC_OVERRIDEABLE_METHODS


#define OCAC_CLASS_WORKER_XXmXX \
    OCAC_CLASS_WORKER_01m01 \
    OCAC_CLASS_WORKER_01m02 \
    OCAC_CLASS_WORKER_01m03 \
    OCAC_CLASS_WORKER_01m04 \
    OCAC_CLASS_WORKER_02mXX

#define OCAC_CLASS_WORKER_NMETHODS_TOTAL (OCAC_CLASS_WORKER_NMETHODS + OCAC_CLASS_ROOT_NMETHODS_TOTAL)

#else

#define OCAC_CLASS_WORKER_XXmXX \
    OCAC_CLASS_WORKER_02mXX

#define OCAC_CLASS_WORKER_NMETHODS_TOTAL OCAC_CLASS_WORKER_NMETHODS

#endif //OCAC_OVERRIDEABLE_METHODS



#ifndef OCAC_CLASS_WORKER_02p01
#define OCAC_CLASS_WORKER_02p01
#endif
#ifndef OCAC_CLASS_WORKER_02p02
#define OCAC_CLASS_WORKER_02p02
#endif
#ifndef OCAC_CLASS_WORKER_02p03
#define OCAC_CLASS_WORKER_02p03
#endif
#ifndef OCAC_CLASS_WORKER_02p04
#define OCAC_CLASS_WORKER_02p04
#endif
#ifndef OCAC_CLASS_WORKER_02p05
#define OCAC_CLASS_WORKER_02p05
#endif

#define OCAC_CLASS_WORKER_02pXX \
    OCAC_CLASS_WORKER_02p01 \
    OCAC_CLASS_WORKER_02p02 \
    OCAC_CLASS_WORKER_02p03 \
    OCAC_CLASS_WORKER_02p04 \
    OCAC_CLASS_WORKER_02p05

//#define OCAC_CLASS_WORKER_NPROPERTIES_TOTAL (OCAC_CLASS_WORKER_NPROPERTIES + OCAC_CLASS_ROOT_NPROPERTIES_TOTAL)
#define OCAC_CLASS_WORKER_NPROPERTIES_TOTAL OCAC_CLASS_WORKER_NPROPERTIES


#define OCAC_CLASS_WORKER_02eXX

#define OCAC_CLASS_WORKER_NEVENTS_TOTAL OCAC_CLASS_WORKER_NEVENTS


#ifndef OCAC_OBJ_WORKER_DEF_ENABLED
#define OCAC_OBJ_WORKER_DEF_ENABLED
#else
#define OCAC_OBJ_WORKER_DEF_ENABLED_USE
#endif
#ifndef OCAC_OBJ_WORKER_DEF_PORTS
#define OCAC_OBJ_WORKER_DEF_PORTS
#else
#define OCAC_OBJ_WORKER_DEF_PORTS_USE
#endif
#ifndef OCAC_OBJ_WORKER_DEF_LABEL
#define OCAC_OBJ_WORKER_DEF_LABEL
#else
#define OCAC_OBJ_WORKER_DEF_LABEL_USE
#endif
#ifndef OCAC_OBJ_WORKER_DEF_OWNER
#define OCAC_OBJ_WORKER_DEF_OWNER
#else
#define OCAC_OBJ_WORKER_DEF_OWNER_USE
#endif
#ifndef OCAC_OBJ_WORKER_DEF_LATENCY
#define OCAC_OBJ_WORKER_DEF_LATENCY
#else
#define OCAC_OBJ_WORKER_DEF_LATENCY_USE
#endif
#ifndef OCAC_OBJ_WORKER_DEF_CUSTOM
#define OCAC_OBJ_WORKER_DEF_CUSTOM
#endif

#define OCAC_OBJ_WORKER_DEF \
    OCAC_OBJ_WORKER_DEF_ENABLED \
    OCAC_OBJ_WORKER_DEF_PORTS \
    OCAC_OBJ_WORKER_DEF_LABEL \
    OCAC_OBJ_WORKER_DEF_OWNER \
    OCAC_OBJ_WORKER_DEF_LATENCY \
    OCAC_OBJ_WORKER_DEF_CUSTOM


/** /AUTO CONFIG **/


/**
 * CLASS/OBJECT DECLARATION
 * You should not need to edit anything.
 */


/** Class type */
OCAC_CLASS_DEF_BEGIN(OcaWorker)
    OCAC_CLASS_DEF_DATA(OCAC_CLASS_WORKER_NMETHODS_TOTAL, OCAC_CLASS_WORKER_NPROPERTIES_TOTAL, OCAC_CLASS_WORKER_NEVENTS_TOTAL)
OCAC_CLASS_DEF_END(OcaWorker)


/** Object type */
OCAC_OBJ_DEF_BEGIN(OcaWorker)
    OCAC_OBJ_ROOT_DEF
    OCAC_OBJ_WORKER_DEF
OCAC_OBJ_DEF_END(OcaWorker)


/** Class object (will be allocated) */
OCAC_CLASS_TYPE(OcaWorker) OCAC_CLASS_NAME(OcaWorker);

/** Object instance (will be allocated) */
OCAC_OBJ_TYPE(OcaWorker) OCAC_OBJ_NAME(OcaWorker);


/** Class methods */
OcaStatus ocac_m_devicemanager_getEnabled(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_setEnabled(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_addPort(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_deletePort(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getPorts(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getPortName(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_setPortName(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getLabel(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_setLabel(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getOwner(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getLatency(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_setLatency(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);
OcaStatus ocac_m_devicemanager_getPath(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref);

/** /CLASS/OBJECT DECLARATION **/

#ifdef DEBUG
void ocac_dump_worker(OCAC_OBJ_BASE * obj);
#endif

#ifdef __cplusplus
}
#endif
#endif //OCAC_IMPL_OCCCLASSES_WORKERS_ABSTRACT_H
