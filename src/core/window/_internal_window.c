#include "_internal_window.h"
#include "_internal.h"

#include "container.h"
#include "callbacks.h"
#include "helpers.h"

#include "dummy.h"
#include "xcb.h"

#include <stdlib.h>
#include <string.h>
#include <stddef.h>

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
    h2ot3_container_t* root_container; 
    callback_funcs_t* funcs;
}; /*TODO: Add more B<->C Communication*/ 

void _internal_h2ot3_window_init(h2ot3_window_t* window){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_init");
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    printf("\n");
    #endif
    memset(window, 0, _internal_h2ot3_window_get_struct_size());
    callback_funcs_t* tmp = malloc(callbacks_get_struct_size());
    if(tmp == NULL){
        return;
    }
    _internal_h2ot3_window_set_funcs(window, tmp);
    callbacks_init(_internal_h2ot3_window_get_funcs(window));
    // TODO: Not hardcode the functions of the dummy backend (aka add runtime function changing)
    callbacks_set_create_func(_internal_h2ot3_window_get_funcs(window), b_xcb_create_window);
    callbacks_set_destroy_func(_internal_h2ot3_window_get_funcs(window), b_xcb_destroy_window);
    callbacks_set_draw_func(_internal_h2ot3_window_get_funcs(window), b_xcb_draw_window);
    return;
}

void _internal_h2ot3_window_free(h2ot3_window_t* window){
    // TODO: Not hardcode the functions of the dummy backend
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_free")
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    printf("\n");
    #endif
    callbacks_call_destroy_func(window->funcs, window);
    _internal_safe_free((void**)&window->funcs);
    _internal_safe_free((void**)_internal_h2ot3_window_get_title_ptr(window));
    return;
}

/***********************************************
******************  GETTER *********************
************************************************/
size_t _internal_h2ot3_window_get_struct_size(){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_get_struct_size")
    LOG_RETURN("size_t", TCV, "%zu\n", sizeof(h2ot3_window_t));
    printf("\n");
    #endif
    return sizeof(h2ot3_window_t);
}

char* _internal_h2ot3_window_get_title    (h2ot3_window_t* window){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_get_title")
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    LOG_RETURN("char*", TCA, "%p,\n", window->title);
    LOG_DEBUG("and data %s\n", window->title);
    printf("\n");
    #endif
    return window->title;
}

char** _internal_h2ot3_window_get_title_ptr(h2ot3_window_t* window){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_get_title_ptr")
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    LOG_RETURN("char**", TCA, "%p,\n", &window->title);
    LOG_DEBUG("data %s\n", window->title);
    LOG_DEBUG("and in the original (type: char*) with address %p\n", window->title);
    printf("\n");
    #endif
    return &window->title;
}

uint  _internal_h2ot3_window_get_width_px (h2ot3_window_t* window){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_get_width_px")
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    LOG_RETURN("uint", TCV, "%u\n", window->width_px);
    printf("\n");
    #endif
    return window->width_px;
}

uint  _internal_h2ot3_window_get_height_px(h2ot3_window_t* window){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_get_height_px")
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    LOG_RETURN("uint", TCV, "%u\n", window->height_px);
    printf("\n");
    #endif
    return window->height_px;
}

mbool _internal_h2ot3_window_get_visibility(h2ot3_window_t* window){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_get_visibility")
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    LOG_RETURN("mbool (aka unsigned char)", TCV, "%u\n", window->visible);
    printf("\n");
    #endif
    return window->visible;
}

h2ot3_container_t* _internal_h2ot3_window_get_container(h2ot3_window_t* window){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_get_container")
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    LOG_RETURN("h2ot3_container_t*", TCA, "%p\n", window->root_container);
    printf("\n");
    #endif
    return window->root_container;
}

callback_funcs_t* _internal_h2ot3_window_get_funcs(h2ot3_window_t* window){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_get_funcs")
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    LOG_RETURN("callback_funcs_t*", TCA, "%p\n", window->funcs);
    printf("\n");
    #endif
    return window->funcs;
}

/***********************************************
******************  SETTER *********************
************************************************/
void  _internal_h2ot3_window_set_title   (h2ot3_window_t* window, char* title){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_set_title");
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    LOG_PARAMETER("2nd", "char*", TCA, "%p\n", title);
    LOG_DEBUG("and data %s\n", title);
    if(window->title != NULL){
        LOG_DEBUG("extra information: window->title (type: char*) has currently address %p\n", window->title);
        LOG_DEBUG("and data %s\n", window->title);
    }
    printf("\n");
    #endif
    _internal_safe_free((void**)_internal_h2ot3_window_get_title_ptr(window));
    window->title = _internal_deep_copy(title, MAX_WINDOW_TITLE_LEN);
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_BACK("_internal_h2ot3_window_set_title");
    if(window->title != NULL){
        LOG_DEBUG("extra information: window->title (type: char*) has now address %p\n", window->title);
        LOG_DEBUG("and data %s\n", window->title);
    }
    printf("\n");
    #endif
}

void  _internal_h2ot3_window_set_width_px (h2ot3_window_t* window, uint width_px){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_set_width_px");
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    LOG_PARAMETER("2nd", "uint", TCV, "%u\n", width_px);
    LOG_DEBUG("extra information: window->width_px (type: uint) has currently value %u\n", window->width_px);
    printf("\n");
    #endif
    window->width_px = width_px;
}

void  _internal_h2ot3_window_set_height_px(h2ot3_window_t* window, uint height_px){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_set_height_px")
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    LOG_PARAMETER("2nd", "uint", TCV, "%u\n", height_px);
    LOG_DEBUG("extra information: window->height (type: uint) has currently value %u\n", window->height_px);
    printf("\n");
    #endif
    window->height_px = height_px;
}

void  _internal_h2ot3_window_set_visibility(h2ot3_window_t* window, mbool visible){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_set_visibility");
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    LOG_PARAMETER("2nd", "mbool (aka unsigned char)", TCV, "%u\n", visible);
    LOG_DEBUG("extra information: window->visible (type: mbool (aka unsigned char) ) has currently value %u\n", window->visible);
    printf("\n");
    #endif
    window->visible = visible;
}

void  _internal_h2ot3_window_set_container(h2ot3_window_t* window, h2ot3_container_t* container){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_set_container");
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    LOG_PARAMETER("2nd", "h2ot3_container_t*", TCA, "%p\n", container);
    if(window->root_container != NULL){
        LOG_DEBUG("extra information: window->container (type: h2ot3_container_t*) has currently address %p\n", window->root_container);
    }
    printf("\n");
    #endif
    window->root_container = container;
}

void _internal_h2ot3_window_set_funcs(h2ot3_window_t* window, callback_funcs_t* funcs){
    #if INTERNAL_WINDOW_DEBUG == 1
    LOG_FUNCTION_CALL("_internal_h2ot3_window_set_funcs");
    LOG_PARAMETER("1st", "h2ot3_window_t*", TCA, "%p\n", window);
    LOG_PARAMETER("2nd", "callback_funcs_t*", TCA, "%p\n", funcs);
    if(window->funcs != NULL){
        LOG_DEBUG("extra information: window->funcs (type: callback_funcs_t*) has currently address %p\n", window->funcs);
    }
    printf("\n");
    #endif
    window->funcs = funcs;
}