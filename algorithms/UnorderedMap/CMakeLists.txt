cmake_minimum_required(VERSION 3.2)
project(unordered_map)

add_executable(umap main.cpp UnorderedMapExercises.cpp UnorderedMapCommon.cpp)

add_executable (test tests/tests.cpp UnorderedMapExercises.cpp  UnorderedMapCommon.cpp uiuc/catch/catchmain.cpp)