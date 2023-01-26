cmake_minimum_required(VERSION 3.2)
project(exe)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPP_SRC
    sort-index.cpp 
)

add_executable(exe ${CPP_SRC})