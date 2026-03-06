#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "mbool.h"

#include <stddef.h>

typedef struct callback_funcs callback_funcs_t;

typedef mbool(*callback_func_t)(void*);

size_t callbacks_get_struct_size();

void callbacks_init(callback_funcs_t* funcs);

void callbacks_set_create_func(callback_funcs_t* funcs, callback_func_t create_func);
void callbacks_set_destroy_func(callback_funcs_t* funcs, callback_func_t destroy_func);
void callbacks_set_draw_func(callback_funcs_t* funcs, callback_func_t draw_func);

void callbacks_call_create_func(callback_funcs_t* funcs, void* data);
void callbacks_call_destroy_func(callback_funcs_t* funcs, void* data);
void callbacks_call_draw_func(callback_funcs_t* funcs, void* data);

#endif