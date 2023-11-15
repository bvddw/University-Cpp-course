/*
Пізнє та раннє зв'язування надає нам можливості викликати методи не залежно від оголошеного типу даних. Тобто якщо ми створимо масив об'єктів типу point, і в ньому деякі елементи будут просто крапками, а деякі - кольоровими крапками, то методи будуть викликатись саме залежно від типу даних об'єкту, а не просто point.
*/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Point {
protected:
    float x, y;

public:
    Point(float _x, float _y) : x(_x), y(_y) {}

    float getX() const {
        return x;
    }
    
    float getY() const {
        return y;
    }

    virtual void display() {
        cout << "Point (" << x << ", " << y << ")";
    }

    float range_to_zero() {
        return sqrt(x * x + y * y);
    }

    float range_to_other(Point other) {
        return sqrt((x - other.getX()) * (x - other.getX()) + (y - other.getY()) * (y - other.getY()));
    }
};

class ColoredPoint : public Point {
private:
    char* color;

public:
    ColoredPoint(float _x, float _y, const char* _color) : Point(_x, _y) {
        int length = strlen(_color);
        color = new char[length + 1];
        strcpy(this->color, _color);
    }

    void display() {
        Point::display();
        cout << "Color is " << color << endl;
    }
};

int main() {
    Point point(3.4, 4.1);
    ColoredPoint coloredPoint(1, 2, "red");

    cout << "Using early binding (static binding):" << endl;

    point.display();
    cout << endl << "Range to zero is: " << point.range_to_zero() << endl << endl;


    coloredPoint.display();
    cout << endl << "Range to zero is: " << coloredPoint.range_to_zero();
    cout << endl << "Range to point 1 is: " << coloredPoint.range_to_other(point) << endl << endl;

    cout << "Using late binding (polymorphic binding):" << endl;

    Point* ptrToBase = &point;
    ptrToBase->display();
    cout << endl << endl;

    Point* ptrToDerived = &coloredPoint; 
    ptrToDerived->display(); 
    cout << endl;

    return 0;
}
