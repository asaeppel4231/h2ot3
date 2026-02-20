#include "window.h"

typedef unsigned int uint;
struct h2ot3_window {
    uint width_px;
    uint height_px;
    uint edge_radius;
    void** child_objects;
};

h2ot3_window_t* init_h2ot3_window(int width_px, int height_px, int edge_radius, int opts){

}

void            free_h2ot3_window(h2ot3_window_t*);

int             get_h2ot3_window_properties();