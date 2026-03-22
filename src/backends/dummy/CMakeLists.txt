validate_backend_mode(H2OT3_BACKEND_DUMMY_MODE "${H2OT3_BACKEND_DUMMY_MODE}")

if(H2OT3_BACKEND_DUMMY_MODE STREQUAL "auto")
    if(H2OT3_BUILD_SHARED)
        add_library(backend_dummy SHARED)
    else()
        add_library(backend_dummy STATIC)
    endif()
elseif(H2OT3_BACKEND_DUMMY_MODE STREQUAL "static")
    add_library(backend_dummy STATIC)
elseif(H2OT3_BACKEND_DUMMY_MODE STREQUAL "shared")
    add_library(backend_dummy SHARED)
elseif(H2OT3_BACKEND_DUMMY_MODE STREQUAL "dynamic")
    add_library(backend_dummy SHARED)
    target_compile_definitions(h2ot3_engine PRIVATE H2OT3_BACKEND_DUMMY_DYNAMIC)
endif()

target_sources(backend_dummy PRIVATE
    _internal_dummy.c
    dummy.c
)

target_link_libraries(backend_dummy PRIVATE
    mbool
)

target_include_directories(backend_dummy PRIVATE
    ${ENGINE_INCLUDE_DIRS}
)

target_include_directories(h2ot3_engine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
