//
// Created by Philip Tschiemer on 19.06.20.
//

#ifndef OCAC_UTF8_H
#define OCAC_UTF8_H

#include "ocac/arch.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCAC_UTF8_INVALID   (-1)
#define OCAC_UTF8_TOO_LONG  (-2)

#define OCAC_UTF8_VALID_BYTE1( b )   ( ( (b) & 0b11000000) != 0b10000000 )

#define OCAC_UTF8_LEN_ONE( b )       ( ( (b) & 0b10000000) == 0 )
#define OCAC_UTF8_LEN_TWO( b )       ( ( (b) & 0b11100000) == 0b11000000 )
#define OCAC_UTF8_LEN_THREE( b )     ( ( (b) & 0b11110000) == 0b11100000 )
#define OCAC_UTF8_LEN_FOUR( b )      ( ( (b) & 0b11111000) == 0b11110000 )


/**
 * Simple utf8 string validation and byte length computation
 * On success, returns number of required bytes, otherwise error code (OCAC_UTF8_INVALID or OCAC_UTF8_TOO_LONG)
 */
s32_t ocac_utf8_bytelen(const u8_t * str, u16_t nchars, u16_t maxbytes);


/**
 * Copies n UTF-8 characters (which can be more than n bytes)
 * On success, returns number of copied bytes, otherwise error code (OCAC_UTF8_INVALID or OCAC_UTF8_TOO_LONG)
 */
s32_t ocac_utr8_cpyn(u8_t * dst, const u8_t * src, u16_t nchars, u16_t maxbytes);


#ifdef __cplusplus
}
#endif

#endif //OCAC_UTF8_H
