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

#ifndef OCAC_DEF_H
#define OCAC_DEF_H

/* arch.h might define NULL already */
#include "ocac/arch.h"
#include "ocac/opt.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif


#if BYTE_ORDER == BIG_ENDIAN
#define ocac_htons(x) ((u16_t)(x))
#define ocac_ntohs(x) ((u16_t)(x))
#define ocac_htonl(x) ((u32_t)(x))
#define ocac_ntohl(x) ((u32_t)(x))
#define PP_HTONS(x)   ((u16_t)(x))
#define PP_NTOHS(x)   ((u16_t)(x))
#define PP_HTONL(x)   ((u32_t)(x))
#define PP_NTOHL(x)   ((u32_t)(x))
#else /* BYTE_ORDER != BIG_ENDIAN */
#ifndef ocac_htons
u16_t ocac_htons(u16_t x);
#endif
#define ocac_ntohs(x) ocac_htons(x)

#ifndef ocac_htonl
u32_t ocac_htonl(u32_t x);
#endif
#define ocac_ntohl(x) ocac_htonl(x)

/* These macros should be calculated by the preprocessor and are used
   with compile-time constants only (so that there is no little-endian
   overhead at runtime). */
#define PP_HTONS(x) ((u16_t)((((x) & (u16_t)0x00ffU) << 8) | (((x) & (u16_t)0xff00U) >> 8)))
#define PP_NTOHS(x) PP_HTONS(x)
#define PP_HTONL(x) ((((x) & (u32_t)0x000000ffUL) << 24) | \
                     (((x) & (u32_t)0x0000ff00UL) <<  8) | \
                     (((x) & (u32_t)0x00ff0000UL) >>  8) | \
                     (((x) & (u32_t)0xff000000UL) >> 24))
#define PP_NTOHL(x) PP_HTONL(x)
#endif /* BYTE_ORDER == BIG_ENDIAN */

/* Provide usual function names as macros for users, but this can be turned off */
//#ifndef OCAC_DONT_PROVIDE_BYTEORDER_FUNCTIONS
//#define htons(x) ocac_htons(x)
//#define ntohs(x) ocac_ntohs(x)
//#define htonl(x) ocac_htonl(x)
//#define ntohl(x) ocac_ntohl(x)
//#endif


#ifndef ocac_memcmp
int ocac_memcmp( const void * lhs, const void * rhs, size_t count );
#endif

#ifndef ocac_memset
void* ocac_memset( void * dst, int ch, size_t count );
#endif

#ifndef ocac_memcpy
void ocac_memcpy( void * dst, const void * src, size_t count );
#endif


u16_t ocac_itoa(s32_t value, u8_t * str, s32_t base);
s32_t ocac_atoi(u8_t * str, size_t len, s32_t base, u16_t * readlen);

//#ifndef ocac_strcpy
//u16_t ocac_strcpy( u8_t * dst, const u8_t * src, u8_t bterminate  );
//#endif

#ifdef __cplusplus
}
#endif

#endif //OCAC_DEF_H
