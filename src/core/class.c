//
// Created by Philip Tschiemer on 12.06.20.
//

#include "ocac/class.h"
#include "ocac/debug.h"


struct ocac_class_method * ocac_class_get_method(OCAC_CLASS_BASE * class_ptr, u16_t deflevel, u16_t index )
{
    OCAC_ASSERT("class_ptr != NULL", class_ptr != NULL);
    OCAC_ASSERT("deflevel > 0", deflevel > 0);
    OCAC_ASSERT("method defined by child", class_ptr->class_identification.ClassID.FieldCount >= deflevel );

    #define OCAC_CLASS_NO_EVENT_OVERRIDE
    #ifdef OCAC_CLASS_NO_EVENT_OVERRIDE
    while (class_ptr->class_identification.ClassID.FieldCount > deflevel){
        OCAC_ASSERT("", class_ptr->class_identification.ClassID.FieldCount > 0);
        class_ptr = class_ptr->parent;
    }
    #endif

    struct ocac_class_method * result = NULL;
    struct ocac_class_method * methods = OCAC_CLASS_METHODS(class_ptr);

    for(uint8_t n = class_ptr->method_count, i = 0; result == NULL && i < n; i++ ){
        if (methods[i].id.DefLevel == deflevel && methods[i].id.MethodIndex == index){
            result = &methods[i];
        }
    }

    return result;
}

struct ocac_class_property * ocac_class_get_property(OCAC_CLASS_BASE * class_ptr, u16_t deflevel, u16_t index )
{
    OCAC_ASSERT("class_ptr != NULL", class_ptr != NULL);
    OCAC_ASSERT("deflevel > 0", deflevel > 0);
    OCAC_ASSERT("property defined by child", class_ptr->class_identification.ClassID.FieldCount >= deflevel);

    #ifdef OCAC_CLASS_NO_PROPERTY_OVERRIDE
    while (class_ptr->class_identification.ClassID.FieldCount > deflevel){
        OCAC_ASSERT("", class_ptr->class_identification.ClassID.FieldCount > 0)
        class_ptr = class_ptr->parent;
    }
    #endif

    struct ocac_class_property * result = NULL;
    struct ocac_class_property * properties = OCAC_CLASS_PROPERTIES(class_ptr);

    for(uint8_t n = class_ptr->property_count, i = 0; result == NULL && i < n; i++ ){
        if (properties[i].id.DefLevel == deflevel && properties[i].id.PropertyIndex == index){
            result = &properties[i];
        }
    }

    return result;
}

struct ocac_class_event * ocac_class_get_event(OCAC_CLASS_BASE * class_ptr, u16_t deflevel, u16_t index )
{
    OCAC_ASSERT("class_ptr != NULL", class_ptr != NULL);
    OCAC_ASSERT("deflevel > 0", deflevel > 0);
    OCAC_ASSERT("event defined by child", class_ptr->class_identification.ClassID.FieldCount >= deflevel);

    #ifdef OCAC_CLASS_NO_EVENT_OVERRIDE
    while (class_ptr->class_identification.ClassID.FieldCount > deflevel){
        OCAC_ASSERT("", class_ptr->class_identification.ClassID.FieldCount > 0);
        class_ptr = class_ptr->parent;
    }
    #endif

    struct ocac_class_event * result = NULL;
    struct ocac_class_event * events = OCAC_CLASS_EVENTS(class_ptr);

    for(uint8_t n = class_ptr->event_count, i = 0; result == NULL && i < n; i++ ){
        if (events[i].id.DefLevel == deflevel && events[i].id.EventIndex == index){
            result = &events[i];
        }
    }

    return result;
}

#ifdef DEBUG

void ocac_dump_class_id(OCAC_CLASS_BASE * class_ptr)
{

    printf(" OcaClassID = %d", class_ptr->class_identification.ClassID.Fields[0]);
    for(int i = 1; i < class_ptr->class_identification.ClassID.FieldCount; i++){
        printf(" %d", class_ptr->class_identification.ClassID.Fields[i]);
    }
    printf(" (v%d)\n", class_ptr->class_identification.ClassVersion);
}

void ocac_dump_class(OCAC_CLASS_BASE * class_ptr){
    printf("ocac_class @ %p\n", class_ptr);

    ocac_dump_class_id(class_ptr);

//    printf(" ClassVersion = %d\n", class_ptr->class_identification.ClassVersion);


    printf( " parent = %p\n", class_ptr->parent);

    struct ocac_class_property * properties = OCAC_CLASS_PROPERTIES(class_ptr);
    printf(" properties (%d) @ %p\n", class_ptr->property_count, properties);
    for(int i = 0; i < class_ptr->property_count; i++){
        printf("  %02dp%02d\n", properties[i].id.DefLevel, properties[i].id.PropertyIndex);
    }


    struct ocac_class_method * methods = OCAC_CLASS_METHODS(class_ptr);
    printf(" methods (%d) @ %p\n", class_ptr->method_count, properties);
    for(int i = 0; i < class_ptr->method_count; i++){
        printf("  %02dm%02d\n", methods[i].id.DefLevel, methods[i].id.MethodIndex);
    }


    struct ocac_class_event * events = OCAC_CLASS_EVENTS(class_ptr);
    printf(" events (%d) @ %p\n", class_ptr->event_count, properties);
    for(int i = 0; i < class_ptr->event_count; i++){
        printf("  %02de%02d\n", events[i].id.DefLevel, events[i].id.EventIndex);
    }
}

#endif // DEBUG