#include "write.hpp"

Output::Output(std::string &output_path) {
    output_path_ = output_path;
}

void Output::WriteImage(cv::Mat &frame) {
    cv::imwrite(output_path_, frame);
}