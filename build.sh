#!/bin/bash


echo cleaning
#clean generators to avoid conflicts when installing another config

clearcache="--clearcache"

clearbuildcache=""
clearoutbuildcache=""

if [ "$1" = "$clearcache" ]; then
    echo "clearing cache"
    clearbuildcache="./build/CMakeCache.txt"
    clearoutbuildcache="./outbuilds/CMakeCache.txt"

fi

rm -rf ./CMakeFiles ./build/Makefile $clearbuildcache ./build/cmake_install.cmake ./build/CMakeFiles #./wxwidgets/libs ./wxwidgets/CMakeFiles ./wxwidgets/utils ./wxwidgets/uninstall.cmake ./wxwidgets/Makefile ./wxwidgets/cmake_install.cmake

rm -rf ./outbuilds/CMakeFiles ./outbuilds/MakeFile ./outbuilds/cmake_install.cmake $clearoutbuildcache

cmake_universal_options='-DCMAKE_TOOLCHAIN_FILE=./toolchain.cmake -DwxBUILD_SHARED=OFF -DDISABLE_CROSS_COMPILE=ON'

echo building lib

#annoying fix, cmake wont move them into the right directory


# build generator using cmake
cmake -B ./build -S ./wxwidgets ${cmake_universal_options}

# run the generator with half your logical cores. you can remove /2 to speed up thje build, or specify your own desired number. 
#cd build; make -j$((`nproc`));
cmake --build build -j$((`nproc`/1));

mv ./build/libs/webp-build/libwxwebpdemux-3.3.a ./build/lib;
mv ./build/libs/webp-build/libwxwebp-3.3.a ./build/lib;
mv ./build/libs/webp-build/libwxsharpyuv-3.3.a ./build/lib

echo building executable


cmake -B ./outbuilds -S . ${cmake_universal_options}

cmake --build ./outbuilds --verbose
