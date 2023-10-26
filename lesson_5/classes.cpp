#include <iostream>
#include <cmath>
#include <cstring>

enum FigureName {
    king,
    queen,
    rook,
    bishop,
    knight,
    pawn,
};

class Figure {
public:
    Figure(FigureName name, bool isWhite, int x, int y) 
        : figure_name(name), is_white(isWhite), current_position{x, y} {
    }

    virtual bool canMoveToPosition(int targetX, int targetY) const = 0;

    const char* getFigureName() {
        const char* result = new char[6]; 
        switch (figure_name)
        {
        case 0:
            return "king";
        case 1:
            return "queen";
        case 2:
            return "rook";
        case 3:
            return "bishop";
        case 4:
            return "knight";
        case 5:
            return "pawn";
        default:
            break;
        }
    }

    const char* getColor() {
        if (is_white) {
            return "white";
        }
        return "black";
    }

protected:
    FigureName figure_name;
    bool is_white;
    int current_position[2];
};

class King : public Figure {
public:
    King(bool isWhite, int x, int y)
        : Figure(FigureName::king, isWhite, x, y) {
    }

    bool canMoveToPosition(int targetX, int targetY) const override {
        int dx = abs(targetX - current_position[0]);
        int dy = abs(targetY - current_position[1]);
        return (dx <= 1 && dy <= 1);
    }
};

class Queen : public Figure {
public:
    Queen(bool isWhite, int x, int y)
        : Figure(FigureName::queen, isWhite, x, y) {
    }

    bool canMoveToPosition(int targetX, int targetY) const override {
        int dx = abs(targetX - current_position[0]);
        int dy = abs(targetY - current_position[1]);
        return (targetX == current_position[0] || targetY == current_position[1] || dx == dy);
    }
};

class Rook : public Figure {
public:
    Rook(bool isWhite, int x, int y)
        : Figure(FigureName::rook, isWhite, x, y) {
    }

    bool canMoveToPosition(int targetX, int targetY) const override {
        return (targetX == current_position[0] || targetY == current_position[1]);
    }
};

class Bishop : public Figure {
public:
    Bishop(bool isWhite, int x, int y)
        : Figure(FigureName::bishop, isWhite, x, y) {
    }

    bool canMoveToPosition(int targetX, int targetY) const override {
        int dx = abs(targetX - current_position[0]);
        int dy = abs(targetY - current_position[1]);
        return (dx == dy);
    }
};

class Knight : public Figure {
public:
    Knight(bool isWhite, int x, int y)
        : Figure(FigureName::knight, isWhite, x, y) {
    }

    bool canMoveToPosition(int targetX, int targetY) const override {
        int dx = abs(targetX - current_position[0]);
        int dy = abs(targetY - current_position[1]);
        return ((dx == 1 && dy == 2) || (dx == 2 && dy == 1));
    }
};

class Pawn : public Figure {
public:
    Pawn(bool isWhite, int x, int y)
        : Figure(FigureName::pawn, isWhite, x, y) {
    }

    bool canMoveToPosition(int targetX, int targetY) const override {
        int dx = abs(targetX - current_position[0]);
        int dy = abs(targetY - current_position[1]);

        if (is_white) {
            if (dx == 0 && targetY == current_position[1] - 1) {
                return true;
            } else if (dx == 0 && current_position[1] == 6 && targetY == 4) {
                return true;
            } else if (dx == 1 && dy == 1 && targetY == current_position[1] - 1) {
                return true;
            }
        } else {
            if (dx == 0 && targetY == current_position[1] + 1) {
                return true;
            } else if (dx == 0 && current_position[1] == 1 && targetY == 3) {
                return true;
            } else if (dx == 1 && dy == 1 && targetY == current_position[1] + 1) {
                return true;
            }
        }
        return false;
    }
};

using namespace std;

int main() {
    King test_king = King(true, 4, 4);
    Queen test_queen = Queen(false, 0, 0);
    Rook test_rook = Rook(true, 3, 4);
    Bishop test_bishop = Bishop(false, 2, 2);
    Knight test_knight = Knight(true, 1, 0);
    Pawn test_pawn = Pawn(false, 4, 6);
    
    int targetX, targetY;
    cout << endl;

    // King
    targetX = 3;
    targetY = 3;
    cout << "Your figure: " << test_king.getColor() << ' ' << test_king.getFigureName() << endl;
    if (test_king.canMoveToPosition(targetX, targetY)) {
        cout << "King can move to position (" << targetX << ", " << targetY << ")" << endl;
    } else {
        cout << "King cannot move to position (" << targetX << ", " << targetY << ")" << endl;
    }
    cout << endl;

    // Queen
    targetX = 2;
    targetY = 0;
    cout << "Your figure: " << test_queen.getColor() << ' ' << test_queen.getFigureName() << endl;
    if (test_queen.canMoveToPosition(targetX, targetY)) {
        cout << "Queen can move to position (" << targetX << ", " << targetY << ")" << endl;
    } else {
        cout << "Queen cannot move to position (" << targetX << ", " << targetY << ")" << endl;
    }
    cout << endl;

    // Rook
    targetX = 3;
    targetY = 7;
    cout << "Your figure: " << test_rook.getColor() << ' ' << test_rook.getFigureName() << endl;
    if (test_rook.canMoveToPosition(targetX, targetY)) {
        cout << "Rook can move to position (" << targetX << ", " << targetY << ")" << endl;
    } else {
        cout << "Rook cannot move to position (" << targetX << ", " << targetY << ")" << endl;
    }
    cout << endl;

    // Bishop
    targetX = 0;
    targetY = 2;
    cout << "Your figure: " << test_bishop.getColor() << ' ' << test_bishop.getFigureName() << endl;
    if (test_bishop.canMoveToPosition(targetX, targetY)) {
        cout << "Bishop can move to position (" << targetX << ", " << targetY << ")" << endl;
    } else {
        cout << "Bishop cannot move to position (" << targetX << ", " << targetY << ")" << endl;
    }
    cout << endl;

    // Knight
    targetX = 2;
    targetY = 1;
    cout << "Your figure: " << test_knight.getColor() << ' ' << test_knight.getFigureName() << endl;
    if (test_knight.canMoveToPosition(targetX, targetY)) {
        cout << "Knight can move to position (" << targetX << ", " << targetY << ")" << endl;
    } else {
        cout << "Knight cannot move to position (" << targetX << ", " << targetY << ")" << endl;
    }
    cout << endl;

    // Pawn
    targetX = 4;
    targetY = 5;
    cout << "Your figure: " << test_pawn.getColor() << ' ' << test_pawn.getFigureName() << endl;
    if (test_pawn.canMoveToPosition(targetX, targetY)) {
        cout << "Pawn can move to position (" << targetX << ", " << targetY << ")" << endl;
    } else {
        cout << "Pawn cannot move to position (" << targetX << ", " << targetY << ")" << endl;
    }
    cout << endl;
    return 0;
}
