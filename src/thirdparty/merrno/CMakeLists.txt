add_library(merrno STATIC
    _internal_merrno.c
    merrno.c
)

target_include_directories(merrno
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
