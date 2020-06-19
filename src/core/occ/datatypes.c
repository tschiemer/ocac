//
// Created by Philip Tschiemer on 13.06.20.
//

#include <ocac/occ/datatypes/base.h>
#include "ocac/occ/datatypes/base.h"
#include "ocac/utf8.h"

#ifdef DEBUG


void ocac_dump_string( OcaString * str )
{
    s32_t bytes = ocac_utf8_bytelen( str->Value, str->Len, 0 );

    if (bytes > 0) {
        for (int i = 0; i < bytes; i++) {
            printf("%c", str->Value[i]);
        }
    }

    printf(" (Len=%d, bytes=%d)", str->Len, bytes);
}

void ocac_dump_blob( OcaBlob * blob )
{
    printf("OcaBlob (Len=%d)", blob->DataSize);

    if (blob->DataSize > 0){
        for(int i = 0; i < blob->DataSize; i++){
            printf(" %02X", blob->Data[i]);
        }
    }
}

void ocac_dump_blobfixedlen( u8_t * blob, u16_t len )
{
    printf("OcaBlobFixedLen%zu", len);

    if (len == 0){
        printf("\n");
        return;
    }

    printf("%02X", blob[0]);
    for(int i = 1; i < len; i++){
        printf(" %02X", blob[i]);
    }
}

#endif