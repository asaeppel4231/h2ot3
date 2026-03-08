cmake_minimum_required(VERSION 3.16)
project(h2ot3 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(H2OT3_ENGINE_SOURCES
    src/core/window/window.c
    src/core/_internal/_internal.c
    src/core/window/_internal_window.c
    src/core/container/grid/grid.c
    src/core/container/container.c
    src/core/container/_internal_container.c
    src/core/callbacks/callbacks.c
    src/core/callbacks/_internal_callbacks.c
    src/core/c2b/_internal_c2b.c
    src/core/c2b/c2b.c
    src/backends/dummy/dummy.c
    src/backends/dummy/_internal_dummy.c
    src/backends/xcb/_internal_xcb.c
    src/backends/xcb/xcb.c
)

set(H2OT3_DEMO src/h2ot3.c)

add_executable(h2ot3_demo
    ${H2OT3_ENGINE_SOURCES}
    ${H2OT3_DEMO}
)

# WICHTIG: PRIVATE hinzufügen!
target_include_directories(h2ot3_demo PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/window
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/_internal
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/helpers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/mbool
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/container
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/container/grid
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/merrno
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/c2b
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/callbacks
    ${CMAKE_CURRENT_SOURCE_DIR}/src/backends/dummy
    ${CMAKE_CURRENT_SOURCE_DIR}/src/backends/xcb
)

add_subdirectory(src/core/merrno)

target_link_libraries(h2ot3_demo PRIVATE xcb merrno)
