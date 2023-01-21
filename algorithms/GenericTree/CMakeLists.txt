cmake_minimum_required(VERSION 3.2)
project(generic_tree)
add_executable(generic_tree main.cpp)

add_executable (test tests/tests.cpp uiuc/catch/catchmain.cpp)