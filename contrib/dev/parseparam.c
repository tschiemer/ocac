//
// Created by Philip Tschiemer on 20.06.20.
//

#include <string.h>
#include "ocac/utf8.h"

u16_t rawpos = 0;
u16_t rawlen = 0;
u8_t raw[1024];

void parse(char * type){

    u8_t tmp[1024];

    if (strcmp(type, "string") == 0)
    {
        u16_t len = ntohs(*(u16_t*)&raw[rawpos]);
        s32_t bytes = ocac_utf8_cpyn(tmp, &raw[rawpos+2], len, sizeof(tmp));

        if (bytes < 0){
            fprintf(stderr, "ERROR tmp buffer too small..\n");
            exit(EXIT_FAILURE);
        }

        tmp[bytes] = '\0';

        printf("string %s\n", tmp);

        rawpos += 2 + bytes;
    }

    if (strcmp(type, "bool") == 0)
    {
        printf("bool %d\n", raw[rawpos]);

        rawpos += 1;
    }
}

int main(int argc, char * argv[]){

    if (argc < 2){
        printf("Usage: %s <oca-type1> ...\n",argv[0]);
        printf("Reads from STDIN given types in HEX format\n");
        return EXIT_SUCCESS;
    }

    while (!feof(stdin)){
        scanf("%02hX", &raw[rawlen++]);
    }

    for (int i = 1; i < argc; i++){
        parse(argv[i]);
    }
}