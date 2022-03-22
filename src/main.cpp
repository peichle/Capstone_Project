#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

#include "read.hpp"
#include "write.hpp"
#include "detector.hpp"

std::string image_out = "../image_output.jpg";
std::string cfg_path{"../extern/yolov3-tiny.cfg"};
std::string weights_path{"../extern/yolov3-tiny.weights"};
std::string names_path{"../extern/coco.names"};

int main()
{
    // Link to the image must be changed manually
    std::string input = "../input/random_cars_2.jpg";
    
    
    std::ifstream inStream(input);
    std::unique_ptr<read> capture = std::make_unique<read>(input);
    cv::Mat image;
    capture->GetImage(image);
    std::unique_ptr<ObjectDetector> detector = std::make_unique<ObjectDetector>(cfg_path, weights_path, names_path);
    
    cv::Mat detected_image = detector->DetectObjects(image);
    std::unique_ptr<Output> output = std::make_unique<Output>(image_out);
    output->WriteImage(detected_image);
    
    // name the window
    static const std::string kWinName = "Object detector with openCV";
    namedWindow(kWinName, cv::WINDOW_NORMAL);
    // show image with boundingbox and confidence
    imshow(kWinName, image);
    // hold the window for 3 sec
    cv::waitKey(3000);
    // close everything and stop code
    cv::destroyAllWindows();

}