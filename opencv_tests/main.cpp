//
// Created by Valery Piashchynski on 30/9/19.
//

#include </usr/local/Cellar/opencv/4.1.1_2/include/opencv4/opencv2/imgproc/imgproc.hpp>
#include </usr/local/Cellar/opencv/4.1.1_2/include/opencv4/opencv2/highgui/highgui.hpp>
#include </usr/local/Cellar/opencv/4.1.1_2/include/opencv4/opencv2/core/core.hpp>
#include </usr/local/Cellar/opencv/4.1.1_2/include/opencv4/opencv2/ml/ml.hpp>
#include </usr/local/Cellar/opencv/4.1.1_2/include/opencv4/opencv2/core/mat.hpp>
#include <opencv4/opencv.hpp>
#include "main.h"

using namespace cv;

int main(int argc, char** argv) {
    auto img = cv::imread(argv[1], -1);
    if (img.empty())
        return -1;
    
}