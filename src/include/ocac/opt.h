//
// Created by Philip Tschiemer on 13.06.20.
//

#ifndef OCAC_OPT_H
#define OCAC_OPT_H


/*
 * Include user defined options first. Anything not defined in these files
 * will be set to standard values. Override anything you don't like!
 */
#include "ocacopts.h"
#include "ocac/debug.h"


#ifndef OCAC_OBJ_ROOT_ROLE_MAXLEN
#define OCAC_OBJ_ROOT_ROLE_MAXLEN 10
#endif

#ifndef OCAC_CLASS_NAME
#define OCAC_CLASS_NAME(name) ocac_occ_ ## name
#endif

#ifndef OCAC_OBJ_NAME
#define OCAC_OBJ_NAME(name) ocac_obj_ ## name
#endif

#endif //OCAC_OPT_H
