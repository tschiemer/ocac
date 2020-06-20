//
// Created by Philip Tschiemer on 11.06.20.
//

#include <stdio.h>
#include <ocac/occ/datatypes/framework.h>
#include <ocac/utf8.h>
#include <assert.h>
#include <ocac/def.h>

#include "occclasses/root.h"
#include "occclasses/managers/device.h"

#include "obj_registry.h"



int main(int argc, char * argv[]){

    if (argc < 2){
        printf("Usage: %s <ono> <deflevel> <methodindex> [<params (hex)>]\n", argv[0]);
        printf("If no <params (hex)> are given reads hex from STDIN until EOF\n");
        printf("Output: <status> <result-len> [<result (hex)>]\n");
        return EXIT_SUCCESS;
    }

    OcaONo ono = atoi(argv[1]);

    OCAC_OBJ_BASE * obj = ocac_obj_registry_get_by_id(ono);

    if (obj == NULL){
        fprintf(stderr,"ERROR No object with ONo %u\n", ono);
        exit(EXIT_FAILURE);
    }

    OcaMethodID method;

    method.DefLevel = atoi(argv[2]);
    method.MethodIndex = atoi(argv[3]);

    u8_t request[1024];
    u16_t request_len = 0;

    if (argc > 4){
        if (strcmp(argv[4], "-") == 0){
            // no arg passing
        } else {
            request_len = strlen(argv[4]);

            if (request_len % 2 == 1){
                fprintf(stderr, "ERROR <params (hex)> must be a multiple of 2 (whole octets..)\n");
                exit(EXIT_FAILURE);
            }

            if (request_len / 2 > sizeof(request)){
                fprintf(stderr, "ERROR <params (hex)> longer than expected (%lu bytes)\n", sizeof(request));
                exit(EXIT_FAILURE);
            }

            for(int i = 0, j = 0; i < request_len; i += 2, j++){
                sscanf(&argv[4][i],"%02hhX", &request[j]);
            }
            request_len /= 2;

        }
    } else {
        for (int c = getc(stdin); request_len < sizeof(request) && !feof(stdin); c = getc(stdin), request_len++){
            if (feof(stdin)){
                fprintf(stderr, "ERROR incomplete hex from STDIN\n");
                exit(EXIT_FAILURE);
            }
            int c2 = getc(stdin);
            char str[3] = {c, c2, 0};

            sscanf(str, "%02hhX", &request[request_len]);
        }
    }

    u8_t response[1024];
    u16_t response_len = 0;

    struct ocac_session session;

    OcaStatus status = ocac_obj_exec( obj, method.DefLevel, method.MethodIndex, request, request_len, response, &response_len, sizeof(response), &session );

//    printf("%d %d", status, response_len);

    if (response_len > 0){
//        printf(" ");
        for( int i = 0; i < response_len; i++){
            printf("%02X", response[i] );
        }
//        printf("\n");
    }


    return status;

//    return 0;

    if (status == OcaStatus_OK){
//        ocac_dump_obj((OCAC_OBJ_BASE*)&OCAC_OBJ_NAME(OcaDeviceManager));

        // Root

        if (OCAC_IS_METHOD(method, OCAC__Root_DefLevel, OCAC__Root_m_getClassIdentification)){

        }

        if (OCAC_IS_METHOD(method, OCAC__Root_DefLevel, OCAC__Root_m_getLockable)){

        }

        if (OCAC_IS_METHOD(method, OCAC__Root_DefLevel, OCAC__Root_m_lock)){

        }

        if (OCAC_IS_METHOD(method, OCAC__Root_DefLevel, OCAC__Root_m_unlock)){

        }

        if (OCAC_IS_METHOD(method, OCAC__Root_DefLevel, OCAC__Root_m_getRole)){
            OcaUint16 len = ntohs(*(OcaUint16*)response);
            response[response_len] = '\0';
            printf("Role = %s (%d)\n", &response[2], len);
        }

        // DeviceManager

        if (OCAC_IS_METHOD(method, OCAC__DeviceManager_DefLevel, OCAC__DeviceManager_m_getDeviceName) ){
            OcaUint16 len = ntohs(*(OcaUint16*)response);
            response[response_len] = '\0';
            printf("Device Name = %s (%d)\n", &response[2], len);
        }
        if (OCAC_IS_METHOD(method, OCAC__DeviceManager_DefLevel, OCAC__DeviceManager_m_getRole) ){
            OcaUint16 len = ntohs(*(OcaUint16*)response);
            response[response_len] = '\0';
            printf("Role = %s (%d)\n", &response[2], len);
        }
        if (OCAC_IS_METHOD(method, OCAC__DeviceManager_DefLevel, OCAC__DeviceManager_m_getSerialNumber) ){
            OcaUint16 len = ntohs(*(OcaUint16*)response);
            response[response_len] = '\0';
            printf("Serial = %s (%d)\n", &response[2], len);
        }
        if (OCAC_IS_METHOD(method, OCAC__DeviceManager_DefLevel, OCAC__DeviceManager_m_getUserInventoryCode) ){
            OcaUint16 len = ntohs(*(OcaUint16*)response);
            response[response_len] = '\0';
            printf("User Inventory Code = %s (%d)\n", &response[2], len);
        }
        if (OCAC_IS_METHOD(method, OCAC__DeviceManager_DefLevel, OCAC__DeviceManager_m_getMessage) ){
            OcaUint16 len = ntohs(*(OcaUint16*)response);
            response[response_len] = '\0';
            printf("Message = %s (%d)\n", &response[2], len);
        }
        if (OCAC_IS_METHOD(method, OCAC__DeviceManager_DefLevel, OCAC__DeviceManager_m_getRevisionID)){
            OcaUint16 len = ntohs(*(OcaUint16*)response);
            response[response_len] = '\0';
            printf("RevisionID = %s (%d)\n", &response[2], len);
        }


        if (OCAC_IS_METHOD(method, OCAC__DeviceManager_DefLevel, OCAC__DeviceManager_m_getModelDescription) ){
            OcaUint16 len;
            char str[100];
            u32_t bytes1, bytes2, bytes3;

            len = ntohs(*(OcaUint16*)response);
            bytes1 = ocac_utf8_cpyn((u8_t *)str, &response[sizeof(OcaUint16)], len, sizeof(str)-1);

            OCAC_ASSERT("bytes1 >= 0",bytes1 >= 0);
            str[bytes1] = '\0';

            printf("Manufacturer = %s (len=%d,bytes=%d)\n", str, len, bytes1);

            len = ntohs(*(OcaUint16*)&response[sizeof(OcaUint16) + bytes1]);
            bytes2 = ocac_utf8_cpyn((u8_t *)str, &response[sizeof(OcaUint16) + bytes1 + sizeof(OcaUint16)], len, sizeof(str)-1);
            OCAC_ASSERT("bytes2 >= 0", bytes2 >= 0);
            str[bytes2] = '\0';

            printf("Name = %s (%d)\n", str, len);


            len = ntohs(*(OcaUint16*)&response[sizeof(OcaUint16) + bytes1 + sizeof(OcaUint16) + bytes2]);
            bytes3 = ocac_utf8_cpyn((u8_t *)str, &response[sizeof(OcaUint16) + bytes1 + sizeof(OcaUint16) + bytes2 + sizeof(OcaUint16)], len, sizeof(str)-1);
            OCAC_ASSERT("bytes3 >= 0", bytes3 >= 0);
            str[bytes3] = '\0';

            printf("Version = %s (%d)\n", str, len);


        }

        if (OCAC_IS_METHOD(method, OCAC__DeviceManager_DefLevel, OCAC__DeviceManager_m_getManagers) ){
            OcaUint16 n = ntohs(*(OcaUint16*)response);

            printf("Managers (%d):\n", n);

            u8_t * rsp = response + 2;
            for (int m = 0; m < n; m++){

                OcaONo ono = ntohl(*(OcaONo*)rsp);

                rsp += sizeof(OcaONo);

                OcaUint16 namelen = ntohs(*(OcaUint16*)rsp);

                rsp += sizeof(OcaUint16);

                char name[100];
                u32_t slen = ocac_utf8_cpyn((u8_t*)name, rsp, namelen, sizeof(name));

                OCAC_ASSERT("0 <= slen", 0 <= slen);

                name[slen] = '\0';

                printf("ONo = %u, Name = %s, ", ono, name);

                rsp += slen;


                printf("ClassID = ");

                OcaClassID classid;

                classid.FieldCount = ntohs(*(OcaUint16*)rsp);

                rsp += sizeof(OcaUint16);

                OCAC_ASSERT("classid.FieldCount != OcaClassAuthorityID_Sentinel", classid.FieldCount != OcaClassAuthorityID_Sentinel);

                for(int i = 0; i < classid.FieldCount; i++){
                    classid.Fields[i] = ntohs(*(OcaUint16*)rsp);
                    rsp += sizeof(OcaUint16);

                    printf("%hu ", classid.Fields[i]);
                }

                OcaUint16 classver = ntohs(*(OcaUint16*)rsp);

                rsp += sizeof(OcaUint16);

                printf(" (v%hu)\n", classver);

            }
        }

//        ocac_dump_obj((OCAC_OBJ_BASE*)&OCAC_OBJ_NAME(OcaDeviceManager));
    }



    return 0;
}