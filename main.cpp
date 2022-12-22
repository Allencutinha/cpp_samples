#include "canny.hpp"
#include "circle.hpp"
#include "gaussian.hpp"
#include "line.hpp"
#include "linefit.hpp"
#include "linefit3d.hpp"
#include "median.hpp"
#include "polygon.hpp"
#include "rectangle.hpp"
#include <opencv2/opencv.hpp>

void help() {
    std::cout << "Enter a valid input option" << std::endl;
    std::cout << "l - to draw line" << std::endl;
    std::cout << "c - to draw circle" << std::endl;
    std::cout << "r - to draw rectangle" << std::endl;
    std::cout << "p - to draw polygon" << std::endl;
    std::cout << "g image - gaussian filter" << std::endl;
    exit(2);
}
bool eq(std::string const &a, std::string const &b) {
    return (0 == std::strcmp(a.c_str(), b.c_str()));
}

int main(int argc, char **argv) {
    if (argc < 2) {
        help();
    }
    if (eq("l", argv[1])) {
        test_line();
    } else if (eq("c", argv[1])) {
        test_circle();
    } else if (eq("r", argv[1])) {
        test_rectangle();
    } else if (eq("p", argv[1])) {
        test_polygon();
    } else if (eq("g", argv[1])) {
        test_gaussian(argc, argv);
    } else if (eq("fitline", argv[1])) {
        linefit::test();
    } else if (eq("fitline3d", argv[1])) {
        linefit3d::test();
    } else if (eq("canny", argv[1])) {
        medianfilter::test(argc, argv);
    } else {
        help();
    }
    cv::destroyAllWindows();
    return 0;
}
