#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    Point() : x(0.0), y(0.0) {}

    Point(double x, double y) : x(x), y(y) {}

    double getX() const { 
        return x; 
    }
    double getY() const { 
        return y; 
    }
    double setX(double newX) {
        x = newX;
    }
    double setY(double newY) {
        y = newY;
    }

private:
    double x;
    double y;
};

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

    void print() {
        cout << "Rectange with:\n \tlength = " << this->length << "\n\twidth = " << this->width << endl;
    }

protected:
    double length;
    double width;
};

class CoordinateRectangle : public Rectangle {
public:
    CoordinateRectangle(const Point& intput_bottomLeft, const Point& input_topRight): 
        Rectangle(((intput_bottomLeft.getX() - input_topRight.getX() > 0) ? (intput_bottomLeft.getX() - input_topRight.getX()) : (input_topRight.getX() - intput_bottomLeft.getX())), ((input_topRight.getY() - intput_bottomLeft.getY() > 0) ? (input_topRight.getY() - intput_bottomLeft.getY()) : (intput_bottomLeft.getY() - input_topRight.getX()))), 
        bottomLeft(intput_bottomLeft), 
        topRight(input_topRight) {
            Point topLeft = Point(intput_bottomLeft.getX(), input_topRight.getY());
            this->topLeft = topLeft;
            Point bottomRight = Point(intput_bottomLeft.getY(), input_topRight.getX());
            this->bottomRight = bottomRight;
        }

    double getLength() const { 
        return this->length; 
    }

    double getWidth() const { 
        return this->width; 
    }

    void setBottomLeft(const Point& intput_bottomLeft) {
        this->bottomLeft = intput_bottomLeft;
        this->topLeft.setX(intput_bottomLeft.getX());
        this->bottomRight.setY(intput_bottomLeft.getY());
        this->length = abs(bottomLeft.getY() - topLeft.getY());
        this->width = abs(bottomLeft.getX() - bottomRight.getX());
    }

    void setTopRight(const Point& input_topRight) { 
        this->topRight = input_topRight;
        this->topLeft.setY(input_topRight.getY());
        this->bottomRight.setX(input_topRight.getX());
        this->length = abs(bottomLeft.getY() - topLeft.getY());
        this->width = abs(bottomLeft.getX() - bottomRight.getX());
    }

    double area() const { 
        return this->length * this->width; 
    }
    
    double perimeter() const { 
        return 2 * (this->length + this->width); 
    }

    Point getBottomLeft() const { 
        return this->bottomLeft; 
    }

    Point getTopLeft() const { 
        return this->topLeft; 
    }

    Point getTopRight() const { 
        return this->topRight; 
    }

    Point getBottomRight() const {
        return this->bottomRight;
    }

    void print() const {
        cout << "Rectange with:\n \tlength = " << this->length << "\n\twidth = " << this->width << "\nCoordinates:\n";
        cout << "\tBottom left: (" << this->bottomLeft.getX() << ", " << this->bottomLeft.getY() << ")\n";
        cout << "\tTop left: (" << this->topLeft.getX() << ", " << this->topLeft.getY() << ")\n";
        cout << "\tTop right: (" << this->topRight.getX() << ", " << this->topRight.getY() << ")\n";
        cout << "\tBottom right: (" << this->bottomRight.getX() << ", " << this->bottomRight.getY() << ")\n";
    }

private:
    Point bottomLeft;
    Point topRight;
    Point topLeft;
    Point bottomRight;
};

int main() {
    Rectangle r1(4.0, 5.0);
    cout << "Rectangle 1:\n";
    r1.print();
    cout << "\tArea: " << r1.area() << ", Perimeter: " << r1.perimeter() << "\n";
    cout << endl;

    Point bottomLeft(1.0, 2.0);
    Point topRight(5.0, 6.0);

    CoordinateRectangle r2(bottomLeft, topRight);
    cout << "\nRectangle 2:\n";
    r2.print();
    cout << "\tArea: " << r2.area() << ", Perimeter: " << r2.perimeter() << endl;

    Point newBottomLeft(0.0, 0.0);
    Point newTopRight(8.0, 4.0);
    r2.setBottomLeft(newBottomLeft);
    r2.setTopRight(newTopRight);

    std::cout << "\nUpdated Rectangle 2:\n";
    r2.print();
    std::cout << "\tArea: " << r2.area() << ", Perimeter: " << r2.perimeter() << "\n";

    Rectangle* rectPtr = &r1;
    std::cout << "\nUsing a pointer to base class for Rectangle 1:\n";
    r1.print();
    std::cout << "Area: " << rectPtr->area() << ", Perimeter: " << rectPtr->perimeter() << "\n\n";


    Rectangle rectangles[2] = {r1, r2};
    cout << "Array of Rectangles:\n";
    for (int i = 0; i < 2; ++i) {
        rectangles[i].print();
        cout << "\tArea: " << rectangles[i].area() << ", Perimeter: " << rectangles[i].perimeter() << "\n\n";
    }

    return 0;
}
