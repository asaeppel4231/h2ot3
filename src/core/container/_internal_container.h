#ifndef INTERNAL_CONTAINER_H
#define INTERNAL_CONTAINER_H

#include "types.h"
#include "mbool.h"

#include "window.h"

#define H2OT3_CONTAINER_VISIBILITY_BIT 0
#define H2OT3_CONTAINER_REDRAW_BIT     1
#define H2OT3_CONTAINER_RELAYOUT_BIT   2

typedef struct h2ot3_container h2ot3_container_t;

/***********************************************
******************  GETTER *********************
************************************************/
size_t _internal_h2ot3_container_get_struct_size();

uint  _internal_h2ot3_container_get_flags_raw     (h2ot3_container_t* container);
mbool _internal_h2ot3_container_get_visibility    (h2ot3_container_t* container);
mbool _internal_h2ot3_container_get_needs_redraw  (h2ot3_container_t* container);
mbool _internal_h2ot3_container_get_needs_relayout(h2ot3_container_t* container);

h2ot3_window_t* _internal_h2ot3_container_get_window(h2ot3_container_t* container);

/***********************************************
******************  SETTER *********************
************************************************/
void _internal_h2ot3_container_set_visibility    (h2ot3_container_t* container, mbool visible);
void _internal_h2ot3_container_set_needs_redraw  (h2ot3_container_t* container, mbool needs_redraw);
void _internal_h2ot3_container_set_needs_relayout(h2ot3_container_t* container, mbool needs_relayout);

void _internal_h2ot3_container_set_window        (h2ot3_container_t* container, h2ot3_window_t* window);

#endif