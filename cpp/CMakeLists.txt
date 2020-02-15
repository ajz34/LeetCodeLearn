cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

project(test_cpp)

include_directories("src")
add_executable(main
        src/main.cpp
        src/e0001_e0100/e0022_generate_parentheses.h)

add_subdirectory(Google_tests)

# Avoid LNK2038 MTd error
# https://stackoverflow.com/a/34335077/9647779
set(gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll" FORCE)