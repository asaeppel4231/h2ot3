#ifndef WINDOW_H
#define WINDOW_H

#include "types.h"
#include "mbool.h"

#define WINDOW_DEBUG MTRUE

typedef struct h2ot3_window h2ot3_window_t;

#define MAX_WINDOW_TITLE_LEN 200

h2ot3_window_t* new_h2ot3_window (char* title, uint width_px, uint height_px, int opts);
void            free_h2ot3_window(h2ot3_window_t* window);

char*           get_h2ot3_window_title    (h2ot3_window_t* window);
uint            get_h2ot3_window_width_px (h2ot3_window_t* window);
uint            get_h2ot3_window_height_px(h2ot3_window_t* window);

uint            set_h2ot3_window_title    (h2ot3_window_t* window, char* title);
uint            set_h2ot3_window_width_px (h2ot3_window_t* window, uint width_px);
uint            set_h2ot3_window_height_px(h2ot3_window_t* window, uint height_px);

#endif