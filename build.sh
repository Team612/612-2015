#!/bin/bash

#satisfy dependencies
./.wpilib-download.sh
./.compiler-download.sh

#build
cd ./.build
rm -rf CMakeFiles CMakeCache.txt cmake_install.cmake Makefile
cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=./arm.cmake robot.cmake ..
make VERBOSE=1

#delete files that will make Eclipse fail
echo "Removing Cmake files!!"
rm -rf CMakeFiles
