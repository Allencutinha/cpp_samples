#include "circle.hpp"
#include <opencv2/opencv.hpp>

void test_circle() {
    cv::Mat img = cv::Mat::zeros(400, 800, CV_8UC3);
    drawCircle(img, cv::Point2d(200, 400), 50);
    cv::imshow("dekh-le", img);
    cv::waitKey(0);
}

void test_rectangle() {}

void help() {
    std::cout << "Enter a valid input option" << std::endl;
    std::cout << "c - to draw circle" << std::endl;
    std::cout << "r - to draw rectangle" << std::endl;
    exit(2);
}
int main(int argc, char ** argv) {
    if (argc < 2) {
        help();
    }
    if (0 == std::strcmp("c", argv[1])) {
        test_circle();
    } else if (0 == std::strcmp("c", argv[1])) {

    } else {
        help();
    }
    return 0;
}