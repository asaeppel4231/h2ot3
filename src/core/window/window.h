#ifndef WINDOW_H
#define WINDOW_H

typedef struct h2ot3_window h2ot3_window_t;

typedef unsigned int uint;

#define MAX_WINDOW_TITLE_LEN 200

h2ot3_window_t* new_h2ot3_window(char* title, uint width_px, uint height_px, uint edge_radius_px, int opts);
void            free_h2ot3_window(h2ot3_window_t* window);

int             get_h2ot3_window_properties();

#endif