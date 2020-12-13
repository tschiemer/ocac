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

#ifndef OCAC_IMPL_OCCCLASSES_SHARED_H
#define OCAC_IMPL_OCCCLASSES_SHARED_H


#include "ocac/arch.h"
#include "ocac/session.h"

// for memcpy (tmp)
//#include <string.h>


#ifdef __cplusplus
extern "C" {
#endif

//#define OCAC_ASSERT_HAS_REQUEST \
//    OCAC_ASSERT("req != NULL", req != NULL); \
//    OCAC_ASSERT("reqlen > 0", reqlen > 0);
//
//#define OCAC_ASSERT_HAS_RESPONSE \
//    OCAC_ASSERT("rsp != NULL", rsp != NULL); \
//    OCAC_ASSERT("rsplen != NULL", rsplen != NULL);

//OCAC_ASSERT("reqlen > 0", reqlen > 0); \

#define OCAC_METHOD_ASSERT_PARAMS \
    OCAC_ASSERT("obj != NULL", obj != NULL); \
    OCAC_ASSERT("req != NULL", req != NULL); \
    OCAC_ASSERT("rsp != NULL", rsp != NULL); \
    OCAC_ASSERT("rsplen != NULL", rsplen != NULL); \
    OCAC_ASSERT("session != NULL", session != NULL);


//#define OCAC_CLASS_METHOD(__method__) OcaStatus __method__(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)

#ifdef __cplusplus
}
#endif

#endif //OCAC_IMPL_OCCCLASSES_SHARED_H
