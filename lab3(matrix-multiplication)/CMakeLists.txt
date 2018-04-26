cmake_minimum_required(VERSION 3.3)
project(matrix_multiplier)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")
set_source_files_properties(optimized.cpp PROPERTIES COMPILE_FLAGS -O2)
set_source_files_properties(optimized_2.cpp PROPERTIES COMPILE_FLAGS -O2)

set(SOURCE_FILES util.h util.cpp matrix.h matrix.cpp)
add_executable(matrix_multiplier_sequential ${SOURCE_FILES} sequential.cpp)
add_executable(matrix_multiplier_parallel ${SOURCE_FILES} parallel.cpp)
add_executable(matrix_multiplier_optimized ${SOURCE_FILES} optimized.cpp)
add_executable(matrix_multiplier_optimized2 ${SOURCE_FILES} optimized_2.cpp)
