if(H2OT3_BUILD_SHARED)
    add_library(h2ot3_engine SHARED)
else()
    add_library(h2ot3_engine STATIC)
endif()

target_sources(h2ot3_engine PRIVATE
    core/window/window.c
    core/window/_internal_window.c
    core/_internal/_internal.c
    core/container/container.c
    core/container/_internal_container.c
    core/container/grid/grid.c
    core/callbacks/callbacks.c
    core/callbacks/_internal_callbacks.c
    backends/dummy/dummy.c
    backends/dummy/_internal_dummy.c
    backends/xcb/xcb.c
    backends/xcb/_internal_xcb.c
)

target_include_directories(h2ot3_engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${CMAKE_CURRENT_SOURCE_DIR}/core/mbool
    ${CMAKE_CURRENT_SOURCE_DIR}/core/container
    ${CMAKE_CURRENT_SOURCE_DIR}/core/callbacks
    ${CMAKE_CURRENT_SOURCE_DIR}/core/merrno
    ${CMAKE_CURRENT_SOURCE_DIR}/core/_internal
    ${CMAKE_CURRENT_SOURCE_DIR}/core/helpers
    ${CMAKE_CURRENT_SOURCE_DIR}/core/window

    # bad
    ${CMAKE_CURRENT_SOURCE_DIR}/backends/dummy
    ${CMAKE_CURRENT_SOURCE_DIR}/backends/xcb
)

add_subdirectory(core/merrno)

if(H2OT3_BUILD_TESTCODE)
    add_subdirectory(testcode)
endif()