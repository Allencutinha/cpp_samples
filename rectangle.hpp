#pragma once
#include "line.hpp"
#include <opencv2/opencv.hpp>
inline void drawRectangle(cv::Mat &img, cv::Point2d const &tl,
                          cv::Point2d const &br) {
    cv::Point2d tr = cv::Point2d(tl.x, br.y);
    cv::Point2d bl = cv::Point2d(br.x, tl.y);
    drawLine(img, tl, tr);
    drawLine(img, tr, br);
    drawLine(img, br, bl);
    drawLine(img, bl, tl);
}

inline void drawRectangle(cv::Mat &img, cv::Point2d const &tl, int width,
                          int height) {
    cv::Point2d br = tl + cv::Point2d(height, width);
    drawRectangle(img, tl, br);
}

void test_rectangle() {
    cv::Mat img = cv::Mat::zeros(400, 800, CV_8UC3);
    drawRectangle(img, cv::Point2d(100, 100), cv::Point2d(300, 500));
    drawRectangle(img, cv::Point2d(150, 150), 200, 100);
    cv::imshow("test-rectangle", img);
    cv::waitKey(0);
}