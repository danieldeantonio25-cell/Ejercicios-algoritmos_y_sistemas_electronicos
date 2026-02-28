#include <iostream>
#include <cmath>
#include <vector>

struct Point {
    double x;
    double y;
};


double calcularDistanciaMasCercana(const std::vector<Point>& puntos, const Point &pUsuario, int &indiceMasCercano) {
    if (puntos.empty()) {
        indiceMasCercano = -1;
        return -1.0;
    }

    indiceMasCercano = 0;
    double dx = puntos[0].x - pUsuario.x;
    double dy = puntos[0].y - pUsuario.y;
    double distanciaMinimaCuadrada = dx * dx + dy * dy;

    for (int i = 1; i < puntos.size(); i++) {
        double diffX = puntos[i].x - pUsuario.x;
        double diffY = puntos[i].y - pUsuario.y;
        double distanciaActualCuadrada = diffX * diffX + diffY * diffY;

        if (distanciaActualCuadrada < distanciaMinimaCuadrada) {
            distanciaMinimaCuadrada = distanciaActualCuadrada;
            indiceMasCercano = i;
        }
    }
    return std::sqrt(distanciaMinimaCuadrada);
}

int main() {
    int n;
    std::cout << "Ingrese la cantidad de puntos: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Cantidad no valida." << std::endl;
        return 1;
    }

    
    std::vector<Point> puntos(n); 

    for (int i = 0; i < n; i++) {
        std::cout << "Punto " << i << " (x y): ";
        std::cin >> puntos[i].x >> puntos[i].y;
    }

    Point pUsuario;
    std::cout << "\nIngrese su posicion actual (x y): ";
    std::cin >> pUsuario.x >> pUsuario.y;

    int indice;
    
    double dist = calcularDistanciaMasCercana(puntos, pUsuario, indice);

    std::cout << "\n--- Resultados ---" << std::endl;
    if (indice != -1) {
        std::cout << "El punto mas cercano es el indice: " << indice << std::endl;
        std::cout << "Coordenadas: (" << puntos[indice].x << ", " << puntos[indice].y << ")" << std::endl;
        std::cout << "Distancia minima: " << dist << std::endl;
    }

    return 0;
}

