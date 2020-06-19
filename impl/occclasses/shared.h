//
// Created by Philip Tschiemer on 18.06.20.
//

#ifndef OCAC_IMPL_OCCCLASSES_SHARED_H
#define OCAC_IMPL_OCCCLASSES_SHARED_H

// for memcpy (tmp)
#include <string.h>

#include "ocac/arch.h"
#include "ocac/session.h"


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

#define OCAC_METHOD_ASSERT_PARAMS \
    OCAC_ASSERT("obj != NULL", obj != NULL); \
    OCAC_ASSERT("req != NULL", req != NULL); \
    OCAC_ASSERT("reqlen > 0", reqlen > 0); \
    OCAC_ASSERT("rsp != NULL", rsp != NULL); \
    OCAC_ASSERT("rsplen != NULL", rsplen != NULL); \
    OCAC_ASSERT("OCAC_SESSIONREF_ISVALID(session_ref)", OCAC_SESSIONREF_ISVALID(session_ref));


//#define OCAC_CLASS_METHOD_DEF(method) OcaStatus method(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)

#ifdef __cplusplus
}
#endif

#endif //OCAC_IMPL_OCCCLASSES_SHARED_H
