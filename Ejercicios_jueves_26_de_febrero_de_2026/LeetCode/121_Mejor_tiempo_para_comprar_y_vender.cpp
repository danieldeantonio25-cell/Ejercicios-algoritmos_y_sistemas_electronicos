#include <iostream>
#include <vector>
#include <algorithm> // Necesaria para std::max y std::min

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 1e9; // Un número muy grande
        int max_profit = 0;
        
        for (int price : prices) {
            // Actualizamos el precio mínimo visto hasta ahora
            min_price = min(min_price, price);
            // Calculamos la ganancia si vendiéramos hoy
            int profit = price - min_price;
            // Guardamos la ganancia máxima
            max_profit = max(max_profit, profit);
        }
        
        return max_profit;
    }
};

int main() {
    // 1. Creamos una instancia de la solución
    Solution sol;
    
    // 2. Creamos un vector de prueba (ejemplo de LeetCode)
    vector<int> precios = {7, 1, 5, 3, 6, 4};
    
    // 3. Llamamos a la función y guardamos el resultado
    int resultado = sol.maxProfit(precios);
    
    // 4. Mostramos el resultado en la terminal
    cout << "El maximo beneficio posible es: " << resultado << endl;
    
    return 0;
}

