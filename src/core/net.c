//
// Created by Philip Tschiemer on 21.06.20.
//

#include <ocac/occ/datatypes/base.h>
#include "ocac/net.h"
#include "ocac/utf8.h"



s32_t ocac_net_str2addr(struct ocac_net_addr * addr, OcaString * str)
{
    OCAC_ASSERT("str != NULL", str != NULL);
    OCAC_ASSERT("addr != NULL", addr != NULL);

    u16_t ncolons = 0;
    s32_t last = -2;
    u32_t doublecolon = -1;
    for(s32_t i = 0; i < str->Len; i++){
        if (str->Value[i] == ':'){
            if (last == i-1){
                // can not have more than one doublecolon
                if (doublecolon != -1){
                    return 999;
                }
                doublecolon = ncolons;
            }
            ncolons++;
            last = i;
        }
    }

    // if more than one colon must be ipv6
    if (ncolons > 1){
        #ifdef OCAC_USE_IPv6

        u16_t len = 0, end = str->Len, l;
        s32_t a;

        if (str->Value[0] == '['){
            len++;

            if (str->Value[end-1] != ']'){
                // assume port is given
                ncolons--;
            }
        }

        if (str->Len < len + 1) return false;
        a = ocac_atoi(&str->Value[len], str->Len - len, 16, &l);
        if (l == 0 && str->Value[len] == ':' && doublecolon == 1){
            addr->addr[0] = 0;
            addr->addr[1] = 0;
        }
        else if (l == 0 || l > 4 || (a & 0xffff0000)) return false;
        else {
            addr->addr[0] = a >> 8;
            addr->addr[1] = a & 0xff;
            len += l;
        }

        for (int i = 1; i < 8; i++){

            if (str->Len < len + 1 || str->Value[len++] != ':') return false;

            if (i == doublecolon) {
                for (int j = 0; j < 8 - ncolons && i < 8; j++, i++){
                    addr->addr[2*i] = 0;
                    addr->addr[2*i+1] = 0;
                }
                if (str->Len <= len + 1 || str->Value[len+1] == ']') {
                    addr->addr[14] = 0;
                    addr->addr[15] = 0;
                    if (str->Len >= len + 2){

                        len++;
                    }
                } else {
                    i--;
                }
                continue;
            }

            a = ocac_atoi(&str->Value[len], str->Len - len, 16, &l);
            if (l == 0 || l > 4 || (a & 0xffff0000)) return false;
            addr->addr[2*i] = a >> 8;
            addr->addr[2*i+1] = a & 0xff;
            len += l;
        }

        if (str->Value[0] != '[' || (str->Len == len + 1 && str->Value[len] == ']')) {
            addr->port = 0;
        } else {
            if (str->Len < len + 3 || str->Value[len] != ']' || str->Value[len+1] != ':'){
                return false;
            }
            a = ocac_atoi(&str->Value[len+2], str->Len - len - 1, 10, &l);
            if (l == 0 || str->Len != len + 2 + l || (a & 0xffff0000)){
                return false;
            }
            addr->port = a;
            if (str->Len != len + 2 + l){
                return false;
            }
        }

        addr->ipver = ocac_net_ipver_6;

        #else

        return false;

        #endif
    } else {
        u16_t len = 0, l;
        s32_t a;

        a = ocac_atoi(&str->Value[0], str->Len, 10, &l);
        if (l == 0 || l > 3 || (a & 0xff000000)) return false;
        addr->addr[0] = a;
        len = l;

        for (int i = 1; i < 4; i++) {
            if (str->Len < len + 1 || str->Value[len++] != '.') return false;
            a = ocac_atoi(&str->Value[len], str->Len - len, 10, &l);
            if (l == 0 || l > 3 || (a & 0xff000000)) return false;
            addr->addr[i] = a;
            len += l;
        }

        if (len == str->Len){
            addr->port = 0;
        } else if (str->Len < len + 2 || str->Value[len] != ':') {
            return false;
        } else {
            a = ocac_atoi(&str->Value[len+1], str->Len - len - 1, 10, &l);
            if (l == 0 || str->Len != len + 1 + l || (a & 0xffff0000)){
                return false;
            }
            addr->port = a;
        }

        addr->ipver = ocac_net_ipver_4;
    }

    return true;
}

s32_t ocac_net_addr2str(OcaString * str, struct ocac_net_addr * addr)
{
    OCAC_ASSERT("str != NULL", str != NULL);
    OCAC_ASSERT("addr != NULL", addr != NULL);

    #ifdef OCAC_USE_IPv6
    OCAC_ASSERT("addr->ipver == ocac_net_ipver_4 || addr->ipver == ocac_net_ipver_6", addr->ipver == ocac_net_ipver_4 || addr->ipver == ocac_net_ipver_6);
    #else
    OCAC_ASSERT("addr->ipver == ocac_net_ipver_4", addr->ipver == ocac_net_ipver_4);
    #endif

    u16_t len = 0;


    #ifdef OCAC_USE_IPv6
    if (addr->ipver == ocac_net_ipver_6){

        if (addr->port > 0){
            str->Value[len++] = '[';
        }

        u16_t val = (addr->addr[0] << 8) | (addr->addr[1]);
        len += ocac_itoa(val, &str->Value[len], 16);

        for(int i = 1; i < 8; i++){
            str->Value[len++] = ':';
            u16_t val = (addr->addr[2*i] << 8) | (addr->addr[2*i+1]);
            len += ocac_itoa(val, &str->Value[len], 16);
        }

        if (addr->port > 0){
            str->Value[len++] = ']';
            str->Value[len++] = ':';
            len += ocac_itoa(addr->port, &str->Value[len], 10);
        }

    } else {
    #endif

        len += ocac_itoa(addr->addr[0], str->Value, 10);
        str->Value[len++] = '.';
        len += ocac_itoa(addr->addr[1], &str->Value[len], 10);
        str->Value[len++] = '.';
        len += ocac_itoa(addr->addr[2], &str->Value[len], 10);
        str->Value[len++] = '.';
        len += ocac_itoa(addr->addr[3], &str->Value[len], 10);

        if (addr->port > 0) {
            str->Value[len++] = ':';
            len += ocac_itoa(addr->port, &str->Value[len], 10);
        }

    #ifdef OCAC_USE_IPv6
    }
    #endif

    str->Len = len;


    return true;
}


#ifdef DEBUG
void ocac_dump_net_addr(struct ocac_net_addr * addr)
{
    OCAC_ASSERT("addr != NULL", addr != NULL);

    printf("net_addr = ipv%d ", addr->ipver);

    if (addr->ipver == ocac_net_ipver_4){
        printf("%d.%d.%d.%d", addr->addr[0], addr->addr[1], addr->addr[2], addr->addr[3]);
        if (addr->port){
            printf(":%d", addr->port);
        }
    }
    #ifdef OCAC_USE_IPv6
    if (addr->ipver == ocac_net_ipver_6){
        u16_t i[8];
        i[0] = (addr->addr[0] << 8) | (addr->addr[1]);
        i[1] = (addr->addr[2] << 8) | (addr->addr[3]);
        i[2] = (addr->addr[4] << 8) | (addr->addr[5]);
        i[3] = (addr->addr[6] << 8) | (addr->addr[7]);
        i[4] = (addr->addr[8] << 8) | (addr->addr[9]);
        i[5] = (addr->addr[10] << 8) | (addr->addr[11]);
        i[6] = (addr->addr[12] << 8) | (addr->addr[13]);
        i[7] = (addr->addr[14] << 8) | (addr->addr[15]);

        if (addr->port){
            printf("[");
        }
        printf("%x:%x:%x:%x:%x:%x:%x:%x", i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7]);

        if (addr->port){
            printf("]:%d", addr->port);
        }
    }
    #endif
}
#endif