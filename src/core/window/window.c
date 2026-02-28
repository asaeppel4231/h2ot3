#include "window.h"

#include <stdlib.h>

#include "_internal/_internal.h"
#include "_internal_window.h"

#include "helpers/helpers.h"
#include "types.h"

#include "merrno.h"
#include "mbool.h"

/***********************************************
**********  ALLOCATION / FREEING ***************
************************************************/
h2ot3_window_t* new_h2ot3_window(char* title, uint width_px, uint height_px, int flags){
    h2ot3_window_t* window = malloc(_internal_h2ot3_window_get_struct_size());
    RETURN_IF_NULL(window, NULL);
    _internal_h2ot3_window_set_title(window, _internal_deep_copy(title, MAX_WINDOW_TITLE_LEN));
    _internal_h2ot3_window_set_width_px(window, width_px);
    _internal_h2ot3_window_set_height_px(window, height_px);
    _internal_h2ot3_window_set_visibility(window, MTRUE);
    /*window->child_objects = NULL; */ /*FIXME: Add container setter and getter and replace this*/
    return window;
}
//TODO: Add childrens

void            free_h2ot3_window(h2ot3_window_t* window){
    // TODO: Recursive freeing of childrens
    // TODO: Add Widgets
    free(_internal_h2ot3_window_get_title(window));
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

/***********************************************
******************  SETTER *********************
************************************************/

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

//TODO: Implement backends