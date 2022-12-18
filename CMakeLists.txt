cmake_minimum_required(VERSION 3.2)
project(samples)
include(/home/allen/deps/OpenCV-3.4.18/share/OpenCV/OpenCVConfig.cmake)
include_directories(include)
set(IMLIB_SRC
    main.cpp 
)

add_executable(exe ${IMLIB_SRC})

target_link_libraries(exe ${OpenCV_LIBS})


