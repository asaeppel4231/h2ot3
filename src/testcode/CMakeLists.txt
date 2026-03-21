add_executable(h2ot3_testcode testcode.c)

target_link_libraries(h2ot3_testcode PRIVATE
    h2ot3_engine
    merrno
)
