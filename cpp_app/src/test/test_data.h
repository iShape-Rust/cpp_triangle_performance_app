//
// Created by Nail Sharipov on 05.06.2025.
//

#ifndef CPP_APP_TEST_DATA_H
#define CPP_APP_TEST_DATA_H


#include <cstdlib>

struct TestData {
    size_t count;
    size_t repeat;

    TestData(size_t count, size_t repeat)
            : count(count), repeat(repeat) {}
};


#endif //CPP_APP_TEST_DATA_H
