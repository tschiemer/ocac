//
// Created by Philip Tschiemer on 30.11.20.
//

#ifndef OCAC_IMPL_OCCCLASSES_WORKERS_BLOCK_H
#define OCAC_IMPL_OCCCLASSES_WORKERS_BLOCK_H

#include "occclasses/workers/worker.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * CONSTANTS
 * Don't change!
 */


#define OCAC_CLASS_BLOCK_ID          {3, {1,1,1}}
#define OCAC_CLASS_BLOCK_VERSION     2


#define OCAC_OBJ_ROOTBLOCK_ONO          100

// Specific type property value of root block
#define OCAC_OBJ_ROOTBLOCK_TYPE    1

#define OCAC__Block_DefLevel  3

#define OCAC__Block_m_getType                           1
#define OCAC__Block_m_constructMember                   2
#define OCAC__Block_m_constructMemberUsingFactory       3
#define OCAC__Block_m_deleteMember                      4
#define OCAC__Block_m_getMembers                        5
#define OCAC__Block_m_getMembersRecursive               6
#define OCAC__Block_m_addSignalPath                     7
#define OCAC__Block_m_deleteSignalPath                  8
#define OCAC__Block_m_getSignalPaths                    9
#define OCAC__Block_m_getSignalPathsRecursive           10
#define OCAC__Block_m_getMostRecentParamSetIdentifier   11
#define OCAC__Block_m_applyParamSet                     12
#define OCAC__Block_m_getCurrentParamSetData            13
#define OCAC__Block_m_storeCurrentParamSetData          14
#define OCAC__Block_m_getGlobalType                     15
#define OCAC__Block_m_getONoMap                         16
#define OCAC__Block_m_findObjectsByRole                 17
#define OCAC__Block_m_findObjectsByRoleRecursive        18
#define OCAC__Block_m_findObjectsByLabelRecursive       19
#define OCAC__Block_m_findObjectsByPath                 20

#define OCAC__Block_p_type                              1
#define OCAC__Block_p_members                           2
#define OCAC__Block_p_signalPaths                       3
#define OCAC__Block_p_mostRecentParamSetIdentifier      4
#define OCAC__Block_p_globalType                        5
#define OCAC__Block_p_oNoMap                            6

/**
 * CONFIGURATION
 * Edit here if wanted.
 *
 * To enable/disable a method/property/event define/undefine given method/property/event AND set the number of
 * methods/properties/events accordingly
 */

#define OCAC_CLASS_BLOCK_NMETHODS     20
#define OCAC_CLASS_BLOCK_NPROPERTIES  6
#define OCAC_CLASS_BLOCK_NEVENTS      0

#define OCAC_CLASS_BLOCK_03m01       {{3,1}, ocac_m_block_getType},
#define OCAC_CLASS_BLOCK_03m02       {{3,2}, ocac_m_block_constructMember},
#define OCAC_CLASS_BLOCK_03m03       {{3,3}, ocac_m_block_constructMemberUsingFactory},
#define OCAC_CLASS_BLOCK_03m04       {{3,4}, ocac_m_block_deleteMember},
#define OCAC_CLASS_BLOCK_03m05       {{3,5}, ocac_m_block_getMembers},
#define OCAC_CLASS_BLOCK_03m06       {{3,6}, ocac_m_block_getMembersRecursive},
#define OCAC_CLASS_BLOCK_03m07       {{3,7}, ocac_m_block_addSignalPath},
#define OCAC_CLASS_BLOCK_03m08       {{3,8}, ocac_m_block_deleteSignalPath},
#define OCAC_CLASS_BLOCK_03m09       {{3,9}, ocac_m_block_getSignalPaths},
#define OCAC_CLASS_BLOCK_03m10       {{3,10}, ocac_m_block_getSignalPathsRecursive},
#define OCAC_CLASS_BLOCK_03m11       {{3,11}, ocac_m_block_getMostRecentParamSetIdentifier},
#define OCAC_CLASS_BLOCK_03m12       {{3,12}, ocac_m_block_applyParamSet},
#define OCAC_CLASS_BLOCK_03m13       {{3,13}, ocac_m_block_getCurrentParamSetData},
#define OCAC_CLASS_BLOCK_03m14       {{3,14}, ocac_m_block_storeCurrentParamSetData},
#define OCAC_CLASS_BLOCK_03m15       {{3,15}, ocac_m_block_getGlobalType},
#define OCAC_CLASS_BLOCK_03m16       {{3,16}, ocac_m_block_getONoMap},
#define OCAC_CLASS_BLOCK_03m17       {{3,17}, ocac_m_block_findObjectsByRole},
#define OCAC_CLASS_BLOCK_03m18       {{3,18}, ocac_m_block_findObjectsByRoleRecursive},
#define OCAC_CLASS_BLOCK_03m19       {{3,19}, ocac_m_block_findObjectsByLabelRecursive},
#define OCAC_CLASS_BLOCK_03m20       {{3,20}, ocac_m_block_findObjectsByPath},

#define OCAC_CLASS_BLOCK_03p01
#define OCAC_CLASS_BLOCK_03p02
#define OCAC_CLASS_BLOCK_03p03
#define OCAC_CLASS_BLOCK_03p04
#define OCAC_CLASS_BLOCK_03p05
#define OCAC_CLASS_BLOCK_03p06

#ifdef OCAC_OVERRIDEABLE_METHODS
#define OCAC_CLASS_BLOCK_01m01       {{1,1}, ocac_m_root_getClassIdentification},
#define OCAC_CLASS_BLOCK_01m02       {{1,2}, ocac_m_root_getLockable},
#define OCAC_CLASS_BLOCK_01m03       {{1,3}, ocac_m_root_lock},
#define OCAC_CLASS_BLOCK_01m04       {{1,4}, ocac_m_root_unlock},
#define OCAC_CLASS_BLOCK_01m05       {{1,5}, ocac_m_root_getRole},
#define OCAC_CLASS_BLOCK_01m06       {{1,5}, ocac_m_root_lockReadonly},
#define OCAC_CLASS_BLOCK_02m01       {{2,1}, ocac_m_worker_getEnabled},
#define OCAC_CLASS_BLOCK_02m02       {{2,2}, ocac_m_worker_setEnabled},
#define OCAC_CLASS_BLOCK_02m03       {{2,3}, ocac_m_worker_addPort},
#define OCAC_CLASS_BLOCK_02m04       {{2,4}, ocac_m_worker_deletePort},
#define OCAC_CLASS_BLOCK_02m05       {{2,5}, ocac_m_worker_getPorts},
#define OCAC_CLASS_BLOCK_02m06       {{2,6}, ocac_m_worker_getPortName},
#define OCAC_CLASS_BLOCK_02m07       {{2,7}, ocac_m_worker_setPortName},
#define OCAC_CLASS_BLOCK_02m08       {{2,8}, ocac_m_worker_getLabel},
#define OCAC_CLASS_BLOCK_02m09       {{2,9}, ocac_m_worker_setLabel},
#define OCAC_CLASS_BLOCK_02m10       {{2,10}, ocac_m_worker_getOwner},
#define OCAC_CLASS_BLOCK_02m11       {{2,11}, ocac_m_worker_getLatency},
#define OCAC_CLASS_BLOCK_02m12       {{2,12}, ocac_m_worker_setLatency},
#define OCAC_CLASS_BLOCK_02m13       {{2,13}, ocac_m_worker_getPath},
#endif

#define OCAC_OBJ_BLOCK_DEF_TYPE         OcaONo type;
/**
 * formally speaking OCAC_OBJ_BLOCK_DEF_MEMBERS should be:
 *      OCAC_LIST(OcaObjectIdentification, MAX_MEMBERS);
 * but we're cheating here by directly linking objects through
 * 1. first child, and
 * 2. next sibling references
 * thereby we can avoid the statically declared lists and hope to create a more flexible setup even if
 * any modifications of references mean more overhead (and potential errors); but well,
 * looking up an object based on ONo wouldn't really save any overhead, as otherwise necessary..
 *
 * Sidenote: just a general critique, OCA does not seem to have been designed with a low-level perspective in mind.
 * Just as the length attribute of UTF8 strings does not designate the actual length in bytes, but the utf8 character
 * length, requiring unnecessary overhead for the most basic of operations..
 *
 * Also see OCAC_OBJ_WORKER_DEF_CUSTOM in workers/worker.h
 */
#define OCAC_OBJ_BLOCK_DEF_MEMBERS      OCAC_OBJ_BASE * first_child;
#define OCAC_OBJ_BLOCK_DEF_SIGNALPATHS  // TODO OcaMap<OcaUin16, OcaSignalPath>
#define OCAC_OBJ_BLOCK_DEF_MOSTRECENTPARAMSETID OcaLibVolIdentifier mostRecentParamSetIdentifier;
#define OCAC_OBJ_BLOCK_DEF_GLOBALTYPE     OcaGlobalTypeIdentifier globalType;
#define OCAC_OBJ_BLOCK_DEF_ONOMAP       // TODO OcaMap<OcaProtoONo, OcaONo> ONoMap

// Add your own definitions if desired
#define OCAC_OBJ_BLOCK_DEF_CUSTOM



/** /CONFIGURATION **/


/**
 * AUTO CONFIG
 * You should not need to change anything.
 */

#ifndef OCAC_CLASS_BLOCK_03m01
#define OCAC_CLASS_BLOCK_03m01
#endif
#ifndef OCAC_CLASS_BLOCK_03m02
#define OCAC_CLASS_BLOCK_03m02
#endif
#ifndef OCAC_CLASS_BLOCK_03m03
#define OCAC_CLASS_BLOCK_03m03
#endif
#ifndef OCAC_CLASS_BLOCK_03m04
#define OCAC_CLASS_BLOCK_03m04
#endif
#ifndef OCAC_CLASS_BLOCK_03m05
#define OCAC_CLASS_BLOCK_03m05
#endif
#ifndef OCAC_CLASS_BLOCK_03m06
#define OCAC_CLASS_BLOCK_03m06
#endif
#ifndef OCAC_CLASS_BLOCK_03m07
#define OCAC_CLASS_BLOCK_03m07
#endif
#ifndef OCAC_CLASS_BLOCK_03m08
#define OCAC_CLASS_BLOCK_03m08
#endif
#ifndef OCAC_CLASS_BLOCK_03m09
#define OCAC_CLASS_BLOCK_03m09
#endif
#ifndef OCAC_CLASS_BLOCK_03m10
#define OCAC_CLASS_BLOCK_03m10
#endif
#ifndef OCAC_CLASS_BLOCK_03m11
#define OCAC_CLASS_BLOCK_03m11
#endif
#ifndef OCAC_CLASS_BLOCK_03m12
#define OCAC_CLASS_BLOCK_03m12
#endif
#ifndef OCAC_CLASS_BLOCK_03m13
#define OCAC_CLASS_BLOCK_03m13
#endif
#ifndef OCAC_CLASS_BLOCK_03m14
#define OCAC_CLASS_BLOCK_03m14
#endif
#ifndef OCAC_CLASS_BLOCK_03m15
#define OCAC_CLASS_BLOCK_03m15
#endif
#ifndef OCAC_CLASS_BLOCK_03m16
#define OCAC_CLASS_BLOCK_03m16
#endif
#ifndef OCAC_CLASS_BLOCK_03m17
#define OCAC_CLASS_BLOCK_03m17
#endif
#ifndef OCAC_CLASS_BLOCK_03m18
#define OCAC_CLASS_BLOCK_03m18
#endif
#ifndef OCAC_CLASS_BLOCK_03m19
#define OCAC_CLASS_BLOCK_03m19
#endif
#ifndef OCAC_CLASS_BLOCK_03m20
#define OCAC_CLASS_BLOCK_03m20
#endif

#define OCAC_CLASS_BLOCK_03mXX \
    OCAC_CLASS_BLOCK_03m01 \
    OCAC_CLASS_BLOCK_03m02 \
    OCAC_CLASS_BLOCK_03m03 \
    OCAC_CLASS_BLOCK_03m04 \
    OCAC_CLASS_BLOCK_03m05 \
    OCAC_CLASS_BLOCK_03m06 \
    OCAC_CLASS_BLOCK_03m07 \
    OCAC_CLASS_BLOCK_03m08 \
    OCAC_CLASS_BLOCK_03m09 \
    OCAC_CLASS_BLOCK_03m10 \
    OCAC_CLASS_BLOCK_03m11 \
    OCAC_CLASS_BLOCK_03m12 \
    OCAC_CLASS_BLOCK_03m13 \
    OCAC_CLASS_BLOCK_03m14 \
    OCAC_CLASS_BLOCK_03m15 \
    OCAC_CLASS_BLOCK_03m16 \
    OCAC_CLASS_BLOCK_03m17 \
    OCAC_CLASS_BLOCK_03m18 \
    OCAC_CLASS_BLOCK_03m19 \
    OCAC_CLASS_BLOCK_03m20


#ifdef OCAC_OVERRIDEABLE_METHODS

#define OCAC_CLASS_BLOCK_XXmXX \
    OCAC_CLASS_BLOCK_01m01 \
    OCAC_CLASS_BLOCK_01m02 \
    OCAC_CLASS_BLOCK_01m03 \
    OCAC_CLASS_BLOCK_01m04 \
    OCAC_CLASS_BLOCK_01m05 \
    OCAC_CLASS_BLOCK_01m06 \
    OCAC_CLASS_BLOCK_02m01 \
    OCAC_CLASS_BLOCK_02m02 \
    OCAC_CLASS_BLOCK_02m03 \
    OCAC_CLASS_BLOCK_02m04 \
    OCAC_CLASS_BLOCK_02m05 \
    OCAC_CLASS_BLOCK_02m06 \
    OCAC_CLASS_BLOCK_02m07 \
    OCAC_CLASS_BLOCK_02m08 \
    OCAC_CLASS_BLOCK_02m09 \
    OCAC_CLASS_BLOCK_02m10 \
    OCAC_CLASS_BLOCK_02m11 \
    OCAC_CLASS_BLOCK_02m12 \
    OCAC_CLASS_BLOCK_02m13 \
    OCAC_CLASS_BLOCK_03mXX

#define OCAC_CLASS_BLOCK_NMETHODS_TOTAL (OCAC_CLASS_BLOCK_NMETHODS + OCAC_CLASS_WORKER_NMETHODS + OCAC_CLASS_ROOT_NMETHODS_TOTAL)

#else

#define OCAC_CLASS_BLOCK_XXmXX \
    OCAC_CLASS_BLOCK_03mXX

#define OCAC_CLASS_BLOCK_NMETHODS_TOTAL OCAC_CLASS_BLOCK_NMETHODS

#endif //OCAC_OVERRIDEABLE_METHODS



#ifndef OCAC_CLASS_BLOCK_03p01
#define OCAC_CLASS_BLOCK_03p01
#endif
#ifndef OCAC_CLASS_BLOCK_03p02
#define OCAC_CLASS_BLOCK_03p02
#endif
#ifndef OCAC_CLASS_BLOCK_03p03
#define OCAC_CLASS_BLOCK_03p03
#endif
#ifndef OCAC_CLASS_BLOCK_03p04
#define OCAC_CLASS_BLOCK_03p04
#endif
#ifndef OCAC_CLASS_BLOCK_03p05
#define OCAC_CLASS_BLOCK_03p05
#endif
#ifndef OCAC_CLASS_BLOCK_03p06
#define OCAC_CLASS_BLOCK_03p06
#endif

#define OCAC_CLASS_BLOCK_03pXX \
    OCAC_CLASS_BLOCK_03p01 \
    OCAC_CLASS_BLOCK_03p02 \
    OCAC_CLASS_BLOCK_03p03 \
    OCAC_CLASS_BLOCK_03p04 \
    OCAC_CLASS_BLOCK_03p05 \
    OCAC_CLASS_BLOCK_03p06

//#define OCAC_CLASS_WORKER_NPROPERTIES_TOTAL (OCAC_CLASS_WORKER_NPROPERTIES + OCAC_CLASS_ROOT_NPROPERTIES_TOTAL)
#define OCAC_CLASS_BLOCK_NPROPERTIES_TOTAL OCAC_CLASS_BLOCK_NPROPERTIES


#define OCAC_CLASS_BLOCK_03eXX

#define OCAC_CLASS_BLOCK_NEVENTS_TOTAL OCAC_CLASS_BLOCK_NEVENTS


#ifndef OCAC_OBJ_BLOCK_DEF_TYPE
#define OCAC_OBJ_BLOCK_DEF_TYPE
#else
#define OCAC_OBJ_BLOCK_DEF_TYPE_USE
#endif
#ifndef OCAC_OBJ_BLOCK_DEF_MEMBERS
#define OCAC_OBJ_BLOCK_DEF_MEMBERS
#else
#define OCAC_OBJ_BLOCK_DEF_MEMBERS_USE
#endif
#ifndef OCAC_OBJ_BLOCK_DEF_SIGNALPATHS
#define OCAC_OBJ_BLOCK_DEF_SIGNALPATHS
#else
#define OCAC_OBJ_BLOCK_DEF_SIGNALPATHS_USE
#endif
#ifndef OCAC_OBJ_BLOCK_DEF_MOSTRECENTPARAMSETID
#define OCAC_OBJ_BLOCK_DEF_MOSTRECENTPARAMSETID
#else
#define OCAC_OBJ_BLOCK_DEF_MOSTRECENTPARAMSETID_USE
#endif
#ifndef OCAC_OBJ_BLOCK_DEF_GLOBALTYPE
#define OCAC_OBJ_BLOCK_DEF_GLOBALTYPE
#else
#define OCAC_OBJ_BLOCK_DEF_GLOBALTYPE_USE
#endif
#ifndef OCAC_OBJ_BLOCK_DEF_ONOMAP
#define OCAC_OBJ_BLOCK_DEF_ONOMAP
#else
#define OCAC_OBJ_BLOCK_DEF_ONOMAP_USE
#endif
#ifndef OCAC_OBJ_BLOCK_DEF_CUSTOM
#define OCAC_OBJ_BLOCK_DEF_CUSTOM
#endif

#define OCAC_OBJ_BLOCK_DEF \
    OCAC_OBJ_BLOCK_DEF_TYPE \
    OCAC_OBJ_BLOCK_DEF_MEMBERS \
    OCAC_OBJ_BLOCK_DEF_SIGNALPATHS \
    OCAC_OBJ_BLOCK_DEF_MOSTRECENTPARAMSETID \
    OCAC_OBJ_BLOCK_DEF_GLOBALTYPE \
    OCAC_OBJ_BLOCK_DEF_ONOMAP \
    OCAC_OBJ_BLOCK_DEF_CUSTOM


/** /AUTO CONFIG **/


/**
 * CLASS/OBJECT DECLARATION
 * You should not need to edit anything.
 */


/** Class type */
OCAC_CLASS_DEF_BEGIN(OcaBlock)
OCAC_CLASS_DEF_DATA(OCAC_CLASS_BLOCK_NMETHODS_TOTAL, OCAC_CLASS_BLOCK_NPROPERTIES_TOTAL, OCAC_CLASS_BLOCK_NEVENTS_TOTAL)
OCAC_CLASS_DEF_END(OcaBlock)


/** Object type */
OCAC_OBJ_DEF_BEGIN(OcaBlock)
OCAC_OBJ_ROOT_DEF
OCAC_OBJ_WORKER_DEF
OCAC_OBJ_BLOCK_DEF
OCAC_OBJ_DEF_END(OcaBlock)


/** Class object (will be allocated) */
extern OCAC_CLASS_TYPE(OcaWorker) OCAC_CLASS_NAME(OcaWorker);

/** Object instance (will be allocated) */
extern OCAC_OBJ_TYPE(OcaBlock) OCAC_OBJ_NAME(RootBlock);

/** Class methods */
OcaStatus ocac_m_block_getType(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_constructMember(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_constructMemberUsingFactory(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_deleteMember(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_getMembers(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_getMembersRecursive(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_addSignalPath(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_deleteSignalPath(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_getSignalPaths(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_getSignalPathsRecursive(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_getMostRecentParamSetIdentifier(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_applyParamSet(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_getCurrentParamSetData(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_storeCurrentParamSetData(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_getGlobalType(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_getONoMap(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_findObjectsByRole(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_findObjectsByRoleRecursive(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_findObjectsByLabelRecursive(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_block_findObjectsByPath(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);

/** /CLASS/OBJECT DECLARATION **/

#ifdef DEBUG
void ocac_dump_block(OCAC_OBJ_BASE * obj);
#endif


#ifdef __cplusplus
}
#endif

#endif //OCAC_IMPL_OCCCLASSES_WORKERS_BLOCK_H
