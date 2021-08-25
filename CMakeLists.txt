cmake_minimum_required(VERSION 3.20)
project(multilingual_data_structure_algorithm)

set(CMAKE_CXX_STANDARD 14)
add_executable(hello_c multilingual/c/hello_c.c)
add_executable(align multilingual/c/align.c)
add_executable(compile-run multilingual/compile-run.c)