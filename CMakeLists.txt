cmake_minimum_required(VERSION 3.17)
project(c3xx)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(test)
endif()