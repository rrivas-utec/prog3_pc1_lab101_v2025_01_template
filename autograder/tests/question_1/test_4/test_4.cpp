//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "geodesy.h"

static void test_4() {
    geodesy::GeoMeasurement m1({0.20}, 1, 200, "M1");
    geodesy::GeoMeasurement m2({0.21, 0.22}, 2, 300, "M2");
    geodesy::GeoMeasurement combinada = m1 + m2;

    std::cout << combinada << "\n"; // M1 + M2: 3 angulos, 500 km

    double resultado = combinada.calculate_circumference();
    if (resultado < 0) {
        std::cerr << "Error calculo: necesita exactamente 2 angulos\n";
    }
}

TEST_CASE("Question #1.4") {
    execute_test("question_1_test_4.in", test_4);
}