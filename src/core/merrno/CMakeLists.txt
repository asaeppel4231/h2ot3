add_library(merrno STATIC
    merrno.c
)

target_include_directories(merrno
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
