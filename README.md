# Capstone_Project
Object detection (tested with cars) using openCV and C++.
An image path is enterd in src/main.cpp. This image is taken and a bounding box is overlayed throw the usage of openCV.
Furthermore the confidence is calculated to which object type it is classified. The classes are also used from openCV.


## System dependecies
- Ubuntu 20.04
- cmake >= 3.22.3
- g++/gcc >= 9.4.0

## Getting started
```
Git clone https://github.com/peichle/Capstone_Project.git
mkdir build
cd /build
cmake .. && make
./car_detection
```
## Adjustments 
Changes by the user can be done in the main file 

![Result](https://github.com/peichle/Capstone_Project/blob/main/image_output.jpg?raw=true)

## References
- Darknet: https://github.com/pjreddie/darknet
- openCV: https://docs.opencv.org/4.2.0/index.html
