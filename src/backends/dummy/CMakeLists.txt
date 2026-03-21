add_library(backend_dummy SHARED)

target_sources(backend_dummy PRIVATE
    _internal_dummy.c
    dummy.c
)

target_link_libraries(backend_dummy PRIVATE
    mbool
)

target_include_directories(h2ot3_engine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)