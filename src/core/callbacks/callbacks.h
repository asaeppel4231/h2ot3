#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "mbool.h"

typedef struct callback_funcs callback_funcs_t;

typedef mbool(*callback_func_t)(void*);

void callbacks_set_create_func(callback_funcs_t* funcs, callback_func_t create_func);
void callbacks_set_destroy_func(callback_funcs_t* funcs, callback_func_t destroy_func);
void callbacks_set_draw_func(callback_funcs_t* funcs, callback_func_t draw_func);

void callbacks_call_create_func(callback_funcs_t* funcs, void* data);
void callbacks_call_destroy_func(callback_funcs_t* funcs, void* data);
void callbacks_call_draw_func(callback_funcs_t* funcs, void* data);

#endif