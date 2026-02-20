#ifndef WINDOW_H
#define WINDOW_H

typedef unsigned int uint;

//only for the first, please don't call the police because that
struct h2ot3_window {
    char* title;
    uint width_px;
    uint height_px;
    void** child_objects;
};

typedef struct h2ot3_window h2ot3_window_t;

#define MAX_WINDOW_TITLE_LEN 200

h2ot3_window_t* new_h2ot3_window(char* title, uint width_px, uint height_px, int opts);
void            free_h2ot3_window(h2ot3_window_t* window);

int             get_h2ot3_window_properties();

#endif