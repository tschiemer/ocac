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

#ifndef OCAC_UTF8_H
#define OCAC_UTF8_H

#include "ocac/arch.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCAC_UTF8_INVALID   (-1)
#define OCAC_UTF8_TOO_LONG  (-2)

#define OCAC_UTF8_CONTINUATION_BYTE( b )     ( ( (b) & 0b11000000) == 0b10000000 )

#define OCAC_UTF8_LEN_ONE( b )       ( ( (b) & 0b10000000) == 0 )
#define OCAC_UTF8_LEN_TWO( b )       ( ( (b) & 0b11100000) == 0b11000000 )
#define OCAC_UTF8_LEN_THREE( b )     ( ( (b) & 0b11110000) == 0b11100000 )
#define OCAC_UTF8_LEN_FOUR( b )      ( ( (b) & 0b11111000) == 0b11110000 )


#ifndef ocac_utf8_bytelen
/**
 * Simple utf8 string validation and byte length computation
 * On success, returns number of required bytes, otherwise error code (OCAC_UTF8_INVALID or OCAC_UTF8_TOO_LONG)
 */
s32_t ocac_utf8_bytelen(const u8_t * str, u16_t nchars, u16_t maxbytes);
#endif //ocac_utf8_bytelen


#ifndef ocac_utf8_cpyn
/**
 * Copies n UTF-8 characters (which can be more than n bytes)
 * On success, returns number of copied bytes, otherwise error code (OCAC_UTF8_INVALID or OCAC_UTF8_TOO_LONG)
 */
s32_t ocac_utf8_cpyn(u8_t * dst, const u8_t * src, u16_t nchars, u16_t maxbytes);
#endif //ocac_utf8_cpyn

#ifndef ocac_utf8_strlen
s32_t ocac_utf8_strlen(const u8_t * str, u16_t slen);
#endif //ocac_utf8_strlen


#ifdef __cplusplus
}
#endif

#endif //OCAC_UTF8_H
