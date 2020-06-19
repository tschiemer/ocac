//
// Created by Philip Tschiemer on 13.06.20.
//

#include "ocac/obj.h"

OcaStatus ocac_obj_exec(OCAC_OBJ_BASE * obj, u16_t deflevel, u16_t index, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_ASSERT("obj != NULL", obj != NULL);
    OCAC_ASSERT("obj->class_ptr != NULL", obj->class_ptr != NULL);

    struct ocac_class_method * method = ocac_class_get_method(obj->class_ptr, deflevel, index);

    if (method == NULL){
        return OcaStatus_NotImplemented;
    }

    return method->fun(obj, req, reqlen, rsp, rsplen, maxrsplen, session_ref);
}

#ifdef DEBUG

void ocac_dump_obj( OCAC_OBJ_BASE * obj )
{
    OCAC_ASSERT("obj != NULL", obj != NULL);
    OCAC_ASSERT("obj->class_ptr != NULL", obj->class_ptr != NULL);

    printf("ocac_obj @ %p\n", obj);

    printf(" ONo = %d\n", obj->ono);

    ocac_dump_class_id( obj->class_ptr);

    if (obj->class_ptr->dump == NULL){
        printf("No class dumper defined!\n");
        return;
    }

    obj->class_ptr->dump(obj);
}

#endif // DEBUG