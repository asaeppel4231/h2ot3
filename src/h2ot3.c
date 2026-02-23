#include "h2ot3.h"

// only for first tests; similar parts are the backends doing in the future.
#include <xcb/xcb.h>
#include "window.h"
#include <stdio.h>
#include <string.h>

// Test 1: Dummy Test
void h2ot3_backend_draw_window(h2ot3_window_t *win) {
    printf("Drawing window %ux%u with title: %s\n", get_h2ot3_window_width_px(win), get_h2ot3_window_height_px(win), get_h2ot3_window_title(win));
}

// Test 2: Real XCB Window opening
/* Test 2 removed but is in the git history available*/

int main(){
    h2ot3_window_t* window = new_h2ot3_window("Test Window", 180, 240, 0);
    if(window == NULL){
        return -1;
    }
    h2ot3_backend_draw_window(window);
    /* because test_xcb_window not defined; "see Test 2:" */
    //test_xcb_window(get_h2ot3_window_width_px(window), get_h2ot3_window_heigh_px(window), get_h2ot3_window_title(window));
    free_h2ot3_window(window);    
}
