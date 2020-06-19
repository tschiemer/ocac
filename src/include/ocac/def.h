//
// Created by Philip Tschiemer on 13.06.20.
//

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


#ifndef ocac_memcpy
void ocac_memcpy( void * dst, const void * src, size_t len );
#endif

#ifdef __cplusplus
}
#endif

#endif //OCAC_DEF_H
