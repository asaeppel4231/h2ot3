cmake_minimum_required(VERSION 3.16)
project(h2ot3 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(H2OT3_BUILD_SHARED "Build h2ot3 as a shared library" ON)
option(H2OT3_BUILD_TESTCODE "Build h2ot3's testcode" ON)


add_subdirectory(src)
