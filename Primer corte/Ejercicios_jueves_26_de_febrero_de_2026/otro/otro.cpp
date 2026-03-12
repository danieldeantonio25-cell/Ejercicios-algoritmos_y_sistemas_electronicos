#include <iostream>
#include <string>
#include <vector>


typedef float (*OperacionCallback)(float, float);


float sumar(float a, float b) { return a + b; }
float restar(float a, float b) { return a - b; }
float multiplicar(float a, float b) { return a * b; }
float dividir(float a, float b) {
    if (b == 0) {
        std::cerr << "Error: División por cero no permitida." << std::endl;
        exit(1);
    }
    return a / b;
}


void mostrarError(char* nombreArchivo) {
    std::cout << "Ha ingresado valores inadecuados para el programa:" << std::endl;
    std::cout << "USO: " << nombreArchivo << " <num1> <operador> <num2>" << std::endl;
    std::cout << "Operadores permitidos: +, -, *, x, /" << std::endl;
}

int main(int argc, char* argv[]) {
    
    if (argc != 4) {
        mostrarError(argv[0]);
        return 1;
    }

    try {
        
        float num1 = std::stof(argv[1]);
        std::string operador = argv[2];
        float num2 = std::stof(argv[3]);

        OperacionCallback operacionSeleccionada = nullptr;

        
        if (operador == "+") operacionSeleccionada = sumar;
        else if (operador == "-") operacionSeleccionada = restar;
        else if (operador == "*" || operador == "x") operacionSeleccionada = multiplicar;
        else if (operador == "/") operacionSeleccionada = dividir;
        else {
            mostrarError(argv[0]);
            return 1;
        }

        
        float resultado = operacionSeleccionada(num1, num2);
        std::cout << "El resultado de la operacion es: " << resultado << std::endl;

    } catch (const std::invalid_argument& e) {
        mostrarError(argv[0]);
        return 1;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Número demasiado grande." << std::endl;
        return 1;
    }

    return 0;
}
