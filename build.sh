#!/bin/bash


echo cleaning
#clean generators to avoid conflicts when installing another config
rm -rf ./build/Makefile ./build/CMakeCache.txt ./build/cmake_install.cmake ./build/CMakeFiles ./wxwidgets/libs ./wxwidgets/CMakeFiles ./wxwidgets/utils ./wxwidgets/uninstall.cmake ./wxwidgets/Makefile ./wxwidgets/cmake_install.cmake

cmake_universal_options='-DCMAKE_TOOLCHAIN_FILE=../toolchain.cmake -DwxBUILD_SHARED=ON -DDISABLE_CROSS_COMPILE=ON'

echo building lib

# build generator using cmake
cmake -B ./build -S ./wxwidgets ${cmake_universal_options}

# run the generator with half your logical cores. you can remove /2 to speed up thje build, or specify your own desired number. 
#cd build; make -j$((`nproc`));
cmake --build build -j$((`nproc`/1));

echo building executable


cmake -B . -S . ${cmake_universal_options}
