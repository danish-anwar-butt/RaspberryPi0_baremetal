# RaspberryPi0_baremetal
Baremetal programing tutorial for Rasperry Pi Zero W
Baremetal Application is an application that run without an operating system. The code directly run on startup. In this tutorial we will run a C application to blink Action LED on Raspberry Pi Zero W. The setup use python application to upload binary application on raspberry pi.

use following command to setup toolchain
```console
sudo apt install -f ./gdb-arm-none-eabi_9.2-0ubuntu1_20.04+10-107e_amd64.deb
arm-none-eabi-gcc --version
```

Install python3-pip: 
```console
sudo apt install python3-pip
```

Install the pyserial and xmodem packages: 
```console
python3 -m pip install pyserial xmodem
```

## Directories
### bootloader: 
This directory contain the bootloader for Raspberry Pi Zero W. Copy entire content to an SD Card and insert it into RPI 0.


### app: 
This directory contain a minimal file strucutre of a C application that can be cross compiled for RPI 0. The make file build a .bin file that can be uploaded to raspberry pi using the bootloader and python application on host.


### pytho_app_host: 
Host application to upload bin file on RPI 0. This is a modified version of Stanford CS107E course application.


### toolchain: 
This contain a deb package that can be installed to compiled C application for RPI 0.

## Note: 
The default USB port is /dev/ttyUSB0 in rpi-run.py change it according to your setup in rpi-run.py file.
In order to make rpi-run.py to terminal executable follow:
1. At the unix command prompt, type the following to make myscript.py executable: $ chmod +x myscript.py.
2. Move rpi-run.py into your bin directory, and it will be runnable from anywhere.


