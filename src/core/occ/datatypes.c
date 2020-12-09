/**
 * MIT License
 *
 * Copyright (c) 2020 Philip Tschiemer, https://github.com/tschiemer/ocac
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

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
    printf("OcaBlobFixedLen%hu", len);

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