#include <iostream>
#include <string>
#include <stdexcept>

int hamming_distance(const std::string& strand1, const std::string& strand2) {
    if (strand1.length() != strand2.length()) {
        throw std::invalid_argument("Strands must be of equal length");
    }

    int distance = 0;

    for (size_t i = 0; i < strand1.length(); i++) {
        if (strand1[i] != strand2[i]) {
            distance++;
        }
    }

    return distance;
}

// --- ESTO ES LO QUE FALTABA ---
int main() {
    try {
        std::string s1 = "GAGCCTACTAACGGGAT";
        std::string s2 = "CATCGTAATGACGGCAT";
        
        int dist = hamming_distance(s1, s2);
        
        std::cout << "Strand 1: " << s1 << std::endl;
        std::cout << "Strand 2: " << s2 << std::endl;
        std::cout << "Distancia de Hamming: " << dist << std::endl;
        
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

