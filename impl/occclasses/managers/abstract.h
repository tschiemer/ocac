//
// Created by Philip Tschiemer on 13.06.20.
//

#ifndef OCAC_IMPL_OCCCLASSES_MANAGERS_ABSTRACT_H
#define OCAC_IMPL_OCCCLASSES_MANAGERS_ABSTRACT_H

#include "occclasses/root.h"

#ifdef __cplusplus
extern "C" {
#endif



/**
 * CONSTANTS
 * Don't change!
 */
#define OCAC_CLASS_MANAGER_ID           {2, {1,3}}
#define OCAC_CLASS_MANAGER_VERSION      2

/**
 * CONFIGURATION
 * Edit here if wanted.
 *
 * To enable/disable a method/property/event define/undefine given method/property/event AND set the number of
 * methods/properties/events accordingly
 */

#define OCAC_CLASS_MANAGER_NMETHODS        0
#define OCAC_CLASS_MANAGER_NPROPERTIES     0
#define OCAC_CLASS_MANAGER_NEVENTS         0


#define OCAC_OBJ_MANAGER_DEF_NAME          OCAC_STRING(OCAC_OBJ_MANAGER_NAME_MAXLEN) mngr_name; // Needed for manager descripter (see device manager)


// Add your own definitions if desired
#define OCAC_OBJ_MANAGER_DEF_CUSTOM



/** /CONFIGURATION **/



/**
 * AUTO CONFIG
 * You should not need to change anything.
 */

#define OCAC_CLASS_MANAGER_02mXX

#ifdef OCAC_OVERRIDEABLE_METHODS

#define OCAC_CLASS_MANAGER_XXmXX \
    OCAC_CLASS_ROOT_01mXX \
    OCAC_CLASS_MANAGER_02mXX

#define OCAC_CLASS_MANAGER_NMETHODS_TOTAL (OCAC_CLASS_MANAGER_NMETHODS + OCAC_CLASS_ROOT_NMETHODS)

#else

#define OCAC_CLASS_MANAGER_XXmXX \
    OCAC_CLASS_MANAGER_02mXX

#define OCAC_CLASS_MANAGER_NMETHODS_TOTAL OCAC_CLASS_MANAGER_NMETHODS

#endif //OCAC_OVERRIDEABLE_METHODS



#define OCAC_CLASS_MANAGER_02pXX

//#define OCAC_CLASS_MANAGER_XXpXX \
//    OCAC_CLASS_ROOT_01mXX \
//    OCAC_CLASS_MANAGER_02mXX

#define OCAC_CLASS_MANAGER_NPROPERTIES_TOTAL OCAC_CLASS_MANAGER_NPROPERTIES



#define OCAC_CLASS_MANAGER_02eXX

//#define OCAC_CLASS_MANAGER_XXeXX \
//    OCAC_CLASS_ROOT_01eXX \
//    OCAC_CLASS_MANAGER_02eXX

#define OCAC_CLASS_MANAGER_NEVENTS_TOTAL OCAC_CLASS_MANAGER_NEVENTS



#ifndef OCAC_OBJ_MANAGER_DEF_NAME
#define OCAC_OBJ_MANAGER_DEF_NAME
#else
#define OCAC_OBJ_MANAGER_DEF_NAME_USE
#endif
#ifndef OCAC_OBJ_MANAGER_DEF_CUSTOM
#define OCAC_OBJ_MANAGER_DEF_CUSTOM
#endif

#define OCAC_OBJ_MANAGER_DEF \
    OCAC_OBJ_MANAGER_DEF_NAME \
    OCAC_OBJ_MANAGER_DEF_CUSTOM


/** /AUTO CONFIG **/


/**
 * CLASS/OBJECT DECLARATION
 * You should not need to edit anything.
 */

/** Class type */
OCAC_CLASS_DEF_BEGIN(OcaManager)
    OCAC_CLASS_DEF_DATA(OCAC_CLASS_MANAGER_NMETHODS_TOTAL, OCAC_CLASS_MANAGER_NPROPERTIES_TOTAL, OCAC_CLASS_MANAGER_NEVENTS_TOTAL)
OCAC_CLASS_DEF_END(OcaManager)

/** Object type */
OCAC_OBJ_DEF_BEGIN(OcaManager)
    OCAC_OBJ_ROOT_DEF
    OCAC_OBJ_MANAGER_DEF
OCAC_OBJ_DEF_END(OcaManager)

/** Class object (will be allocated) */
// in principle not needed as there ares methods/properties/events
extern OCAC_CLASS_TYPE(OcaManager) OCAC_CLASS_NAME(OcaManager);

/** Object instance (will be allocated) */
// none

/** Class methods */
// none

/** /CLASS/OBJECT DECLARATION **/

#ifdef DEBUG
void ocac_dump_manager(OCAC_OBJ_BASE * obj);
#endif

#ifdef __cplusplus
}
#endif

#endif //OCAC_IMPL_OCCCLASSES_MANAGERS_ABSTRACT_H
