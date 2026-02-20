#include "window.h"

#include <stdlib.h>

#include "helpers/helpers.h"

typedef unsigned int uint;

struct h2ot3_window {
    uint width_px;
    uint height_px;
    uint edge_radius;
    void** child_objects;
};

h2ot3_window_t* new_h2ot3_window(uint width_px, uint height_px, uint edge_radius, int opts){
    h2ot3_window_t* window = malloc(sizeof(h2ot3_window_t));
    RETURN_IF_NULL(window);
    window->width_px = width_px;
    window->height_px = height_px;
    window->edge_radius = edge_radius;
    window->child_objects = NULL;
    return window;
}

void            free_h2ot3_window(h2ot3_window_t* window){
    // TODO: Recursive freeing
    free(window);
}
