cmake_minimum_required(VERSION 3.16)
project(h2ot3 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

enable_testing()

option(H2OT3_BUILD_SHARED "Build h2ot3 as a shared library" ON)

option(H2OT3_BUILD_TESTCODE "Build h2ot3's testcode" ON)

option(H2OT3_BACKEND_SUPPORT_DUMMY "Set whether h2ot3 can use the dummy backend" ON)
option(H2OT3_BACKEND_SUPPORT_XCB "Set whether h2ot3 can use the xcb backend" ON)
# TODO: Use this options
option(H2OT3_BACKEND_SUPPORT_XORG "Set whether h2ot3 can use the xorg backend" OFF)
option(H2OT3_BACKEND_SUPPORT_COCOA "Set whether h2ot3 can use the cocoa backend" OFF)
option(H2OT3_BACKEND_SUPPORT_WIN32 "Set whether h2ot3 can use the win32 backend" OFF)
option(H2OT3_BACKEND_SUPPORT_WAYLAND "Set whether h2ot3 can use the wayland backend" OFF)

set(H2OT3_BACKEND_DUMMY_MODE "auto" CACHE STRING "Mode of the dummy backend")
set_property(CACHE H2OT3_BACKEND_DUMMY_MODE PROPERTY STRINGS auto static shared dynamic)

set(H2OT3_BACKEND_XCB_MODE "auto" CACHE STRING "Mode of the xcb backend")
set_property(CACHE H2OT3_BACKEND_XCB_MODE PROPERTY STRINGS auto static shared dynamic)

set(H2OT3_BACKEND_XORG_MODE "auto" CACHE STRING "Mode of the xorg backend")
set_property(CACHE H2OT3_BACKEND_XORG_MODE PROPERTY STRINGS auto static shared dynamic)

set(H2OT3_BACKEND_COCOA_MODE "auto" CACHE STRING "Mode of the cocoa backend")
set_property(CACHE H2OT3_BACKEND_COCOA_MODE PROPERTY STRINGS auto static shared dynamic)

set(H2OT3_BACKEND_WIN32_MODE "auto" CACHE STRING "Mode of the win32 backend")
set_property(CACHE H2OT3_BACKEND_WIN32_MODE PROPERTY STRINGS auto static shared dynamic)

set(H2OT3_BACKEND_WAYLAND_MODE "auto" CACHE STRING "Mode of the wayland backend")
set_property(CACHE H2OT3_BACKEND_WAYLAND_MODE PROPERTY STRINGS auto static shared dynamic)

add_subdirectory(src)
