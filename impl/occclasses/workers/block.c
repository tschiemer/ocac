//
// Created by Philip Tschiemer on 30.11.20.
//

#include "occclasses/workers/block.h"

OCAC_CLASS_TYPE(OcaBlock) OCAC_CLASS_NAME(OcaBlock) = {

    .class_identification = {
            .ClassID = OCAC_CLASS_BLOCK_ID,
            .ClassVersion = OCAC_CLASS_BLOCK_VERSION
    },

    .parent = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaWorker),

    .method_count = OCAC_CLASS_BLOCK_NMETHODS_TOTAL,
    .methods = {
            OCAC_CLASS_BLOCK_XXmXX
    },

    #if OCAC_USE_PROPERTIES == 1
    .property_count = OCAC_CLASS_BLOCK_NPROPERTIES_TOTAL,
    .properties = {
            OCAC_CLASS_BLOCK_03pXX
    },
    #endif

    #if OCAC_USE_EVENTS == 1
    .event_count = OCAC_CLASS_BLOCK_NEVENTS_TOTAL,
    .events = {
            OCAC_CLASS_BLOCK_03eXX
    },
    #endif

    #if DEBUG
    .dump = ocac_dump_block
    #endif

} OCAC_CLASS_BLOCK_ATTRIBUTES;


OCAC_OBJ_TYPE(OcaBlock) OCAC_OBJ_NAME(OcacRootBlock) = {
    .ono = OCAC_ROOT_BLOCK_ONO,
    .class_ptr = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaBlock),

    #ifdef OCAC_OBJ_WORKER_DEF_ENABLED_USE
    .enabled = true,
    #endif

    #ifdef OCAC_OBJ_WORKER_DEF_PORTS_USE
    //TODO
    #endif

    #ifdef OCAC_OBJ_WORKER_DEF_LABEL_USE
//    .label =
    #endif

    #ifdef OCAC_OBJ_WORKER_DEF_OWNER_USE
    .owner = OCAC_ROOT_BLOCK_ONO,
    #endif

    #ifdef OCAC_OBJ_WORKER_DEF_LATENCY_USE
    .latency = 0.0,
    #endif

    #ifdef OCAC_OBJ_BLOCK_DEF_TYPE_USE
    .type = OCAC_ROOT_BLOCK_TYPE,
    #endif

    #ifdef OCAC_OBJ_BLOCK_DEF_MEMBERS_USE
    .next_sibling = NULL,
    .first_child = NULL,
    #endif

    #ifdef OCAC_OBJ_BLOCK_DEF_SIGNALPATHS_USE
    // TODO
    #endif

    #ifdef OCAC_OBJ_BLOCK_DEF_MOSTRECENTPARAMSETID_USE
    .mostRecentParamSetIdentifier = {
        .Library = 0,
        .ID = 0
    },
    #endif

    #ifdef OCAC_OBJ_BLOCK_DEF_GLOBALTYPE_USE
    .globalType = {
        .Authority = {
            .bytes = {0,0,0}
        },
        .ID = 0
    }
    #endif

    #ifdef OCAC_OBJ_BLOCK_DEF_ONOMAP_USE
    // TODO
    #endif
};

OcaStatus ocac_m_block_getType(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    #ifdef OCAC_OBJ_BLOCK_DEF_TYPE_USE

    if (*rsplen + sizeof(OcaBoolean) > maxrsplen){
        return OcaStatus_BufferOverflow;
    }

    *(OcaBoolean*)rsp = ((OCAC_OBJ_TYPE(OcaBlock)*)obj)->type;
    *rsplen = sizeof(OcaBoolean);

    return OcaStatus_OK;

    #else
    return OcaStatus_NotImplemented;
    #endif
}

OcaStatus ocac_m_block_constructMember(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_constructMemberUsingFactory(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_deleteMember(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_getMembers(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_getMembersRecursive(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_addSignalPath(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_deleteSignalPath(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_getSignalPaths(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_getSignalPathsRecursive(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_getMostRecentParamSetIdentifier(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_applyParamSet(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_getCurrentParamSetData(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_storeCurrentParamSetData(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_getGlobalType(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_getONoMap(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_findObjectsByRole(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_findObjectsByRoleRecursive(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_findObjectsByLabelRecursive(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

OcaStatus ocac_m_block_findObjectsByPath(OCAC_OBJ_BASE * obj, u8_t * req, u16_t reqlen, u8_t * rsp, u16_t * rsplen, u16_t maxrsplen, struct ocac_session * session)
{
    OCAC_METHOD_ASSERT_PARAMS

    return OcaStatus_NotImplemented;
}

/** /CLASS/OBJECT DECLARATION **/

#ifdef DEBUG
void ocac_dump_block(OCAC_OBJ_BASE * obj)
{
    ocac_dump_worker(obj);

    OCAC_OBJ_TYPE(OcaWorker) * worker_obj = OCAC_OBJ_CAST(OcaWorker,obj);

    //TODO dump properties
}
#endif
