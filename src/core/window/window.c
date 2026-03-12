#include "window.h"

#include "_internal/_internal.h"
#include "_internal_window.h"

#include "types.h"

#include "merrno.h"
#include "mbool.h"

#include <stddef.h>
#include <stdlib.h>
#include <time.h>

#include "callbacks.h"

/***********************************************
**********  ALLOCATION / FREEING ***************
************************************************/
h2ot3_window_t* new_h2ot3_window(char* title, uint width_px, uint height_px, int flags){
    h2ot3_window_t* window = malloc(_internal_h2ot3_window_get_struct_size());
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_NO_MEMORY, NULL);
    _internal_h2ot3_window_init(window);
    _internal_h2ot3_window_set_title(window, title);
    _internal_h2ot3_window_set_width_px(window, width_px);
    _internal_h2ot3_window_set_height_px(window, height_px);
    _internal_h2ot3_window_set_visibility(window, MTRUE);
    _internal_h2ot3_window_set_container(window, NULL);
    callbacks_call_create_func(
         _internal_h2ot3_window_get_funcs(window),
        window
    );

    return window;
}
//TODO: Add childrens

void            free_h2ot3_window(h2ot3_window_t* window){
    // TODO: Recursive freeing of childrens
    // TODO: Add Widgets
    _internal_h2ot3_window_free(window);
    free(window);
}

/***********************************************
******************  GETTER *********************
************************************************/
char*           get_h2ot3_window_title (h2ot3_window_t* window){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, NULL);
    return _internal_h2ot3_window_get_title(window);
}

uint            get_h2ot3_window_width_px (h2ot3_window_t* window){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, H2OT3_INVALID);
    return _internal_h2ot3_window_get_width_px(window);
}

uint            get_h2ot3_window_height_px (h2ot3_window_t* window){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, H2OT3_INVALID);
    return _internal_h2ot3_window_get_height_px(window);
}

uint            get_h2ot3_window_visibility(h2ot3_window_t* window){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, H2OT3_INVALID);
    return _internal_h2ot3_window_get_visibility(window);
}

h2ot3_container_t* get_h2ot3_window_container(h2ot3_window_t* window){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, NULL);
    return _internal_h2ot3_window_get_container(window);  
}

/***********************************************
******************  SETTER *********************
************************************************/

mbool           set_h2ot3_window_title     (h2ot3_window_t* window, char* title){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_INV_1ST_ARG, MFALSE);
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(title != NULL, MERRNO_EC_INV_2ND_ARG, MFALSE);
    _internal_h2ot3_window_set_title(window, title);
    callbacks_call_draw_func(_internal_h2ot3_window_get_funcs(window), window); // TODO: Replace this with a job queue
    return MTRUE;
}

mbool           set_h2ot3_window_width_px  (h2ot3_window_t* window, uint width_px){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, MFALSE);
    _internal_h2ot3_window_set_width_px(window, width_px);
    callbacks_call_draw_func(_internal_h2ot3_window_get_funcs(window), window);
    return MTRUE;
}

mbool           set_h2ot3_window_height_px (h2ot3_window_t* window, uint height_px){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, MFALSE);
    _internal_h2ot3_window_set_height_px(window, height_px);
    callbacks_call_draw_func(_internal_h2ot3_window_get_funcs(window), window);
    return MTRUE;
}

mbool           set_h2ot3_window_visibility(h2ot3_window_t* window, mbool visible){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, MFALSE);
    _internal_h2ot3_window_set_visibility(window, visible);
    callbacks_call_draw_func(_internal_h2ot3_window_get_funcs(window), window);
    return MTRUE;
}

mbool           set_h2ot3_window_container (h2ot3_window_t* window, h2ot3_container_t* container){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, MFALSE);
    _internal_h2ot3_window_set_container(window, container);
    callbacks_call_draw_func(_internal_h2ot3_window_get_funcs(window), window);
    return MTRUE;
}

void            explicit_update_h2ot3_window(h2ot3_window_t* window, int flags){
    callbacks_call_draw_func(_internal_h2ot3_window_get_funcs(window), window);
}