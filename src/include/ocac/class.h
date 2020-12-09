/**
 * MIT License
 *
 * Copyright (c) 2020 Philip Tschiemer, https://github.com/tschiemer/ocac
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef OCAC_OCAC_CLASS_H
#define OCAC_OCAC_CLASS_H

#include "ocac/arch.h"
#include "ocac/occ/datatypes/base.h"
#include "ocac/occ/datatypes/framework.h"
#include "ocac/session.h"

#ifdef __cplusplus
extern "C" {
#endif

//forward declaration
struct ocac_obj_base;


#if OCAC_USE_PROPERTIES == 1

#define OCAC_PROPERTY_STATUS_SUBSCRIBABLE 1

struct ocac_class_property {
    OcaPropertyID id;
    u8_t status;
};
#endif

#if OCAC_USE_EVENTS == 1
struct ocac_class_event {
    OcaEventID id;
};
#endif

typedef OcaStatus (*ocac_method_ptr)(struct ocac_obj_base * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);

struct ocac_class_method {
    OcaMethodID id;
    ocac_method_ptr fun;
};


#if OCAC_USE_PROPERTIES == 0
#define OCAC_CLASS_DEF_PROPERTIES
#define OCAC_CLASS_DEF_DATA_PROPERTIES(nproperties)
#else
#define OCAC_CLASS_DEF_PROPERTIES const u8_t property_count;
#define OCAC_CLASS_DEF_DATA_PROPERTIES(nproperties) struct ocac_class_property properties[nproperties];
#endif


#if OCAC_USE_EVENTS == 0
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

#define OCAC_CLASS_BASE                 OCAC_CLASS_TYPE(base)
#define OCAC_CLASS_CAST(name,class_ptr) ((OCAC_CLASS_TYPE(name)*)class_ptr)
#define OCAC_CLASS_PTR(class_ptr)       OCAC_CLASS_CAST(base, class_ptr)

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

#if OCAC_USE_PROPERTIES == 1
struct ocac_class_property * ocac_class_get_property(OCAC_CLASS_BASE * class_ptr, u16_t deflevel, u16_t index );
#endif

#if OCAC_USE_EVENTS == 1
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
