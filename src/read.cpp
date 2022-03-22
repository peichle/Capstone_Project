#include "read.hpp"


read::read(std::string &image_path) {
    finish_ = false;
    std::ifstream image_stream(image_path);
    if (image_stream) {
        cap_ = cv::VideoCapture(image_path);
    }
    else {
        throw std::runtime_error("[ERROR:] Cannot open input file\n");
    }
}

read::~read() {
    cap_.release();
}

bool read::Finishing() {
    return finish_;
}

bool read::GetImage(cv::Mat &_mat) {
    if (!read::Finishing()) {
        // operator overloading from openCV
        cap_ >> _mat;
    }
    finish_ = true;
    return !read::Finishing();
}