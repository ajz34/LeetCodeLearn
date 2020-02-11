cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

project(test_cpp)

include_directories("src")
add_executable(main
        src/main.cpp
        src/e0001_e0100/e0009_palindrome_number.h)

add_subdirectory(Google_tests)
