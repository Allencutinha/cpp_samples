mkdir build
cd build
cmake ..
buildr
cd Release
./exe l
./exe c
./exe r
./exe p
./exe g ../../data/apple.jpg
./exe canny ../../data/left01.jpg
./exe hough ../../data/left01.jpg
./exe fitline
./exe fitline3d
./exe median ../../data/noisyimg.png
cd ..
cd ..
