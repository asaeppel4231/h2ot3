#ifndef HELPERS_H
#define HELPERS_H

#include <stdlib.h>

#define RETURN_IF_NULL(ptr) \
do{\
    if((ptr) == NULL){ \
        return NULL; \
    } \
}while(0)

#endif