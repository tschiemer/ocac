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
    return dst;
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



/**
 * Inspired by v0.3 from http://www.strudel.org.uk/itoa/
 * Returns length and does not null-terminate
 */
u16_t ocac_itoa(s32_t value, u8_t * str, s32_t base)
{
    u8_t *front = str;
    u8_t * back = str;
    s32_t sign, len;

    // Validate base
    if (base < 2 || base > 35){
//        *back = '\0';
        return 0;
    }

    // Take care of sign
    if ((sign=value) < 0) {
        value = -value;
    }

    // Conversion. Number is reversed.
    do {
        *back++ = "0123456789abcdefghijklmnopqrstuvwxyz"[value % base];
    } while(value /= base);

    if(sign < 0) {
        *back ++= '-';
    }
    len = back - front;
//    *back-- = '\0';
    back--;

    // reverse
    u8_t swap;
    while( back > front) {
        swap = *back;
        *back --= *front;
        *front++ = swap;
    }

    return len;
}

s32_t ocac_atoi(u8_t * str, size_t len, s32_t base, u16_t * readlen)
{
    if (base < 2 || 35 < base){
        if (readlen != NULL){
            *readlen = 0;
        }
        return 0;
    }

    s32_t result = 0;
    s32_t sign = str[0] == '-' ? -1 : 1;
    u16_t i;

    for(i = sign == -1 ? 1 : 0; i < len; i++){
        s32_t m;
        if ('0' <= str[i] && str[i] <= '9') m = str[i] - '0';
        else if ('a' <= str[i] && str[i] <= 'z') m = str[i] - 'a' + 10;
        else if ('A' <= str[i] && str[i] <= 'Z') m = str[i] - 'A' + 10;
        else break;

        // validate
        if (m >= base){
//            *readlen = 100;
//            exit(m);
            break;
        }

        result = result * base + m;
    }

    if (readlen != NULL){
        *readlen = i;
    }

    return  sign * result;
}

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