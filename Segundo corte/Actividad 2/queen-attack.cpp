#include <iostream>
#include <stdexcept>
#include <cmath>

namespace queen_attack {

class queen {
private:
    int r, c;

public:
    
    queen(int row, int col) : r(row), c(col) {
        if (row < 0 || row >= 8 || col < 0 || col >= 8) {
            throw std::domain_error("Queen must be placed on the board (0-7).");
        }
    }

    int row() const { return r; }
    int column() const { return c; }

    
    bool can_attack(const queen& other) const {
        
        if (r == other.row()) return true;
        
        if (c == other.column()) return true;
        
        if (std::abs(r - other.row()) == std::abs(c - other.column())) return true;

        return false;
    }
};

} 

int main() {
    try {
        
        queen_attack::queen white(2, 4);
        queen_attack::queen black(2, 6);
        
        std::cout << "White at (2,4), Black at (2,6)" << std::endl;
        if (white.can_attack(black)) {
            std::cout << "Result: They can attack!" << std::endl;
        }

        
        queen_attack::queen q1(0, 0);
        queen_attack::queen q2(7, 7);
        
        std::cout << "\nQ1 at (0,0), Q2 at (7,7)" << std::endl;
        std::cout << "Can attack? " << (q1.can_attack(q2) ? "Yes" : "No") << std::endl;

        
        std::cout << "\nTrying to place a queen at (8,8)..." << std::endl;
        queen_attack::queen invalid(8, 8);

    } catch (const std::domain_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

