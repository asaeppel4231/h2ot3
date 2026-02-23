#include "window.h"

#include <stdlib.h>

#include "helpers/helpers.h"
#include "_internal/_internal.h"
#include "types.h"

#define H2OT3_INVALID 1 /*only for the first*/ /*TODO: Move that to anything else*/ 

struct h2ot3_window {
    char* title;
    uint width_px;
    uint height_px;
    uint visible:1;
    void** child_objects;
};

h2ot3_window_t* new_h2ot3_window(char* title, uint width_px, uint height_px, int opts){
    h2ot3_window_t* window = malloc(sizeof(h2ot3_window_t));
    RETURN_IF_NULL(window, NULL);
    window->title = _internal_deep_copy(title, MAX_WINDOW_TITLE_LEN);
    window->width_px = width_px;
    window->height_px = height_px;
    window->child_objects = NULL;
    return window;
}
//TODO: Add childrens

void            free_h2ot3_window(h2ot3_window_t* window){
    // TODO: Recursive freeing of childrens
    // TODO: Add Widgets
    free(window->title);
    free(window);
}

char*           get_h2ot3_window_title(h2ot3_window_t* window){
    RETURN_IF_NULL(window, NULL);
    return window->title;
}

uint            get_h2ot3_window_width_px(h2ot3_window_t* window){
    RETURN_IF_NULL(window, H2OT3_INVALID);
    return window->width_px;
}

uint            get_h2ot3_window_heigh_px(h2ot3_window_t* window){
    RETURN_IF_NULL(window, H2OT3_INVALID);
    return window->height_px;
}

uint            set_h2ot3_window_title    (h2ot3_window_t* window, char* title){
    if(window == NULL){
        return H2OT3_INVALID;
    }
    window->title = title;
}

uint            set_h2ot3_window_width_px (h2ot3_window_t* window, uint width_px){
    if(window == NULL){
        return H2OT3_INVALID;
    }
    window->width_px = width_px;
}

uint            set_h2ot3_window_height_px(h2ot3_window_t* window, uint height_px){
    if(window == NULL){
        return H2OT3_INVALID;
    }
    window->height_px = height_px;
}

//TODO: Add backends
// TODO: Do internal stuff in internal functions instead of in the public API