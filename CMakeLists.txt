cmake_minimum_required(VERSION 3.16)
project(h2ot3 C)

# Setze C-Standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Aktiviere Warnungen (gut für ein Toolkit)
if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-parameter)
endif()

# Haupt-Header-Verzeichnis
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src
${CMAKE_CURRENT_SOURCE_DIR}/src/core/)

# Sammle alle Quellcodes rekursiv
file(GLOB_RECURSE H2OT3_SOURCES
    src/*.c
)

# Baue die Bibliothek
add_library(h2ot3 STATIC
    ${H2OT3_SOURCES}
)

# Beispielprogramm (optional)
add_executable(h2ot3_demo
    src/h2ot3.c
)

target_link_libraries(h2ot3_demo h2ot3 xcb)
