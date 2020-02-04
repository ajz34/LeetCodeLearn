cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

project(test_cpp)

include_directories("test_cpp")

add_executable(hello_cpp hello.cpp)
add_executable(test_cpp test.cpp)
