# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(test_e0001_e0100
        e0001_e0100/test_e0001.cpp
        e0001_e0100/test_e0002.cpp
        e0001_e0100/test_e0003.cpp
        e0001_e0100/test_e0004.cpp)
target_link_libraries(test_e0001_e0100 gtest gtest_main)
