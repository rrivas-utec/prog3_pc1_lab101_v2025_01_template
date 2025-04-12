//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "geodesy.h"

static void test_3() {
    geodesy::GeoMeasurement temporal({0.18, 0.19}, 2, 300, "Temporal");

    // Robar recursos del objeto temporal
    geodesy::GeoMeasurement movido = std::move(temporal);

    std::cout << movido << "\n";        // Temporal: 2 angulos, 300 km
    std::cout << temporal << "\n";      // Temporal: 0 angulos, 0 km
}

TEST_CASE("Question #1.3") {
    execute_test("question_1_test_3.in", test_3);
}