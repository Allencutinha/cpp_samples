#pragma once

#include <algorithm>
#include <random>
#include <vector>
namespace linefit3d {
struct Point3D {
    double x;
    double y;
    double z;
};

struct Line3D {
    Point3D point;
    Point3D direction;
};

// Calculates the distance from a point to a line.
double pointToLineDistance(const Point3D& point, const Line3D& line)
{
    // Calculate the direction vector of the line.
    Point3D lineDirection = {
        line.direction.x - line.point.x, line.direction.y - line.point.y, line.direction.z - line.point.z};

    // Calculate the projection of the point onto the line.
    double t = ((point.x - line.point.x) * lineDirection.x + (point.y - line.point.y) * lineDirection.y +
                (point.z - line.point.z) * lineDirection.z) /
               (lineDirection.x * lineDirection.x + lineDirection.y * lineDirection.y +
                lineDirection.z * lineDirection.z);

    Point3D projection = {line.point.x + t * lineDirection.x,
                          line.point.y + t * lineDirection.y,
                          line.point.z + t * lineDirection.z};

    // Calculate the distance between the point and its projection onto the
    // line.
    double distance = std::sqrt((point.x - projection.x) * (point.x - projection.x) +
                                (point.y - projection.y) * (point.y - projection.y) +
                                (point.z - projection.z) * (point.z - projection.z));

    return distance;
}

// Fits a line to the given 3D points using the RANSAC algorithm.
Line3D fitLineRANSAC(const std::vector<Point3D>& points, double inlierThreshold, int numIterations)
{
    std::mt19937 rng;
    rng.seed(std::random_device()());

    Line3D bestLine;
    int bestNumInliers = 0;

    for (int i = 0; i < numIterations; i++) {
        // Randomly select two points.
        std::uniform_int_distribution<int> dist(0, points.size() - 1);
        int index1 = dist(rng);
        int index2 = dist(rng);

        // Calculate the direction of the line passing through the two points.
        Point3D direction = {points[index2].x - points[index1].x,
                             points[index2].y - points[index1].y,
                             points[index2].z - points[index1].z};

        // Normalize the direction vector.
        double norm =
            std::sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
        direction.x /= norm;
        direction.y /= norm;
        direction.z /= norm;

        // Create a line passing through the first point and with the calculated
        // direction.
        Line3D line = {points[index1], direction};

        // Count the number of inliers that are within the inlier threshold.
        int numInliers = 0;
        for (const Point3D& point: points) {
            if (pointToLineDistance(point, line) < inlierThreshold) {
                numInliers++;
            }
        }

        // Update the best line if necessary.
        if (numInliers > bestNumInliers) {
            bestLine = line;
            bestNumInliers = numInliers;
        }
    }
    std::cout << "\nInput size : " << points.size() << "\tInliers : " << bestNumInliers << std::endl;
    return bestLine;
}

int test1()
{
    // Create some example 3D points.
    std::vector<Point3D> points = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {4, 5, 6}, {5, 6, 7}};

    // Fit a line to the points using RANSAC.
    Line3D line = fitLineRANSAC(points, 1.0, 1000);

    // Print the result.
    std::cout << "Point: (" << line.point.x << ", " << line.point.y << ", " << line.point.z << ")"
              << std::endl;
    std::cout << "Direction: (" << line.direction.x << ", " << line.direction.y << ", " << line.direction.z
              << ")" << std::endl;

    return 0;
}

int test2()
{
    std::vector<Point3D> points = {{1, 2, 3},    {2, 3, 4},    {3, 4, 5},    {4, 5, 6},    {5, 6, 7},
                                   {6, 7, 8},    {7, 8, 9},    {8, 9, 10},   {9, 10, 11},  {10, 11, 12},
                                   {11, 12, 13}, {12, 13, 14}, {13, 14, 15}, {14, 15, 16}, {15, 16, 17},
                                   {16, 17, 18}, {17, 18, 19}, {18, 19, 20}, {19, 20, 21}, {20, 21, 22}};

    // Fit a line to the points using RANSAC.
    Line3D line = fitLineRANSAC(points, 1.0, 1000);

    // Print the result.
    std::cout << "Point: (" << line.point.x << ", " << line.point.y << ", " << line.point.z << ")"
              << std::endl;
    std::cout << "Direction: (" << line.direction.x << ", " << line.direction.y << ", " << line.direction.z
              << ")" << std::endl;
    return 0;
}
int test3()
{
    std::vector<Point3D> points = {
        {1, 2, 3},    {2, 3, 4},    {3, 4, 5},    {4, 5, 6},    {5, 6, 7},    {6, 7, 8},    {7, 8, 9},
        {8, 9, 10},   {9, 10, 11},  {10, 11, 12}, {11, 12, 13}, {12, 13, 14}, {13, 14, 15}, {14, 15, 16},
        {15, 16, 17}, {16, 17, 18}, {17, 18, 19}, {18, 19, 20}, {19, 20, 21}, {20, 21, 22}, {21, 22, 23},
        {22, 23, 24}, {23, 24, 25}, {24, 25, 26}, {25, 26, 27}, {26, 27, 28}, {27, 28, 29}, {28, 29, 30},
        {29, 30, 31}, {30, 31, 32}, {31, 32, 33}, {32, 33, 34}, {33, 34, 35}, {34, 35, 36}, {35, 36, 37},
        {36, 37, 38}, {37, 38, 39}, {38, 39, 40}, {39, 40, 41}, {40, 41, 42}, {41, 42, 43}, {42, 43, 44},
        {43, 44, 45}, {44, 45, 46}, {45, 46, 47}, {46, 47, 48}, {47, 48, 49}, {48, 49, 50}, {49, 50, 51},
        {50, 51, 52}};

    // Fit a line to the points using RANSAC.
    Line3D line = fitLineRANSAC(points, 1.0, 1000);

    // Print the result.
    std::cout << "Point: (" << line.point.x << ", " << line.point.y << ", " << line.point.z << ")"
              << std::endl;
    std::cout << "Direction: (" << line.direction.x << ", " << line.direction.y << ", " << line.direction.z
              << ")" << std::endl;
    return 0;
}

int test4_slope3()
{
    std::vector<Point3D> points = {{1, 3, 9},    {2, 6, 12},   {3, 9, 15},   {4, 12, 18},  {5, 15, 21},
                                   {6, 18, 24},  {7, 21, 27},  {8, 24, 30},  {9, 27, 33},  {10, 30, 36},
                                   {11, 33, 39}, {12, 36, 42}, {13, 39, 45}, {14, 42, 48}, {15, 45, 51},
                                   {16, 48, 54}, {17, 51, 57}, {18, 54, 60}, {19, 57, 63}, {20, 60, 66},
                                   {21, 63, 69}, {22, 66, 72}, {23, 69, 75}, {24, 72, 78}, {25, 75, 81},
                                   {26, 78, 84}, {27, 81, 87}, {28, 84, 90}, {29, 87, 93}, {30, 90, 96}};
    // Fit a line to the points using RANSAC.
    Line3D line = fitLineRANSAC(points, 1.0, 1000);

    // Print the result.
    std::cout << "Point: (" << line.point.x << ", " << line.point.y << ", " << line.point.z << ")"
              << std::endl;
    std::cout << "Direction: (" << line.direction.x << ", " << line.direction.y << ", " << line.direction.z
              << ")" << std::endl;
    return 0;
}
void test()
{
    test1();
    test2();
    test3();
    test4_slope3();
}
/*
Here are ten unit tests that you can use to test the fitLineRANSAC function:

Test fitting a line to a single point:
 Create a vector with a single point, and
verify that the returned line passes through that point.

Test fitting a line to two points: Create a vector with two points that are not
collinear, and verify that the returned line passes through both points.

Test fitting a line to three points: Create a vector with three points that are
not collinear, and verify that the returned line passes through at least two of
the points.

Test fitting a line to a random set of points: Create a vector with a random set
of points, and verify that the returned line has a reasonable number of inliers.

Test fitting a line to a set of points with a large inlier threshold: Create a
vector with a random set of points and a large inlier threshold, and verify that
the returned line has a high number of inliers.

Test fitting a line to a set of points with a small inlier threshold: Create a
vector with a random set of points and a small inlier threshold, and verify that
the returned line has a low number of inliers.


Test fitting a line to a set of points with a very small inlier threshold:
Create a vector with a random set of points and a very small inlier threshold,
and verify that the returned line has a very low number of inliers.

Test fitting a line to a set of points with a zero inlier threshold: Create a
vector with a random set of points and a zero inlier threshold, and verify that
the returned line has exactly two inliers.

Test fitting a line to a set of points with a large number of iterations: Create
a vector with a random set of points and a large number of iterations, and
verify that the returned line has a reasonable number of inliers.

Test fitting a line to a set of points with a small number of iterations: Create
a vector with a random set of points and a small number of iterations, and
verify that the returned line has a reasonable number of inliers.

You can use these unit tests to verify that the fitLineRANSAC function
is working correctly for a variety of different input cases.
*/
} // namespace linefit3d
