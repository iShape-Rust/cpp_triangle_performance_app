//
// Created by Nail Sharipov on 07.06.2025.
//

#include "runner.h"

size_t Runner::run_earcut(const vector<vector<Point>>& shape, TestData test) const {
    size_t sum = 0;

    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < test.repeat; ++i) {
        vector<uint32_t> result = mapbox::earcut<uint32_t>(shape);
        sum += result.size();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double time = 1000000 * duration.count() / test.repeat;
    std::cout << test.count << " - " << time << std::endl;

    return sum;
}


size_t Runner::run_triangle(const vector<double>& points, TestData test) const {
    size_t sum = 0;
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < test.repeat; ++i) {
        sum += run_points(points);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double time = 1000000 * duration.count() / test.repeat;
    std::cout << test.count << " - " << time << std::endl;

    return sum;
}

size_t Runner::run_points(const vector<double>& points) const {
    struct triangulateio in{};
    struct triangulateio out{};

    size_t point_count = points.size() / 2;

    // Fill input pointlist
    in.numberofpoints = static_cast<int>(point_count);
    in.pointlist = const_cast<double*>(points.data()); // Triangle doesn't modify it with "pzQ"

    // Allocate segment list (each edge of the polygon)
    in.numberofsegments = static_cast<int>(point_count);
    in.segmentlist = (int*)malloc(sizeof(int) * point_count * 2);

    for (int i = 0; i < in.numberofsegments; ++i) {
        in.segmentlist[i * 2] = i;
        in.segmentlist[i * 2 + 1] = (i + 1) % in.numberofsegments;
    }

    // Run Triangle
    triangulate((char*)"pzQ", &in, &out, nullptr);

    size_t triangle_count = out.numberoftriangles;

    // Only need to free things Triangle allocated
    free(out.pointlist);
    free(out.trianglelist);

    // Free our allocation
    free(in.segmentlist);

    return triangle_count * 3;
}