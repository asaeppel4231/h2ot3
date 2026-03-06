#ifndef INTERNAL_CALLBACKS_H
#define INTERNAL_CALLBACKS_H

#include "mbool.h"

#include <stddef.h>

typedef struct callback_funcs callback_funcs_t;

typedef mbool(*callback_func_t)(void*);

size_t _internal_callbacks_get_struct_size();

void _internal_callbacks_set_create_func(callback_funcs_t* funcs, callback_func_t create_func);
void _internal_callbacks_set_destroy_func(callback_funcs_t* funcs, callback_func_t destroy_func);
void _internal_callbacks_set_draw_func(callback_funcs_t* funcs, callback_func_t draw_func);

callback_func_t _internal_callbacks_get_create_func(callback_funcs_t *funcs);
callback_func_t _internal_callbacks_get_destroy_func(callback_funcs_t *funcs);
callback_func_t _internal_callbacks_get_draw_func(callback_funcs_t *funcs);

void _internal_callbacks_call_create_func(callback_funcs_t* funcs, void* data);
void _internal_callbacks_call_destroy_func(callback_funcs_t* funcs, void* data);
void _internal_callbacks_call_draw_func(callback_funcs_t* funcs, void* data);

#endif