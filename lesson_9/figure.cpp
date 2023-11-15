/*
Має реалізації для всіх віртуальних функцій, а не тільки чисто віртуальні.
Може бути створений напряму, а не тільки як базовий клас для успадкування.
Надає деяку реалізацію за замовчуванням, яку можна використовувати у випадках, коли вона не перевизначається в похідних класах.
*/


#include <iostream>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual double area() {
        return 0.0;
    }

    virtual double perimeter() {
        return 0.0;
    }

    virtual void display() {
        cout << "It is a point with coordinates (0, 0)." << endl;
    };
};

class Rectangle : public Figure {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) {
        if (w <= 0 || h <= 0) {
            throw std::invalid_argument("Invalid dimensions for Rectangle");
        }
        width = w;
        height = h;
    }

    double area() {
        return width * height;
    }

    double perimeter() {
        return 2 * (width + height);
    }

    void display() {
        cout << "Rectangle with width " << width << " and height " << height << endl;
    }
};

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) {
        if (r <= 0) {
            throw std::invalid_argument("Invalid radius for Circle");
        }
        radius = r;
    }
    double area() {
        return M_PI * radius * radius;
    }

    double perimeter() {
        return 2 * M_PI * radius;
    }

    void display() {
        cout << "Circle with radius " << radius << endl;
    }
};

class Triangle : public Figure {
private:
    double a;
    double b;
    double c;

public:
    Triangle(double sideA, double sideB, double sideC) {
        if (sideA <= 0 || sideB <= 0 || sideC <= 0 ||
            sideA + sideB <= sideC || sideA + sideC <= sideB || sideB + sideC <= sideA) {
            throw std::invalid_argument("Invalid dimensions for Triangle");
        }
        a = sideA;
        b = sideB;
        c = sideC;
    }


    double area() {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() {
        return a + b + c;
    }

    void display() {
        cout << "Triangle with sides (" << a << ", " << b << ", " << c << ")" << endl;
    }
};

class Point: public Figure {
private:
    double x;
    double y;

public: 
    Point(double _x, double _y): x(_x), y(_y) {}

    void display() {
        cout << "It is a point with coordinates (" << x << ", " << y << ")." << endl;
    }
};

int main() {
    Figure* figure = new Figure();

    figure->display();
    cout << "Area: " << figure->area() << endl;
    cout << "Perimeter: " << figure->perimeter() << endl;

    Figure* figures[4];

    Rectangle* rectangle = new Rectangle(4, 5);
    rectangle->display();
    cout << "Area: " << rectangle->area() << endl;
    cout << "Perimeter: " << rectangle->perimeter() << endl;
    cout << endl;

    Circle* circle = new Circle(3);
    circle->display();
    cout << "Area: " << circle->area() << endl;
    cout << "Perimeter: " << circle->perimeter() << endl;
    cout << endl;

    Triangle* triangle = new Triangle(6, 8, 10);
    triangle->display();
    cout << "Area: " << triangle->area() << endl;
    cout << "Perimeter: " << triangle->perimeter() << endl;
    cout << endl;

    Point* point = new Point(2, 1.7);
    point->display();
    cout << "Area: " << point->area() << endl;
    cout << "Perimeter: " << point->perimeter() << endl;
    cout << endl;

    figures[0] = rectangle;
    figures[1] = circle;
    figures[2] = triangle;
    figures[3] = point;

    for (int i = 0; i < 4; i++) {
        cout << "Figure " << i + 1 << ":" << endl;
        figures[i]->display();
        cout << "Area: " << figures[i]->area() << endl;
        cout << "Perimeter: " << figures[i]->perimeter() << endl;
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete figures[i];
    }

    return 0;
}
