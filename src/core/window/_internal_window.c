#include "_internal_window.h"
#include "container.h"
#include "dummy.h"
#include "callbacks.h"
#include "helpers.h"

#include <stdlib.h>

#if INTERNAL_WINDOW_DEBUG == 1
#include <stdio.h>
#endif

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
    void* backend_window; /*TODO: Replace with B<->C Communication*/ /*TODO: Remove backend_window or initialize it*/
    callback_funcs_t* funcs;
};

mbool _internal_h2ot3_window_init(h2ot3_window_t* window){
    // TODO: Not hardcode the functions of the dummy backend
    #if INTERNAL_WINDOW_DEBUG == 1
    printf(DEBUG "_internal_h2ot3_window_init was called.\n");
    printf(DEBUG "1st parameter (type: h2ot3_window_t*) with address %p\n", window);
    printf("\n");
    #endif
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
    #if INTERNAL_WINDOW_DEBUG == 1
    printf(DEBUG "_internal_h2ot3_window_free was called.\n");
    printf(DEBUG "1st parameter (type: h2ot3_window_t*) with address %p\n", window);
    printf("\n");
    #endif
    callbacks_call_destroy_func(window->funcs, NULL);
    free(window->funcs);
    return MTRUE;
}

/***********************************************
******************  GETTER *********************
************************************************/
size_t _internal_h2ot3_window_get_struct_size(){
    #if INTERNAL_WINDOW_DEBUG == 1
    printf(DEBUG "_internal_h2ot3_window_get_struct_size was called.\n");
    printf(DEBUG "Returning (type: size_t) value %zu", sizeof(h2ot3_window_t));
    printf("\n");
    #endif
    return sizeof(h2ot3_window_t);
}

char* _internal_h2ot3_window_get_title    (h2ot3_window_t* window){
    #if INTERNAL_WINDOW_DEBUG == 1
    printf(DEBUG "_internal_h2ot3_window_get_title was called.\n");
    printf(DEBUG "1st parameter (type: h2ot3_window_t*) with address %p\n", window);
    printf(DEBUG "Returning (type: char*) string with address %p\n", window->title);
    printf(DEBUG "and data %s\n", window->title);
    printf("\n");
    #endif
    return window->title;
}

uint  _internal_h2ot3_window_get_width_px (h2ot3_window_t* window){
    #if INTERNAL_WINDOW_DEBUG == 1
    printf(DEBUG "_internal_h2ot3_window_get_width_px was called.\n");
    printf(DEBUG "1st parameter (type: h2ot3_window_t*) with address %p\n", window);
    printf(DEBUG "Returning (type: uint) value %u\n", window->width_px);
    printf("\n");
    #endif
    return window->width_px;
}

uint  _internal_h2ot3_window_get_height_px(h2ot3_window_t* window){
    #if INTERNAL_WINDOW_DEBUG == 1
    printf(DEBUG "_internal_h2ot3_window_get_height_px was called.\n");
    printf(DEBUG "1st parameter (type: h2ot3_window_t*) with address %p\n", window);
    printf(DEBUG "Returning (type: uint) value %u\n", window->height_px);
    printf("\n");
    #endif
    return window->height_px;
}

mbool _internal_h2ot3_window_get_visibility(h2ot3_window_t* window){
    #if INTERNAL_WINDOW_DEBUG == 1
    printf(DEBUG "_internal_h2ot3_window_get_visibility was called.\n");
    printf(DEBUG "1st parameter (type: h2ot3_window_t*) with address %p\n", window);
    printf(DEBUG "Returning (type: mbool (aka unsigned char) ) value %u", window->visible);
    printf("\n");
    #endif
    return window->visible;
}

h2ot3_container_t* _internal_h2ot3_window_get_container(h2ot3_window_t* window){
    #if INTERNAL_WINDOW_DEBUG == 1
    printf(DEBUG "_internal_h2ot3_window_get_container was called.\n");
    printf(DEBUG "1st parameter (type: h2ot3_window_t*) with address %p\n", window);
    printf(DEBUG "Returning (type: h2ot3_container_t*) struct pointer with address %p\n", window->container);
    printf("\n");
    #endif
    return window->container;
}

/***********************************************
******************  SETTER *********************
************************************************/
void  _internal_h2ot3_window_set_title   (h2ot3_window_t* window, char* title){
    callbacks_call_draw_func(window->funcs, NULL); // TODO: Replace this with a job queue
    #if INTERNAL_WINDOW_DEBUG == 1
    printf(DEBUG "_internal_h2ot3_window_set_title was called.\n");
    printf(DEBUG "1st parameter (type: h2ot3_window_t*) with address %p\n", window);
    printf(DEBUG "2nd parameter (type: char*) with address %p\n", title);
    printf(DEBUG "and data %s\n", title);
    printf(DEBUG "extra information: window->title (type: char*) has currently address %p\n", window->title);
    printf(DEBUG "and data %s\n", window->title);
    printf("\n");
    #endif
    window->title = title;
}

void  _internal_h2ot3_window_set_width_px (h2ot3_window_t* window, uint width_px){
    callbacks_call_draw_func(window->funcs, NULL);
    #if INTERNAL_WINDOW_DEBUG == 1
    printf(DEBUG "_internal_h2ot3_window_set_width_px was called.\n");
    printf(DEBUG "1st parameter (type: h2ot3_window_t*) with address %p\n", window);
    printf(DEBUG "2nd parameter (type: uint) with value %u\n", width_px);
    printf(DEBUG "extra information: window->width_px has currenctly value %u\n", window->width_px);
    printf("\n");
    #endif
    window->width_px = width_px;
}

void  _internal_h2ot3_window_set_height_px(h2ot3_window_t* window, uint height_px){
    callbacks_call_draw_func(window->funcs, NULL);
    #if INTERNAL_WINDOW_DEBUG == 1
    printf(DEBUG "_internal_h2ot3_window_set_height_px was called.\n");
    printf(DEBUG "1st parameter (type: h2ot3_window_t*) with address %p\n", window);
    printf(DEBUG "2nd parameter (type: uint) with value %u\n", height_px);
    printf(DEBUG "extra information: window->height has currenctly value %u\n", window->height_px);
    printf("\n");
    #endif
    window->height_px = height_px;
}

void  _internal_h2ot3_window_set_visibility(h2ot3_window_t* window, mbool visible){
    callbacks_call_draw_func(window->funcs, NULL);
    #if INTERNAL_WINDOW_DEBUG == 1
    printf(DEBUG "_internal_h2ot3_window_set_visibility was called.\n");
    printf(DEBUG "1st parameter (type: h2ot3_window_t*) with address %p\n", window);
    printf(DEBUG "2nd parameter (type: mbool (aka unsigned char)) with value %u\n", visible);
    printf(DEBUG "extra information: window->visible has currenctly value %u\n", window->visible);
    printf("\n");
    #endif
    window->visible = visible;
}

void  _internal_h2ot3_window_set_container(h2ot3_window_t* window, h2ot3_container_t* container){
    callbacks_call_draw_func(window->funcs, NULL);
    #if INTERNAL_WINDOW_DEBUG == 1
    printf(DEBUG "_internal_h2ot3_window_set_container was called.\n");
    printf(DEBUG "1st parameter (type: h2ot3_window_t*) with address %p\n", window);
    printf(DEBUG "2nd parameter (type: h2ot3_container_t*) with address %p\n", container);
    printf(DEBUG "extra information: window->container has currenctly address %p\n", window->container);
    printf("\n");
    #endif
    window->container = container;
}