cmake_minimum_required(VERSION 3.22)
project(cpp_tests)

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

# Add your own source files
add_executable(lambda_test  lambda.cpp)

# Link the Google Test libraries to your test executable
target_link_libraries(lambda_test gtest gtest_main)

# Add the unit tests to CMake
add_test(NAME lambda_tests COMMAND lambda_test)


# Create a custom target to run the tests
add_custom_command(
     TARGET lambda_test
     COMMENT "Run tests on c++ lambda"
     POST_BUILD 
     COMMAND lambda_test
)