#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> grid;

    
    int parseOperand(string op) {
        if (isdigit(op[0])) {
            return stoi(op);
        } else {
            int col = op[0] - 'A';
            int row = stoi(op.substr(1)) - 1; 
            return grid[row][col];
        }
    }

public:
    Spreadsheet(int rows) {
        
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        grid[row][col] = value;
    }

    void resetCell(string cell) {
        setCell(cell, 0);
    }

    int getValue(string formula) {
        
        string expression = formula.substr(1);
        
        
        size_t plusPos = expression.find('+');
        
        string partX = expression.substr(0, plusPos);
        string partY = expression.substr(plusPos + 1);

        return parseOperand(partX) + parseOperand(partY);
    }
};

int main() {
    
    Spreadsheet* sheet = new Spreadsheet(3);

    cout << "getValue(\"=5+7\"): " << sheet->getValue("=5+7") << endl;

    sheet->setCell("A1", 10);
    cout << "setCell(\"A1\", 10)" << endl;
    
    cout << "getValue(\"=A1+6\"): " << sheet->getValue("=A1+6") << endl; 

    sheet->setCell("B2", 15);
    cout << "setCell(\"B2\", 15)" << endl;

    cout << "getValue(\"=A1+B2\"): " << sheet->getValue("=A1+B2") << endl; 

    sheet->resetCell("A1");
    cout << "resetCell(\"A1\")" << endl;

    cout << "getValue(\"=A1+B2\"): " << sheet->getValue("=A1+B2") << endl;

    delete sheet;
    return 0;
}

