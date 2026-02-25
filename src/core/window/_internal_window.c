#include "_internal_window.h"

typedef struct h2ot3_container h2ot3_container_t;

/* only for prototyping*/
struct h2ot3_container{
    int _not_really_used;
};

struct h2ot3_window {
    char* title;
    uint width_px;
    uint height_px;
    uint visible:1;
    h2ot3_container_t* container;
};

/***********************************************
******************  GETTER *********************
************************************************/
size_t _internal_h2ot3_window_get_struct_size(){
    return sizeof(h2ot3_window_t);
}

char* _internal_h2ot3_window_get_title    (h2ot3_window_t* window){
    return window->title;
}

uint  _internal_h2ot3_window_get_width_px (h2ot3_window_t* window){
    return window->width_px;
}

uint  _internal_h2ot3_window_get_height_px(h2ot3_window_t* window){
    return window->height_px;
}

mbool _internal_h2ot3_window_get_visibility(h2ot3_window_t* window){
    return window->visible;
}


/***********************************************
******************  SETTER *********************
************************************************/
void  _internal_h2ot3_window_set_title   (h2ot3_window_t* window, char* title){
    window->title = title;
}

void  _internal_h2ot3_window_set_width_px (h2ot3_window_t* window, uint width_px){
    window->width_px = width_px;
}

void  _internal_h2ot3_window_set_height_px(h2ot3_window_t* window, uint height_px){
    window->height_px = height_px;
}

void  _internal_h2ot3_window_set_visibility(h2ot3_window_t* window, mbool visible){
    window->visible = visible;
}