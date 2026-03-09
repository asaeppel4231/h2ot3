#include "_internal.h"

#include "helpers/helpers.h"

#include "merrno.h"

#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#if INTERNAL_DEBUG == 1
#include <stdio.h>
#endif

size_t         _internal_secure_strlen(char* string, size_t max_len){
    #if INTERNAL_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_secure_strlen")
    LOG_PARAMETER("1st", "char*", TCA, "%p\n", string);
    LOG_DEBUG("and data %s\n", string);
    LOG_PARAMETER("2nd", "size_t", TCV, "%zu\n", max_len);
    #endif
    size_t i = 0;
    while(string[i] != '\0' && i < max_len){
        i++;
    }
    #if INTERNAL_DEBUG == 1
    LOG_RETURN("size_t", TCV, "%zu\n", i);
    printf("\n");
    #endif
    return i;
}

char*           _internal_deep_copy(char* string, size_t max_len){
    #if INTERNAL_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_deep_copy")
    LOG_PARAMETER("1st", "char*", TCA, "%p\n", string);
    LOG_DEBUG("and data %s\n", string);
    LOG_PARAMETER("2nd", "size_t", TCV, "%zu\n", max_len);
    printf("\n");
    #endif
    size_t size_string = _internal_secure_strlen(string, max_len);
    char* string_copy = malloc( (sizeof(char) * \
                        size_string) + \
                        1*sizeof(char) /*for the \0 byte*/ \
    );
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(string_copy != NULL, MERRNO_EC_ISNULL, NULL);
    memcpy(string_copy, string, size_string);
    string_copy[size_string] = '\0';
    #if INTERNAL_DEBUG == 1
    LOG_FUNCTION_BACK("_internal_deep_copy");
    LOG_RETURN("char*", TCA, "%p,\n", string_copy);
    LOG_DEBUG("data %s\n", string_copy);
    LOG_DEBUG("and a length of %zu characters\n", size_string);
    printf("\n");
    #endif
    return string_copy;
}

void           _internal_safe_free(void** pointer){
    #if INTERNAL_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_safe_free");
    if(pointer != NULL || *pointer != NULL){
        LOG_PARAMETER("1st", "void**", TCA, "%p\n", pointer);
        LOG_DEBUG("casted (type: void*) with address %p\n", *pointer);
    }
    printf("\n");
    #endif
    if(pointer == NULL || *pointer == NULL){
        #if INTERNAL_DEBUG == 1
        LOG_DEBUG("pointer is NULL!!!\n\n");
        #endif
        return;
    }
    free(*pointer);
    *pointer = NULL;
}