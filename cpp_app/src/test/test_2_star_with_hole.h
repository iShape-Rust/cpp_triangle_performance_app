//
// Created by Nail Sharipov on 03.05.2025.
//

#ifndef CPP_APP_TEST_2_STAR_WITH_HOLE_H
#define CPP_APP_TEST_2_STAR_WITH_HOLE_H

#include <cstddef>
#include <vector>
#include <array>
#include <iostream>
#include "util/star_builder.h"
#include "../lib/earcut.hpp"
#include "util/triangle_wrapper.h"

using namespace std;
using Point = array<double, 2>;

class StarWithHoleTest {
public:
    static vector<vector<Point>> shape(size_t count);
    static vector<double> points(size_t count);

private:
    static vector<vector<Point>> star(size_t count);
};


#endif //CPP_APP_TEST_2_STAR_WITH_HOLE_H
