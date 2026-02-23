#include "_internal.h"

#include <string.h>

#include "helpers/helpers.h"

int             _internal_secure_strlen(char* string, size_t max_len){
    int i = 0;
    while(string[i] != '\0' && i < max_len){
        i++;
    }
    return i;
}

char*           _internal_deep_copy(char* string, size_t max_len){
    size_t size_string = _internal_secure_strlen(string, max_len);
    char* string_copy = malloc( (sizeof(char) * \
                        size_string) + \
                        1*sizeof(char) /*for the \0 byte*/ \
    );
    RETURN_IF_NULL(string_copy, NULL);
    memcpy(string_copy, string, size_string);
    string_copy[size_string] = '\0';
    return string_copy;
}