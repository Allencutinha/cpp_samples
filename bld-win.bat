set PATH=C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin;%PATH%
set PATH=K:\bin\cmake-3.25.1\bin;%PATH%
set PATH=K:\bin\opencv-3.4.15-vc14_vc15\opencv\build\x64\vc15\bin;%PATH%
mkdir build
cd build
cmake ..
::buildr
msbuild.exe ALL_BUILD.vcxproj /p:configuration=release
cd Release
exe l
exe c
exe r
exe p
exe g ../../data/apple.jpg
exe canny ../../data/left01.jpg
exe hough ../../data/left01.jpg
exe fitline
exe fitline3d
exe median ../../data/noisyimg.png
cd ..
cd ..
