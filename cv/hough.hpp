#pragma once

#include "canny.hpp"
#include <opencv2/opencv.hpp>
typedef struct {
    int rho;
    int theta;
} sLine;

const int THETA_DIM = 180;

const int MAX_LINES = 1000;

void hough_buffer(uchar *inBuff, int height, int width,
                  std::vector<sLine> &lines, int minLinePixels) {
    // make sure the num of lines detected are zero before hough
    lines.clear();
    int aWidth = THETA_DIM;
    int aHeight = sqrt(height * height + width * width) - 1;

    std::vector<int> accum(aWidth * aHeight);
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (inBuff[row * width + col] == 255) {
                for (int theta = 0; theta < 180; theta++) {
                    double thetaRad = (float(theta) * 3.14) / 180.0;
                    int r = int(col * cos(thetaRad) + row * sin(thetaRad));
                    if (r > 0 && r < aHeight) {
                        accum[r * THETA_DIM + theta]++;
                    }
                }
            }
        }
    }

    // detect lines which have voted more than 100 pixels
    for (int t = 0; t < THETA_DIM; t++) {
        for (int r = 0; r < aHeight; r++) {
            if (accum[r * THETA_DIM + t] > minLinePixels) {
                sLine l;
                l.rho = r;
                l.theta = t;
                lines.push_back(l);
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
    // draw_line(inBuff, height, width, x1, y1, x2, y2);
    cv::line(img, pt1, pt2, cv::Scalar(0, 0, 255), 3, CV_AA);
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
        cv::Mat drawImage = image.clone();
        for (const auto &line : lines) {
            drawLine(drawImage, line.rho, line.theta);
        }

        cv::namedWindow("edge");
        cv::imshow("edge", grayOut);

        cv::namedWindow("lines");
        cv::imshow("lines", drawImage);
        cv::waitKey(500);
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
        cv::waitKey(0);
    }
}
} // namespace hough