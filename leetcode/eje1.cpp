#include <iostream>

using namespace std;

bool esPalindromo(int x) {
    
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int numeroOriginal = x;
    long numeroInvertido = 0;

    while (x > 0) {
        int ultimoDigito = x % 10;
        numeroInvertido = (numeroInvertido * 10) + ultimoDigito;
        x /= 10;
    }

    return numeroOriginal == numeroInvertido;
}

int main() {
    int x;
    cout << "Ingrese un número entero: ";
    cin >> x;

    if (esPalindromo(x)) {
        cout << "true (Es palíndromo)" << endl;
    } else {
        cout << "false (No es palíndromo)" << endl;
    }

    return 0;
}
