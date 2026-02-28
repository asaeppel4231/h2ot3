#ifndef INTERNAL_H
#define INTERNAL_H

#include <stddef.h>

#define H2OT3_INVALID 0

int             _internal_secure_strlen(char* string, size_t max_len);
char*           _internal_deep_copy(char* string, size_t max_len);

#endif