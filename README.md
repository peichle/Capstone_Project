# Capstone_Project
Object detection (tested with cars) using openCV and C++.
An image path is enterd in src/main.cpp. This image is taken and a bounding box is overlayed throw the usage of openCV.
Furthermore the confidence is calculated to which object type it is classified. The classes are also used from openCV.


## Dependecies
- Ubuntu 20.04
- cmake >= 3.22.3
- g++/gcc >= 9.4.0
- openCV >= 4.2.0

## Project Structure

There are 4 main folders

`/src` - contains the c++/cuda source files

`/include` - contains the c++ header files

`/input` - contains some images to test the code

`/extern` - contains the model (yolo3 and coco) which needs to be loaded 

## Getting started
Clone the repo
``` Git clone https://github.com/peichle/Capstone_Project.git ```

Load the data from extern/model.sh
1. ``` cd extern ```
2. ``` sudo chmod a+x Model.sh ```

Then the following can be executed
```
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
