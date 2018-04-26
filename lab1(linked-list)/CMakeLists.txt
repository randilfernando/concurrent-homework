cmake_minimum_required(VERSION 3.9)
project(linkec_list C)

set_source_files_properties(src/one_mutex.c PROPERTIES COMPILE_FLAGS -pthread)
set_source_files_properties(src/read_write_lock.c PROPERTIES COMPILE_FLAGS -pthread)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES src/linked_list.h)

add_executable(linked_list_sequential ${SOURCE_FILES} src/sequential.c)
add_executable(linked_list_one_mutex ${SOURCE_FILES} src/one_mutex.c)
add_executable(linked_list_read_write_lock ${SOURCE_FILES} src/read_write_lock.c)
