target_sources(h2ot3_engine PRIVATE
    _internal_callbacks.c
    callbacks.c
)

target_include_directories(h2ot3_engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)