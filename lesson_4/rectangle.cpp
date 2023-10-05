#include <iostream>

using namespace std;

class Rectangle {
public:
    Rectangle(double input_length, double input_width) : length(input_length), width(input_width) {}

    double getLength() const { 
        return this->length; 
    }

    double getWidth() const { 
        return this->width; 
    }

    void setLength(double input_length) {
        length = input_length; 
    }
    
    void setWidth(double input_width) {
        width = input_width; 
    }

    double area() const { 
        return this->length * this->width; 
    }

    double perimeter() const { 
        return 2 * (this->length + this->width); 
    }

private:
    double length;
    double width;
};

class CoordinateRectangle : public Rectangle {
public:
    CoordinateRectangle(double x1, double y1, double x2, double y2)
        : Rectangle((x2 - x1 > 0) ? (x2 - x1) : (x1 - x2), (y2 - y1 > 0) ? (y2 - y1) : (y1 - y2)) {}

    double getX1() const { 
        return 0; 
    }

    double getY1() const { 
        return 0; 
    }

    double getX2() const { 
        return this->getLength(); 
    }
    
    double getY2() const { 
        return this->getWidth(); 
    }
};

int main() {
    Rectangle r1(4.0, 5.0);
    cout << "Rectangle 1:\n";
    cout << "Length: " << r1.getLength() << ", Width: " << r1.getWidth() << "\n";
    cout << "Area: " << r1.area() << ", Perimeter: " << r1.perimeter() << "\n";
    cout << endl;

    CoordinateRectangle r2(1.0, 2.0, 5.0, 6.0);
    cout << "Rectangle 2 (Coordinate-based):\n";
    cout << "Length: " << r2.getLength() << ", Width: " << r2.getWidth() << "\n";
    cout << "Area: " << r2.area() << ", Perimeter: " << r2.perimeter() << "\n";
    cout << endl;

    Rectangle rectangles[2] = {r1, r2};
    cout << "Array of Rectangles:\n";
    for (int i = 0; i < 2; ++i) {
        cout << "Rectangle " << i + 1 << ":\n";
        cout << "Length: " << rectangles[i].getLength() << ", Width: " << rectangles[i].getWidth() << "\n";
        cout << "Area: " << rectangles[i].area() << ", Perimeter: " << rectangles[i].perimeter() << "\n\n";
    }

    return 0;
}
