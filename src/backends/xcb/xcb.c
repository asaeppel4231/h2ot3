#include "xcb.h"

#include "container.h"

#include "window.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <xcb/xcb.h>

typedef struct {
    xcb_window_t win;
    h2ot3_window_t* frontend_window;
} xcb_backend_window_t;

static xcb_backend_window_t** window_list = NULL;
static size_t num_windows = 0;
static size_t capacity_windows = 0;

static xcb_connection_t* connection = NULL;

mbool b_xcb_create_window(void* data){
    printf("b_xcb_create_window called\n");

    h2ot3_window_t* win_frontend = data;
    if (!win_frontend) {
        printf("ERROR: create_window called with NULL\n");
        return MFALSE;
    }

    // Verbindung herstellen, falls noch nicht vorhanden
    if (connection == NULL) {
        connection = xcb_connect(NULL, NULL);
        if (xcb_connection_has_error(connection)) {
            printf("XCB connection failed\n");
            return MFALSE;
        }
    }

    // Screen holen
    const xcb_setup_t* setup = xcb_get_setup(connection);
    xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);
    xcb_screen_t* screen = iter.data;

    // Backend-Fenster anlegen
    xcb_backend_window_t* bw = malloc(sizeof(xcb_backend_window_t));
    if (!bw) return MFALSE;

    bw->frontend_window = win_frontend;   // <— wichtig!
    bw->win = xcb_generate_id(connection);

    // Fenster erstellen
    xcb_create_window(
        connection,
        XCB_COPY_FROM_PARENT,
        bw->win,
        screen->root,
        0, 0,
        get_h2ot3_window_width_px(win_frontend),
        get_h2ot3_window_height_px(win_frontend),
        0,
        XCB_WINDOW_CLASS_INPUT_OUTPUT,
        screen->root_visual,
        0,
        NULL
    );

    // In Liste eintragen (ohne Überschreiben)
    num_windows++;
    window_list = realloc(window_list, sizeof(void*) * num_windows);
    window_list[num_windows - 1] = bw;

    b_xcb_draw_window(data);
    
    return MTRUE;
}

mbool b_xcb_draw_window(void* data){
    h2ot3_window_t* win_frontend = data;

    // Backend-Fenster suchen
    xcb_backend_window_t* bw = NULL;
    for (size_t i = 0; i < num_windows; i++) {
        xcb_backend_window_t* cur = window_list[i];
        if (cur->frontend_window == win_frontend) {
            bw = cur;
            break;
        }
    }

    if (!bw) {
        printf("ERROR: no backend window found for draw\n");
        return MFALSE;
    }
    const char* title = get_h2ot3_window_title(win_frontend);

    xcb_change_property(
        connection,
        XCB_PROP_MODE_REPLACE,
        bw->win,
        XCB_ATOM_WM_NAME,
        XCB_ATOM_STRING,
        8,
        strlen(title),
        title
    );

    xcb_map_window(connection, bw->win);
    xcb_flush(connection);

    return MTRUE;
}

mbool b_xcb_destroy_window(void* data){
    printf("b_xcb_destroy_window called\n");

    h2ot3_window_t* win_frontend = data;
    if (!win_frontend) {
        printf("ERROR: destroy called with NULL window\n");
        return MFALSE;
    }

    // Das passende Backend-Fenster suchen
    xcb_backend_window_t* bw = NULL;
    size_t index = 0;

    for (size_t i = 0; i < num_windows; i++) {
        xcb_backend_window_t* cur = window_list[i];
        if (cur->frontend_window == win_frontend) {
            bw = cur;
            index = i;
            break;
        }
    }

    if (!bw) {
        printf("ERROR: no backend window found for destroy\n");
        return MFALSE;
    }

    // XCB-Fenster zerstören
    xcb_unmap_window(connection, bw->win);
    xcb_destroy_window(connection, bw->win);
    xcb_flush(connection);

    // Backend-Fenster freigeben
    free(bw);

    // Aus der Liste entfernen
    for (size_t i = index; i < num_windows - 1; i++) {
        window_list[i] = window_list[i + 1];
    }

    num_windows--;
    if (num_windows == 0) {
        free(window_list);
        window_list = NULL;
    } else {
        window_list = realloc(window_list, sizeof(void*) * num_windows);
    }
    // TODO: Don't free the XCB Connection of more windows are open, if the backend can handle multiple windows
    xcb_disconnect(connection);
    connection = NULL;

    return MTRUE;
}
