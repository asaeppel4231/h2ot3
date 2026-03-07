#ifndef INTERNAL_WINDOW_H
#define INTERNAL_WINDOW_H

#include "_internal_container.h"

#include "types.h"
#include "mbool.h"

#include <stddef.h>

#ifndef NDEBUG
#define INTERNAL_WINDOW_DEBUG 1
#endif

typedef struct h2ot3_window h2ot3_window_t;

void  _internal_h2ot3_window_init(h2ot3_window_t* window);
void _internal_h2ot3_window_free(h2ot3_window_t* window);

/***********************************************
******************  GETTER *********************
************************************************/
size_t _internal_h2ot3_window_get_struct_size();
char* _internal_h2ot3_window_get_title     (h2ot3_window_t* window);
char** _internal_h2ot3_window_get_title_ptr(h2ot3_window_t* window);
uint  _internal_h2ot3_window_get_width_px  (h2ot3_window_t* window);
uint  _internal_h2ot3_window_get_height_px (h2ot3_window_t* window);
mbool _internal_h2ot3_window_get_visibility(h2ot3_window_t* window);

h2ot3_container_t* _internal_h2ot3_window_get_container(h2ot3_window_t* window);

/***********************************************
******************  SETTER *********************
************************************************/
void  _internal_h2ot3_window_set_title     (h2ot3_window_t* window, char* title);
void  _internal_h2ot3_window_set_width_px  (h2ot3_window_t* window, uint width_px);
void  _internal_h2ot3_window_set_height_px (h2ot3_window_t* window, uint height_px);
void  _internal_h2ot3_window_set_visibility(h2ot3_window_t* window, mbool visible);

void  _internal_h2ot3_window_set_container(h2ot3_window_t* window, h2ot3_container_t* container);

#endif