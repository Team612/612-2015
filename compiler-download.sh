#!/bin/bash

# Will download required packages for building
sudo apt-add-repository -y ppa:byteit101/frc-toolchain 
sudo apt update -y
sudo apt install -y frc-toolchain
