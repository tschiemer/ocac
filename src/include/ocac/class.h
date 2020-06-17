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


#ifndef OCAC_NO_PROPERTIES
struct ocac_class_property {
    OcaPropertyID id;
};
#endif

#ifndef OCAC_NO_EVENTS
struct ocac_class_event {
    OcaEventID id;
};
#endif

typedef OcaStatus (*ocac_method_ptr)(struct ocac_obj_base * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen);

struct ocac_class_method {
    OcaMethodID id;
    ocac_method_ptr fun;
};


#ifdef OCAC_NO_PROPERTIES
#define OCAC_CLASS_DEF_PROPERTIES
#define OCAC_CLASS_DEF_DATA_PROPERTIES(nproperties)
#else
#define OCAC_CLASS_DEF_PROPERTIES const u8_t property_count;
#define OCAC_CLASS_DEF_DATA_PROPERTIES(nproperties) struct ocac_class_property properties[nproperties];
#endif


#ifdef OCAC_NO_EVENTS
#define OCAC_CLASS_DEF_EVENTS
#define OCAC_CLASS_DEF_DATA_EVENTS(nevents)
#else
#define OCAC_CLASS_DEF_EVENTS const u8_t event_count;
#define OCAC_CLASS_DEF_DATA_EVENTS(nevents) struct ocac_class_event events[nevents];
#endif


#ifdef DEBUG
#define OCAC_CLASS_DEF_DUMP void (*dump)(struct ocac_obj_base * obj);
#else
#define OCAC_CLASS_DEF_DUMP
#endif


#define OCAC_CLASS_TYPE(name) struct ocac_class_ ## name

#define OCAC_CLASS_DEF_BEGIN(name) \
    OCAC_CLASS_TYPE(name) { \
        const OcaClassIdentification class_identification; \
        \
        OCAC_CLASS_BASE * parent; \
        \
        const u8_t method_count; \
        OCAC_CLASS_DEF_PROPERTIES \
        OCAC_CLASS_DEF_EVENTS \
        \
        OCAC_CLASS_DEF_DUMP


#define OCAC_CLASS_DEF_DATA(nmethods, nproperties, nevents) \
    struct ocac_class_method methods[nmethods]; \
    OCAC_CLASS_DEF_DATA_PROPERTIES(nproperties) \
    OCAC_CLASS_DEF_DATA_EVENTS(nevents);


#define OCAC_CLASS_DEF_END(name) \
    } PACK_STRUCT_STRUCT; \
    // End of class definition: name

#define OCAC_CLASS_BASE OCAC_CLASS_TYPE(base)
#define OCAC_CLASS_CAST(name,class_ptr) ((OCAC_CLASS_TYPE(name)*)class_ptr)
#define OCAC_CLASS_PTR(class_ptr) OCAC_CLASS_CAST(base, class_ptr)

// &class_ptr->data[0]
#define OCAC_CLASS_METHODS( class_ptr ) ((struct ocac_class_method *)(OCAC_CLASS_PTR(class_ptr)->data))
// &class_ptr->data[ nmethods * sizeof(methods) ];
#define OCAC_CLASS_PROPERTIES( class_ptr ) ((struct ocac_class_property *)(&OCAC_CLASS_PTR(class_ptr)->data[OCAC_CLASS_PTR(class_ptr)->method_count * sizeof(struct ocac_class_method)]))
// &class_ptr->data[ nmethods * sizeof(method_struct) + nparams * sizeof(param_struct) ];
#define OCAC_CLASS_EVENTS( class_ptr ) ((struct ocac_class_event *)(&OCAC_CLASS_PTR(class_ptr)->data[OCAC_CLASS_PTR(class_ptr)->method_count * sizeof(struct ocac_class_method) + OCAC_CLASS_PTR(class_ptr)->property_count * sizeof(struct ocac_class_property)]))

/**
 * Generic base class
 * Used for basic handling
 */
OCAC_CLASS_DEF_BEGIN(base)
    u8_t data[];
OCAC_CLASS_DEF_END(base)


struct ocac_class_method * ocac_class_get_method(OCAC_CLASS_BASE * class_ptr, u16_t deflevel, u16_t index );

#ifdef OCAC_NO_PROPERTIES
struct ocac_class_property * ocac_class_get_property(OCAC_CLASS_BASE * class_ptr, u16_t deflevel, u16_t index );
#endif

#ifdef OCAC_NO_EVENTS
struct ocac_class_event * ocac_class_get_event(OCAC_CLASS_BASE * class_ptr, u16_t deflevel, u16_t index );
#endif


#ifdef DEBUG
void ocac_dump_class_id(OCAC_CLASS_BASE * class_ptr);
void ocac_dump_class(OCAC_CLASS_BASE * class_ptr);
#endif // DEBUG

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCAC_CLASS_H
