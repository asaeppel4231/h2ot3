#include "_internal_window.h"
#include "dummy.h"
#include "callbacks.h"

#include <stdlib.h>

typedef struct h2ot3_container h2ot3_container_t;

/* only for prototyping*/
struct h2ot3_container{
    int _not_really_used;
};

struct h2ot3_window {
    char* title;
    uint width_px;
    uint height_px;
    uint visible:1;
    h2ot3_container_t* container;
    void* backend_window; /*TODO: Replace with B<->C Communication*/
    callback_funcs_t* funcs;
};

mbool _internal_h2ot3_window_init(h2ot3_window_t* window){
    // TODO: Not hardcode the functions of the dummy backend
    window->funcs = malloc(callbacks_get_struct_size());
    callbacks_init(window->funcs);
    callbacks_set_create_func(window->funcs, b_create_window);
    callbacks_call_create_func(window->funcs, NULL);
    callbacks_set_destroy_func(window->funcs, b_free_window);
    callbacks_set_draw_func(window->funcs, b_draw_window);
    return MTRUE;
}

mbool _internal_h2ot3_window_free(h2ot3_window_t* window){
    // TODO: Not hardcode the functions of the dummy backend
    callbacks_call_destroy_func(window->funcs, NULL);
    free(window->funcs);
    return MTRUE;
}

/***********************************************
******************  GETTER *********************
************************************************/
size_t _internal_h2ot3_window_get_struct_size(){
    return sizeof(h2ot3_window_t);
}

char* _internal_h2ot3_window_get_title    (h2ot3_window_t* window){
    return window->title;
}

uint  _internal_h2ot3_window_get_width_px (h2ot3_window_t* window){
    return window->width_px;
}

uint  _internal_h2ot3_window_get_height_px(h2ot3_window_t* window){
    return window->height_px;
}

mbool _internal_h2ot3_window_get_visibility(h2ot3_window_t* window){
    return window->visible;
}

h2ot3_container_t* _internal_h2ot3_window_get_container(h2ot3_window_t* window){
    return window->container;
}
/***********************************************
******************  SETTER *********************
************************************************/
void  _internal_h2ot3_window_set_title   (h2ot3_window_t* window, char* title){
    callbacks_call_draw_func(window->funcs, NULL); // TODO: Replace this with a job queue
    window->title = title;
}

void  _internal_h2ot3_window_set_width_px (h2ot3_window_t* window, uint width_px){
    callbacks_call_draw_func(window->funcs, NULL);
    window->width_px = width_px;
}

void  _internal_h2ot3_window_set_height_px(h2ot3_window_t* window, uint height_px){
    callbacks_call_draw_func(window->funcs, NULL);
    window->height_px = height_px;
}

void  _internal_h2ot3_window_set_visibility(h2ot3_window_t* window, mbool visible){
    callbacks_call_draw_func(window->funcs, NULL);
    window->visible = visible;
}

void  _internal_h2ot3_window_set_container(h2ot3_window_t* window, h2ot3_container_t* container){
    callbacks_call_draw_func(window->funcs, NULL);
    window->container = container;
}