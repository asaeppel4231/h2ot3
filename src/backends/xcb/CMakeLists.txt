add_library(backend_xcb SHARED)

target_sources(backend_xcb PRIVATE
    _internal_xcb.c
    xcb.c
)

target_include_directories(h2ot3_engine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)