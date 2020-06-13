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

#endif /* BYTE_ORDER == LITTLE_ENDIAN */