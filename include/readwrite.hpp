#ifndef READWRITE_HPP
#define READWRITE_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

//Base class to get image input.
class readwrite
{
public:
    explicit readwrite(std::string &input_path); //parsing path for input image file
    bool EndOfFile(); //parse end of image file
    bool GetImageFrame(cv::Mat &frame); //frame of input image
    ~readwrite();
    //Output(){}; //constructor
    //readwrite(std::string &output_path); //passing path for output file
    void WriteFrame(cv::Mat &frame); //writing the frame to the output file
    //~Output(){}; //destructor

protected:
    bool end_of_file_;  //end of image file
    cv::VideoCapture cap_; //get image through cv
    std::string output_path_{""}; //path for output file

};



#endif