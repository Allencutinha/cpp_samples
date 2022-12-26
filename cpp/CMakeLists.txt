cmake_minimum_required(VERSION 3.9)
project(cpp_tests)
set(CMAKE_CXX_STANDARD 14)


# Use FetchContent to download and include Google Test
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

enable_testing()

add_executable(lambdatest lambda.cpp)
target_link_libraries(lambdatest GTest::gtest_main)

add_executable(transformtest transform.cpp)
target_link_libraries(transformtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lambdatest)
gtest_discover_tests(transformtest)