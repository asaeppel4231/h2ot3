#ifndef CONFIG_H
#define CONFIG_H

/**************************
***** BACKEND CONFIGS *****
**************************/

#define H2OT3_SUPPORT_DUMMY 1 /*Set whether h2ot3 should be builded with the dummy backend*/
#define H2OT3_SUPPORT_XCB   1 /*Set whether h2ot3 should be builded with the xcb backend*/
#define H2OT3_SUPPORT_WAYLAND 0 /*Set whether h2ot3 should be builded with the wayland backend*/
#define H2OT3_SUPPORT_XORG  0 /*Set whether h2ot3 should be builded with the xorg backend*/
#define H2OT3_SUPPORT_WIN32 0 /*Set whether h2ot3 should be builded with the win32 backend*/
#define H2OT3_SUPPORT_COCOA 0 /*Set whether h2ot3 should be builded with the cocoa backend*/
/* more support defines are coming in the future ...*/

typedef enum h2ot3_backend{
    H2OT3_BACKEND_DUMMY=0,
    H2OT3_BACKEND_XCB,
    H2OT3_BACKEND_WAYLAND,
    H2OT3_BACKEND_XORG,
    H2OT3_BACKEND_WIN32,
    H2OT3_BACKEND_COCOA
}h2ot3_backend_t;

#define H2OT3_DEFAULT_BACKEND 1

#endif
