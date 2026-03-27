/**
 * @file main.cpp
 * @brief Programa principal del sistema de medidores de energía.
 * @details Crea al menos dos objetos MedidorEnergia, los almacena en un
 *          std::vector, solicita datos al usuario con cin y muestra
 *          resultados con cout.
 * @author Daniel
 * @date 2025
 */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "MedidorEnergia.h"

// ── Utilidades de entrada ─────────────────────────────────────────────────────

void limpiarBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

float pedirFloat(const std::string& mensaje) {
    float valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor && valor >= 0) break;
        std::cout << "  [!] Ingrese un numero positivo valido.\n";
        std::cin.clear();
        limpiarBuffer();
    }
    limpiarBuffer();
    return valor;
}

// ── Menú ──────────────────────────────────────────────────────────────────────

void mostrarMenu() {
    std::cout << "\n+----------------------------------+\n";
    std::cout << "|  SISTEMA DE MEDIDORES DE ENERGIA |\n";
    std::cout << "+----------------------------------+\n";
    std::cout << "| 1. Listar medidores              |\n";
    std::cout << "| 2. Registrar lectura             |\n";
    std::cout << "| 3. Ver reporte de un medidor     |\n";
    std::cout << "| 4. Ver historial de un medidor   |\n";
    std::cout << "| 5. Agregar nuevo medidor         |\n";
    std::cout << "| 0. Salir                         |\n";
    std::cout << "+----------------------------------+\n";
    std::cout << "Opcion: ";
}

void listarMedidores(const std::vector<MedidorEnergia>& medidores) {
    std::cout << "\n--- Medidores registrados ---\n";
    for (int i = 0; i < static_cast<int>(medidores.size()); ++i) {
        std::cout << "  [" << i << "] Serie: " << medidores[i].getSerie()
                  << "  | Ultima lectura: " << medidores[i].getLecturaActual()
                  << " kWh  | Total lecturas: " << medidores[i].cantidadLecturas()
                  << "\n";
    }
}

int elegirMedidor(const std::vector<MedidorEnergia>& medidores) {
    listarMedidores(medidores);
    std::cout << "Seleccione el numero del medidor (-1 para cancelar): ";
    int idx;
    std::cin >> idx;
    limpiarBuffer();
    if (idx < 0 || idx >= static_cast<int>(medidores.size())) return -1;
    return idx;
}

// ── main ──────────────────────────────────────────────────────────────────────

int main() {
    // Crear al menos dos objetos y almacenarlos en std::vector
    std::vector<MedidorEnergia> medidores;
    medidores.push_back(MedidorEnergia("SER-001"));
    medidores.push_back(MedidorEnergia("SER-002"));

    // Lecturas iniciales de ejemplo
    medidores[0].registrarLectura(120.5f);
    medidores[0].registrarLectura(98.3f);
    medidores[0].registrarLectura(134.7f);
    medidores[1].registrarLectura(200.0f);
    medidores[1].registrarLectura(185.6f);

    std::cout << "\nBienvenido al Sistema de Medidores de Energia.\n";
    std::cout << "Medidores cargados: " << medidores.size() << "\n";

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
            case 1:
                listarMedidores(medidores);
                break;

            case 2: {
                int idx = elegirMedidor(medidores);
                if (idx == -1) { std::cout << "Cancelado.\n"; break; }
                float valor = pedirFloat("Nueva lectura (kWh): ");
                medidores[idx].registrarLectura(valor);
                std::cout << "Lectura registrada correctamente.\n";
                break;
            }

            case 3: {
                int idx = elegirMedidor(medidores);
                if (idx == -1) { std::cout << "Cancelado.\n"; break; }
                medidores[idx].mostrarReporte();
                break;
            }

            case 4: {
                int idx = elegirMedidor(medidores);
                if (idx == -1) { std::cout << "Cancelado.\n"; break; }
                medidores[idx].mostrarHistorial();
                break;
            }

            case 5: {
                std::string serie;
                std::cout << "Numero de serie del nuevo medidor: ";
                std::getline(std::cin, serie);
                medidores.push_back(MedidorEnergia(serie));
                std::cout << "Medidor '" << serie << "' agregado.\n";
                break;
            }

            case 0:
                std::cout << "\nCerrando el sistema. Hasta luego.\n";
                break;

            default:
                std::cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);

    return 0;
}
