# 1. Thirdparty zuerst
add_subdirectory(thirdparty/merrno)
add_subdirectory(thirdparty/mbool)

# 2. Engine definieren
if(H2OT3_BUILD_SHARED)
    add_library(h2ot3_engine SHARED)
else()
    add_library(h2ot3_engine STATIC)
endif()

# 3. Engine gegen thirdparty libs linken
target_link_libraries(h2ot3_engine PUBLIC
    merrno
    mbool
    xcb
)

# 4. Engine-Header
target_include_directories(h2ot3_engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${CMAKE_CURRENT_SOURCE_DIR}/core/container
    ${CMAKE_CURRENT_SOURCE_DIR}/core/callbacks
    ${CMAKE_CURRENT_SOURCE_DIR}/core/_internal
    ${CMAKE_CURRENT_SOURCE_DIR}/core/helpers
    ${CMAKE_CURRENT_SOURCE_DIR}/core/window
    # bad
    ${CMAKE_CURRENT_SOURCE_DIR}/backends/xcb
    ${CMAKE_CURRENT_SOURCE_DIR}/backends/dummy
)

# 5. Engine-Basisquellen
target_sources(h2ot3_engine PRIVATE
    core/container/grid/grid.c
    backends/dummy/dummy.c
    backends/dummy/_internal_dummy.c
    backends/xcb/xcb.c
    backends/xcb/_internal_xcb.c
)

# 6. Jetzt erst die Unterordner einbinden
add_subdirectory(core)

# 7. Testcode optional
if(H2OT3_BUILD_TESTCODE)
    add_subdirectory(testcode)
endif()
