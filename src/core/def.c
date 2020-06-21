//
// Created by Philip Tschiemer on 13.06.20.
//

#include "ocac/def.h"


#if BYTE_ORDER == LITTLE_ENDIAN

#if !defined(ocac_htons)
/**
 * Convert an u16_t from host- to network byte order.
 *
 * @param n u16_t in host byte order
 * @return n in network byte order
 */
u16_t ocac_htons(u16_t n)
{
    return PP_HTONS(n);
}
#endif /* ocac_htons */

#if !defined(ocac_htonl)
/**
 * Convert an u32_t from host- to network byte order.
 *
 * @param n u32_t in host byte order
 * @return n in network byte order
 */
u32_t ocac_htonl(u32_t n)
{
    return PP_HTONL(n);
}
#endif /* ocac_htonl */



#ifndef ocac_memcpy
void ocac_memcpy( void * dst, const void * src, size_t count )
{
    for(size_t i = 0; i < count; i++){
        ((u8_t*)dst)[i] = ((u8_t*)src)[i];
    }
}
#endif

#ifndef ocac_memset
void* ocac_memset( void * dst, int ch, size_t count )
{
    for(size_t i = 0; i < count; i++){
        *(u8_t*)dst = (u8_t)ch;
    }
}
#endif

#ifndef ocac_memcmp
int ocac_memcmp( const void * lhs, const void * rhs, size_t count )
{
    for(size_t i = 0; i < count; i++){
        if (((u8_t*)lhs)[i] < ((u8_t*)rhs)[i]) return -1;
        if (((u8_t*)lhs)[i] > ((u8_t*)rhs)[i]) return 1;
    }
    return 0;
}
#endif

//#ifndef ocac_strcpy
//u16_t ocac_strcpy( u8_t * dst, const u8_t * src, u8_t bterminate  )
//{
//  u16_t i;
//  for(i = 0; src[i] != '\0'; i++){
//    dst[i] = src[i];
//  }
//  if (bterminate){
//    dst[i++] = '\0';
//  }
//  return i;
//}
//#endif

#endif /* BYTE_ORDER == LITTLE_ENDIAN */