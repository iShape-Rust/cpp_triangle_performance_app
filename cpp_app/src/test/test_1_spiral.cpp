//
// Created by Nail Sharipov on 05.06.2025.
//

#include "test_1_spiral.h"

vector<vector<Point>> SpiralTest::shape(size_t count) {
    auto main = spiral(count);
    vector<vector<Point>> shape = {
            main
    };

    return shape;
}

vector<double> SpiralTest::points(size_t count) {
    auto contour = spiral(count);
    vector<double> flat;
    flat.reserve(contour.size() * 2);
    for (const auto& p : contour) {
        flat.push_back(p[0]);
        flat.push_back(p[1]);
    }

    return flat;
}

vector<Point> SpiralTest::spiral(size_t count) {
    auto s = 10.0;

    vector<Point> path_0;
    vector<Point> path_1;

    path_0.reserve(count);
    path_1.reserve(count / 2);

    double s0 = s;
    double s1 = 2.0 * s;
    double x0 = 0.0, y0 = 0.0;
    double x1 = 0.0, y1 = 0.0;

    y0 += s0;
    path_0.push_back({x0, y0});
    x0 += s0;
    path_0.push_back({x0, y0});

    path_1.push_back({x1, y1});
    x1 += s1;
    path_1.push_back({x1, y1});
    s1 += s;

    size_t n = count - 4;

    for (size_t i = 0; i < n / 2; ++i) {
        switch (i % 4) {
            case 0: y0 += s0; y1 += s1; break;
            case 1: x0 -= s0; x1 -= s1; break;
            case 2: y0 -= s0; y1 -= s1; break;
            case 3: x0 += s0; x1 += s1; break;
        }

        path_0.push_back({x0, y0});
        path_1.push_back({x1, y1});
        s0 += s;
        s1 += s;
    }

    path_1.insert(path_1.end(), path_0.rbegin(), path_0.rend());
    return path_1;
}