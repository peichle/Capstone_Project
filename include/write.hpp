#ifndef WRITE_HPP
#define WRITE_HPP

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

class Output {
public:
    // constructor
    Output(std::string &output_path); 
    //destructor
    ~Output(){}; 

    void WriteImage(cv::Mat &_mat); 

private:
    std::string output_path_{""}; //path for output file
};

#endif