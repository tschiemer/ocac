//
// Created by Philip Tschiemer on 19.06.20.
//

#include "ocac/utf8.h"
#include "ocac/opt.h"
#include "ocac/def.h"


s32_t ocac_utf8_bytelen(const u8_t * str, u16_t nchars, u16_t maxbytes)
{
    u16_t len = 0;

    for(u16_t c = 0, l = 0; c < nchars && len < maxbytes; c++, len += l){
        if (OCAC_UTF8_LEN_ONE(str[len])) {
            l = 1;
        } else if (OCAC_UTF8_LEN_TWO(str[len])) {
            if (OCAC_UTF8_CONTINUATION_BYTE(str[len+1]) == false){
                return OCAC_UTF8_INVALID;
            }
            l = 2;
        } else if (OCAC_UTF8_LEN_THREE(str[len])) {
            if (OCAC_UTF8_CONTINUATION_BYTE(str[len+1]) == false || OCAC_UTF8_CONTINUATION_BYTE(str[len+2]) == false){
                return OCAC_UTF8_INVALID;
            }
            l = 3;
        } else if (OCAC_UTF8_LEN_FOUR(str[len])) {
            if (OCAC_UTF8_CONTINUATION_BYTE(str[len+1]) == false || OCAC_UTF8_CONTINUATION_BYTE(str[len+2]) == false || OCAC_UTF8_CONTINUATION_BYTE(str[len+3]) == false){
                return OCAC_UTF8_INVALID;
            }
            l = 4;
        } else {
            return OCAC_UTF8_INVALID;
        }
        if (len + l >= maxbytes){
            return OCAC_UTF8_TOO_LONG;
        }
    }

    OCAC_ASSERT("len >= nchars", len >= nchars);

    return len;
}


s32_t ocac_utr8_cpyn(u8_t * dst, const u8_t * src, u16_t nchars, u16_t maxbytes)
{
    s32_t len = ocac_utf8_bytelen(src, nchars, maxbytes);

    if (len < 0) return len;

    ocac_memcpy(dst, src, len);

    return len;
}