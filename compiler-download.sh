#!/bin/bash

# Will download required packages for building
sudo apt-add-repository -y ppa:byteit101/frc-toolchain 
sudo apt-get update -y
sudo apt-get install -y frc-toolchain
