//
// Created by Philip Tschiemer on 19.06.20.
//

#include "occclasses/workers/worker.h"
#include "ocac/def.h"
#include "ocac/utf8.h"

OCAC_CLASS_TYPE(OcaWorker) OCAC_CLASS_NAME(OcaWorker) = {

    .class_identification = {
        .ClassID = OCAC_CLASS_WORKER_ID,
        .ClassVersion = OCAC_CLASS_WORKER_VERSION
    },

    .parent = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaRoot),

    .method_count = OCAC_CLASS_WORKER_NMETHODS_TOTAL,
    .methods = {
        OCAC_CLASS_WORKER_XXmXX
    },

    #ifndef OCAC_NO_PROPERTIES
    .property_count = OCAC_CLASS_WORKER_NPROPERTIES_TOTAL,
    .properties = {
        OCAC_CLASS_WORKER_02pXX
    },
    #endif

    #ifndef OCAC_NO_EVENTS
    .event_count = OCAC_CLASS_WORKER_NEVENTS_TOTAL,
    .events = {
        OCAC_CLASS_WORKER_02eXX
    },
    #endif

    #if DEBUG
    .dump = ocac_dump_worker
    #endif

} OCAC_CLASS_WORKER_ATTRIBUTES;


OcaStatus ocac_m_devicemanager_getEnabled(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_WORKER_DEF_ENABLED_USE

    *(OcaBoolean*)rsp = ((OCAC_OBJ_TYPE(OcaWorker)*)obj)->enabled;
    *rsplen = sizeof(OcaBoolean);

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_setEnabled(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    if (reqlen != sizeof(OcaBoolean)){
        return OcaStatus_InvalidRequest;
    }

    #ifdef OCAC_OBJ_WORKER_DEF_ENABLED_USE

    ((OCAC_OBJ_TYPE(OcaWorker)*)obj)->enabled = (*(OcaBoolean*)req) == false;
    *rsplen = 0;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_addPort(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_deletePort(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getPorts(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getPortName(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_setPortName(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_devicemanager_getLabel(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_WORKER_DEF_LABEL_USE
    if (0 < maxrsplen && maxrsplen < sizeof(OcaUint16)){
        return OcaStatus_BufferOverflow;
    }

    s32_t bytes = ocac_utf8_cpyn( &rsp[2], OCAC_OBJ_CAST(OcaWorker,obj)->label.Value, OCAC_OBJ_CAST(OcaWorker,obj)->label.Len, maxrsplen - sizeof(OcaUint16) );

    // should never occur (internal state should always be valid)
    OCAC_ASSERT("bytes != OCAC_UTF8_INVALID", bytes != OCAC_UTF8_INVALID);

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    *(OcaUint16*)rsp =  OCAC_OBJ_CAST(OcaWorker,obj)->label.Len;

    *rsplen = sizeof(OcaUint16) + bytes;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_setLabel(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_WORKER_DEF_LABEL_USE

    u16_t len = *(OcaUint16*)req;

    s32_t bytes = ocac_utf8_cpyn( OCAC_OBJ_CAST(OcaWorker,obj)->label.Value, &req[2], len, sizeof(OCAC_OBJ_CAST(OcaWorker,obj)->label.Value) );

    // should never occur (internal state should always be valid)
    if (bytes == OCAC_UTF8_INVALID){
        return OcaStatus_BadFormat;
    }

    if (bytes == OCAC_UTF8_TOO_LONG){
        return OcaStatus_BufferOverflow;
    }

    OCAC_OBJ_CAST(OcaWorker,obj)->label.Len = len;

    *rsplen = 0;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_getOwner(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_WORKER_DEF_OWNER_USE
    if (0 < maxrsplen && maxrsplen < sizeof(OcaONo)){
        return OcaStatus_BufferOverflow;
    }

    *(OcaONo*)rsp = htonl(OCAC_OBJ_CAST(OcaWorker,obj)->owner);

    *rsplen = sizeof(OcaONo);

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_getLatency(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_WORKER_DEF_LATENCY_USE
    if (0 < maxrsplen && maxrsplen < sizeof(OcaTimeInterval)){
        return OcaStatus_BufferOverflow;
    }

    *(OcaTimeInterval*)rsp = OCAC_OBJ_CAST(OcaWorker,obj)->latency;

    *rsplen = sizeof(OcaONo);

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_setLatency(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_WORKER_DEF_LATENCY_USE
    if (reqlen != sizeof(OcaTimeInterval)){
        return OcaStatus_InvalidRequest;
    }

    OCAC_OBJ_CAST(OcaWorker,obj)->latency = *(OcaTimeInterval*)req;

    *rsplen = 0;

    return OcaStatus_OK;
    #else
    OCAC_ASSERT("Not implemented", false):
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_devicemanager_getPath(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, ocac_session_ref session_ref)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}


#ifdef DEBUG
void ocac_dump_worker(OCAC_OBJ_BASE * obj){

    ocac_dump_root(obj);

    OCAC_OBJ_TYPE(OcaWorker) * worker_obj = OCAC_OBJ_CAST(OcaWorker,obj);

    #ifdef OCAC_OBJ_WORKER_DEF_ENABLED_USE
    printf(" Enabled = %d\n", worker_obj->enabled);
    #endif

    #ifdef OCAC_OBJ_WORKER_DEF_PORTS_USE
    //TODO
    #endif

    #ifdef OCAC_OBJ_WORKER_DEF_LABEL_USE
    printf(" Label = ");
    ocac_dump_string( (OcaString*)&worker_obj->label );
    printf("\n");
    #endif

    #ifdef OCAC_OBJ_WORKER_DEF_OWNER
    printf(" Owner ONo = %d\n", worker_obj->owner);
    #endif

    #ifdef OCAC_OBJ_WORKER_DEF_LATENCY
    printf(" Latency = %f\n", worker_obj->latency);
    #endif
}
#endif
