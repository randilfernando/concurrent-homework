cmake_minimum_required(VERSION 3.3)
project(matrix_multiplier)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")
set_source_files_properties(src/optimized.cpp PROPERTIES COMPILE_FLAGS -O2)
set_source_files_properties(src/optimized_2.cpp PROPERTIES COMPILE_FLAGS -O2)

set(SOURCE_FILES src/util.h src/util.cpp src/matrix.h src/matrix.cpp)
add_executable(matrix_multiplier_sequential ${SOURCE_FILES} src/sequential.cpp)
add_executable(matrix_multiplier_parallel ${SOURCE_FILES} src/parallel.cpp)
add_executable(matrix_multiplier_optimized ${SOURCE_FILES} src/optimized.cpp)
