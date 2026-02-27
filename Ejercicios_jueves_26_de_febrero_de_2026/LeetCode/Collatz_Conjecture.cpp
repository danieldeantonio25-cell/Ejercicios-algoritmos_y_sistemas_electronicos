#include <iostream>

using namespace std;

int main() {
    long long n;
    int steps = 0;

    cout << "Enter a starting number: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    cout << "Sequence: " << n;

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        cout << " ➜ " << n;
        steps++;
    }

    cout << "\n\nReached 1 in " << steps << " steps." << endl;

    return 0;
}

