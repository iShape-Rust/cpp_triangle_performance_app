#include <iostream>
#include "util/args.h"
#include "test/test_0_star.h"
#include "test/test_2_star_with_hole.h"
#include "test/test_3_star_with_8_holes.h"
#include "test/test_1_spiral.h"
#include "test/test_4_spike.h"
#include "test/test_data.h"

void star(const EnvArgs& args);
void star_with_hole(const EnvArgs& args);
void rect_with_star_holes(const EnvArgs& args);
void spiral(const EnvArgs& args);
void spike(const EnvArgs& args);

int main(int argc, char** argv) {
    EnvArgs args(argc, argv);
    size_t test = args.get_usize("test", 0);

    switch (test) {
        case 0: star(args); break;
        case 1: star_with_hole(args); break;
        case 2: rect_with_star_holes(args); break;
        case 3: spiral(args); break;
        case 4: spike(args); break;
        default: std::cerr << "Unknown test\n"; return 1;
    }
}

void star(const EnvArgs& args) {
    StarTest test(
            100.0,
            100,
            10,
            100,
            0.0,
            1.0
    );

    std::cout << "earcut: " << std::endl;
    size_t s0 = 0;
    for (int i = 0; i < 8; ++i) {
        size_t count = 4 << i;
        s0 += test.run_earcut(count);
    }

    std::cout << "triangle: " << std::endl;
    size_t s1 = 0;
    for (int i = 0; i < 8; ++i) {
        size_t count = 4 << i;
        s1 += test.run_triangle(count);
    }

    std::cout << "s0: " << s0 << " s1: " << s1 << std::endl;
}

void star_with_hole(const EnvArgs& args) {
    StarWithHoleTest test(
            100.0,
            100,
            10,
            100,
            0.1, // must be > 0 to prevent intersection!
            1.0
    );

    std::cout << "earcut: " << std::endl;
    size_t s0 = 0;
    for (int i = 0; i < 5; ++i) {
        size_t count = 4 << i;
        s0 += test.run_earcut(count);
    }

    std::cout << "triangle: " << std::endl;
    size_t s1 = 0;
    for (int i = 0; i < 7; ++i) {
        size_t count = 4 << i;
        s1 += test.run_triangle(count);
    }

    std::cout << "s0: " << s0 << "s1: " << s1 << std::endl;
}

void rect_with_star_holes(const EnvArgs& args) {
    StarWith8HolesTest test(
            100.0,
            5,
            10,
            5,
            0.0,
            1.0,
            5
    );

    std::cout << "earcut: " << std::endl;
    size_t s0 = 0;
    for (int i = 0; i < 4; ++i) {
        size_t count = 4 << i;
        s0 += test.run_earcut(count);
    }

    std::cout << "triangle: " << std::endl;
    size_t s1 = 0;
    for (int i = 0; i < 7; ++i) {
        size_t count = 4 << i;
        s1 += test.run_triangle(count);
    }

    std::cout << "s0: " << s0 << "s1: " << s1 << std::endl;
}

void spiral(const EnvArgs& args) {

    std::vector<TestData> tests = {
            TestData(8, 10000),
            TestData(16, 10000),
            TestData(32, 10000),
            TestData(64, 10000),
    };

    for (int i = 1; i < 6; ++i) {
        tests.emplace_back(64 << i, 256 >> i);
    }

    SpiralTest test(10.0);

    std::cout << "earcut: " << std::endl;
    size_t s0 = 0;
    for (int i = 0; i < tests.size(); ++i) {
        auto t = tests[i];
        s0 += test.run_earcut(t);
    }

    std::cout << "triangle: " << std::endl;
    size_t s1 = 0;
    for (int i = 0; i < tests.size(); ++i) {
        auto t = tests[i];
        s1 += test.run_triangle(t);
    }

    std::cout << "s0: " << s0 << " s1: " << s1 << std::endl;
}

void spike(const EnvArgs& args) {
    std::vector<TestData> tests = {
            TestData(8, 10000),
            TestData(16, 10000),
            TestData(32, 10000),
            TestData(64, 10000),
    };

    for (int i = 1; i < 8; ++i) {
        tests.emplace_back(64 << i, 256 >> i);
    }

    SpikeTest test(80.0, 160.0);

    std::cout << "earcut: " << std::endl;
    size_t s0 = 0;
    for (int i = 0; i < tests.size(); ++i) {
        auto t = tests[i];
        s0 += test.run_earcut(t);
    }

    std::cout << "triangle: " << std::endl;
    size_t s1 = 0;
    for (int i = 0; i < tests.size(); ++i) {
        auto t = tests[i];
        s1 += test.run_triangle(t);
    }

    std::cout << "s0: " << s0 << " s1: " << s1 << std::endl;
}