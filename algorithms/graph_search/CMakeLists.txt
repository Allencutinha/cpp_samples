cmake_minimum_required(VERSION 3.2)
project(graph_search)

add_executable(gsearch main.cpp GridGraph.cpp PuzzleState.cpp GraphSearchExercises.cpp)

add_executable (test tests/tests.cpp uiuc/catch/catchmain.cpp GridGraph.cpp PuzzleState.cpp GraphSearchExercises.cpp)