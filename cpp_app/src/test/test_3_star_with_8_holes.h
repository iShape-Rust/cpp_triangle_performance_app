//
// Created by Nail Sharipov on 03.05.2025.
//

#ifndef CPP_APP_TEST_3_STAR_WITH_8_HOLES_H
#define CPP_APP_TEST_3_STAR_WITH_8_HOLES_H


#include <cstddef>
#include <vector>
#include <array>
#include <iostream>
#include "util/star_builder.h"
#include "../lib/earcut.hpp"
#include "util/triangle_wrapper.h"

using namespace std;
using Point = array<double, 2>;

class StarWith8HolesTest {
public:
    vector<Point> contour(size_t count) const;
    vector<double> points(size_t count) const;

private:
    vector<Point> star(size_t count) const;
};

#endif //CPP_APP_TEST_3_STAR_WITH_8_HOLES_H
