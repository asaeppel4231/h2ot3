#include "window.h"

#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "helpers/helpers.h"

typedef unsigned int uint;

struct h2ot3_window {
    char* title;
    uint width_px;
    uint height_px;
    uint edge_radius_px;
    void** child_objects;
};

char*           _internal_deep_copy(char* string);

h2ot3_window_t* new_h2ot3_window(char* title, uint width_px, uint height_px, uint edge_radius_px, int opts){
    h2ot3_window_t* window = malloc(sizeof(h2ot3_window_t));
    RETURN_IF_NULL(window);
    window->title = _internal_deep_copy(title);
    window->width_px = width_px;
    window->height_px = height_px;
    window->edge_radius_px = edge_radius_px;
    window->child_objects = NULL;
    return window;
}

void            free_h2ot3_window(h2ot3_window_t* window){
    // TODO: Recursive freeing
    free(window);
}

// TODO: Move to internal module
int             _internal_secure_strlen(char* string, int max_len){
    int i = 0;
    while(string[i] != '\0' && i < max_len){
        i++;
    }
    return i;
}

char*           _internal_deep_copy(char* string){
    size_t size_string = _internal_secure_strlen(string, MAX_WINDOW_TITLE_LEN);
    char* string_copy = malloc( (sizeof(char) * \
                        size_string) + \
                        1*sizeof(char) /*for the \0 byte*/ \
    );
    RETURN_IF_NULL(string_copy);
    memcpy(string_copy, string, size_string);
    return string_copy;
}