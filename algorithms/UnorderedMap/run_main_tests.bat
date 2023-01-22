mkdir build
cd build
cmake ..
msbuild.exe ALL_BUILD.vcxproj /p:configuration=release
cd ..
::call executable form source folder to access input text file
call .\build\release\umap.exe

:: call executable form source folder to access input text file
call .\build\Release\test.exe


