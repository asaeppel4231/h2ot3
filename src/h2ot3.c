#include "h2ot3.h"

// only for first tests; similar parts are the backends doing in the future.
#include <xcb/xcb.h>
#include "core/window/window.h"
#include <stdio.h>
#include <string.h>

// Test 1: Dummy Test
void h2ot3_backend_draw_window(h2ot3_window_t *win) {
    printf("Drawing window %ux%u with title: %s\n", get_h2ot3_window_width_px(win), get_h2ot3_window_heigh_px(win), get_h2ot3_window_title(win));
}

// Test 2: Real XCB Window opening
#include <xcb/xcb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void test_xcb_window(int width, int height, char* title) {
    xcb_connection_t *conn = xcb_connect(NULL, NULL);
    if (xcb_connection_has_error(conn)) {
        printf("XCB: Connection error\n");
        return;
    }

    const xcb_setup_t *setup = xcb_get_setup(conn);
    xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);
    xcb_screen_t *screen = iter.data;

    xcb_window_t win = xcb_generate_id(conn);

    uint32_t mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    uint32_t values[2] = {
        screen->white_pixel,
        XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_KEY_PRESS
    };

    xcb_create_window(
        conn,
        XCB_COPY_FROM_PARENT,
        win,
        screen->root,
        0, 0,
        width, height,
        0,
        XCB_WINDOW_CLASS_INPUT_OUTPUT,
        screen->root_visual,
        mask,
        values
    );

    xcb_change_property( 
        conn, 
        XCB_PROP_MODE_REPLACE, 
        win, 
        XCB_ATOM_WM_NAME, 
        XCB_ATOM_STRING, 
        8, 
        strlen(title), 
        title 
    );
    
    xcb_map_window(conn, win);
    xcb_flush(conn);

    printf("XCB: Window opened (%dx%d)\n", width, height);

    // Simple event loop
    xcb_generic_event_t *event;
    while ((event = xcb_wait_for_event(conn))) {
        uint8_t type = event->response_type & ~0x80;

        if (type == XCB_EXPOSE) {
            printf("Expose event\n");
        }

        if (type == XCB_KEY_PRESS) {
            printf("Key pressed → closing window\n");
            free(event);
            break;
        }

        free(event);
    }

    xcb_disconnect(conn);
}

int main(){
    h2ot3_window_t* window = new_h2ot3_window("Test Window", 180, 240, 0);
    if(window == NULL){
        return -1;
    }
    h2ot3_backend_draw_window(window);
    test_xcb_window(get_h2ot3_window_width_px(window), get_h2ot3_window_heigh_px(window), get_h2ot3_window_title(window));
    free_h2ot3_window(window);    
}
