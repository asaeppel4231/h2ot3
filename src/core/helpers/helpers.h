#ifndef HELPERS_H
#define HELPERS_H

#include <stdlib.h>

#define RETURN_IF_NULL(ptr, value) \
do{\
    if((ptr) == NULL){ \
        return (value); \
    } \
}while(0)

#endif