//
// Created by Philip Tschiemer on 19.06.20.
//

#include "ocac/utf8.h"
#include "ocac/opt.h"
#include "ocac/def.h"

#ifndef ocac_utf8_bytelen
s32_t ocac_utf8_bytelen(const u8_t * str, u16_t nchars, u16_t maxbytes)
{
    u16_t len = 0;

    for(u16_t c = 0, l = 0; c < nchars && (0 == maxbytes || len < maxbytes); c++, len += l){
        if (OCAC_UTF8_LEN_ONE(str[len])) {
            // string termination can not be a character
            if (str[len] == '\0'){
                return OCAC_UTF8_INVALID;
            }
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
        if (0 < maxbytes && maxbytes < len + l){
            return OCAC_UTF8_TOO_LONG;
        }
    }

//    printf("%d %d\n", len, nchars);

    OCAC_ASSERT("nchars <= len", nchars <= len);

    return len;
}
#endif //ocac_utf8_bytelen


#ifndef ocac_utf8_cpyn
s32_t ocac_utf8_cpyn(u8_t * dst, const u8_t * src, u16_t nchars, u16_t maxbytes)
{
    s32_t len = ocac_utf8_bytelen(src, nchars, maxbytes);

    if (len < 0) {
        return len;
    }

    ocac_memcpy(dst, src, len);

    return len;
}
#endif //ocac_utf8_cpyn


#ifndef ocac_utf8_strlen
s32_t ocac_utf8_strlen(const u8_t * str, u16_t slen){

    u16_t u8chars = 0;

    for(u16_t len = 0, l = 0; len < slen; u8chars++, len += l){
        if (OCAC_UTF8_LEN_ONE(str[len])) {
            // maybe string is NUL-terminated?
            if (str[len] == '\0'){
                return u8chars;
            }
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
    }

    return u8chars;
}
#endif //ocac_utf8_strlen