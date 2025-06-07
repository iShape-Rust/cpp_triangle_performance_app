//
// Created by Nail Sharipov on 05.06.2025.
//

#ifndef CPP_APP_TEST_1_SPIRAL_H
#define CPP_APP_TEST_1_SPIRAL_H

#include <cstddef>
#include <vector>
#include <array>
#include <iostream>
#include "util/star_builder.h"
#include "../lib/earcut.hpp"
#include "util/triangle_wrapper.h"
#include "test_data.h"

using namespace std;
using Point = array<double, 2>;

class SpiralTest {
public:
    static vector<vector<Point>> shape(size_t count);
    static vector<double> points(size_t count);

private:
    static vector<Point> spiral(size_t count);
};

#endif //CPP_APP_TEST_1_SPIRAL_H
