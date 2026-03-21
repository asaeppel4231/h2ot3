add_library(merrno STATIC
    _internal_merrno.c
    merrno.c
)

set_property(TARGET merrno PROPERTY POSITION_INDEPENDENT_CODE ON)

target_include_directories(merrno
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
