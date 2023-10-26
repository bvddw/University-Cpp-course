#include <iostream>

enum FigureName {
    King,
    Queen,
    Rook,
    Bishop,
    Knight,
    Pawn
};

struct Figure {
    FigureName figure_name;
    bool is_white;
    int current_position[2];
};

using namespace std;

bool canMoveToPosition(const Figure& figure, int targetX, int targetY) {
    int currentX = figure.current_position[0];
    int currentY = figure.current_position[1];
    
    if (targetX < 0 || targetX > 7 || targetY < 0 || targetY > 7) {
        cout << "There's no such field on the board" << endl;
        return false;
    }

    if (targetX == currentX && targetY == currentY) {
        cout << "Figure is already on this field" << endl;
        return false;
    }

    switch (figure.figure_name) {
        case King:
            return (abs(targetX - currentX) <= 1 && abs(targetY - currentY) <= 1);
        case Queen:
            return (targetX == currentX || targetY == currentY || abs(targetX - currentX) == abs(targetY - currentY));
        case Rook:
            return (targetX == currentX || targetY == currentY);
        case Bishop:
            return (abs(targetX - currentX) == abs(targetY - currentY));

        case Knight:
            return ((abs(targetX - currentX) == 1 && abs(targetY - currentY) == 2) || (abs(targetX - currentX) == 2 && abs(targetY - currentY) == 1));
        case Pawn:
            if (figure.is_white) {
                if (targetY == currentY - 1) {
                    return (targetX == currentX);
                } else if (currentY == 6 && targetY == 4 && targetX == currentX) {
                    return true;
                } else if (abs(targetX - currentX) == 1 && targetY == currentY - 1) {
                    return true;
                }
            } else {
                if (targetY == currentY + 1) {
                    return (targetX == currentX);
                } else if (currentY == 1 && targetY == 3 && targetX == currentX) {
                    return true;
                } else if (abs(targetX - currentX) == 1 && targetY == currentY + 1) {
                    return true;
                }
            }
            return false;
        default:
            cout << "Unknown figure type" << endl;
            return false;
    }
}

int main() {
    Figure king = {King, true, {4, 4}};
    Figure rook = {Rook, false, {0, 0}};
    
    int targetX, targetY;
    
    targetX = 3;
    targetY = 3;
    if (canMoveToPosition(king, targetX, targetY)) {
        cout << "King can move to position (" << targetX << ", " << targetY << ")" << endl;
    } else {
        cout << "King cannot move to position (" << targetX << ", " << targetY << ")" << endl;
    }

    targetX = 4;
    targetY = 4;
    if (canMoveToPosition(rook, targetX, targetY)) {
        cout << "Rook can move to position (" << targetX << ", " << targetY << ")" << endl;
    } else {
        cout << "Rook cannot move to position (" << targetX << ", " << targetY << ")" << endl;
    }

    return 0;
}