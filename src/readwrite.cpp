
#include "readwrite.hpp"


readwrite::readwrite(std::string &input_path) {
    end_of_file_ = false;
    std::ifstream image_stream(input_path);
    if (image_stream) {
        cap_.open(input_path);
    }
    else {
        throw std::runtime_error("[ERROR:] Cannot open input file\n");
    }
}

bool readwrite::EndOfFile() {
    return end_of_file_;
}

readwrite::~readwrite() {
    cap_.release();
}

bool readwrite::GetImageFrame(cv::Mat &frame) {
    if (!readwrite::EndOfFile()) {
        cap_ >> frame;
    }
    end_of_file_ = true;
    return !readwrite::EndOfFile();
}



// readwrite::readwrite(std::string &output_path) {
//     output_path_ = output_path;
// }

void readwrite::WriteFrame(cv::Mat &frame) {
    cv::imwrite(output_path_, frame);
}