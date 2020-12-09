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

#ifndef OCAC_OCAC_OBJ_H
#define OCAC_OCAC_OBJ_H


#include "ocac/occ/datatypes/framework.h"
#include "ocac/class.h"
#include "ocac/session.h"
#include "ocac/opt.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Any ONo below this number are reserved for standard use
 */
#define OCAC_RESERVED_ONOS 4096


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


#define OCAC_OBJ_TYPE(name)         struct ocac_obj_ ## name
#define OCAC_OBJ_BASE               OCAC_OBJ_TYPE(base)
#define OCAC_OBJ_CAST(name,obj_ptr) ((OCAC_OBJ_TYPE(name)*)obj_ptr)
#define OCAC_OBJ_PTR(obj_ptr)       OCAC_OBJ_CAST(base, obj_ptr)

OCAC_OBJ_DEF_BEGIN(base)
OCAC_OBJ_DEF_END(base)

OcaStatus ocac_obj_exec(OCAC_OBJ_BASE * obj, u16_t deflevel, u16_t index, u8_t * argv, u16_t argvlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session);

#ifdef DEBUG

void ocac_dump_obj( OCAC_OBJ_BASE * obj );

#endif

#ifdef __cplusplus
}
#endif

#endif //OCAC_OCAC_OBJ_H
