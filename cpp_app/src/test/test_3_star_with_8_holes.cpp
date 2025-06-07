//
// Created by Nail Sharipov on 03.05.2025.
//

#include "test_3_star_with_8_holes.h"
#include <cmath>
#include <chrono>
#include <iostream>

vector<vector<Point>> StarWith8HolesTest::shape(size_t count) {
    return star(count);
}

vector<double> StarWith8HolesTest::points(size_t count) {
    auto contours = star(count);
    size_t total_points = 0;
    for (const auto& ring : contours) {
        total_points += ring.size();
    }

    vector<double> flat;
    flat.reserve(total_points * 2);

    for (const auto& ring : contours) {
        for (const auto& p : ring) {
            flat.push_back(p[0]);
            flat.push_back(p[1]);
        }
    }

    return flat;
}

vector<vector<Point>> StarWith8HolesTest::star(size_t count) {
    const size_t corners_count = 8;
    const size_t holes = 8;
    const size_t main_points_count = count / 2;
    const size_t holes_points_count = count - main_points_count;

    const size_t main_points_per_corner = main_points_count / corners_count;
    const size_t hole_points_per_corner = holes_points_count / (corners_count * holes);

    std::vector<std::vector<Point>> shape;
    shape.push_back(StarBuilder::generate_star(
            80.0,
            0.3,
            0.0, // start_angle
            main_points_per_corner,
            corners_count,
            true,
            {0.0, 0.0}
    ));

    const double r = 50.0;
    const double n = static_cast<double>(holes);

    for (size_t i = 0; i < holes; ++i) {
        double a = static_cast<double>(i) * 2.0 * M_PI / n;
        double x = r * std::cos(a);
        double y = r * std::sin(a);

        auto hole = StarBuilder::generate_star(
                10.0,
                0.3,
                0.0, // start_angle
                hole_points_per_corner,
                corners_count,
                false,
                {x, y}
        );

        shape.push_back(std::move(hole));
    }

    return shape;
}
