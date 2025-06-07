#include <iostream>
#include "util/args.h"
#include "test/test_0_star.h"
#include "test/test_1_spiral.h"
#include "test/test_2_star_with_hole.h"
#include "test/test_3_star_with_8_holes.h"
#include "test/test_data.h"
#include "test/runner.h"

void star(const EnvArgs& args);
void star_with_hole(const EnvArgs& args);
void rect_with_star_holes(const EnvArgs& args);
void spiral(const EnvArgs& args);
void spike(const EnvArgs& args);

void test_0();
void test_1();
void test_2();
void test_3();

int main(int argc, char** argv) {
    EnvArgs args(argc, argv);
    size_t test = args.get_usize("test", 0);

    switch (test) {
        case 0: test_0(); break;
        case 1: test_1(); break;
        case 2: test_2(); break;
        case 3: test_3(); break;
        default: std::cerr << "Unknown test\n"; return 1;
    }
}

void test_0() {
    std::vector<TestData> tests = {
            TestData(8, 10000),
            TestData(16, 10000),
            TestData(32, 10000),
            TestData(64, 10000),
    };

    for (int i = 1; i < 9; ++i) {
        tests.emplace_back(64 << i, 256 >> i);
    }

    std::cout << "earcut: " << std::endl;
    size_t s0 = 0;
    for (int i = 0; i < tests.size(); ++i) {
        auto t = tests[i];
        auto shape = StarTest::shape(t.count);
        s0 += Runner::run_earcut(shape, t);
    }

    std::cout << "triangle: " << std::endl;
    size_t s1 = 0;
    for (int i = 0; i < tests.size(); ++i) {
        auto t = tests[i];
        auto points = StarTest::points(t.count);
        s1 += Runner::run_triangle(points, t);
    }

    std::cout << "s0: " << s0 << " s1: " << s1 << std::endl;
}

void test_1() {
    std::vector<TestData> tests = {
            TestData(8, 10000),
            TestData(16, 10000),
            TestData(32, 10000),
            TestData(64, 10000),
    };

    for (int i = 1; i < 9; ++i) {
        tests.emplace_back(64 << i, 256 >> i);
    }

    std::cout << "earcut: " << std::endl;
    size_t s0 = 0;
    for (int i = 0; i < tests.size(); ++i) {
        auto t = tests[i];
        auto shape = SpiralTest::shape(t.count);
        s0 += Runner::run_earcut(shape, t);
    }

    std::cout << "triangle: " << std::endl;
    size_t s1 = 0;
    for (int i = 0; i < tests.size(); ++i) {
        auto t = tests[i];
        auto points = SpiralTest::points(t.count);
        s1 += Runner::run_triangle(points, t);
    }

    std::cout << "s0: " << s0 << " s1: " << s1 << std::endl;
}

void test_2() {
    std::vector<TestData> tests;

    for (int i = 1; i < 9; ++i) {
        tests.emplace_back(64 << i, 256 >> i);
    }

    std::cout << "earcut: " << std::endl;
    size_t s0 = 0;
    for (int i = 0; i < tests.size(); ++i) {
        auto t = tests[i];
        auto shape = StarWithHoleTest::shape(t.count);
        s0 += Runner::run_earcut(shape, t);
    }

    std::cout << "triangle: " << std::endl;
    size_t s1 = 0;
    for (int i = 0; i < tests.size(); ++i) {
        auto t = tests[i];
        auto points = StarWithHoleTest::points(t.count);
        s1 += Runner::run_triangle(points, t);
    }

    std::cout << "s0: " << s0 << " s1: " << s1 << std::endl;
}

void test_3() {
    std::vector<TestData> tests;

    for (int i = 1; i < 8; ++i) {
        tests.emplace_back(128 << i, 256 >> i);
    }

    std::cout << "earcut: " << std::endl;
    size_t s0 = 0;
    for (int i = 0; i < tests.size(); ++i) {
        auto t = tests[i];
        auto shape = StarWith8HolesTest::shape(t.count);
        s0 += Runner::run_earcut(shape, t);
    }

    std::cout << "triangle: " << std::endl;
    size_t s1 = 0;
    for (int i = 0; i < tests.size(); ++i) {
        auto t = tests[i];
        auto points = StarWith8HolesTest::points(t.count);
        s1 += Runner::run_triangle(points, t);
    }

    std::cout << "s0: " << s0 << " s1: " << s1 << std::endl;
}