#include "_internal_container.h"
#include "window.h"

typedef void h2ot3_widget_t; /*FIXME: Replace with another definition*/

#define H2OT3_CONTAINER_VISIBILITY_BIT 0
#define H2OT3_CONTAINER_REDRAW_BIT     1
#define H2OT3_CONTAINER_RELAYOUT_BIT   2

struct h2ot3_container{
    uint flags:3;
    h2ot3_container_t* parent;
    h2ot3_widget_t** children;
    h2ot3_window_t* window;
};

uint  _internal_h2ot3_container_get_flags_raw     (h2ot3_container_t* container){
    return container->flags;
}

mbool _internal_h2ot3_container_get_visibility    (h2ot3_container_t* container){
    return ( container->flags & (1 << H2OT3_CONTAINER_VISIBILITY_BIT)) != 0;
}
mbool _internal_h2ot3_container_get_needs_redraw  (h2ot3_container_t* container){
    return ( container->flags & (1 << H2OT3_CONTAINER_REDRAW_BIT)) != 0;
}

mbool _internal_h2ot3_container_get_needs_relayout(h2ot3_container_t* container){
    return ( container->flags & (1 << H2OT3_CONTAINER_RELAYOUT_BIT)) != 0;
}

void _internal_h2ot3_container_set_visibility    (h2ot3_container_t* container, mbool visible){
    if (visible){
        container->flags |=  (1 << H2OT3_CONTAINER_VISIBILITY_BIT);   // Set bit
    }
    else{
        container->flags &= ~(1 << H2OT3_CONTAINER_VISIBILITY_BIT);   // Remove bit
    }
}

void _internal_h2ot3_container_set_needs_redraw  (h2ot3_container_t* container, mbool needs_redraw){
    if (needs_redraw){
        container->flags |=  (1 << H2OT3_CONTAINER_REDRAW_BIT);   // Set bit
    }
    else{
        container->flags &= ~(1 << H2OT3_CONTAINER_REDRAW_BIT);   // Remove bit
    }
}

void _internal_h2ot3_container_set_needs_relayout(h2ot3_container_t* container, mbool needs_relayout){
    if (needs_relayout){
        container->flags |=  (1 << H2OT3_CONTAINER_RELAYOUT_BIT);   // Set bit
    }
    else{
        container->flags &= ~(1 << H2OT3_CONTAINER_RELAYOUT_BIT);   // Remove bit
    }
}