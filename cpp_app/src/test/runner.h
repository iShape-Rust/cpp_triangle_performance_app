//
// Created by Nail Sharipov on 07.06.2025.
//

#ifndef CPP_APP_RUNNER_H
#define CPP_APP_RUNNER_H

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

class Runner {
public:
    static size_t run_earcut(const vector<vector<Point>>& shape, TestData test);
    static size_t run_triangle(const vector<double>& points, TestData test);

private:
    static size_t run_points(const vector<double>& points);
};


#endif //CPP_APP_RUNNER_H
