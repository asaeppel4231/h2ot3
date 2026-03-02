#include "_internal_callbacks.h"

struct callback_funcs {
    callback_func_t create;
    callback_func_t destroy;
    callback_func_t draw;
};

size_t _internal_callbacks_get_struct_size(){
    return sizeof(callback_funcs_t);
}

void _internal_callbacks_set_create_func(callback_funcs_t* funcs, callback_func_t create_func){
    funcs->create = create_func;
}

void _internal_callbacks_set_destroy_func(callback_funcs_t* funcs, callback_func_t destroy_func){
    funcs->destroy = destroy_func;
}

void _internal_callbacks_set_draw_func(callback_funcs_t* funcs, callback_func_t draw_func){
    funcs->draw = draw_func;
}


void _internal_callbacks_call_create_func(callback_funcs_t* funcs, void* data){
    funcs->create(data);
}

void _internal_callbacks_call_destroy_func(callback_funcs_t* funcs, void* data){
    funcs->destroy(data);
}

void _internal_callbacks_call_draw_func(callback_funcs_t* funcs, void* data){
    funcs->draw(data);
}