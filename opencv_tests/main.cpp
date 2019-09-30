//
// Created by Valery Piashchynski on 30/9/19.
//

#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "main.h"

using namespace cv;

int main(int argc, char** argv) {
    auto img = cv::imread(argv[1], cv::COLOR_BayerBG2BGR);
    if (img.empty())
        return -1;

    cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example 1", img);
    cv::waitKey(0);
    cv::destroyWindow("Example1");
    return 0;
}