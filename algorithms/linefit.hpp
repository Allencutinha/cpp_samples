#pragma once

#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

namespace linefit {
// A point in 2D space
struct Point {
    double x;
    double y;
};

// The line is represented as y = m * x + b
struct Line {
    double m;
    double b;
};

Line fitLine(const std::vector<Point>& points, int numIterations = 300, double inlierThreshold = 0.01)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, points.size() - 1);

    Line bestLine;
    int maxNumInliers = 0;

    // Iteratively fit a line to the points using RANSAC
    for (int i = 0; i < numIterations; i++) {
        // Sample two points randomly
        int idx1 = dis(gen);
        int idx2 = dis(gen);
        Point point1 = points[idx1];
        Point point2 = points[idx2];

        // Fit a line to the two points
        double m = (point2.y - point1.y) / (point2.x - point1.x);
        double b = point1.y - m * point1.x;
        Line line = {m, b};

        // Count the number of inliers (points that are within inlierThreshold
        // of the line)
        int numInliers = 0;
        for (const auto& point: points) {
            double error = std::abs(point.y - line.m * point.x - line.b) / std::sqrt(line.m * line.m + 1);
            if (error < inlierThreshold) {
                numInliers++;
            }
        }

        // Update the best line if this one has more inliers
        if (numInliers > maxNumInliers) {
            maxNumInliers = numInliers;
            bestLine = line;
        }
    }

    return bestLine;
}

void test()
{
    std::cout << "Line fiting Test :\n";
    // Test fitting a line to a set of points with no noise
    {
        std::vector<Point> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
        Line line = fitLine(points);
        assert(std::abs(line.m - 1) < 1e-6);
        assert(std::abs(line.b - 1) < 1e-6);
    }

    // Test fitting a line to a set of points with noise
    {
        std::vector<Point> points = {{1, 5}, {2, 7}, {3, 9}, {4, 11}, {5, 13}};
        Line line = fitLine(points, 30, 0.1);
        std::cout << "y = " << line.m << "x + " << line.b << std::endl;
    }

    // Test fitting a line using RANSAC
    {
        std::vector<Point> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
        Line line = fitLine(points, 1000, 1e-6);
        std::cout << "y = " << line.m << "x + " << line.b << std::endl;
    }
    {
        std::vector<Point> points = {
            {8, 3}, {2, 10}, {11, 3}, {6, 6}, {5, 8}, {4, 12}, {12, 1}, {9, 4}, {6, 9}, {1, 14}};

        Line line = fitLine(points);
        std::cout << "y = " << line.m << "x + " << line.b << std::endl;
    }
}
} // namespace linefit
