//
// Created by Philip Tschiemer on 13.06.20.
//

#include "ocac/occ/classes/root.h"
#include "ocac/def.h"


const OCAC_CLASS_TYPE(Root) OCAC_CLASS_NAME(Root) = {
    .class_identification = {
        .ClassID = OCAC_CLASS_ROOT_ID,
        .ClassVersion = OCAC_CLASS_ROOT_VERSION
    },
    .property_count = OCAC_CLASS_ROOT_PROPERTIES,
    .method_count = OCAC_CLASS_ROOT_METHODS,
    .event_count = OCAC_CLASS_ROOT_EVENTS,
    .methods = {
        OCAC_CLASS_ROOT_01mXX
    },
    .properties = {
//        OCAC_CLASS_ROOT_01pXX
    },
    .events = {
        OCAC_CLASS_ROOT_01eXX
    }

};

OcaStatus ocac_root_getClassIdentification(OCAC_BASE_OBJ * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
    OCAC_ASSERT("obj != NULL", obj != NULL);
    OCAC_ASSERT("req == NULL", req == NULL);
    OCAC_ASSERT("reqlen != 0", reqlen == 0);
    OCAC_ASSERT("rsp != NULL", rsp != NULL);
    OCAC_ASSERT("rsplen != NULL", rsplen != NULL);

    const OcaClassIdentification * ci = &obj->class_ptr->class_identification;

    //
    u16_t size = sizeof(OcaUint16) * (2 + ci->ClassID.FieldCount);

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

OcaStatus ocac_root_getLockable(OCAC_BASE_OBJ * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
    OCAC_ASSERT("obj != NULL", obj != NULL);
    OCAC_ASSERT("req == NULL", req == NULL);
    OCAC_ASSERT("reqlen != 0", reqlen == 0);
    OCAC_ASSERT("rsp != NULL", rsp != NULL);
    OCAC_ASSERT("rsplen != NULL", rsplen != NULL);

    // obviously never true...
//    if (0 < maxrsplen && maxrsplen < 1){
//        return OcaStatus_BufferOverflow;
//    }

    *rsp = ((OCAC_OBJ_TYPE(Root)*)obj)->lockable;
    *rsplen = 1;

    return OcaStatus_OK;
}

OcaStatus ocac_root_lock(OCAC_BASE_OBJ * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
    OCAC_ASSERT("obj != NULL", obj != NULL);
    OCAC_ASSERT("reqlen != 0", reqlen == 0);
    OCAC_ASSERT("rsp != NULL", rsp != NULL);
    OCAC_ASSERT("rsplen != NULL", rsplen != NULL);

    OCAC_ASSERT("Root.lock() not implemented", 0);

    return OcaStatus_OK;
}

OcaStatus ocac_root_unlock(OCAC_BASE_OBJ * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
    OCAC_ASSERT("obj != NULL", obj != NULL);
    OCAC_ASSERT("req == NULL", req == NULL);
    OCAC_ASSERT("reqlen != 0", reqlen == 0);
    OCAC_ASSERT("rsp != NULL", rsp != NULL);
    OCAC_ASSERT("rsplen != NULL", rsplen != NULL);


    OCAC_ASSERT("Root.unlock() not implemented", 0);

    return OcaStatus_OK;
}

OcaStatus ocac_root_getRole(OCAC_BASE_OBJ * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
    OCAC_ASSERT("obj != NULL", obj != NULL);
    OCAC_ASSERT("req == NULL", req == NULL);
    OCAC_ASSERT("reqlen != 0", reqlen == 0);
    OCAC_ASSERT("rsp != NULL", rsp != NULL);
    OCAC_ASSERT("rsplen != NULL", rsplen != NULL);

    OcaString * role = (OcaString*) &((OCAC_OBJ_TYPE(Root)*)obj)->role;

    // Len (OcaUint16) + string
    u16_t size = sizeof(OcaUint16) + role->Len;

    if (0 < maxrsplen && maxrsplen < size){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16 *)rsp = ocac_htons(role->Len);
    rsp += sizeof(OcaUint16);

    for(u16_t i = 0; i < role->Len; i++, rsp++){
        *rsp = role->Value[i];
    }

    *rsplen = size;

    return OcaStatus_OK;
}