#include "container.h"
#include "_internal_container.h"

#include "helpers/helpers.h"
#include "mbool.h"

uint  h2ot3_container_get_flags_raw     (h2ot3_container_t* container){
    RETURN_IF_NULL(container, -1);
    return _internal_h2ot3_container_get_flags_raw(container);
}

mbool h2ot3_container_get_visibility    (h2ot3_container_t* container){
    RETURN_IF_NULL(container, MFALSE);
    return _internal_h2ot3_container_get_visibility(container);
}

mbool h2ot3_container_get_needs_redraw  (h2ot3_container_t* container){
    RETURN_IF_NULL(container, MFALSE);
    return _internal_h2ot3_container_get_needs_redraw(container);
}

mbool h2ot3_container_get_needs_relayout(h2ot3_container_t* container){
    RETURN_IF_NULL(container, MFALSE);
    return _internal_h2ot3_container_get_needs_relayout(container);
}

mbool h2ot3_container_set_visibility    (h2ot3_container_t* container, mbool visible){
    RETURN_IF_NULL(container, MFALSE);
    _internal_h2ot3_container_set_visibility(container, visible);
    return MTRUE;
}

mbool h2ot3_container_set_needs_redraw  (h2ot3_container_t* container, mbool needs_redraw){
    RETURN_IF_NULL(container, MFALSE);
    _internal_h2ot3_container_set_needs_redraw(container, needs_redraw);
    return MTRUE;
}

mbool h2ot3_container_set_needs_relayout(h2ot3_container_t* container, mbool needs_relayout){
    RETURN_IF_NULL(container, MFALSE);
    _internal_h2ot3_container_set_needs_relayout(container, needs_relayout);
    return MTRUE;
}
