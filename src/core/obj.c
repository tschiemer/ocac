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

#include "ocac/obj.h"

OcaStatus ocac_obj_exec(OCAC_OBJ_BASE * obj, u16_t deflevel, u16_t index, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_ASSERT("obj != NULL", obj != NULL);
    OCAC_ASSERT("obj->class_ptr != NULL", obj->class_ptr != NULL);

    struct ocac_class_method * method = ocac_class_get_method(obj->class_ptr, deflevel, index);

    if (method == NULL){
        return OcaStatus_NotImplemented;
    }

    return method->fun(obj, req, reqlen, rsp, rsplen, maxrsplen, session);
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