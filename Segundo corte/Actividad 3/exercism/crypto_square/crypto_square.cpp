/*
 * Exercism - Crypto Square (C++)
 *
 * Implementa el método clásico de cifrado por cuadrado:
 *  1. Normalizar el texto: quitar espacios y puntuación, convertir a minúsculas.
 *  2. Organizar los caracteres en un rectángulo lo más cuadrado posible,
 *     donde c >= r y c - r <= 1 (c = columnas, r = filas).
 *  3. Leer las columnas de arriba a abajo para obtener el texto cifrado.
 *  4. Devolver los chunks separados por espacio, rellenando con espacios
 *     donde falten caracteres.
 */

#include "crypto_square.h"
#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>

namespace crypto_square {

cipher::cipher(const std::string& text) {
    normalized_ = normalize(text);
    compute_dimensions((int)normalized_.size(), rows_, cols_);
}

std::string cipher::normalize(const std::string& text) const {
    std::string result;
    for (char c : text) {
        if (std::isalnum((unsigned char)c)) {
            result += std::tolower((unsigned char)c);
        }
    }
    return result;
}

void cipher::compute_dimensions(int length, int& rows, int& cols) const {
    if (length == 0) {
        rows = 0;
        cols = 0;
        return;
    }
    cols = (int)std::ceil(std::sqrt((double)length));
    rows = (int)std::ceil((double)length / cols);
}

std::string cipher::normalized_cipher_text() const {
    if (normalized_.empty()) return "";

    // Rellenar con espacios hasta completar el rectángulo r x c
    std::string padded = normalized_;
    padded.resize(rows_ * cols_, ' ');

    // Leer columna por columna y formar chunks
    std::string result;
    for (int col = 0; col < cols_; col++) {
        if (col > 0) result += ' ';
        for (int row = 0; row < rows_; row++) {
            result += padded[row * cols_ + col];
        }
    }
    return result;
}

} // namespace crypto_square

// ---- Función main de demostración ----
int main() {
    using namespace crypto_square;

    std::cout << "=== Exercism: Crypto Square ===\n\n";

    struct TestCase {
        std::string input;
        std::string expected;
    };

    std::vector<TestCase> tests = {
        {"", ""},
        {"s", "s"},
        {"If man was meant to stay on the ground, god would have given us roots.",
         "imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn  sseoau "},
        {"Have a nice day!", "hae and via ecy"},
        {"Chill out.", "clu hlt io "},
    };

    for (auto& tc : tests) {
        cipher c(tc.input);
        std::string got = c.normalized_cipher_text();
        std::string status = (got == tc.expected) ? "OK" : "FALLO";
        std::cout << "[" << status << "] Input: \"" << tc.input << "\"\n";
        std::cout << "       Resultado : \"" << got << "\"\n";
        std::cout << "       Esperado  : \"" << tc.expected << "\"\n\n";
    }

    return 0;
}
