#pragma once

#include <algorithm>          // for std::sort
#include <array>              // for std::array
#include <opencv2/opencv.hpp> // for cv::Mat, etc.

// Function to apply the median filter to an image
void medianFilter(cv::Mat &image, int KERNEL_SIZE = 3) {
    // Create a kernel to store the neighboring pixels
    std::vector<uchar> kernel(KERNEL_SIZE * KERNEL_SIZE);

    // Temporary image to store the filtered image
    cv::Mat temp(image.size(), image.type());

    // Iterate over the image
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            // Fill the kernel with the neighboring pixels
            int index = 0;
            for (int m = -KERNEL_SIZE / 2; m <= KERNEL_SIZE / 2; m++) {
                for (int n = -KERNEL_SIZE / 2; n <= KERNEL_SIZE / 2; n++) {
                    int x = i + m;
                    int y = j + n;
                    // Check if the pixel is out of bounds
                    if (x >= 0 && x < image.rows && y >= 0 && y < image.cols) {
                        kernel[index++] = image.at<uchar>(x, y);
                    }
                }
            }
            // Sort the kernel
            std::sort(kernel.begin(), kernel.end());
            // Set the median value as the new pixel value
            temp.at<uchar>(i, j) = kernel[KERNEL_SIZE * KERNEL_SIZE / 2];
        }
    }

    // Copy the filtered image back to the original image
    image = temp.clone();
}

namespace medianfilter {
cv::Mat readInput(std::string const &file) {
    cv::Mat img = cv::imread(file, 0);
    if (!img.empty()) {
        return (img);
    } else {
        std::cout << "\n\n\t\t!!!!Enter Valid file path!!!!!\n";
        exit(3);
    }
}

void test(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "\n\n\t!!!!Median needs an input image file path!!!\n\n"
                  << std::endl;
        exit(3);
    } else {
        // custom implementation test
        cv::Mat image = readInput(argv[2]).clone();
        cv::Mat result;
        image.copyTo(result);
        medianFilter(result, 3);
        cv::imshow("input", image);
        cv::imshow("median", result);
        cv::waitKey(0);
    }
}

} // namespace medianfilter