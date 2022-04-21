cmake_minimum_required(VERSION 3.16)
project(clog C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-pthread")

add_library(clog STATIC clog.c)
target_include_directories(clog PUBLIC include)

add_executable(mini_example mini_example.c)
target_link_libraries(mini_example clog)