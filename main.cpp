#include "circle.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include <opencv2/opencv.hpp>

void help() {
    std::cout << "Enter a valid input option" << std::endl;
    std::cout << "l - to draw line" << std::endl;
    std::cout << "c - to draw circle" << std::endl;
    std::cout << "r - to draw rectangle" << std::endl;
    exit(2);
}
int main(int argc, char **argv) {
    if (argc < 2) {
        help();
    }
    if (0 == std::strcmp("l", argv[1])) {
        test_line();
    } else if (0 == std::strcmp("c", argv[1])) {
        test_circle();
    } else if (0 == std::strcmp("r", argv[1])) {
        test_rectangle();
    } else {
        help();
    }
    return 0;
}