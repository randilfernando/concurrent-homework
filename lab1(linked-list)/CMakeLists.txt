cmake_minimum_required(VERSION 3.9)
project(concurrent_l2 C)

set(CMAKE_C_STANDARD 99)

add_executable(concurrent_l2 serial.c one_mutex.c read_write_lock.c)