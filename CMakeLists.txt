cmake_minimum_required(VERSION 3.10)
project(samples)
#include(/home/allen/deps/OpenCV-3.4.18/share/OpenCV/OpenCVConfig.cmake)
#include(K:/bin/opencv-4.7.0/opencv/build/OpenCVConfig.cmake)
include(K:/bin/opencv-3.4.15-vc14_vc15/opencv/build/OpenCVConfig.cmake)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(draw)
include_directories(cv)
include_directories(algorithms)

set(IMLIB_SRC
    main.cpp 
)

add_executable(exe ${IMLIB_SRC})

target_link_libraries(exe ${OpenCV_LIBS})


