#include <opencv2/opencv.hpp>
inline void drawCircle(cv::Mat& img, cv::Point2d const& center, int radius)
{
    int count = 2 * 3.14 * radius;
    double inc = 2 * 3.14 / double(count);
    double angle = 0.;
    for (int i = 0; i < count; ++i) {
        int x = center.x + radius * cos(angle);
        int y = center.y + radius * sin(angle);
        angle += inc;
        cv::Vec3b& pix = img.at<cv::Vec3b>(x, y);
        pix = cv::Vec3b(0, 255, 0);
    }
}

inline void test_circle()
{
    cv::Mat img = cv::Mat::zeros(400, 800, CV_8UC3);
    drawCircle(img, cv::Point2d(200, 400), 50);
    cv::imshow("test-circle", img);
    cv::waitKey(2000);
}