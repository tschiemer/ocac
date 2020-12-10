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

#include <ocac/occ/datatypes/base.h>
#include "ocac/reset.h"


struct ocac_reset_cfg ocac_reset = {
    .status = OCAC_RESET_STATUS_UNSET,
    .sentinel.bytes = OCAC_RESET_SENTINEL
};


void ocac_reset_set(OcaBlobFixedLen16 * key)
{
    ocac_memcpy(ocac_reset.key.bytes, key->bytes, sizeof(OcaBlobFixedLen16));

    ocac_reset.status = OCAC_RESET_STATUS_SET;
}

u8_t ocac_reset_check(u8_t * bytes, u16_t length)
{
    if (ocac_reset.status == OCAC_RESET_STATUS_UNSET || length != 24){
        return OCAC_RESET_NOK;
    }


    if ( ocac_memcmp(ocac_reset.sentinel.bytes, bytes, sizeof(OcaBlobFixedLen8)) != 0 ){
        return OCAC_RESET_NOK;
    }

    if ( ocac_memcmp(ocac_reset.key.bytes, &bytes[sizeof(OcaBlobFixedLen8)], sizeof(OcaBlobFixedLen16)) != 0 ){
        return OCAC_RESET_NOK;
    }

    return OCAC_RESET_OK;
}
