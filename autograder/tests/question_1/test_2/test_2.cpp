//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "geodesy.h"

static void test_2() {
    // Crear original y copia
    double angs[] = {0.15, 0.16};
    geodesy::GeoMeasurement original(angs, 2, 500, "Original");
    geodesy::GeoMeasurement copia = original;

    copia.add_angle(0.17);

    std::cout << original << "\n";          // Original: 2 angulos, 500 km
    std::cout << copia << "\n";             // Original: 3 angulos, 500 km
}

TEST_CASE("Question #1.2") {
    execute_test("question_1_test_2.in", test_2);
}