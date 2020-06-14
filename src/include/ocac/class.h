//
// Created by Philip Tschiemer on 11.06.20.
//

#ifndef OCAC_OCAC_CLASS_H
#define OCAC_OCAC_CLASS_H

#include "arch.h"
#include "occ/datatypes/base.h"
#include "occ/datatypes/framework.h"

#ifdef __cplusplus
extern "C" {
#endif

//forward declaration
struct ocac_obj_base;


struct ocac_class_property {
    OcaPropertyID id;
};

struct ocac_class_event {
    OcaEventID id;
};

typedef OcaStatus (*ocac_method_ptr)(struct ocac_obj_base * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);

struct ocac_class_method {
    OcaMethodID id;
    ocac_method_ptr fun;
};

#ifdef DEBUG
#define OCAC_CLASS_DEF_DUMP void (*dump)(struct ocac_obj_base * obj);
#else
#define OCAC_CLASS_DEF_DUMP
#endif

#define OCAC_CLASS_DEF_BEGIN(name) \
    PACK_STRUCT_BEGIN \
    struct ocac_class_ ## name { \
        const OcaClassIdentification class_identification; \
        \
        OCAC_CLASS_BASE * parent; \
        OCAC_CLASS_BASE * next; \
        \
        const u8_t property_count; \
        const u8_t method_count; \
        const u8_t event_count; \
        \
        OCAC_CLASS_DEF_DUMP


#define OCAC_CLASS_DEF_DATA(nproperties, nmethods, nevents) \
    struct ocac_class_property properties[nproperties]; \
    struct ocac_class_method methods[nmethods]; \
    struct ocac_class_event events[nevents];
//        u8_t data[nproperties * sizeof(struct ocac_class_property) + nevents * sizeof(struct ocac_class_event) + nmethods * sizeof(struct ocac_class_method)];


#define OCAC_CLASS_DEF_END(name) \
    } PACK_STRUCT_STRUCT; \
    PACK_STRUCT_END \
    // End of class definition: name

#define OCAC_CLASS_TYPE(name) struct ocac_class_ ## name
#define OCAC_CLASS_BASE OCAC_CLASS_TYPE(base)
#define OCAC_CLASS_CAST(name,class_ptr) ((OCAC_CLASS_TYPE(name)*)class_ptr)
#define OCAC_CLASS_PTR(class_ptr) OCAC_CLASS_CAST(base, class_ptr)

#define OCAC_CLASS_PROPERTIES( class_ptr ) (struct ocac_class_property *)(OCAC_CLASS_PTR(class_ptr)->data)
#define OCAC_CLASS_METHODS( class_ptr ) (struct ocac_class_method*)(&OCAC_CLASS_PTR(class_ptr)->data[OCAC_CLASS_PTR(class_ptr)->property_count * sizeof(struct ocac_class_property)])
#define OCAC_CLASS_EVENTS( class_ptr ) (struct ocac_class_event*)(&OCAC_CLASS_PTR(class_ptr)->data[OCAC_CLASS_PTR(class_ptr)->property_count * sizeof(struct ocac_class_property) + OCAC_CLASS_PTR(class_ptr)->method_count * sizeof(struct ocac_class_method)])

/**
 * Generic base class
 * Used to reference
 * struct ocac_class_base_st
 */
OCAC_CLASS_DEF_BEGIN(base)
    u8_t data[];
OCAC_CLASS_DEF_END(base)


struct ocac_class_method * ocac_class_get_method(OCAC_CLASS_BASE * class_ptr, u16_t deflevel, u16_t index );
struct ocac_class_property * ocac_class_get_property(OCAC_CLASS_BASE * class_ptr, u16_t deflevel, u16_t index );
struct ocac_class_event * ocac_class_get_event(OCAC_CLASS_BASE * class_ptr, u16_t deflevel, u16_t index );

//OcaStatus ocac_class_exec(OCAC_CLASS_BASE * class_ptr, u16_t deflevel, u16_t index, struct ocac_obj * obj, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);

#ifdef DEBUG
void ocac_dump_class_id(OCAC_CLASS_BASE * class_ptr);
void ocac_dump_class(OCAC_CLASS_BASE * class_ptr);
#endif // DEBUG

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCAC_CLASS_H
