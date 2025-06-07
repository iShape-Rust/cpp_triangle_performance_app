#ifndef STAR_BUILDER_H
#define STAR_BUILDER_H

#include <vector>
#include <array>
#include <cstddef>

using namespace std;
using Point = array<double, 2>;

class StarBuilder {
public:
    static vector<Point> generate_star(
            double radius,
            double scale,
            double start_angle,
            size_t points_per_corner,
            size_t corners_count,
            bool direction,
            Point center
    );
};

#endif // STAR_BUILDER_H
