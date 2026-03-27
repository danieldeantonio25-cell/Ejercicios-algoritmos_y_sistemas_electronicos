/**
 * @file MedidorEnergia.h
 * @brief Declaración de la clase MedidorEnergia.
 * @details Clase que representa un medidor de energía eléctrica con
 *          historial de lecturas, cálculo de consumo total y promedio diario.
 * @author Daniel
 * @date 2025
 */

#ifndef MEDIDORENERGIA_H
#define MEDIDORENERGIA_H

#include <string>
#include <vector>

/**
 * @class MedidorEnergia
 * @brief Clase que representa un medidor de energía eléctrica con historial de lecturas.
 */
class MedidorEnergia {
private:
    std::string serie;             /**< Número de serie único del medidor */
    float lecturaActual;          /**< Valor de la última lectura registrada */
    std::vector<float> historial; /**< Listado de todas las lecturas históricas */

public:
    /**
     * @brief Constructor que inicializa el medidor con su número de serie.
     * @param serie El número de serie del dispositivo.
     */
    MedidorEnergia(std::string serie);

    /**
     * @brief Registra una nueva lectura en el historial y actualiza la lectura actual.
     * @param valor El valor de la lectura de energía a registrar.
     */
    void registrarLectura(float valor);

    /**
     * @brief Calcula la suma total de todas las lecturas registradas.
     * @return El consumo total acumulado en el historial.
     */
    float calcularConsumoTotal() const;

    /**
     * @brief Calcula el promedio de las lecturas registradas en el historial.
     * @return El promedio diario de consumo. Si no hay lecturas, retorna 0.
     */
    float promedioDiario() const;

    /**
     * @brief Retorna el número de serie del medidor.
     * @return Número de serie como string.
     */
    std::string getSerie() const;

    /**
     * @brief Retorna la última lectura registrada.
     * @return Valor de la lectura actual en kWh.
     */
    float getLecturaActual() const;

    /**
     * @brief Retorna el número de lecturas en el historial.
     * @return Cantidad de lecturas registradas.
     */
    int cantidadLecturas() const;

    /**
     * @brief Muestra un reporte completo del medidor en consola.
     */
    void mostrarReporte() const;

    /**
     * @brief Muestra el historial completo de lecturas.
     */
    void mostrarHistorial() const;
};

#endif // MEDIDORENERGIA_H
