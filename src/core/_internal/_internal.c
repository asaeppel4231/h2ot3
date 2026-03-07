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
    printf(DEBUG "_internal_secure_strlen called.\n");
    printf(DEBUG "1st parameter (type: char*) with address %p\n", string);
    printf(DEBUG "and data %s\n", string);
    printf(DEBUG "2nd parameter (type: size_t) with value %zu\n", max_len);
    #endif
    size_t i = 0;
    while(string[i] != '\0' && i < max_len){
        i++;
    }
    #if INTERNAL_DEBUG == 1
    printf(DEBUG "Returning (type: size_t) value %zu\n", i);
    printf("\n");
    #endif
    return i;
}

char*           _internal_deep_copy(char* string, size_t max_len){
    #if INTERNAL_DEBUG == 1
    printf(DEBUG "_internal_deep_copy called.\n");
    printf(DEBUG "1st parameter (type: char*) with address %p\n", string);
    printf(DEBUG "and data %s\n", string);
    printf(DEBUG "2nd parameter (type: size_t) with value %zu\n", max_len);
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
    printf(DEBUG "Back in _internal_deep_copy\n");
    printf(DEBUG "Returning (type: char*) string with address %p,\n", string_copy);
    printf(DEBUG "data %s\n", string_copy);
    printf(DEBUG "and a length of %zu characters\n", size_string);
    printf("\n");
    #endif
    return string_copy;
}

void           _internal_safe_free(void** pointer){
    #if INTERNAL_DEBUG == 1
    printf(DEBUG "_internal_safe_free called.\n");
    printf(DEBUG "1st parameter (type: void**) with address %p,\n", pointer);
    printf(DEBUG "casted (type: void*) with address %p\n", *pointer);
    printf("\n");
    #endif
    free(*pointer);
    *pointer = NULL;
}