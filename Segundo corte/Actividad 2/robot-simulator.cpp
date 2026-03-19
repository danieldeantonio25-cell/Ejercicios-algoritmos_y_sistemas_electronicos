#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Direction { NORTH, EAST, SOUTH, WEST };

class Robot {
public:
    int x, y;
    Direction dir;

    Robot(int startX, int startY, Direction startDir) 
        : x(startX), y(startY), dir(startDir) {}

    void turnRight() {
        
        dir = static_cast<Direction>((static_cast<int>(dir) + 1) % 4);
    }

    void turnLeft() {
        
        dir = static_cast<Direction>((static_cast<int>(dir) + 3) % 4);
    }

    void advance() {
        if (dir == Direction::NORTH) y++;
        else if (dir == Direction::EAST) x++;
        else if (dir == Direction::SOUTH) y--;
        else if (dir == Direction::WEST) x--;
    }

    void executeInstructions(string instructions) {
        for (char c : instructions) {
            if (c == 'R') turnRight();
            else if (c == 'L') turnLeft();
            else if (c == 'A') advance();
        }
    }

    string getDirectionName() {
        string names[] = {"NORTH", "EAST", "SOUTH", "WEST"};
        return names[static_cast<int>(dir)];
    }
};

int main() {
    
    Robot myRobot(7, 3, Direction::NORTH);

    string instructions = "RAALAL";
    myRobot.executeInstructions(instructions);

    cout << "--- Resultado de la simulación ---" << endl;
    cout << "Instrucciones: " << instructions << endl;
    cout << "Posicion final: {" << myRobot.x << ", " << myRobot.y << "}" << endl;
    cout << "Orientacion: " << myRobot.getDirectionName() << endl;

    
    return 0;
}

