#ifndef CONTAINER_H
#define CONTAINER_H

#include "types.h"
#include "mbool.h"

typedef struct h2ot3_container h2ot3_container_t;

uint  h2ot3_container_get_flags_raw     (h2ot3_container_t* container);
mbool h2ot3_container_get_visibility    (h2ot3_container_t* container);
mbool h2ot3_container_get_needs_redraw  (h2ot3_container_t* container);
mbool h2ot3_container_get_needs_relayout(h2ot3_container_t* container);

mbool h2ot3_container_set_visibility    (h2ot3_container_t* container, mbool visible);
mbool h2ot3_container_set_needs_redraw  (h2ot3_container_t* container, mbool needs_redraw);
mbool h2ot3_container_set_needs_relayout(h2ot3_container_t* container, mbool needs_relayout);

#endif