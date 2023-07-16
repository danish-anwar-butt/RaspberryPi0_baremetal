# RaspberryPi0_baremetal
Baremetal programing tutorial for Rasperry Pi Zero W
Baremetal Application is an application that run without an operating system. The code directly run on startup. In this tutorial we will run a C application to blink Action LED on Raspberry Pi Zero W. The setup use python application to upload binary application on raspberry pi.

use following command to setup toolchain
# sudo apt install -f ./gdb-arm-none-eabi_9.2-0ubuntu1_20.04+10-107e_amd64.deb
# arm-none-eabi-gcc --version

Install python3-pip: 
# sudo apt install python3-pip

Install the pyserial and xmodem packages: 
# python3 -m pip install pyserial xmodem
