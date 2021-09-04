cmake_minimum_required(VERSION 3.20)
project(multilingual_data_structure_algorithm)

set(CMAKE_CXX_STANDARD 14)
add_executable(hello_c++ multilingual/cpp/hello_cpp.cpp)
add_executable(align multilingual/c/align.c)
add_executable(compile-run multilingual/compile-run.c)

add_executable(string_suffix multilingual/c/string_suffix.c)

add_executable(hello_c multilingual/c/hello_c.c)

add_executable(create_file multilingual/c/create_file.c)

add_executable(file_print multilingual/c/file_print.c)
