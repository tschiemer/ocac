//
// Created by Philip Tschiemer on 14.06.20.
//

#include "ocac/occ/classes/managers/manager.h"


#ifndef OCAC_CLASS_NO_DEFAULT_ALLOCATION
OCAC_CLASS_TYPE(OcaManager) OCAC_CLASS_NAME(OcaManager) = {
    .class_identification = {
            .ClassID = OCAC_CLASS_MANAGER_ID,
            .ClassVersion = OCAC_CLASS_MANAGER_VERSION
    },
    .parent = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaRoot),
    .property_count = OCAC_CLASS_MANAGER_PROPERTIES,
    .method_count = OCAC_CLASS_MANAGER_METHODS,
    .event_count = OCAC_CLASS_MANAGER_EVENTS,

#if DEBUG
    .dump = ocac_dump_manager
#endif

} OCAC_CLASS_ROOT_ATTRIBUTE;
#endif //OCAC_CLASS_NO_DEFAULT_ALLOCATION


#ifndef OCAC_OBJ_NO_DEFAULT_ALLOCATION
OCAC_OBJ_TYPE(OcaManager) OCAC_OBJ_NAME(OcaManager) = {
        .class_ptr = (OCAC_CLASS_BASE *) &OCAC_CLASS_NAME(OcaManager)
};
#endif

#ifdef DEBUG
void ocac_dump_manager(OCAC_OBJ_BASE * obj){

    ocac_dump_root(obj);

    OCAC_OBJ_TYPE(OcaManager) * manager_obj = OCAC_OBJ_CAST(OcaManager,obj);

    #if OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MIN || OCAC_CLASS_DEFINITION == OCAC_CLASS_DEFINITION_MAX
    printf(" Name = ");
    for(int i = 0; i < manager_obj->name.Len; i++){
        printf("%c", manager_obj->name.Value[i]);
    }
    printf("\n");
    #endif
}
#endif