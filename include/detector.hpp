#ifndef DETECTOR_HPP
#define DETECTOR_HPP

#include <fstream>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class ObjectDetector
{


public:
    // Constructor
    ObjectDetector(std::string &model_cfg, std::string &model_weight, std::string &names_path);
    // copy Constructor
    ObjectDetector(const ObjectDetector &other); //copy constructor
    // copy assignment operator
    ObjectDetector &operator=(const ObjectDetector &other); //copy asignment operator
    // move Constructor
    ObjectDetector(ObjectDetector &&other); //move constructor
    // move assignment operator
    ObjectDetector &operator=(ObjectDetector &&other);
    // Destructor
    ~ObjectDetector() {}
    cv::Mat DetectObjects(cv::Mat &img);

private:
    void GetOutputLayerNames();
    void Get4DBlob(cv::Mat &img, cv::Mat &blob);
    void ImageProcessing(cv::Mat &img, const std::vector<cv::Mat> &outs, float &conf_threshold);
    void DrawBoundingBox(int classId, float conf, int left, int top, int right, int bottom, cv::Mat &img);
    void GetClasses();

    static std::vector<std::string> output_layer_names_;
    static std::vector<std::string> classes_;

    // Width and height of networks input image
    const int inpWidth = 350; 
    const int inpHeight = 350;
    // confidence threshold
    float conf_threshold; 
    // nms (Non Maximum Suppression) threshold
    // Explanation https://learnopencv.com/non-maximum-suppression-theory-and-implementation-in-pytorch/
    float nms_threshold;  
    
    cv::dnn::Net openCV_Net;
    std::string config_{""};
    std::string weights_{""};
    std::string names_path_{""};
};

#endif