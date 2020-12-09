//
// Created by Philip Tschiemer on 13.06.20.
//

#ifndef OCAC_IMPL_OCCCLASSES_CLASSES_ROOT_H
#define OCAC_IMPL_OCCCLASSES_CLASSES_ROOT_H

#include "ocac/obj.h"
#include "occclasses/shared.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * CONSTANTS
 * Don't change!
 */

#define OCAC_CLASS_ROOT_ID          {1, {1}}
#define OCAC_CLASS_ROOT_VERSION     2

#define OCAC__Root_DefLevel                1

#define OCAC__Root_m_getClassIdentification   1
#define OCAC__Root_m_getLockable              2
#define OCAC__Root_m_lock                     3
#define OCAC__Root_m_unlock                   4
#define OCAC__Root_m_getRole                  5
#define OCAC__Root_m_lockReadonly             6

#define OCAC__Root_p_ClassID                    1
#define OCAC__Root_p_ClassVersion               2
#define OCAC__Root_p_ObjectNumber               3
#define OCAC__Root_p_Lockable                   4
#define OCAC__Root_p_Role                       5

#define OCAC__Root_e_PropertyChanged           1


/**
 * CONFIGURATION
 * Edit here if wanted.
 *
 * To enable/disable a method/property/event define/undefine given method/property/event AND set the number of
 * methods/properties/events accordingly
 */


#define OCAC_CLASS_ROOT_NMETHODS        6
#define OCAC_CLASS_ROOT_NPROPERTIES     5
#define OCAC_CLASS_ROOT_NEVENTS         1


#define OCAC_CLASS_ROOT_01m01       {{1,1}, ocac_m_root_getClassIdentification},
#define OCAC_CLASS_ROOT_01m02       {{1,2}, ocac_m_root_getLockable},
#define OCAC_CLASS_ROOT_01m03       {{1,3}, ocac_m_root_lock},
#define OCAC_CLASS_ROOT_01m04       {{1,4}, ocac_m_root_unlock},
#define OCAC_CLASS_ROOT_01m05       {{1,5}, ocac_m_root_getRole},
#define OCAC_CLASS_ROOT_01m06       {{1,5}, ocac_m_root_lockReadonly},

#define OCAC_CLASS_ROOT_01p01
#define OCAC_CLASS_ROOT_01p02
#define OCAC_CLASS_ROOT_01p03
#define OCAC_CLASS_ROOT_01p04
#define OCAC_CLASS_ROOT_01p05


#define OCAC_CLASS_ROOT_01e01

#ifdef OCAC_USE_LOCKS
#define OCAC_OBJ_ROOT_DEF_LOCKABLE      OcaBoolean lockable;
#endif
#define OCAC_OBJ_ROOT_DEF_ROLE          OCAC_STRING(OCAC_OBJ_ROOT_ROLE_MAXLEN) role;

// Add your own definitions if desired
#define OCAC_OBJ_ROOT_DEF_CUSTOM



/** /CONFIGURATION **/



/**
 * AUTO CONFIG
 * You should not need to change anything.
 */

#ifndef OCAC_CLASS_ROOT_01m01
#define OCAC_CLASS_ROOT_01m01
#endif
#ifndef OCAC_CLASS_ROOT_01m02
#define OCAC_CLASS_ROOT_01m02
#endif
#ifndef OCAC_CLASS_ROOT_01m03
#define OCAC_CLASS_ROOT_01m03
#endif
#ifndef OCAC_CLASS_ROOT_01m04
#define OCAC_CLASS_ROOT_01m04
#endif
#ifndef OCAC_CLASS_ROOT_01m05
#define OCAC_CLASS_ROOT_01m05
#endif
#ifndef OCAC_CLASS_ROOT_01m06
#define OCAC_CLASS_ROOT_01m06
#endif



#define OCAC_CLASS_ROOT_01mXX \
    OCAC_CLASS_ROOT_01m01 \
    OCAC_CLASS_ROOT_01m02 \
    OCAC_CLASS_ROOT_01m03 \
    OCAC_CLASS_ROOT_01m04 \
    OCAC_CLASS_ROOT_01m05 \
    OCAC_CLASS_ROOT_01m06


#ifdef OCAC_NO_PROPERTIES
#define OCAC_CLASS_ROOT_01pXX
#else

#ifndef OCAC_CLASS_ROOT_01p01
#define OCAC_CLASS_ROOT_01p01
#endif
#ifndef OCAC_CLASS_ROOT_01p02
#define OCAC_CLASS_ROOT_01p02
#endif
#ifndef OCAC_CLASS_ROOT_01p03
#define OCAC_CLASS_ROOT_01p03
#endif
#ifndef OCAC_CLASS_ROOT_01p04
#define OCAC_CLASS_ROOT_01p04
#endif
#ifndef OCAC_CLASS_ROOT_01p05
#define OCAC_CLASS_ROOT_01p05
#endif

#define OCAC_CLASS_ROOT_01pXX \
    OCAC_CLASS_ROOT_01p01 \
    OCAC_CLASS_ROOT_01p02 \
    OCAC_CLASS_ROOT_01p03 \
    OCAC_CLASS_ROOT_01p04 \
    OCAC_CLASS_ROOT_01p05
#endif // OCAC_NO_PROPERTIES




#ifdef OCAC_NO_EVENTS
#define OCAC_CLASS_ROOT_01eXX
#else

#ifndef OCAC_CLASS_ROOT_01e01
#define OCAC_CLASS_ROOT_01e01
#endif

#define OCAC_CLASS_ROOT_01eXX \
    OCAC_CLASS_ROOT_01e01

#endif // OCAC_NO_EVENTS



#ifndef OCAC_OBJ_ROOT_DEF_LOCKABLE
#define OCAC_OBJ_ROOT_DEF_LOCKABLE
#else
#define OCAC_OBJ_ROOT_DEF_LOCKABLE_USE
#endif
#ifndef OCAC_OBJ_ROOT_DEF_ROLE
#define OCAC_OBJ_ROOT_DEF_ROLE
#else
#define OCAC_OBJ_ROOT_DEF_ROLE_USE
#endif
#ifndef OCAC_OBJ_ROOT_DEF_CUSTOM
#define OCAC_OBJ_ROOT_DEF_CUSTOM
#endif

#define OCAC_OBJ_ROOT_DEF \
    OCAC_OBJ_ROOT_DEF_LOCKABLE \
    OCAC_OBJ_ROOT_DEF_ROLE \
    OCAC_OBJ_ROOT_DEF_CUSTOM




/** /AUTO CONFIG **/


/**
 * CLASS/OBJECT DECLARATION
 * You should not need to edit anything.
 */

/** Class type */
OCAC_CLASS_DEF_BEGIN(OcaRoot)
    OCAC_CLASS_DEF_DATA(OCAC_CLASS_ROOT_NMETHODS, OCAC_CLASS_ROOT_NPROPERTIES, OCAC_CLASS_ROOT_NEVENTS)
OCAC_CLASS_DEF_END(OcaRoot)

/** Object type */
OCAC_OBJ_DEF_BEGIN(OcaRoot)
    OCAC_OBJ_ROOT_DEF
OCAC_OBJ_DEF_END(OcaRoot)

/** Class object (will be allocated) */
extern OCAC_CLASS_TYPE(OcaRoot) OCAC_CLASS_NAME(OcaRoot);

/** Object instance (will be allocated) */
// none

/** Class methods */
OcaStatus ocac_m_root_getClassIdentification(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_root_getLockable(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_root_lock(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_root_unlock(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_root_getRole(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);
OcaStatus ocac_m_root_lockReadonly(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);


/** /CLASS/OBJECT DECLARATION **/

#ifdef DEBUG
void ocac_dump_root(OCAC_OBJ_BASE * obj);
#endif
    
#ifdef __cplusplus
}
#endif

#endif //OCAC_IMPL_OCCCLASSES_CLASSES_ROOT_H
