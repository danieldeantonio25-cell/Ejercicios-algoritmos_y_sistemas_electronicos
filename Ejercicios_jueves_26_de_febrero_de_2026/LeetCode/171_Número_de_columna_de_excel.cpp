#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long result = 0;
        for (char c : columnTitle) {
            int value = c - 'A' + 1;
            result = result * 26 + value;
        }
        return (int)result;
    }
};


int main() {
    Solution sol;
    string test = "ZY"; 
    cout << "Input: " << test << "\nOutput: " << sol.titleToNumber(test) << endl;
    return 0;
}

