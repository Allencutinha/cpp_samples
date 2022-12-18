#pragma once
#include "line.hpp"
#include <opencv2/opencv.hpp>
inline void drawRect(cv::Mat &img, cv::Point2d const &tl, cv::Point2d const &tr,
                     cv::Point2d const &br, cv::Point2d const &bl) {
    drawLine(img, tl, tr);
    drawLine(img, tr, br);
    drawLine(img, br, bl);
    drawLine(img, bl, tl);
}

inline void drawRectangle(cv::Mat &img, cv::Point2d const &tl,
                          cv::Point2d const &br) {
    cv::Point2d tr = cv::Point2d(tl.x, br.y);
    cv::Point2d bl = cv::Point2d(br.x, tl.y);
    drawRect(img, tl, tr, br, bl);
}

inline void drawRectangle(cv::Mat &img, cv::Point2d const &tl, int width,
                          int height) {
    cv::Point2d br = tl + cv::Point2d(height, width);
    drawRectangle(img, tl, br);
}

inline cv::Point2d rotatePoint(cv::Point2d const &refPt, float angle,
                               cv::Point2d const &pt) {
    float cx = refPt.x;
    float cy = refPt.y;
    float s = sin(angle);
    float c = cos(angle);

    cv::Point2d p = pt;
    // translate point back to origin:
    p.x -= cx;
    p.y -= cy;

    // rotate point
    float xnew = p.x * c - p.y * s;
    float ynew = p.x * s + p.y * c;

    // translate point back
    p.x = xnew + cx;
    p.y = ynew + cy;

    return p;
}
inline void drawRectangle(cv::Mat &img, cv::Point2d const &tl, int width,
                          int height, double angleDeg) {

    double angle = angleDeg * 3.14 / 180.;
    double dist = sqrt(width * width + height * height);

    cv::Point2d br = tl + cv::Point2d(height, width);
    cv::Point2d tr = cv::Point2d(tl.x, br.y);
    cv::Point2d bl = cv::Point2d(br.x, tl.y);

    tr = rotatePoint(tl, angle, tr);
    bl = rotatePoint(tl, angle, bl);
    br = rotatePoint(tl, angle, br);
    drawRect(img, tl, tr, br, bl);
}

void test_rectangle() {
    cv::Mat img = cv::Mat::zeros(400, 800, CV_8UC3);
    drawRectangle(img, cv::Point2d(100, 100), cv::Point2d(300, 500));
    drawRectangle(img, cv::Point2d(150, 150), 200, 100);
    drawRectangle(img, cv::Point2d(150, 150), 200, 100, 10);
    for (int i = 0; i < 36; ++i) {
        drawRectangle(img, cv::Point2d(150, 150), 200, 100, 10 * i);
    }
    drawRectangle(img, cv::Point2d(150, 150), 200, 100, 20);
    cv::imshow("test-rectangle", img);
    cv::waitKey(0);
}