# Task #PC1: Práctica Calificada  
**course:** Programación III  
**unit:** 1  
**cmake project:** prog3_pc1_lab101_v2025_01

# Indicaciones Específicas

- **Tiempo límite:** 50 minutos
- **Formato de entrega:**
    - La solución debe implementarse en un archivo cabecera (`.h`) y su correspondiente implementación (`.cpp`):
        - `geodesy.h` (Declaración de la clase)
        - `geodesy.cpp` (Implementación de métodos)
    - Los archivos deben nombrarse exactamente como se indica (sensibles a mayúsculas)

- **Plataforma de entrega:**
    - Subir directamente los archivos a [https://www.gradescope.com](https://www.gradescope.com)
    - O crear un archivo comprimido `solucion.zip` que contenga:
        - `geodesy.h`, `geodesy.cpp`

---

## Restricciones Clave

> ⚠️ **Está prohibido usar** `std::vector`, `std::unique_ptr` u otros contenedores STL  
> ✅ **Debe gestionarse memoria manualmente** con `new[]` y `delete[]`

---

## 🔍Recomendaciones que podrían afectar la calificación

>
> - **Asegúrese que cada nuevo método o atributo funcione.** A lo más, podría fallar el último método u operador implementado; al comentarlo, el resto debe funcionar.
> - **Siga las convenciones solicitadas.** Los nombres de clases, namespaces y métodos deben coincidir exactamente con los especificados. Un uso incorrecto podría indicar el uso de herramientas automáticas.
> - Si la clase es totalmente inoperativa o contiene errores críticos (como memory leaks, crashes o funcionalidad básica incorrecta), **la calificación podría reducirse hasta un 60%.**

---

# Pregunta Única

En un proyecto de simulación astronómica, necesitas calcular distancias entre observatorios basados en mediciones angulares del Sol.

Inspirado en el método de **Eratóstenes**, implementa una clase `GeoMeasurement` que utilice la siguiente fórmula:

```math
Circunferencia = (360 / |θ₁ - θ₂|) × Distancia
```

Donde:
- `θ₁` y `θ₂` son ángulos registrados en dos ubicaciones
- **Distancia** es la separación lineal en kilómetros entre ellas

---

## Esqueleto de la Clase

```cpp
#include <iostream>
#include <string>

// ...

class GeoMeasurement {
private:
    double* angles;      // Array dinámico de ángulos
    size_t num_angles;   // Número actual de ángulos
    double distance;     // Distancia en kilómetros
    std::string label;   // Nombre de la medición

public:
    // --- Constructores ---
    
    // --- Métodos ---
    
    // --- Operadores ---
};
```

---

## Instrucciones

1. Implementar todos los constructores y destructor
2. El método `add_angle` debe redimensionar el array dinámicamente
3. Sobrecargar los operadores `+`, `=`, `<<` (copia y movimiento)
4. `calculate_circumference` debe retornar `-1.0` en caso de error

---

## NOTA: Manejo de Múltiples Ángulos para el cálculo de Circunferencia

1. Cuando una instancia de `GeoMeasurement` contiene **más de 2 ángulos**:
    - La clase debe permitir almacenar $N$ ángulos (solo limitado por memoria disponible).
    - Solo se debe utilizar **el primero y el último de los ángulos** para el cálculo.
    - Los demás ángulos se ignoran (pero se mantienen almacenados).
    - 
## Ejemplos de Prueba

---

### Test 1: Constructor básico y añadir ángulos

```cpp
// Crear medición básica y añadir ángulos
double angulos_iniciales[] = {0.12};
geodesy::GeoMeasurement medicion1(angulos_iniciales, 1, 800, "Base");
medicion1.add_angle(0.13);
medicion1.add_angle(0.14);

std::cout << medicion1 << "\n";     // Base: 3 angulos, 800 km

double circ = medicion1.calculate_circumference();
if (circ < 0) {
    std::cerr << "Error: datos insuficientes\n";
} else {
    std::cout << "Circunferencia calculada: " << circ << " km\n";
}
```

### Test 2: Constructor de copia

```cpp
// Crear original y copia
double angs[] = {0.15, 0.16};
geodesy::GeoMeasurement original(angs, 2, 500, "Original");
geodesy::GeoMeasurement copia = original;

copia.add_angle(0.17);

std::cout << original << "\n";  // Original: 2 angulos, 500 km
std::cout << copia << "\n";     // Original: 3 angulos, 500 km
```

### Test 3: Constructor de movimiento

```cpp
geodesy::GeoMeasurement temporal({0.18, 0.19}, 300, "Temporal");

// Robar recursos del objeto temporal
geodesy::GeoMeasurement movido = std::move(temporal);

std::cout << movido << "\n";        // Temporal: 2 angulos, 300 km
std::cout << temporal << "\n";      // Temporal: 0 angulos, 0 km
```

### Test 4: Operadores y manejo de errores

```cpp
// Crear dos mediciones y combinarlas
geodesy::GeoMeasurement m1({0.20}, 200, "M1");
geodesy::GeoMeasurement m2({0.21, 0.22}, 300, "M2");
geodesy::GeoMeasurement combinada = m1 + m2;

std::cout << combinada << "\n"; // M1 + M2: 3 angulos, 500 km

double resultado = combinada.calculate_circumference();
if (resultado < 0) {
    std::cerr << "Error calculo: necesita exactamente 2 angulos\n";
}
```

---

## Rúbrica de Evaluación

| Criterio     | Ponderación | Descripción |
|--------------|-------------|-------------|
| **Correctitud** | 60% | - Manejo adecuado de memoria dinámica<br>- Constructores de copia/movimiento bien implementados<br>- Cálculos correctos según la fórmula<br>- Sobrecarga correcta de operadores |
| **Robustez**    | 30% | - Manejo de casos límite (arrays vacíos, divisiones por cero)<br>- Validación de parámetros<br>- Uso apropiado de retornos de error (no se exige el uso de excepciones) |
| **Legibilidad** | 10% | - Estilo consistente<br>- Comentarios explicativos<br>- Organización lógica<br>- Encabezados claros |


