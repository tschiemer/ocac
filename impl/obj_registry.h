/**
 * MIT License
 *
 * Copyright (c) 2020 Philip Tschiemer, https://github.com/tschiemer/ocac
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef OCAC_IMPL_OBJ_REGISTRY_H
#define OCAC_IMPL_OBJ_REGISTRY_H

#include "ocac/obj.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCAC_MANAGER_COUNT (1+OCAC_USE_MANAGER_SECURITY+OCAC_USE_MANAGER_FIRMWARE+OCAC_USE_MANAGER_SUBSCRIPTION+OCAC_USE_MANAGER_POWER+OCAC_USE_MANAGER_NETWORK+OCAC_USE_MANAGER_MEDIACLOCK+OCAC_USE_MANAGER_LIBRARY+OCAC_USE_MANAGER_AUDIOPROCESSING+OCAC_USE_MANAGER_DEVICETIME+OCAC_USE_MANAGER_TASK+OCAC_USE_MANAGER_CODING+OCAC_USE_MANAGER_DIAGNOSTIC)


#define OCAC_MANAGER_DEVICE 0

#if OCAC_USE_MANAGER_SECURITY==1
#define OCAC_MANAGER_SECURITY OCAC_USE_MANAGER_SECURITY
#endif

#if OCAC_USE_MANAGER_FIRMWARE==1
#define OCAC_MANAGER_FIRMWARE (OCAC_USE_MANAGER_SECURITY+OCAC_USE_MANAGER_FIRMWARE)
#endif

#if OCAC_USE_MANAGER_SUBSCRIPTION==1
#define OCAC_MANAGER_SUBSCRIPTION (OCAC_USE_MANAGER_SECURITY+OCAC_USE_MANAGER_FIRMWARE+OCAC_USE_MANAGER_SUBSCRIPTION)
#endif

#if OCAC_USE_MANAGER_POWER==1
#define OCAC_MANAGER_POWER (OCAC_USE_MANAGER_SECURITY+OCAC_USE_MANAGER_FIRMWARE+OCAC_USE_MANAGER_SUBSCRIPTION+OCAC_USE_MANAGER_POWER)
#endif

#if OCAC_USE_MANAGER_NETWORK==1
#define OCAC_MANAGER_NETWORK (OCAC_USE_MANAGER_SECURITY+OCAC_USE_MANAGER_FIRMWARE+OCAC_USE_MANAGER_SUBSCRIPTION+OCAC_USE_MANAGER_POWER+OCAC_USE_MANAGER_NETWORK)
#endif

#if OCAC_USE_MANAGER_MEDIACLOCK==1
#define OCAC_MANAGER_MEDIACLOCK (OCAC_USE_MANAGER_SECURITY+OCAC_USE_MANAGER_FIRMWARE+OCAC_USE_MANAGER_SUBSCRIPTION+OCAC_USE_MANAGER_POWER+OCAC_USE_MANAGER_NETWORK+OCAC_USE_MANAGER_MEDIACLOCK)
#endif

#if OCAC_USE_MANAGER_LIBRARY==1
#define OCAC_MANAGER_LIBRARY (OCAC_USE_MANAGER_SECURITY+OCAC_USE_MANAGER_FIRMWARE+OCAC_USE_MANAGER_SUBSCRIPTION+OCAC_USE_MANAGER_POWER+OCAC_USE_MANAGER_NETWORK+OCAC_USE_MANAGER_MEDIACLOCK+OCAC_USE_MANAGER_LIBRARY)
#endif

#if OCAC_USE_MANAGER_AUDIOPROCESSING==1
#define OCAC_MANAGER_AUDIOPROCESSING (OCAC_USE_MANAGER_SECURITY+OCAC_USE_MANAGER_FIRMWARE+OCAC_USE_MANAGER_SUBSCRIPTION+OCAC_USE_MANAGER_POWER+OCAC_USE_MANAGER_NETWORK+OCAC_USE_MANAGER_MEDIACLOCK+OCAC_USE_MANAGER_LIBRARY+OCAC_USE_MANAGER_AUDIOPROCESSING)
#endif

#if OCAC_USE_MANAGER_DEVICETIME==1
#define OCAC_MANAGER_DEVICETIME (OCAC_USE_MANAGER_SECURITY+OCAC_USE_MANAGER_FIRMWARE+OCAC_USE_MANAGER_SUBSCRIPTION+OCAC_USE_MANAGER_POWER+OCAC_USE_MANAGER_NETWORK+OCAC_USE_MANAGER_MEDIACLOCK+OCAC_USE_MANAGER_LIBRARY+OCAC_USE_MANAGER_AUDIOPROCESSING+OCAC_USE_MANAGER_DEVICETIME)
#endif

#if OCAC_USE_MANAGER_TASK==1
#define OCAC_MANAGER_TASK (OCAC_USE_MANAGER_SECURITY+OCAC_USE_MANAGER_FIRMWARE+OCAC_USE_MANAGER_SUBSCRIPTION+OCAC_USE_MANAGER_POWER+OCAC_USE_MANAGER_NETWORK+OCAC_USE_MANAGER_MEDIACLOCK+OCAC_USE_MANAGER_LIBRARY+OCAC_USE_MANAGER_AUDIOPROCESSING+OCAC_USE_MANAGER_DEVICETIME+OCAC_USE_MANAGER_TASK)
#endif

#if OCAC_USE_MANAGER_CODING==1
#define OCAC_MANAGER_CODING (OCAC_USE_MANAGER_SECURITY+OCAC_USE_MANAGER_FIRMWARE+OCAC_USE_MANAGER_SUBSCRIPTION+OCAC_USE_MANAGER_POWER+OCAC_USE_MANAGER_NETWORK+OCAC_USE_MANAGER_MEDIACLOCK+OCAC_USE_MANAGER_LIBRARY+OCAC_USE_MANAGER_AUDIOPROCESSING+OCAC_USE_MANAGER_DEVICETIME+OCAC_USE_MANAGER_TASK+OCAC_USE_MANAGER_CODING)
#endif

#if OCAC_USE_MANAGER_DIAGNOSTIC==1
#define OCAC_MANAGER_DIAGNOSTIC (OCAC_USE_MANAGER_SECURITY+OCAC_USE_MANAGER_FIRMWARE+OCAC_USE_MANAGER_SUBSCRIPTION+OCAC_USE_MANAGER_POWER+OCAC_USE_MANAGER_NETWORK+OCAC_USE_MANAGER_MEDIACLOCK+OCAC_USE_MANAGER_LIBRARY+OCAC_USE_MANAGER_AUDIOPROCESSING+OCAC_USE_MANAGER_DEVICETIME+OCAC_USE_MANAGER_TASK+OCAC_USE_MANAGER_CODING+OCAC_USE_MANAGER_DIAGNOSTIC)
#endif

struct ocac_obj_registry_entry {
    OCAC_OBJ_BASE * obj;
    struct ocac_obj_registry_entry * next;
};


void ocac_obj_registry_init();

void ocac_obj_registry_add(OCAC_OBJ_BASE * obj);
void ocac_obj_registry_rm(OCAC_OBJ_BASE * obj);

OCAC_OBJ_BASE * ocac_obj_registry_get(OcaONo ono);


extern OCAC_OBJ_BASE * ocac_managers[OCAC_MANAGER_COUNT];



#ifdef __cplusplus
}
#endif


#endif //OCAC_IMPL_OBJ_REGISTRY_H
