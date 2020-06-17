//
// Created by Philip Tschiemer on 13.06.20.
//

#include "occclasses/root.h"
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


OcaStatus ocac_m_root_getClassIdentification(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
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

OcaStatus ocac_m_root_getLockable(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
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

    *rsp = ((OCAC_OBJ_TYPE(OcaRoot)*)obj)->lockable;
    *rsplen = 1;

    return OcaStatus_OK;
}

OcaStatus ocac_m_root_lock(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
    OCAC_ASSERT("obj != NULL", obj != NULL);
    OCAC_ASSERT("reqlen != 0", reqlen == 0);
    OCAC_ASSERT("rsp != NULL", rsp != NULL);
    OCAC_ASSERT("rsplen != NULL", rsplen != NULL);

    OCAC_ASSERT("Root.lock() not implemented", 0);

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_root_unlock(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
    OCAC_ASSERT("obj != NULL", obj != NULL);
    OCAC_ASSERT("req == NULL", req == NULL);
    OCAC_ASSERT("reqlen != 0", reqlen == 0);
    OCAC_ASSERT("rsp != NULL", rsp != NULL);
    OCAC_ASSERT("rsplen != NULL", rsplen != NULL);

    OCAC_ASSERT("Root.unlock() not implemented", 0);

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_root_getRole(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen)
{
    OCAC_ASSERT("obj != NULL", obj != NULL);
    OCAC_ASSERT("req == NULL", req == NULL);
    OCAC_ASSERT("reqlen != 0", reqlen == 0);
    OCAC_ASSERT("rsp != NULL", rsp != NULL);
    OCAC_ASSERT("rsplen != NULL", rsplen != NULL);

    OcaString * role = (OcaString*) &((OCAC_OBJ_TYPE(OcaRoot)*)obj)->role;

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

#ifdef DEBUG
void ocac_dump_root(OCAC_OBJ_BASE * obj)
{
    #if OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_CUSTOM
    OCAC_ASSERT("Please define your own class dumper", 0);
    #endif

    OCAC_OBJ_TYPE(OcaRoot) * root_obj = OCAC_OBJ_CAST(OcaRoot,obj);
    OCAC_CLASS_TYPE(OcaRoot) * root_class = OCAC_CLASS_CAST(OcaRoot, root_obj->class_ptr);

    #if OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MAX
    printf(" Role (%d) = ", root_obj->role.Len);
    for(u16_t i = 0; i < root_obj->role.Len; i++){
        printf("%c", root_obj->role.Value[i]);
    }
    printf("\n");
    #endif

    #if OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MIN || OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MAX
    printf(" Lockable = %d\n", root_obj->lockable);
    #endif
}
#endif