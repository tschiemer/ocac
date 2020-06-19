//
// Created by Philip Tschiemer on 13.06.20.
//

#include <ocac/occ/datatypes/base.h>
#include "occclasses/root.h"
#include "ocac/utf8.h"
#include "ocac/def.h"


OCAC_CLASS_TYPE(OcaRoot) OCAC_CLASS_NAME(OcaRoot) = {

    .class_identification = {
        .ClassID = OCAC_CLASS_ROOT_ID,
        .ClassVersion = OCAC_CLASS_ROOT_VERSION
    },

    .parent = NULL,

    .method_count = OCAC_CLASS_ROOT_NMETHODS,
    .methods = {
        OCAC_CLASS_ROOT_01mXX
    },

    #ifndef OCAC_NO_PROPERTIES
    .property_count = OCAC_CLASS_ROOT_NPROPERTIES,
    .properties = {
        OCAC_CLASS_ROOT_01pXX
    },
    #endif

    #ifndef OCAC_NO_EVENTS
    .event_count = OCAC_CLASS_ROOT_NEVENTS,
    .events = {
        OCAC_CLASS_ROOT_01eXX
    },
    #endif

    #if DEBUG
    .dump = ocac_dump_root
    #endif

} OCAC_CLASS_ROOT_ATTRIBUTES;


OcaStatus ocac_m_root_getClassIdentification(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    const OcaClassIdentification * ci = &obj->class_ptr->class_identification;

    const u16_t size = sizeof(OcaUint16) * (2 + ci->ClassID.FieldCount);

    if (0 < maxrsplen && maxrsplen < size ){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16 *)rsp = ocac_htons(ci->ClassID.FieldCount);
    rsp += sizeof(OcaUint16);

    for (OcaUint16 i = 0; i < ci->ClassID.FieldCount; i++){
        *(OcaUint16 *)rsp = ocac_htons(ci->ClassID.Fields[i]);
        rsp += sizeof(OcaUint16);
    }

    *(OcaUint16 *)rsp = ocac_htons(ci->ClassVersion);

    *rsplen = size;

    return OcaStatus_OK;
}

OcaStatus ocac_m_root_getLockable(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    // obviously never true...
//    if (0 < maxrsplen && maxrsplen < 1){
//        return OcaStatus_BufferOverflow;
//    }

    #ifdef OCAC_USE_LOCKS
    *rsp = ((OCAC_OBJ_TYPE(OcaRoot)*)obj)->lockable;
    #else
    *rsp = false;
    #endif
    *rsplen = 1;

    return OcaStatus_OK;
}

OcaStatus ocac_m_root_lock(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_USE_LOCKS
    OCAC_ASSERT("Root.lock() not implemented", 0);

    return OcaStatus_NotImplemented;
    #else
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_root_unlock(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_USE_LOCKS
    OCAC_ASSERT("Root.unlock() not implemented", 0);

    return OcaStatus_NotImplemented;
    #else
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_root_getRole(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_ROOT_DEF_ROLE_USE
    if (0 < maxrsplen && maxrsplen < sizeof(OcaUint16)){
        return OcaStatus_BufferOverflow;
    }

    u32_t bytes = ocac_utf8_cpyn( &rsp[2], OCAC_OBJ_CAST(OcaRoot,obj)->role.Value, OCAC_OBJ_CAST(OcaRoot,obj)->role.Len, maxrsplen - sizeof(OcaUint16) );

    // should never occur (internal state should always be valid)
    OCAC_ASSERT("bytes != OCAC_UTF8_INVALID", bytes != OCAC_UTF8_INVALID);

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16 *)rsp = ocac_htons(OCAC_OBJ_CAST(OcaRoot,obj)->role.Len);

    *rsplen = sizeof(OcaUint16) + bytes;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

#ifdef DEBUG
void ocac_dump_root(OCAC_OBJ_BASE * obj)
{
    OCAC_OBJ_TYPE(OcaRoot) * root_obj = OCAC_OBJ_CAST(OcaRoot,obj);
    OCAC_CLASS_TYPE(OcaRoot) * root_class = OCAC_CLASS_CAST(OcaRoot, root_obj->class_ptr);

    #ifdef OCAC_OBJ_ROOT_DEF_ROLE_USE
    printf(" Role = ");
    ocac_dump_string((OcaString*)&root_obj->role);
    printf("\n");
    #endif

    #ifdef OCAC_OBJ_ROOT_DEF_LOCKABLE_USE
    printf(" Lockable = %d\n", root_obj->lockable);
    #endif
}
#endif