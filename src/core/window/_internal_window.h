#ifndef INTERNAL_WINDOW_H
#define INTERNAL_WINDOW_H

#include "types.h"
#include "mbool.h"

#include <stddef.h>

typedef struct h2ot3_window h2ot3_window_t;

/***********************************************
******************  GETTER *********************
************************************************/
size_t _internal_h2ot3_window_get_struct_size();
char* _internal_h2ot3_window_get_title     (h2ot3_window_t* window);
uint  _internal_h2ot3_window_get_width_px  (h2ot3_window_t* window);
uint  _internal_h2ot3_window_get_height_px (h2ot3_window_t* window);
mbool _internal_h2ot3_window_get_visibility(h2ot3_window_t* window);

/***********************************************
******************  SETTER *********************
************************************************/
void  _internal_h2ot3_window_set_title     (h2ot3_window_t* window, char* title);
void  _internal_h2ot3_window_set_width_px  (h2ot3_window_t* window, uint width_px);
void  _internal_h2ot3_window_set_height_px (h2ot3_window_t* window, uint height_px);
void  _internal_h2ot3_window_set_visibility(h2ot3_window_t* window, mbool visible);

#endif