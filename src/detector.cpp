#include "detector.hpp"

std::vector<std::string> ObjectDetector::output_layer_names_;
std::vector<std::string> ObjectDetector::classes_;


/*
    Rule of Five implemented
*/

// Constructor
ObjectDetector::ObjectDetector(std::string &m_conf, std::string &m_weight, 
                            std::string &names_path) : config_(m_conf), weights_(m_weight),
                            names_path_(names_path), nms_threshold(0), conf_threshold(0) {
    openCV_Net = cv::dnn::readNetFromDarknet(config_, weights_);
    GetOutputLayerNames();
    GetClasses();
}

// copy constructor
ObjectDetector::ObjectDetector(const ObjectDetector &other) {
    config_ = other.config_;
    weights_ = other.weights_;
    names_path_ = other.names_path_;
    openCV_Net = other.openCV_Net;
}

// copy assignment operator
ObjectDetector &ObjectDetector::operator=(const ObjectDetector &other) {
    if (this == &other){
        return *this;
    }
    config_ = other.config_;
    weights_ = other.weights_;
    names_path_ = other.names_path_;
    openCV_Net = other.openCV_Net;

    return *this;
}

// move constructor
ObjectDetector::ObjectDetector(ObjectDetector &&other) {
    config_ = std::move(other.config_);
    weights_ = std::move(other.weights_);
    names_path_ = std::move(other.names_path_);
    openCV_Net = std::move(other.openCV_Net);
}

// move assignment operator
ObjectDetector &ObjectDetector::operator=(ObjectDetector &&other) {
    if (this == &other) {
        return *this;
    }
    config_ = std::move(other.config_);
    weights_ = std::move(other.weights_);
    names_path_ = std::move(other.names_path_);
    openCV_Net = std::move(other.openCV_Net);

    return *this;
}



cv::Mat ObjectDetector::DetectObjects(cv::Mat &img) {
    cv::Mat blob;
    std::vector<cv::Mat> output;

    Get4DBlob(img, blob);
    
    openCV_Net.setInput(blob);
    openCV_Net.forward(output, output_layer_names_);
    ImageProcessing(img, output, conf_threshold);
    cv::Mat detected_frame;
    img.convertTo(detected_frame, CV_8U);
    return std::move(detected_frame);
}



void ObjectDetector::Get4DBlob(cv::Mat &img, cv::Mat &blob_output) {
    // Information taken from: 
    // https://docs.opencv.org/3.4/d6/d0f/group__dnn.html#ga29f34df9376379a603acd8df581ac8d7
    // Creates 4-dimensional blob from image. 
    cv::dnn::blobFromImage(img, blob_output, 1 / 255.0, 
                            cv::Size(inpWidth, inpHeight), cv::Scalar(0, 0, 0), true, false);
}

// Remove bbox with low confidence using nms
void ObjectDetector::ImageProcessing(cv::Mat &img, const std::vector<cv::Mat> &output, float &cfg_threshold) {
    std::vector<int> classIds;
    std::vector<float> confidences;
    std::vector<cv::Rect> boxes;
    for (size_t i = 0; i < output.size(); ++i) {   
        float *data = (float *)output[i].data;
        for (int j = 0; j < output[i].rows; ++j, data += output[i].cols) {
            cv::Mat scores = output[i].row(j).colRange(5, output[i].cols);
            cv::Point classIdPoint;
            double confidence;

            // find value and position with highest number
            minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
            if (confidence > cfg_threshold) {
                int centerX = (int)(data[0] * img.cols);
                int centerY = (int)(data[1] * img.rows);
                int width = (int)(data[2] * img.cols);
                int height = (int)(data[3] * img.rows);
                int left = centerX - width / 2;
                int top = centerY - height / 2;

                classIds.push_back(classIdPoint.x);
                confidences.push_back((float)confidence);
                boxes.push_back(cv::Rect(left, top, width, height));
            }
        }
    }

    // Non-Max Supression
    std::vector<int> indices;
    cv::dnn::NMSBoxes(boxes, confidences, cfg_threshold, nms_threshold, indices);
    for (size_t i = 0; i < indices.size(); ++i) {
        int idx = indices[i];
        cv::Rect box = boxes[idx];
        DrawBoundingBox(classIds[idx], confidences[idx], box.x, box.y, box.x + box.width, box.y + box.height, img);
    }
}

void ObjectDetector::DrawBoundingBox(int classId, float conf, int left, int top, int right, int bottom, cv::Mat &img) {
    
    cv::rectangle(img, cv::Point(left, top), cv::Point(right, bottom), cv::Scalar(10, 178, 50), 3);

    //Get the object type name and confidence
    std::string label = cv::format("%.2f", conf);
    if (!classes_.empty())
    {
        CV_Assert(classId < (int)classes_.size());
        label = classes_[classId] + ":" + label;
    }

    cv::putText(img, label, cv::Point(left, bottom), cv::FONT_HERSHEY_DUPLEX, 1.00, 
                cv::Scalar(0, 0, 255), true);
}

void ObjectDetector::GetOutputLayerNames() {
    if (output_layer_names_.empty()) {
        std::vector<int> output_layers = openCV_Net.getUnconnectedOutLayers();
        std::vector<std::string> layer_names = openCV_Net.getLayerNames();
        output_layer_names_.resize(output_layers.size());
        for (std::size_t i = 0; i < output_layers.size(); i++) {
            output_layer_names_.at(i) = layer_names[output_layers[i] - 1];
        }
    }
}

// Read existing classes from openCV
void ObjectDetector::GetClasses() {
    std::ifstream ifs(names_path_.c_str());
    if(!ifs.is_open())
        CV_Error(cv::Error::StsError, "Class File (" + names_path_ + ") not found.");
    std::string line;
    while(std::getline(ifs, line)) {
        classes_.push_back(line);
    }
}