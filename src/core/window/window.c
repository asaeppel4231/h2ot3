#include "window.h"

#include <stdlib.h>

#include "helpers/helpers.h"
#include "_internal/_internal.h"

typedef unsigned int uint;

struct h2ot3_window {
    char* title;
    uint width_px;
    uint height_px;
    void** child_objects;
};

h2ot3_window_t* new_h2ot3_window(char* title, uint width_px, uint height_px, int opts){
    h2ot3_window_t* window = malloc(sizeof(h2ot3_window_t));
    RETURN_IF_NULL(window);
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
    RETURN_IF_NULL(window);
    return window->title;
}

uint            get_h2ot3_window_width_px(h2ot3_window_t* window){
    RETURN_IF_NULL(window); // FIXME: Returns void* instead of uint if invalid
    return window->width_px;
}

uint            get_h2ot3_window_heigh_px(h2ot3_window_t* window){
    RETURN_IF_NULL(window);
    return window->height_px;
}


//TODO: Implement Setter instead of having the definition in the header file
//TODO: Add backends
// TODO: Do internal stuff in internal functions instead of in the public API