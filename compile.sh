#!/bin/bash
fcode
mkdir build
cd build
rm exe
make
./exe l
./exe c
./exe r
./exe p
cd ..
