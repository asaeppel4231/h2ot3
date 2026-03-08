#include "h2ot3.h"

// only for first tests; similar parts are the backends doing in the future.
#include <xcb/xcb.h>
#include "window.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

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
    char* test = malloc(sizeof(char)*4);
    test[0] = 'A';
    test[1] = 'B';
    test[2] = 'C';
    test[3] = '\0';
    set_h2ot3_window_title(window, test);
    /* because test_xcb_window not defined; "see Test 2:" */
    //test_xcb_window(get_h2ot3_window_width_px(window), get_h2ot3_window_heigh_px(window), get_h2ot3_window_title(window));
    sleep(5);
    free_h2ot3_window(window);
}
