#!/bin/bash
rm -rf CMakeFiles CMakeCache.txt cmake_install.cmake Makefile
cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=./arm.cmake robot.cmake ..
make VERBOSE=1

