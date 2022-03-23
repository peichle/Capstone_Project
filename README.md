# Capstone_Project
Object detection (tested with vehicles) using openCV and C++.
The detection works as follows. An image-path is in src/main.cpp. This image is taken and a bounding box is overlayed throw the usage of openCV. The bounding box is placed over the detected objects, in this case it tested with three cars. Furthermore, the confidence is calculated to which object type it is classified. The classes are used from openCV. The code finishes by it self after 3 seconds. This duration is implemented in the src/main.cpp and can be adjusted. 
Finally, the image with the bounding box is saved in the project workspace.

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


## Achieved Project Specifications

### README (All Rubric Points REQUIRED)
- [x] A README with instructions is included with the project
- [x] The README indicates which project is chosen.
- [x] The README includes information about each rubric point addressed.


### Compiling and Testing (All Rubric Points REQUIRED)
- [x] The submission must compile and run.

### Loops, Functions, I/O
- [x] The project demonstrates an understanding of C++ functions and control structures
- [x] The project reads data from a file and process the data, or the program writes data to a file 
- [ ] The project accepts user input and processes the input

### Object Oriented Programming
- [x] The project uses Object Oriented Programming techniques.
- [x] Classes use appropriate access specifiers for class members.
- [x] Class constructors utilize member initialization lists.
- [x] Classes abstract implementation details from their interfaces.
- [x] Classes encapsulate behavior.
- [x] Classes follow an appropriate inheritance hierarchy.
- [ ] Overloaded functions allow the same function to operate on different parameters.
- [ ] Derived class functions override virtual base class functions.
- [ ] Templates generalize functions in the project.

### Memory Management
- [x] The project makes use of references in function declarations.
- [x] The project uses destructors appropriately.
- [ ] The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
- [x] The project follows the Rule of 5.
- [x] The project uses move semantics to move data, instead of copying it, where possible.
- [x] The project uses smart pointers instead of raw pointers.

### Concurrency
- [ ] The project uses multithreading.
- [ ] A promise and future is used in the project.
- [ ] A mutex or lock is used in the project.
- [ ] A condition variable is used in the project.
