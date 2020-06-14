//
// Created by Philip Tschiemer on 13.06.20.
//

#ifndef OCAC_OPT_H
#define OCAC_OPT_H


#define OCAC_CLASS_DEFINITION_CUSTOM    0
#define OCAC_CLASS_DEFINITION_MIN       1
#define OCAC_CLASS_DEFINITION_MAX       2

/*
 * Include user defined options first. Anything not defined in these files
 * will be set to standard values. Override anything you don't like!
 */
#include "ocacopts.h"
#include "ocac/debug.h"



#ifndef OCAC_OCC_MANAGEMENT_MODEL_MANUFACTURER_MAXLEN
#define OCAC_OCC_MANAGEMENT_MODEL_MANUFACTURER_MAXLEN 32
#endif

#ifndef OCAC_OCC_MANAGEMENT_MODEL_NAME_MAXLEN
#define OCAC_OCC_MANAGEMENT_MODEL_NAME_MAXLEN 32
#endif

#ifndef OCAC_OCC_MANAGEMENT_MODEL_VERSION_MAXLEN
#define OCAC_OCC_MANAGEMENT_MODEL_VERSION_MAXLEN 16
#endif


#ifndef OCAC_OCC_NETWORK_HOSTID_MAXLEN
#define OCAC_OCC_NETWORK_HOSTID_MAXLEN 128
#endif

#ifndef OCAC_OCC_NETWORK_NODEID_MAXLEN
#define OCAC_OCC_NETWORK_NODEID_MAXLEN 128
#endif

#ifndef OCAC_OCC_NETWORK_ADDR_MAXLEN
#define OCAC_OCC_NETWORK_ADDR_MAXLEN 128
#endif

#ifndef OCAC_OCC_NETWORK_STREAMID_MAXLEN
#define OCAC_OCC_NETWORK_STREAMID_MAXLEN 128
#endif

#ifndef OCAC_OCC_NETWORK_STREAMPARAM_MAXLEN
#define OCAC_OCC_NETWORK_STREAMPARAM_MAXLEN 128
#endif

#ifndef OCAC_OCC_NETWORK_STREAMCONNID_MAXLEN
#define OCAC_OCC_NETWORK_STREAMCONNID_MAXLEN 128
#endif


//#define OCAC_CLASS_NO_METHOD_OVERRIDE


/**
 * If set does not define the standard class types in which case YOU MUST DO THIS YOURSELF.
 */
//#define OCAC_CLASS_NO_DEFAULT_DEFINITION

/**
 * If set does allocate/define the default class objects in which case YOU MUST DO THIS YOURSELF.
 */
//#define OCAC_CLASS_NO_DEFAULT_ALLOCATION

/**
 * If set inherited methods CANNOT be overriden and are only located in the original class.
 * If not set, child classes must include any methods even if they have been previously defined.
 */
//#define OCAC_CLASS_NO_METHOD_OVERRIDE

/**
 * If set does not define the standard object types in which case YOU MUST DO THIS YOURSELF.
 */
//#define OCAC_OBJ_NO_DEFAULT_DEFINITION

/**
 * If set does not allocate/define the standard class instance objects in which case YOU MUST DO THIS YOURSELF.
 */
//#define OCAC_OBJ_NO_DEFAULT_ALLOCATION


#ifndef OCAC_CLASS_DEFINITION
#define OCAC_CLASS_DEFINITION OCAC_CLASS_DEFINITION_MAX
#elif OCAC_CLASS_DEFINITION != OCAC_CLASS_DEFINITION_CUSTOM && OCAC_CLASS_DEFINITION != OCAC_CLASS_DEFINITION_MIN && OCAC_CLASS_DEFINITION != OCAC_CLASS_DEFINITION_MAX
#error Invalid setting for OCAC_CLASS_DEFINITION
#endif


#ifndef OCAC_CLASS_NAME
#define OCAC_CLASS_NAME(name)  name ## _class
#endif

#ifndef OCAC_OBJ_NAME
#define OCAC_OBJ_NAME(name) name ## _obj
#endif



#ifndef OCAC_OBJ_ROOT_ROLE_MAXLEN
#define OCAC_OBJ_ROOT_ROLE_MAXLEN 10
#endif

#ifndef OCAC_OBJ_ROOT_DEF_CUSTOM
#define OCAC_OBJ_ROOT_DEF_CUSTOM
#endif

/**
 * Root class instance attributes
 * eg. you can define __attribute__((section ("asdfasdf")))
 */
#ifndef OCAC_CLASS_ROOT_ATTRIBUTE
#define OCAC_CLASS_ROOT_ATTRIBUTE
#endif

#ifndef OCAC_OBJ_MANAGER_DEF_CUSTOM
#define OCAC_OBJ_MANAGER_DEF_CUSTOM
#endif

#ifndef OCAC_OBJ_MANAGER_NAME_MAXLEN
#define OCAC_OBJ_MANAGER_NAME_MAXLEN 20
#endif


#ifndef OCAC_OBJ_DEVICEMANAGER_DEF_CUSTOM
#define OCAC_OBJ_DEVICEMANAGER_DEF_CUSTOM
#endif

#ifndef OCAC_OBJ_DEVICEMANAGER_DEVICENAME_MAXLEN
#define OCAC_OBJ_DEVICEMANAGER_DEVICENAME_MAXLEN 32
#endif

#ifndef OCAC_OBJ_DEVICEMANAGER_INVENTORYCODE_MAXLEN
#define OCAC_OBJ_DEVICEMANAGER_INVENTORYCODE_MAXLEN 32
#endif
#ifndef OCAC_DEVICE_INVENTORYCODE_DEFAULT
#define OCAC_DEVICE_INVENTORYCODE_DEFAULT {0, ""}
#endif

#ifndef OCAC_OBJ_DEVICEMANAGER_MSG_MAXLEN
#define OCAC_OBJ_DEVICEMANAGER_MSG_MAXLEN 128
#endif
#ifndef OCAC_DEVICE_MESSAGE_DEFAULT
#define OCAC_DEVICE_MESSAGE_DEFAULT {8, "ILOVEYOU"}
#endif


#endif //OCAC_OPT_H
