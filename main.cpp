#include "circle.hpp"
#include "line.hpp"
#include "polygon.hpp"
#include "rectangle.hpp"
#include <opencv2/opencv.hpp>

void help() {
    std::cout << "Enter a valid input option" << std::endl;
    std::cout << "l - to draw line" << std::endl;
    std::cout << "c - to draw circle" << std::endl;
    std::cout << "r - to draw rectangle" << std::endl;
    exit(2);
}
bool streq(std::string const &a, std::string const &b) {
    return (0 == std::strcmp(a.c_str(), b.c_str()));
}
int main(int argc, char **argv) {
    if (argc < 2) {
        help();
    }
    if (streq("l", argv[1])) {
        test_line();
    } else if (streq("c", argv[1])) {
        test_circle();
    } else if (streq("r", argv[1])) {
        test_rectangle();
    } else if (streq("p", argv[1])) {
        test_polygon();
    } else {
        help();
    }
    cv::destroyAllWindows();
    return 0;
}
