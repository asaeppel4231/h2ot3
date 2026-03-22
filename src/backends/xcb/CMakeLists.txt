# XCB-Backend – Check mode
validate_backend_mode(H2OT3_BACKEND_XCB_MODE "${H2OT3_BACKEND_XCB_MODE}")

# Specify library type
set(_xcb_libtype STATIC)

if(H2OT3_BACKEND_XCB_MODE STREQUAL "auto")
    if(H2OT3_BUILD_SHARED)
        set(_xcb_libtype SHARED)
    endif()

elseif(H2OT3_BACKEND_XCB_MODE STREQUAL "static")
    set(_xcb_libtype STATIC)

elseif(H2OT3_BACKEND_XCB_MODE STREQUAL "shared")
    set(_xcb_libtype SHARED)

elseif(H2OT3_BACKEND_XCB_MODE STREQUAL "dynamic")
    # .so bauen, Engine lädt zur Laufzeit
    set(_xcb_libtype SHARED)
    target_compile_definitions(h2ot3_engine PRIVATE H2OT3_BACKEND_XCB_DYNAMIC)
endif()

# add library
add_library(backend_xcb ${_xcb_libtype})

# sources
target_sources(backend_xcb PRIVATE
    _internal_xcb.c
    xcb.c
)

# Includes: Backend owned + Engine-API
target_include_directories(backend_xcb PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${ENGINE_INCLUDE_DIRS}
)

# Link-Libs: Thirdparty + System-xcb
target_link_libraries(backend_xcb PRIVATE
    mbool
    xcb
)

# Important: NOT link with h2ot3_engine
# (Engine knows Backend Header, but not reversed)
