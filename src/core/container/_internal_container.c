#include "_internal_container.h"
#include "window.h"

typedef void h2ot3_widget_t; /*FIXME: Replace with another definition*/

struct h2ot3_container{
    uint flags;
    h2ot3_container_t* parent;
    h2ot3_widget_t** children;
    h2ot3_window_t* window;
};

// TODO: Add window getter and setter
// TODO: Add children getter and setter

void _internal_helper_h2ot3_set_delete_flag(uint* flag, uint bit, uint set_delete){
    if(mbool_is_true(set_delete)){
        *flag |=  (1 << bit);   // Set bit
    }
    else{
        *flag &= ~(1 << bit);   // Remove bit
    }
}

size_t _internal_h2ot3_container_get_struct_size(){
    return sizeof(h2ot3_container_t);
}

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

h2ot3_window_t* _internal_h2ot3_container_get_window(h2ot3_container_t* container){
    return container->window;
}

void _internal_h2ot3_container_set_visibility    (h2ot3_container_t* container, mbool visible){
    _internal_helper_h2ot3_set_delete_flag(&container->flags, H2OT3_CONTAINER_VISIBILITY_BIT, visible);
}

void _internal_h2ot3_container_set_needs_redraw  (h2ot3_container_t* container, mbool needs_redraw){
    _internal_helper_h2ot3_set_delete_flag(&container->flags, H2OT3_CONTAINER_REDRAW_BIT, needs_redraw);
}

void _internal_h2ot3_container_set_needs_relayout(h2ot3_container_t* container, mbool needs_relayout){
    _internal_helper_h2ot3_set_delete_flag(&container->flags, H2OT3_CONTAINER_RELAYOUT_BIT, needs_relayout);
}

void _internal_h2ot3_container_set_window(h2ot3_container_t* container, h2ot3_window_t* window){
    container->window = window;
}