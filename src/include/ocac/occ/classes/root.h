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

#define OCAC_CLASS_ROOT_PROPERTIES  5
#define OCAC_CLASS_ROOT_METHODS     5
#define OCAC_CLASS_ROOT_EVENTS      1

#define OCAC_CLASS_ROOT_01p01
#define OCAC_CLASS_ROOT_01p02
#define OCAC_CLASS_ROOT_01p03
#define OCAC_CLASS_ROOT_01p04
#define OCAC_CLASS_ROOT_01p05

#define OCAC_CLASS_ROOT_01pXX       OCAC_CLASS_ROOT_01p01, OCAC_CLASS_ROOT_01p02, OCAC_CLASS_ROOT_01p03, OCAC_CLASS_ROOT_01p04, OCAC_CLASS_ROOT_01p05

#define OCAC_CLASS_ROOT_01m01       {{1,1}, ocac_m_root_getClassIdentification}
#define OCAC_CLASS_ROOT_01m02       {{1,2}, ocac_m_root_getLockable}
#define OCAC_CLASS_ROOT_01m03       {{1,3}, ocac_m_root_lock}
#define OCAC_CLASS_ROOT_01m04       {{1,4}, ocac_m_root_unlock}
#define OCAC_CLASS_ROOT_01m05       {{1,5}, ocac_m_root_getRole}

#define OCAC_CLASS_ROOT_01mXX       OCAC_CLASS_ROOT_01m01, OCAC_CLASS_ROOT_01m02, OCAC_CLASS_ROOT_01m03, OCAC_CLASS_ROOT_01m04, OCAC_CLASS_ROOT_01m05

#define OCAC_CLASS_ROOT_01e01

#define OCAC_CLASS_ROOT_01eXX       OCAC_CLASS_ROOT_01e01


OCAC_CLASS_DEF_BEGIN(Root)
    OCAC_CLASS_DEF_DATA(OCAC_CLASS_ROOT_PROPERTIES, OCAC_CLASS_ROOT_METHODS, OCAC_CLASS_ROOT_EVENTS)
OCAC_CLASS_DEF_END(Root)



#define OCAC_OBJ_ROOT_DEF \
    OcaBoolean lockable; \
    OCAC_STRING(OCAC_OBJ_ROOT_ROLE_MAXLEN) role;


OCAC_OBJ_DEF_BEGIN(Root)
    OCAC_OBJ_ROOT_DEF
OCAC_OBJ_DEF_END(Root)


extern const OCAC_CLASS_TYPE(Root) OCAC_CLASS_NAME(Root);
extern const OCAC_OBJ_TYPE(Root) OCAC_OBJ_NAME(Root);


OcaStatus ocac_m_root_getClassIdentification(OCAC_OBJ_BASE * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_root_getLockable(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_root_lock(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_root_unlock(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);
OcaStatus ocac_m_root_getRole(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);

#ifdef DEBUG
void ocac_dump_root(void * obj);
#endif
    
#ifdef __cplusplus
}
#endif

#endif //OCAC_OCC_CLASSES_ROOT_H
