#pragma once
#include <opencv2/opencv.hpp>
void createGaussianFilter(cv::Mat& gKernel, int filterSize, double sigma)
{
    double r, s = ((float)filterSize / 2.0) * sigma * sigma;

    // sum is for normalization
    double sum = 0.0;
    gKernel = cv::Mat::zeros(filterSize, filterSize, CV_32FC1);
    int buff = filterSize / 2;
    for (int x = -buff; x <= buff; x++) {
        for (int y = -buff; y <= buff; y++) {
            r = sqrt(x * x + y * y);
            int row = (x + buff);
            int col = (y + buff);
            gKernel.at<float>(row, col) = (exp(-(r * r) / s)) / (CV_PI * s);
            sum += gKernel.at<float>(row, col);
        }
    }
    std::cout << sum << std::endl;
    // normalize the Kernel
    for (int i = 0; i < filterSize; ++i) {
        for (int j = 0; j < filterSize; ++j) {
            gKernel.at<float>(i, j) /= sum;
        }
    }
}

void gaussianFilter(cv::Mat const& img, cv::Mat& out, int kernelSize = 3)
{
    cv::Mat kernel;
    int offset = kernelSize / 2;
    int rows = img.rows;
    int cols = img.cols;
    int channels = img.channels();
    out = img.clone();
    createGaussianFilter(kernel, kernelSize, 1.0);
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            for (int ch = 0; ch < channels; ch++) {
                double sum = 0.;
                for (int r = -offset; r <= offset; ++r) {
                    for (int c = -offset; c <= offset; ++c) {
                        int i = row + r;
                        int j = col + c;
                        if (i >= 0 && i < img.rows && j >= 0 && j < img.cols) {
                            sum += img.at<cv::Vec3b>(i, j)[ch] * kernel.at<float>(r + offset, c + offset);
                        }
                    }
                }
                out.at<cv::Vec3b>(row, col)[ch] = sum;
            }
        }
    }
}
namespace gaussian {
cv::Mat readInput(std::string const& file)
{
    cv::Mat img = cv::imread(file, 1);
    if (!img.empty()) {
        return (img);
    } else {
        std::cout << "\n\n\t\t!!!!Enter Valid file path!!!!!\n";
        exit(3);
    }
}

inline void test(int argc, char** argv)
{
    if (argc < 3) {
        std::cout << "\n\n\t!!!!Gaussian needs an input image file path!!!\n\n" << std::endl;
        exit(3);
    } else {
        // custom implementation test
        cv::Mat image = readInput(argv[2]).clone();
        cv::Mat result;
        image.copyTo(result);
        gaussianFilter(image, result, 9);
        // opencv output
        cv::Mat out;
        GaussianBlur(image, out, cv::Size(9, 9), 0, 0);
        cv::imshow("input", image);
        cv::imshow("gaussian", result);
        cv::imshow("ocv-gaussian", out);
        cv::waitKey(2000);
    }
}
} // namespace gaussian