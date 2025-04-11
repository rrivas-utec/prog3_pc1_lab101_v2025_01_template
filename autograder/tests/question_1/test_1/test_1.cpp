//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "geodesy.h"

static void test_1() {
    // Crear medición básica y añadir ángulos
    double angulos_iniciales[] = {0.12};
    geodesy::GeoMeasurement medicion1(angulos_iniciales, 1, 800, "Base");
    medicion1.add_angle(0.13);
    medicion1.add_angle(0.14);

    std::cout << medicion1 << "\n";
    // Salida esperada: "Base: 3 angulos, 800 km"

    double circ = medicion1.calculate_circumference();
    if (circ < 0) {
        std::cerr << "Error: datos insuficientes\n";
    } else {
        std::cout << circ << " km\n";
    }
}

TEST_CASE("Question #1.1") {
    execute_test("question_1_test_1.in", test_1);
}