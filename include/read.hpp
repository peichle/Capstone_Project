#ifndef READ_HPP
#define READ_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class read
{
public:
    // constructor / destructor
    read(std::string &image_path); 
    ~read();
    
    bool Finishing();
    bool GetImage(cv::Mat &_mat); 
    
private:
    bool finish_;  
    cv::VideoCapture cap_; 
};



#endif