#pragma once

#include "canny.hpp"
#include <opencv2/opencv.hpp>
struct sLine {
    sLine();
    sLine(int r, int t) : rho(r), theta(t) {}
    int rho;
    int theta;
};

const int THETA_DIM = 360;

void hough_buffer(uchar *inBuff, int height, int width,
                  std::vector<sLine> &lines, int minLinePixels) {
    // make sure the num of lines detected are zero before hough
    lines.clear();
    int aWidth = THETA_DIM;
    int aHeight = sqrt(height * height + width * width) - 1;

    std::vector<int> accum(aWidth * aHeight);
    std::fill(accum.begin(), accum.end(), 0);
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (inBuff[row * width + col] == 255) {
                for (int theta = 0; theta < 360; theta++) {
                    double thetaRad = (float(theta) * 3.14) / 180.0;
                    int r = int(col * cos(thetaRad) + row * sin(thetaRad));
                    int element = r * THETA_DIM + theta;
                    if (r > 0 && r < aHeight) {
                        // push the line at the moment the threshold is reached
                        if (accum[element] == minLinePixels) {
                            lines.push_back(sLine(r, theta));
                        }
                        accum[element]++;
                    }
                }
            }
        }
    }

    std::cout << "number of lines detected " << lines.size() << std::endl;
}
int im_round(double number) {
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}
// accepts theta in degrees
void drawLine(cv::Mat &img, double rho, double theta_) {

    float theta = (theta_ * 3.14) / (180.0);
    cv::Point pt1, pt2;
    double a = cos(theta), b = sin(theta);
    double x0 = a * rho, y0 = b * rho;
    pt1.x = cvRound(x0 + 1000 * (-b));
    pt1.y = cvRound(y0 + 1000 * (a));
    pt2.x = cvRound(x0 - 1000 * (-b));
    pt2.y = cvRound(y0 - 1000 * (a));
    cv::line(img, pt1, pt2, cv::Scalar(0, 0, 255), 3, CV_AA);
}

void drawLines(cv::Mat const &image, std::vector<sLine> const &lines) {
    cv::Mat drawImage = image.clone();
    for (const auto &line : lines) {
        drawLine(drawImage, line.rho, line.theta);
    }
    cv::namedWindow("lines");
    cv::imshow("lines", drawImage);
    cv::waitKey(500);
}
int hough_custom(cv::Mat &image) {
    cv::Mat gray;
    cv::Mat grayOut;
    cv::Mat grayInt;
    if (image.channels() == 3) {
        cvtColor(image, gray, CV_BGR2GRAY);
    } else {
        image.copyTo(gray);
    }
    gray.copyTo(grayInt);
    gray.copyTo(grayOut);
    uchar *inBuff = (uchar *)gray.data;
    uchar *outBuff = (uchar *)grayOut.data;
    uchar *intBuff = (uchar *)grayInt.data;
    int height = image.rows;
    int width = image.cols;

    std::vector<sLine> lines;
    int numLinesDetected = 0;

    // minimum nuber of pixels required to be considered a line
    int minLinePixels = 50;

    detectCannyEdges(inBuff, outBuff, intBuff, height, width);

    for (int i = 0; i < 20; ++i) {

        int lineSegmentLength = minLinePixels + 10 * i;
        hough_buffer(outBuff, height, width, lines, lineSegmentLength);

        drawLines(image, lines);
    }
    return 0;
}

namespace hough {
cv::Mat readInput(std::string const &file) {
    cv::Mat img = cv::imread(file, 1);
    if (!img.empty()) {
        return (img);
    } else {
        std::cout << "\n\n\t\t!!!!Enter Valid file path!!!!!\n";
        exit(3);
    }
}
void test(int argc, char **argv) {
    std::cout << "entered hough Test" << std::endl;
    if (argc < 3) {
        std::cout << "\n\n\t!!!!Hough line detection needs an input image file "
                     "path!!!\n\n"
                  << std::endl;
        exit(3);
    } else {
        cv::Mat image = readInput(argv[2]).clone();
        hough_custom(image);
        cv::waitKey(50);
    }
}
} // namespace hough