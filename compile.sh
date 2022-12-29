#!/bin/bash
fcode
mkdir build
cd build
cmake ..
rm exe
make
./exe l
./exe c
./exe r
./exe p
./exe g ../data/apple.jpg
./exe canny ../data/left01.jpg
./exe hough ../data/left01.jpg
./exe fitline
./exe fitline3d
./exe median ../data/Noise_salt_and_pepper.png
cd ..
