#pragma once
#include <string>

namespace crypto_square {

class cipher {
public:
    explicit cipher(const std::string& text);
    std::string normalized_cipher_text() const;

private:
    std::string normalized_;  // texto normalizado (solo alfanumérico, minúsculas)
    int rows_;
    int cols_;

    std::string normalize(const std::string& text) const;
    void compute_dimensions(int length, int& rows, int& cols) const;
};

} // namespace crypto_square
