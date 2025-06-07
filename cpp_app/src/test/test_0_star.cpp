#include "test_0_star.h"

vector<vector<Point>> StarTest::shape(size_t count) {
    auto main = star(count);
    vector<vector<Point>> shape = {
            main
    };

    return shape;
}

vector<double> StarTest::points(size_t count) {
    auto contour = star(count);
    vector<double> flat;
    flat.reserve(contour[0].size() * 2);
    for (const auto &p: contour) {
        flat.push_back(p[0]);
        flat.push_back(p[1]);
    }

    return flat;
}

vector<Point> StarTest::star(size_t count) {
    auto r0 = 160.0;
    auto r1 = 80.0;

    std::vector<Point> path;
    path.reserve(count);

    const size_t n = count / 2;
    const double da = M_PI / static_cast<double>(n);
    double a = 0.0;

    for (size_t i = 0; i < n; ++i) {
        path.push_back({std::cos(a) * r0, std::sin(a) * r0});
        a += da;
        path.push_back({std::cos(a) * r1, std::sin(a) * r1});
        a += da;
    }

    return path;
}