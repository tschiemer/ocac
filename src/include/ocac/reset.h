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

#ifndef OCAC_RESET_H
#define OCAC_RESET_H

#include "ocac/arch.h"
#include "ocac/session.h"
#include "ocac/net.h"

#ifdef __cplusplus
extern "C" {
#endif

// 0x DEAF DADA CAFE BABE
#define OCAC_RESET_SENTINEL     {0xDE, 0xAF, 0xDA, 0xDA, 0xCA, 0xFE, 0xBA, 0xBE}

#define OCAC_RESET_OK           0
#define OCAC_RESET_NOK          1

#define OCAC_RESET_STATUS_SET       1
#define OCAC_RESET_STATUS_UNSET     0

struct ocac_reset_cfg {
    u8_t status;
    OcaBlobFixedLen8 sentinel;
    OcaBlobFixedLen16 key;
} PACK_STRUCT_STRUCT;

extern struct ocac_reset_cfg ocac_reset;


u8_t ocac_reset_set(OcaBlobFixedLen16 * key);

u8_t ocac_reset_check(u8_t * bytes, u16_t length);

#ifdef __cplusplus
}
#endif

#endif //OCAC_RESET_H
