cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

project(test_cpp)

include_directories("src")
add_executable(main
        src/0001_0100/0001_two_sum.h
        src/main.cpp
        src/main.h)

add_subdirectory(Google_tests)
