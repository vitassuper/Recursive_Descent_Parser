cmake_minimum_required(VERSION 3.8)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(DEBUG_OPTIONS -m64 -Wall -Wextra -pedantic -Werror)
set(RELEASE_OPTIONS -m64 -O2)

project(recursive-descent-parser)
add_executable(recursive-descent-parser)

target_sources(recursive-descent-parser PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_sources(recursive-descent-parser PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Parser.cpp)
target_sources(recursive-descent-parser PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Expression.cpp)

add_compile_options("$<$<CONFIG:DEBUG>:${DEBUG_OPTIONS}>")
add_compile_options("$<$<CONFIG:RELEASE>:${RELEASE_OPTIONS}>")