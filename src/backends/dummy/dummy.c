#include "dummy.h"
#include "mbool.h"

#include <stdio.h>

mbool b_dummy_create_window(void* data){
    printf("dummy_backend: b_create_window was called\n");
    return MTRUE;
}

mbool b_dummy_free_window(void* data){
    printf("dummy_backend: b_free_window was called\n");
    return MTRUE;
}

mbool b_dummy_draw_window(void* data){
    printf("dummy_backend: b_draw_window was called\n");
    return MTRUE;
}
