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

#define OCAC_CLASS_WORKER_02m01       {{2,1}, ocac_m_worker_getEnabled},
#define OCAC_CLASS_WORKER_02m02       {{2,2}, ocac_m_worker_setEnabled},
#define OCAC_CLASS_WORKER_02m03       {{2,3}, ocac_m_worker_addPort},
#define OCAC_CLASS_WORKER_02m04       {{2,4}, ocac_m_worker_deletePort},
#define OCAC_CLASS_WORKER_02m05       {{2,5}, ocac_m_worker_getPorts},
#define OCAC_CLASS_WORKER_02m06       {{2,6}, ocac_m_worker_getPortName},
#define OCAC_CLASS_WORKER_02m07       {{2,7}, ocac_m_worker_setPortName},
#define OCAC_CLASS_WORKER_02m08       {{2,8}, ocac_m_worker_getLabel},
#define OCAC_CLASS_WORKER_02m09       {{2,9}, ocac_m_worker_setLabel},
#define OCAC_CLASS_WORKER_02m10       {{2,10}, ocac_m_worker_getOwner},
#define OCAC_CLASS_WORKER_02m11       {{2,11}, ocac_m_worker_getLatency},
#define OCAC_CLASS_WORKER_02m12       {{2,12}, ocac_m_worker_setLatency},
#define OCAC_CLASS_WORKER_02m13       {{2,13}, ocac_m_worker_getPath},

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
/**
 * The next_sibling reference is used in combination with OcaBlock's first_child data member to allow for membership
 * handling.
 * This assumes only workers can be part of objects enumerated through the system's RootBlock
 */
#define OCAC_OBJ_WORKER_DEF_CUSTOM      OCAC_OBJ_BASE * next_sibling;


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
extern OCAC_CLASS_TYPE(OcaWorker) OCAC_CLASS_NAME(OcaWorker);

/** Object instance (will be allocated) */
// none


/** Class methods */
OCAC_CLASS_METHOD(ocac_m_worker_getEnabled);
OCAC_CLASS_METHOD(ocac_m_worker_setEnabled);
OCAC_CLASS_METHOD(ocac_m_worker_addPort);
OCAC_CLASS_METHOD(ocac_m_worker_deletePort);
OCAC_CLASS_METHOD(ocac_m_worker_getPorts);
OCAC_CLASS_METHOD(ocac_m_worker_getPortName);
OCAC_CLASS_METHOD(ocac_m_worker_setPortName);
OCAC_CLASS_METHOD(ocac_m_worker_getLabel);
OCAC_CLASS_METHOD(ocac_m_worker_setLabel);
OCAC_CLASS_METHOD(ocac_m_worker_getOwner);
OCAC_CLASS_METHOD(ocac_m_worker_getLatency);
OCAC_CLASS_METHOD(ocac_m_worker_setLatency);
OCAC_CLASS_METHOD(ocac_m_worker_getPath);

/** /CLASS/OBJECT DECLARATION **/

#ifdef DEBUG
void ocac_dump_worker(OCAC_OBJ_BASE * obj);
#endif

#ifdef __cplusplus
}
#endif
#endif //OCAC_IMPL_OCCCLASSES_WORKERS_ABSTRACT_H
