#ifndef INTERNAL_CONTAINER_H
#define INTERNAL_CONTAINER_H

#include "types.h"
#include "mbool.h"

typedef struct h2ot3_container h2ot3_container_t;

uint  _internal_h2ot3_container_get_flags_raw     (h2ot3_container_t* container);
mbool _internal_h2ot3_container_get_visibility    (h2ot3_container_t* container);
mbool _internal_h2ot3_container_get_needs_redraw  (h2ot3_container_t* container);
mbool _internal_h2ot3_container_get_needs_relayout(h2ot3_container_t* container);

#endif