//
// Created by Philip Tschiemer on 17.06.20.
//

#ifndef OCAC_SESSION_H
#define OCAC_SESSION_H

#include "arch.h"

#ifdef __cplusplus
extern "C" {
#endif


struct ocac_session {
    u8_t tmp;
};

typedef struct ocac_session * ocac_session_ref;

#define OCAC_SESSIONREF_ISVALID(s) (s != NULL)

#ifdef __cplusplus
}
#endif


#endif //OCAC_SESSION_H
