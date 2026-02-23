cmake_minimum_required(VERSION 3.16)
project(h2ot3 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/window
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/_internal
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/helpers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/mbool
)

set(H2OT3_ENGINE_SOURCES
    src/core/window/window.c
    src/core/_internal/_internal.c
    src/core/window/_internal_window.c
)

# Demo separat
set(H2OT3_DEMO src/h2ot3.c)

message(STATUS "Engine sources:")
foreach(src ${H2OT3_ENGINE_SOURCES})
    message(STATUS "  ${src}")
endforeach()

message(STATUS "Demo sources:")
foreach(src ${H2OT3_DEMO})
    message(STATUS "  ${src}")
endforeach()

add_executable(h2ot3_demo
    ${H2OT3_ENGINE_SOURCES}
    ${H2OT3_DEMO}
)

target_link_libraries(h2ot3_demo xcb)
