#include "star_builder.h"
#include <cmath>

vector<Point> StarBuilder::generate_star(
        double radius,
        double scale,
        double start_angle,
        size_t points_per_corner,
        size_t corners_count,
        bool direction,
        Point center
) {
    size_t points_count = points_per_corner * corners_count;

    vector<Point> points;
    points.reserve(points_count);

    double sign = direction ? 1.0 : -1.0;
    double da = sign * 2.0 * M_PI / static_cast<double>(points_count);
    double w = static_cast<double>(corners_count);
    double a = 0.0;

    for (size_t i = 0; i < points_count; ++i) {
        double r = radius * (1.0 + scale * std::cos(w * a));
        double angle = a + start_angle;
        double x = r * std::cos(angle) + center[0];
        double y = r * std::sin(angle) + center[1];
        a += da;
        points.push_back({x, y});
    }

    return points;
}
