cmake_minimum_required(VERSION 3.16)
project(h2ot3 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(H2OT3_BUILD_SHARED "Build h2ot3 as a shared library" ON)
option(H2OT3_BUILD_TESTCODE "Build h2ot3's testcode" ON)

option(H2OT3_BACKEND_SUPPORT_XCB "Build the h2ot3 xcb backend" ON)
# TODO: Use this options
option(H2OT3_BACKEND_SUPPORT_XORG "Build the h2ot3 xorg backend" OFF)
option(H2OT3_BACKEND_SUPPORT_COCOA "Build the h2ot3 cocoa backend" OFF)
option(H2OT3_BACKEND_SUPPORT_WIN32 "Build the h2ot3 win32 backend" OFF)
option(H2OT3_BACKEND_SUPPORT_WAYLAND "Build the h2ot3 wayland backend" OFF)

add_subdirectory(src)
