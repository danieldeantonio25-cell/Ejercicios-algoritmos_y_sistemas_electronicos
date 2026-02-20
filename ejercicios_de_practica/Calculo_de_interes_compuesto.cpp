#include <iostream>
#include <cmath> // Necesaria para la función pow()

    using namespace std;

int main() {
    double A, P, r, n, t;

    cout << "--- Calculadora de Interés Compuesto ---" << endl;

    // Solicitar valores al usuario
    cout << "Ingrese el capital inicial (P): ";
    cin >> P;
    cout << "Ingrese la tasa de interés anual en decimal (r): ";
    cin >> r;
    cout << "Ingrese el número de veces que se aplica el interés al año (n): ";
    cin >> n;
    cout << "Ingrese el número de años (t): ";
    cin >> t;

    // Aplicar la fórmula: A = P * (1 + r/n)^(nt)
    A = P * pow((1 + (r / n)), (n * t));

    // Imprimir el resultado
    cout << "\nEl monto final (A) después de " << t << " años es: " << A << endl;

    return 0;
}
