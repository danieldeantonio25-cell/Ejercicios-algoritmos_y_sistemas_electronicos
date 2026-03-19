#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int number) {
    int original = number;
    int digits = 0;
    int sum = 0;

    
    int temp = number;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    
    temp = number;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}

int main() {
    int n;
    cin >> n;

    if (isArmstrong(n))
        cout << "Armstrong number";
    else
        cout << "Not an Armstrong number";

    return 0;
}
