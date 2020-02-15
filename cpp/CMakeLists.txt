cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

project(test_cpp)

include_directories("src")
add_executable(main
        src/main.cpp
        src/e0001_e0100/e0020_valid_parenthese.h src/e0001_e0100/e0021_merge_two_sorted_lists.h)

add_subdirectory(Google_tests)
