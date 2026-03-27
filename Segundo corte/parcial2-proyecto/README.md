# Medidor de Energía — Proyecto Final Parcial C++

Sistema de gestión de medidores de energía eléctrica implementado en C++ con POO, STL, CMake y Doxygen.

---

## Estructura del proyecto

```
MedidorEnergia/
├── CMakeLists.txt
├── Doxyfile
├── README.md
├── include/
│   └── MedidorEnergia.h
├── src/
│   ├── MedidorEnergia.cpp
│   └── main.cpp
└── docs/
    └── html/               <- generado por Doxygen
```

---

## Descripción de la clase `MedidorEnergia`

| Miembro | Tipo | Descripción |
|---|---|---|
| `serie` | `string` | Número de serie único del medidor |
| `lecturaActual` | `float` | Valor de la última lectura registrada |
| `historial` | `vector<float>` | Todas las lecturas históricas |
| `registrarLectura(float)` | método | Agrega una lectura al historial |
| `calcularConsumoTotal()` | método | Suma todas las lecturas |
| `promedioDiario()` | método | Promedio de las lecturas registradas |

---

## Compilación con CMake

```bash
mkdir build && cd build
cmake ..
cmake --build .
./MedidorEnergia
```

## Generar documentación (requiere Doxygen)

```bash
# Opción 1 — desde build/:
cmake --build . --target docs

# Opción 2 — desde la raíz:
doxygen Doxyfile
```

Abre `docs/html/index.html` en el navegador.

---

## Ejemplo de ejecución

```
Bienvenido al Sistema de Medidores de Energia.
Medidores cargados: 2

+----------------------------------+
|  SISTEMA DE MEDIDORES DE ENERGIA |
+----------------------------------+
| 1. Listar medidores              |
| 2. Registrar lectura             |
| 3. Ver reporte de un medidor     |
| 4. Ver historial de un medidor   |
| 5. Agregar nuevo medidor         |
| 0. Salir                         |
+----------------------------------+
Opcion: 3

  [0] Serie: SER-001 | Ultima lectura: 134.70 kWh | Total lecturas: 3
  [1] Serie: SER-002 | Ultima lectura: 185.60 kWh | Total lecturas: 2
Seleccione el numero del medidor: 0

========================================
   REPORTE DE MEDIDOR DE ENERGIA
========================================
  Serie            : SER-001
  Lectura actual   : 134.70 kWh
  Lecturas regist. : 3
  Consumo total    : 353.50 kWh
  Promedio diario  : 117.83 kWh
========================================
```

---

## Autor

**Daniel** — Proyecto final de parcial, Programación en C++
