//
// Created by Nail Sharipov on 03.05.2025.
//

#include "test_2_star_with_hole.h"
#include <chrono>

vector<vector<Point>> StarWithHoleTest::shape(size_t count) {
    return star(count);
}

vector<double> StarWithHoleTest::points(size_t count) {
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

vector<vector<Point>> StarWithHoleTest::star(size_t count) {
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

    vector<vector<Point>> shape = {
            main,
            hole
    };
    return shape;
}