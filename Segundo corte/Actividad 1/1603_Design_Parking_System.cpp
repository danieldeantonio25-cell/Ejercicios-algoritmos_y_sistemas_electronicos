#include <iostream>

using namespace std;

class ParkingSystem {
private:
    int bigSlots;
    int mediumSlots;
    int smallSlots;

public:
    ParkingSystem(int big, int medium, int small) {
        bigSlots = big;
        mediumSlots = medium;
        smallSlots = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1) {
            if (bigSlots > 0) {
                bigSlots--;
                return true;
            }
        } 
        else if (carType == 2) {
            if (mediumSlots > 0) {
                mediumSlots--;
                return true;
            }
        } 
        else if (carType == 3) {
            if (smallSlots > 0) {
                smallSlots--;
                return true;
            }
        }
        return false;
    }
};

int main() {
    
    ParkingSystem* obj = new ParkingSystem(1, 1, 0);
    
    cout << "Añadiendo carro grande (1): " << (obj->addCar(1) ? "Éxito" : "Fallo") << endl;
    cout << "Añadiendo carro mediano (2): " << (obj->addCar(2) ? "Éxito" : "Fallo") << endl;
    cout << "Añadiendo carro pequeño (3): " << (obj->addCar(3) ? "Éxito" : "Fallo") << endl;

    delete obj;
    return 0;
}

