# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(test_e0001_e0100
        e0001_e0100/test_e0001.cpp e0001_e0100/test_e0002.cpp e0001_e0100/test_e0003.cpp e0001_e0100/test_e0004.cpp
        e0001_e0100/test_e0005.cpp e0001_e0100/test_e0006.cpp e0001_e0100/test_e0007.cpp e0001_e0100/test_e0008.cpp
        e0001_e0100/test_e0009.cpp e0001_e0100/test_e0010.cpp e0001_e0100/test_e0011.cpp e0001_e0100/test_e0012.cpp
        e0001_e0100/test_e0013.cpp e0001_e0100/test_e0014.cpp e0001_e0100/test_e0015.cpp)
target_link_libraries(test_e0001_e0100 gtest gtest_main)
