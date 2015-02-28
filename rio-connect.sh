#!/bin/bash
sudo ifconfig eth0 down
sudo ifconfig eth0 up 
sudo ifconfig eth0 169.254.223.225
sudo ifconfig eth0 netmask 255.255.0.0
ping -c 3 169.254.223.223
echo $?
