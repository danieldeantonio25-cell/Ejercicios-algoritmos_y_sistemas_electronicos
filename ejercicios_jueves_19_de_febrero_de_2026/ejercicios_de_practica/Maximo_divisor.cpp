#include <iostream>

using namespace std;

int calcularMCD(int a, int b) {
    while (b != 0) {
        int residuo = a % b;
        a = b;
        b = residuo;
    }
    return a;
}

int main() {
    int num1, num2;
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;

    if (num1 < 0 || num2 < 0) {
        cout << "Por favor, ingrese números positivos." << endl;
        return 1;
    }

    cout << "El MCD de " << num1 << " y " << num2 << " es: " << calcularMCD(num1, num2) << endl;
    return 0;
}
