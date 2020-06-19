//
// Created by Philip Tschiemer on 14.06.20.
//

#include "occclasses/managers/manager.h"



OCAC_CLASS_TYPE(OcaManager) OCAC_CLASS_NAME(OcaManager) = {

    .class_identification = {
            .ClassID = OCAC_CLASS_MANAGER_ID,
            .ClassVersion = OCAC_CLASS_MANAGER_VERSION
    },

    .parent = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaRoot),

    .method_count = OCAC_CLASS_MANAGER_NMETHODS_TOTAL,

    #ifndef OCAC_NO_PROPERTIES
    .property_count = OCAC_CLASS_MANAGER_NPROPERTIES_TOTAL,
    #endif

    #ifndef OCAC_NO_EVENTS
    .event_count = OCAC_CLASS_MANAGER_NEVENTS_TOTAL,
    #endif

    #if DEBUG
    .dump = ocac_dump_manager
    #endif

} OCAC_CLASS_MANAGER_ATTRIBUTES;



#ifdef DEBUG
void ocac_dump_manager(OCAC_OBJ_BASE * obj){

    ocac_dump_root(obj);

    OCAC_OBJ_TYPE(OcaManager) * manager_obj = OCAC_OBJ_CAST(OcaManager,obj);

    #ifdef OCAC_OBJ_MANAGER_DEF_NAME
    printf(" Manager Name = ");
    ocac_dump_string((OcaString*)&manager_obj->mngr_name);
    printf("\n");
    #endif
}
#endif