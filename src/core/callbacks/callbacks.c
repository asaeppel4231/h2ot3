#include "callbacks.h"
#include "_internal_callbacks.h"

#include "merrno.h"

void callbacks_set_create_func(callback_funcs_t* funcs, callback_func_t create_func){ //TODO: Replace void with mbool
    SET_MERRNO_AND_RETURN_VOID_IF_COND_FAILED(funcs != NULL, MERRNO_EC_ISNULL);
    _internal_callbacks_set_create_func(funcs, create_func);
}

void callbacks_set_destroy_func(callback_funcs_t* funcs, callback_func_t destroy_func){
    SET_MERRNO_AND_RETURN_VOID_IF_COND_FAILED(funcs != NULL, MERRNO_EC_ISNULL);
    _internal_callbacks_set_destroy_func(funcs, destroy_func);
}

void callbacks_set_draw_func(callback_funcs_t* funcs, callback_func_t draw_func){
    SET_MERRNO_AND_RETURN_VOID_IF_COND_FAILED(funcs != NULL, MERRNO_EC_ISNULL);
    _internal_callbacks_set_draw_func(funcs, draw_func);
}

void callbacks_call_create_func(callback_funcs_t* funcs, void* data){
    SET_MERRNO_AND_RETURN_VOID_IF_COND_FAILED(funcs != NULL, MERRNO_EC_ISNULL);
    _internal_callbacks_call_create_func(funcs, data); //TODO: Make that you cannot call a NULL function because that causes a segmentation fault
}

void callbacks_call_destroy_func(callback_funcs_t* funcs, void* data){
    SET_MERRNO_AND_RETURN_VOID_IF_COND_FAILED(funcs != NULL, MERRNO_EC_ISNULL);
    _internal_callbacks_call_destroy_func(funcs, data);
}

void callbacks_call_draw_func(callback_funcs_t* funcs, void* data){
    SET_MERRNO_AND_RETURN_VOID_IF_COND_FAILED(funcs != NULL, MERRNO_EC_ISNULL);
    _internal_callbacks_call_draw_func(funcs, data);
}