#ifndef BACKEND_XCB_H
#define BACKEND_XCB_H

#include "mbool.h"

// TODO: Not quick and dirty in the future
mbool b_xcb_create_window(void* data);
mbool b_xcb_draw_window(void* data);
mbool b_xcb_destroy_window(void* data);

#endif