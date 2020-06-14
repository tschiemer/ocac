//
// Created by Philip Tschiemer on 13.06.20.
//

#ifndef OCAC_OCC_CLASSES_ROOT_H
#define OCAC_OCC_CLASSES_ROOT_H

#include "ocac/obj.h"

#ifdef __cplusplus
extern "C" {
#endif



#define OCAC_CLASS_ROOT_ID          {1, {1}}
#define OCAC_CLASS_ROOT_VERSION     1
#define OCAC_OBJ_ROOT_ONO           100


#define OCAC_CLASS_ROOT_01p01
#define OCAC_CLASS_ROOT_01p02
#define OCAC_CLASS_ROOT_01p03
#define OCAC_CLASS_ROOT_01p04
#define OCAC_CLASS_ROOT_01p05

#define OCAC_CLASS_ROOT_01pXX \
    OCAC_CLASS_ROOT_01p01, \
    OCAC_CLASS_ROOT_01p02, \
    OCAC_CLASS_ROOT_01p03, \
    OCAC_CLASS_ROOT_01p04, \
    OCAC_CLASS_ROOT_01p05

#define OCAC_CLASS_ROOT_01m01       {{1,1}, ocac_m_root_getClassIdentification}
#define OCAC_CLASS_ROOT_01m02       {{1,2}, ocac_m_root_getLockable}
#define OCAC_CLASS_ROOT_01m03       {{1,3}, ocac_m_root_lock}
#define OCAC_CLASS_ROOT_01m04       {{1,4}, ocac_m_root_unlock}
#define OCAC_CLASS_ROOT_01m05       {{1,5}, ocac_m_root_getRole}

#define OCAC_CLASS_ROOT_01mXX_MIN \
    OCAC_CLASS_ROOT_01m02, \
    OCAC_CLASS_ROOT_01m03, \
    OCAC_CLASS_ROOT_01m04

#define OCAC_CLASS_ROOT_01mXX_MAX \
    OCAC_CLASS_ROOT_01m01, \
    OCAC_CLASS_ROOT_01m02, \
    OCAC_CLASS_ROOT_01m03, \
    OCAC_CLASS_ROOT_01m04, \
    OCAC_CLASS_ROOT_01m05

#define OCAC_CLASS_ROOT_01e01

#define OCAC_CLASS_ROOT_01eXX_DEFAULT \
    OCAC_CLASS_ROOT_01e01






#if OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_CUSTOM

#error include some file here

#elif OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MIN

#define OCAC_CLASS_ROOT_PROPERTIES  5

#define OCAC_CLASS_ROOT_METHODS 3
#define OCAC_CLASS_ROOT_01mXX   OCAC_CLASS_ROOT_01mXX_MIN

#define OCAC_CLASS_ROOT_EVENTS  1
#define OCAC_CLASS_ROOT_01eXX   OCAC_CLASS_ROOT_01eXX_DEFAULT

#elif OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MAX

#define OCAC_CLASS_ROOT_PROPERTIES  5

#define OCAC_CLASS_ROOT_METHODS 5
#define OCAC_CLASS_ROOT_01mXX   OCAC_CLASS_ROOT_01mXX_MAX

#define OCAC_CLASS_ROOT_EVENTS  1
#define OCAC_CLASS_ROOT_01eXX   OCAC_CLASS_ROOT_01eXX_DEFAULT

#endif

#ifndef OCAC_CLASS_NO_DEFAULT_DEFINITION
OCAC_CLASS_DEF_BEGIN(OcaRoot)
    OCAC_CLASS_DEF_DATA(OCAC_CLASS_ROOT_PROPERTIES, OCAC_CLASS_ROOT_METHODS, OCAC_CLASS_ROOT_EVENTS)
OCAC_CLASS_DEF_END(OcaRoot)
#endif





#define OCAC_OBJ_ROOT_DEF_MAX \
    OcaBoolean lockable; \
    OCAC_STRING(OCAC_OBJ_ROOT_ROLE_MAXLEN) role;

#define OCAC_OBJ_ROOT_DEF_MIN \
    OcaBoolean lockable;


#if OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_CUSTOM

#error include some file here

#elif OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MIN

#define OCAC_OBJ_ROOT_DEF \
    OCAC_OBJ_ROOT_DEF_MIN \
    OCAC_OBJ_ROOT_DEF_CUSTOM

#elif OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MAX

#define OCAC_OBJ_ROOT_DEF \
    OCAC_OBJ_ROOT_DEF_MAX \
    OCAC_OBJ_ROOT_DEF_CUSTOM

#endif

#ifndef OCAC_OBJ_NO_DEFAULT_DEFINITION
OCAC_OBJ_DEF_BEGIN(OcaRoot)
    OCAC_OBJ_ROOT_DEF
OCAC_OBJ_DEF_END(OcaRoot)
#endif

#ifndef OCAC_CLASS_NO_DEFAULT_ALLOCATION
extern OCAC_CLASS_TYPE(OcaRoot) OCAC_CLASS_NAME(OcaRoot);
#endif



OcaStatus ocac_m_root_getClassIdentification(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_root_getLockable(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_root_lock(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_root_unlock(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_root_getRole(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);

#ifdef DEBUG
void ocac_dump_root(OCAC_OBJ_BASE * obj);
#endif
    
#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_CLASSES_ROOT_H
