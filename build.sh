#!/bin/bash

#satisfy dependencies
./.wpilib-download
./.compiler-download

#build
cd ./.build
rm -rf CMakeFiles CMakeCache.txt cmake_install.cmake Makefile
cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=./arm.cmake robot.cmake ..
make VERBOSE=1

