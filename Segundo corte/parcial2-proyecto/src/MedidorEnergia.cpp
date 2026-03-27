/**
 * @file MedidorEnergia.cpp
 * @brief Implementación de la clase MedidorEnergia.
 * @author Daniel
 * @date 2025
 */

#include "MedidorEnergia.h"
#include <iostream>
#include <iomanip>

// ── Constructor ───────────────────────────────────────────────────────────────

MedidorEnergia::MedidorEnergia(std::string serie)
    : serie(serie), lecturaActual(0.0f) {}

// ── Métodos del parcial (sin modificar la lógica original) ───────────────────

void MedidorEnergia::registrarLectura(float valor) {
    lecturaActual = valor;
    historial.push_back(valor);
}

float MedidorEnergia::calcularConsumoTotal() const {
    float total = 0.0f;
    for (float lectura : historial) {
        total += lectura;
    }
    return total;
}

float MedidorEnergia::promedioDiario() const {
    if (historial.empty()) {
        return 0.0f;
    }
    return calcularConsumoTotal() / historial.size();
}

// ── Getters ───────────────────────────────────────────────────────────────────

std::string MedidorEnergia::getSerie() const {
    return serie;
}

float MedidorEnergia::getLecturaActual() const {
    return lecturaActual;
}

int MedidorEnergia::cantidadLecturas() const {
    return static_cast<int>(historial.size());
}

// ── Métodos de presentación ───────────────────────────────────────────────────

void MedidorEnergia::mostrarReporte() const {
    std::cout << "\n========================================\n";
    std::cout << "   REPORTE DE MEDIDOR DE ENERGIA\n";
    std::cout << "========================================\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  Serie            : " << serie << "\n";
    std::cout << "  Lectura actual   : " << lecturaActual       << " kWh\n";
    std::cout << "  Lecturas regist. : " << cantidadLecturas()  << "\n";
    std::cout << "  Consumo total    : " << calcularConsumoTotal() << " kWh\n";
    std::cout << "  Promedio diario  : " << promedioDiario()    << " kWh\n";
    std::cout << "========================================\n";
}

void MedidorEnergia::mostrarHistorial() const {
    std::cout << "\n--- Historial de lecturas (" << serie << ") ---\n";
    if (historial.empty()) {
        std::cout << "  Sin lecturas registradas.\n";
        return;
    }
    for (int i = 0; i < static_cast<int>(historial.size()); ++i) {
        std::cout << "  Lectura " << (i + 1) << ": "
                  << std::fixed << std::setprecision(2)
                  << historial[i] << " kWh\n";
    }
    std::cout << "-------------------------------------------\n";
}
