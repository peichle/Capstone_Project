cmake_minimum_required(VERSION 3.13.0)

set(CMAKE_CXX_STANDARD 17)
project(car_detection)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")

find_package(OpenCV 4.1.0 REQUIRED)

INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

# Find all executables
file(GLOB SOURCES "src/*.cpp")

add_executable(car_detection ${SOURCES})
target_link_libraries(car_detection ${OpenCV_LIBS})
