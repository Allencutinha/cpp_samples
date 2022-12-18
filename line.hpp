#pragma once
#include <opencv2/opencv.hpp>

inline void writePixel(cv::Mat &img, int x, int y) {
    if (x >= 0 && y >= 0 && x < img.rows && y < img.cols) {
        cv::Vec3b &pix = img.at<cv::Vec3b>(x, y);
        pix = cv::Vec3b(0, 255, 0);
    }
}

void drawLine(cv::Mat &img, cv::Point2d const &pt1, cv::Point2d const &pt2) {
    // Coordinates of the two points
    int x1 = pt1.x, y1 = pt1.y;
    int x2 = pt2.x, y2 = pt2.y;
    double dx = x1 - x2;
    double dy = y1 - y2;

    int lx = pt1.x;
    int rx = pt2.x;
    int ty = pt1.y;
    int by = pt2.y;
    if (dx > 0) {
        lx = pt2.x;
        rx = pt1.x;
    }
    if (dy > 0) {
        ty = pt2.y;
        by = pt1.y;
    }

    if (0 == int(dy)) {
        for (int x = lx; x <= rx; ++x) {
            int y = y1;
            writePixel(img, x, y);
        }
    } else if (0 == int(dx)) {
        for (int y = ty; y <= by; ++y) {
            int x = x1;
            writePixel(img, x, y);
        }
    } else {
        // Calculate the slope and y-intercept
        double m = (dy) / (dx);
        double b = y1 - m * x1;

        // Estimate the coordinates of the line
        if (dx < dy) {
            for (int x = lx; x <= rx; ++x) {
                int y = m * x + b;
                writePixel(img, x, y);
            }
        } else {
            for (int y = ty; y <= by; ++y) {
                int x = (y - b) / m;
                writePixel(img, x, y);
            }
        }
    }
}

inline void test_line() {
    cv::Mat img = cv::Mat::zeros(400, 800, CV_8UC3);
    // horizontal line
    drawLine(img, cv::Point2d(200, 300), cv::Point2d(200, 500));

    // vertical line
    drawLine(img, cv::Point2d(100, 400), cv::Point2d(300, 400));

    // negative slope line
    drawLine(img, cv::Point2d(100, 500), cv::Point2d(300, 300));

    // positive slope line
    drawLine(img, cv::Point2d(100, 300), cv::Point2d(300, 500));

    cv::imshow("test-lines", img);
    cv::waitKey(2000);
}
