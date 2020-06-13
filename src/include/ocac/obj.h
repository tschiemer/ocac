//
// Created by Philip Tschiemer on 11.06.20.
//

#ifndef OCAC_OCAC_OBJ_H
#define OCAC_OCAC_OBJ_H


#include "ocac/occ/datatypes/framework.h"
#include "ocac/class.h"
#include "ocac/opt.h"

#ifdef __cplusplus
extern "C" {
#endif

// forward declaration


#define OCAC_OBJ_DEF_BEGIN(name) \
    PACK_STRUCT_BEGIN \
    struct ocac_obj_ ## name { \
        OcaONo  ono; \
        OCAC_CLASS_BASE * class_ptr; \
        \

#define OCAC_OBJ_DEF_END(name) \
    } PACK_STRUCT_STRUCT; \
    PACK_STRUCT_END \
    // End of class definition: name


#define OCAC_OBJ_TYPE(name) struct ocac_obj_ ## name
#define OCAC_OBJ_BASE OCAC_OBJ_TYPE(base)
#define OCAC_OBJ_CAST(name,obj_ptr) ((OCAC_OBJ_TYPE(name)*)obj_ptr)
#define OCAC_OBJ_PTR(obj_ptr) OCAC_OBJ_CAST(base, obj_ptr)

OCAC_OBJ_DEF_BEGIN(base)
OCAC_OBJ_DEF_END(base)

//#define OCAC_ASSERT_GETTER_PARAMS \
//    OCAC_ASSERT("obj != NULL", obj != NULL); \
//    OCAC_ASSERT("argvlen != 0", reqlen != 0); \
//    OCAC_ASSERT("rsp != NULL", rsp != NULL); \
//    OCAC_ASSERT("rsplen != NULL", rsplen != NULL);
//
//#define OCAC_ASSERT_SETTER_PARAMS \
//    OCAC_ASSERT("obj != NULL", obj != NULL); \
//    OCAC_ASSERT("argvlen != 0", reqlen != 0); \

OcaStatus ocac_obj_exec(OCAC_OBJ_BASE * obj, u16_t deflevel, u16_t index, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);

#ifdef DEBUG

void ocac_dump_obj( OCAC_OBJ_BASE * obj );

#endif

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCAC_OBJ_H
