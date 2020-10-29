cmake_minimum_required(VERSION 3.9)
project(task C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_FLAGS "-std=c99 -ggdb3 -Wall -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS "-std=c++0x")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)

add_library(sequential STATIC ./hw2/lib/sources/sequential.c)

set(lib_files
        ./hw2/lib/sources/main.c
        ./hw2/lib/sources/utility.c)

include_directories(./hw2/includes)

add_executable(task ${lib_files})
TARGET_LINK_LIBRARIES(task sequential)

enable_testing()

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/hw2/lib/includes)
include_directories(${PROJECT_SOURCE_DIR}/hw2/test)

add_executable(gtest_test hw2/test/main.cpp hw2/test/test.cpp)
TARGET_LINK_LIBRARIES(gtest_test ${GTEST_BOTH_LIBRARIES} gtest pthread sequential)