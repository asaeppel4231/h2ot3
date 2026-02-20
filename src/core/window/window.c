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

}

void            free_h2ot3_window(h2ot3_window_t* window){
    // TODO: Recursive freeing
    free(window);
}
