#ifndef WINDOW_H
#define WINDOW_H

#include "types.h"
#include "mbool.h"

typedef struct h2ot3_window h2ot3_window_t;
typedef struct h2ot3_container h2ot3_container_t ;

#define MAX_WINDOW_TITLE_LEN 200

/***********************************************
**********  ALLOCATION / FREEING ***************
************************************************/
h2ot3_window_t* new_h2ot3_window (char* title, uint width_px, uint height_px, int opts);
void            free_h2ot3_window(h2ot3_window_t* window);

/***********************************************
******************  GETTER *********************
************************************************/
char*           get_h2ot3_window_title     (h2ot3_window_t* window);
uint            get_h2ot3_window_width_px  (h2ot3_window_t* window);
uint            get_h2ot3_window_height_px (h2ot3_window_t* window);
uint            get_h2ot3_window_visibility(h2ot3_window_t* window);

h2ot3_container_t* get_h2ot3_window_container(h2ot3_window_t* window);

/***********************************************
******************  SETTER *********************
************************************************/
mbool           set_h2ot3_window_title     (h2ot3_window_t* window, char* title);
mbool           set_h2ot3_window_width_px  (h2ot3_window_t* window, uint width_px);
mbool           set_h2ot3_window_height_px (h2ot3_window_t* window, uint height_px);
mbool           set_h2ot3_window_visibility(h2ot3_window_t* window, mbool visible);
mbool           set_h2ot3_window_container (h2ot3_window_t* window, h2ot3_container_t* container);

void            explicit_update_h2ot3_window(h2ot3_window_t* window, int flags);

#endif