#include <iostream>

using namespace std;

int main() {
    int numeros[5];
    int suma = 0;

    cout << "--- Suma de 5 elementos de un arreglo ---" << endl;

    
    for (int i = 0; i < 5; i++) {
        cout << "Ingrese el numero para la posicion [" << i << "]: ";
        cin >> numeros[i];
    }

    
    for (int i = 0; i < 5; i++) {
        suma += numeros[i];
    }

    
    cout << "\nLa suma total de los elementos es: " << suma << endl;

    return 0;
}
