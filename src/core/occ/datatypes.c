//
// Created by Philip Tschiemer on 13.06.20.
//

#include <ocac/occ/datatypes/base.h>
#include "ocac/occ/datatypes/base.h"

#ifdef DEBUG


void ocac_dump_string( OcaString * string )
{
    printf("OcaString (Len=%d)", string->Len);

    if (string->Len == 0){
        printf("\n");
        return;
    }

    for(int i = 0; i < string->Len; i++){
        printf("%c", string->Value[i]);
    }
    printf("\n");
}

void ocac_dump_blob( OcaBlob * blob )
{
    printf("OcaBlob (Len=%d)", blob->DataSize);

    if (blob->DataSize == 0){
        printf("\n");
        return;
    }

    for(int i = 0; i < blob->DataSize; i++){
        printf(" %02X", blob->Data[i]);
    }
    printf("\n");
}

void ocac_dump_blobfixedlen( u8_t * blob, size_t len )
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
    printf("\n");
}

#endif