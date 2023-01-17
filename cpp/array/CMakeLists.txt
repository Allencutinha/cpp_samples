cmake_minimum_required(VERSION 3.2)
project(array)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPP_SRC
    custom_std_array.cpp 
)

add_executable(array ${CPP_SRC})