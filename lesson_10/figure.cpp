/*
Має чисто віртуальні функції, тобто це абстрактний клас.
Вимагає, щоб похідні класи надавали свої реалізації для всіх віртуальних функцій.
Надає менше реалізації за замовчуванням, тому від похідних класів очікується більше самостійності в реалізації.

Якщо нам потрібно користуватись елементів, причому це будуть різні елементи, успадковані від одного класу - набагато краще використовувати абстрактні класи, бо використовуючи різні зв'язування ми зможемо використовувати різні методи.
Тобто, на мою думку, фігуру краще зробити абстрактним, бо в усіх фігур є периметр і площа. 
Якщо ж нам треба в будь-який час программи слідкувати тільки за набором з одного типу фігур, тоді нам нема сенсу створювати абстрактний клас, і можна користуватись просто класом Фігура.
*/

#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Figure {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() {
        cout << "The figure is:" << endl;
    }
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

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }

    void display() {
        Figure::display();
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

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    void display() {
        Figure::display();
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

    double area() const override {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() const override {
        return a + b + c;
    }

    void display() {
        Figure::display();
        cout << "Triangle with sides (" << a << ", " << b << ", " << c << ")" << endl;
    }
};

int main() {
    Figure* figures[3];

    try {
        figures[0] = new Rectangle(4, 5);
        figures[1] = new Circle(3);
        figures[2] = new Triangle(6, 8, 10);

        for (int i = 0; i < 3; i++) {
            cout << "Figure " << i + 1 << ":" << endl;
            figures[i]->display();
            cout << "Area: " << figures[i]->area() << endl;
            cout << "Perimeter: " << figures[i]->perimeter() << endl;
            cout << endl;
        }

        for (int i = 0; i < 3; i++) {
            delete figures[i];
        }
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
