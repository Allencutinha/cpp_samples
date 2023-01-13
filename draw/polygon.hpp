#pragma once
#include "line.hpp"
#include <opencv2/opencv.hpp>

inline void drawPolygon(cv::Mat& img, std::vector<cv::Point2d> const& poly)
{
    int n = poly.size();
    for (int i = 0; i < n; ++i) {
        drawLine(img, poly[i % n], poly[(i + 1) % n]);
    }
}

inline void drawCirclePoly(cv::Mat& img, cv::Point2d const& center, int radius)
{
    int count = 3.14 * radius / 4;
    double inc = 2 * 3.14 / double(count);
    double angle = 0.;
    std::vector<cv::Point2d> poly;
    for (int i = 0; i < count; ++i) {
        int x = center.x + radius * cos(angle);
        int y = center.y + radius * sin(angle);
        angle += inc;
        poly.push_back(cv::Point2d(x, y));
    }
    drawPolygon(img, poly);
}

inline void test_polygon()
{
    cv::Mat img = cv::Mat::zeros(400, 800, CV_8UC3);
    std::vector<cv::Point2d> poly;
    // triangle
    poly.push_back(cv::Point2d(300, 300));
    poly.push_back(cv::Point2d(200, 550));
    poly.push_back(cv::Point2d(380, 500));
    drawPolygon(img, poly);
    poly.clear();
    // quadrilateral
    poly.push_back(cv::Point2d(120, 120));
    poly.push_back(cv::Point2d(80, 240));
    poly.push_back(cv::Point2d(200, 200));
    poly.push_back(cv::Point2d(310, 100));
    drawPolygon(img, poly);

    // circle using polygon
    drawCirclePoly(img, cv::Point2d(200, 400), 150);

    cv::imshow("test-polygon", img);
    cv::waitKey(2000);
}
