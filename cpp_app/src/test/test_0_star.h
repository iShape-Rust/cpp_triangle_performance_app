#ifndef SIMPLE_STAR_TEST_H
#define SIMPLE_STAR_TEST_H

#include <cstddef>
#include <vector>
#include <array>
#include <iostream>
#include "util/star_builder.h"
#include "../lib/earcut.hpp"
#include "util/triangle_wrapper.h"

using namespace std;
using Point = array<double, 2>;

class StarTest {
public:
    static vector<vector<Point>> shape(size_t count);
    static vector<double> points(size_t count);

private:
    static vector<Point> star(size_t count);

};

#endif // SIMPLE_STAR_TEST_H