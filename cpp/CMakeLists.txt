cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

project(test_cpp)

include_directories("src")
add_executable(main
        src/e0001_e0100/e0002_add_two_numbers.h
        src/main.cpp
        src/main.h)

add_subdirectory(Google_tests)
