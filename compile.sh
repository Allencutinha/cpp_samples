#!/bin/bash
fcode
mkdir build
cd build
cmake ..
rm exe
make
#./exe l
#./exe c
#./exe r
#./exe p
#./exe g ../data/apple.jpg
./exe fitline
./exe fitline3d
cd ..
