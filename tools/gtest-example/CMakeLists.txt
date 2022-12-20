cmake_minimum_required(VERSION 3.10)

# Use FetchContent to download and include Google Test
include(FetchContent)

# Add the Google Test source code to the project
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

# Add the source files for the add function and the unit tests
add_executable(test_add test_add.cpp add.cpp)

# Link the Google Test libraries to the test executable
target_link_libraries(test_add gtest gtest_main)

# Add the unit tests to CMake
add_test(NAME add_tests COMMAND test_add)

# Create a custom target to run the tests
add_custom_command(
     TARGET test_add
     COMMENT "Run tests on Addition"
     POST_BUILD 
     COMMAND test_add
)
