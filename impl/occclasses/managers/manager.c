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



//#ifndef OCAC_OBJ_NO_DEFAULT_ALLOCATION
//OCAC_OBJ_TYPE(OcaManager) OCAC_OBJ_NAME(OcaManager) = {
//        .class_ptr = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaManager)
//};
//#endif

#ifdef DEBUG
void ocac_dump_manager(OCAC_OBJ_BASE * obj){

    ocac_dump_root(obj);

    OCAC_OBJ_TYPE(OcaManager) * manager_obj = OCAC_OBJ_CAST(OcaManager,obj);

    #if OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MIN || OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MAX
    printf(" Name = %s\n", manager_obj->name);
//    for(int i = 0; i < sizeof(manager_obj->name) && manager_obj->name[i] != '\0'; i++){
//        printf("%c", manager_obj->name[i]);
//    }
//    printf("\n");
    #endif
}
#endif