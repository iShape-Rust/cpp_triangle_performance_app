//
// Created by Nail Sharipov on 03.05.2025.
//

#include "test_3_star_with_8_holes.h"
#include <cmath>
#include <chrono>
#include <iostream>

vector<Point> StarWith8HolesTest::contour(size_t count) const {
    return star(count);
}

vector<double> StarWith8HolesTest::points(size_t count) const {
    auto contour = star(count);
    vector<double> flat;
    flat.reserve(contour.size() * 2);
    for (const auto& p : contour) {
        flat.push_back(p[0]);
        flat.push_back(p[1]);
    }

    return flat;
}

vector<Point> StarWith8HolesTest::star(size_t count) const {
    size_t corners_count = 8;
    size_t points_per_corner = count / corners_count;

    std::vector<Point> main = StarBuilder::generate_star(
            80.0,
            0.3,
            0.0,                // start_angle
            points_per_corner,
            corners_count,
            true,               // direction
            {0.0, 0.0}          // center
    );

    std::vector<Point> hole = StarBuilder::generate_star(
            40.0,
            0.3,
            0.0,                // start_angle
            points_per_corner,
            corners_count,
            false,              // direction
            {0.0, 0.0}          // center
    );

    std::vector<Point> result;
    result.reserve(main.size() + hole.size());
    result.insert(result.end(), main.begin(), main.end());
    result.insert(result.end(), hole.begin(), hole.end());

    return result;
}
