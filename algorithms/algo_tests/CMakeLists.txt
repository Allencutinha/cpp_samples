cmake_minimum_required(VERSION 3.22)


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
add_executable(sll_test  test_linked_list.cpp)

# Link the Google Test libraries to your test executable
target_link_libraries(sll_test gtest gtest_main)

# Add the unit tests to CMake
add_test(NAME sll_tests COMMAND sll_test)

# Create a custom target to run the tests
add_custom_command(
     TARGET sll_test
     COMMENT "Run tests on Addition"
     POST_BUILD 
     COMMAND sll_test
)
