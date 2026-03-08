#include "window.h"

#include "_internal/_internal.h"
#include "_internal_window.h"

#include "types.h"

#include "merrno.h"
#include "mbool.h"

#include <stddef.h>
#include <stdlib.h>

// TODO: Remove that
#include "callbacks.h"

/***********************************************
**********  ALLOCATION / FREEING ***************
************************************************/
h2ot3_window_t* new_h2ot3_window(char* title, uint width_px, uint height_px, int flags){
    h2ot3_window_t* window = malloc(_internal_h2ot3_window_get_struct_size());
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, NULL);
    _internal_h2ot3_window_init(window);
    _internal_h2ot3_window_set_title(window, _internal_deep_copy(title, MAX_WINDOW_TITLE_LEN));
    _internal_h2ot3_window_set_width_px(window, width_px);
    _internal_h2ot3_window_set_height_px(window, height_px);
    _internal_h2ot3_window_set_visibility(window, MTRUE);
    _internal_h2ot3_window_set_container(window, NULL);
    // TODO: Not hardcode the address (portability)
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

// FIXME: Create a deep copy instead of a flat copy to avoid errors
mbool           set_h2ot3_window_title     (h2ot3_window_t* window, char* title){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, MFALSE);
    _internal_h2ot3_window_set_title(window, title);
    return MTRUE;
}

mbool           set_h2ot3_window_width_px  (h2ot3_window_t* window, uint width_px){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, MFALSE);
    _internal_h2ot3_window_set_width_px(window, width_px);
    return MTRUE;
}

mbool           set_h2ot3_window_height_px (h2ot3_window_t* window, uint height_px){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, MFALSE);
    _internal_h2ot3_window_set_height_px(window, height_px);
    return MTRUE;
}

mbool           set_h2ot3_window_visibility(h2ot3_window_t* window, mbool visible){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, MFALSE);
    _internal_h2ot3_window_set_visibility(window, visible);
    return MTRUE;
}

mbool           set_h2ot3_window_container (h2ot3_window_t* window, h2ot3_container_t* container){
    SET_MERRNO_AND_RETURN_IF_COND_FAILED(window != NULL, MERRNO_EC_ISNULL, MFALSE);
    _internal_h2ot3_window_set_container(window, container);
    return MTRUE;
}

//TODO: Implement backends