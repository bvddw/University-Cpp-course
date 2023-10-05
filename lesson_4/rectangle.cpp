#include <iostream>

using namespace std;

class Point {
public:
    Point() : x(0.0), y(0.0) {}

    Point(double x, double y) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

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
        this->length = (bottomLeft.getX() - bottomLeft.getY() > 0) ? (bottomLeft.getX() - bottomLeft.getY()) : (bottomLeft.getY() - bottomLeft.getX());
        this->width = (topRight.getX() - topRight.getY() > 0) ? (topRight.getX() - topRight.getY()) : (topRight.getY() - topRight.getX());
    }

    void setTopRight(const Point& input_topRight) { 
        this->topRight = input_topRight;
        this->length = (bottomLeft.getX() - bottomLeft.getY() > 0) ? (bottomLeft.getX() - bottomLeft.getY()) : (bottomLeft.getY() - bottomLeft.getX());
        this->width = (topRight.getX() - topRight.getY() > 0) ? (topRight.getX() - topRight.getY()) : (topRight.getY() - topRight.getX());
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

private:
    Point bottomLeft;
    Point topRight;
    Point topLeft;
    Point bottomRight;
};

int main() {
    Rectangle r1(4.0, 5.0);
    cout << "Rectangle 1:\n";
    cout << "Length: " << r1.getLength() << ", Width: " << r1.getWidth() << "\n";
    cout << "Area: " << r1.area() << ", Perimeter: " << r1.perimeter() << "\n";
    cout << endl;

    Point bottomLeft(1.0, 2.0);
    Point topRight(5.0, 6.0);

    CoordinateRectangle r2(bottomLeft, topRight);
    cout << "Rectangle 2:\n";
    cout << "Length: " << r2.getLength() << ", Width: " << r2.getWidth() << endl;
    cout << "Area: " << r2.area() << ", Perimeter: " << r2.perimeter() << endl;
    cout << "Left Bottom point: " << r2.getBottomLeft().getX() << ' ' << r2.getBottomLeft().getY() << endl;
    cout << "Left Top point: " << r2.getTopLeft().getX() << ' ' << r2.getTopLeft().getY() << endl;
    cout << "Right Top point: " << r2.getTopRight().getX() << ' ' << r2.getTopRight().getY() << endl;
    cout << "Rgiht Bottom point: " << r2.getBottomRight().getX() << ' ' << r2.getBottomRight().getY() << endl;

    Point newBottomLeft(0.0, 0.0);
    Point newTopRight(8.0, 4.0);
    r2.setBottomLeft(newBottomLeft);
    r2.setTopRight(newTopRight);

    std::cout << "Updated Rectangle 2:\n";
    std::cout << "Length: " << r2.getLength() << ", Width: " << r2.getWidth() << "\n";
    std::cout << "Area: " << r2.area() << ", Perimeter: " << r2.perimeter() << "\n";

    Rectangle* rectPtr = &r1;
    std::cout << "Using a pointer to base class for Rectangle 1:\n";
    std::cout << "Length: " << rectPtr->getLength() << ", Width: " << rectPtr->getWidth() << "\n";
    std::cout << "Area: " << rectPtr->area() << ", Perimeter: " << rectPtr->perimeter() << "\n\n";


    Rectangle rectangles[2] = {r1, r2};
    cout << "Array of Rectangles:\n";
    for (int i = 0; i < 2; ++i) {
        cout << "Rectangle " << i + 1 << ":\n";
        cout << "Length: " << rectangles[i].getLength() << ", Width: " << rectangles[i].getWidth() << "\n";
        cout << "Area: " << rectangles[i].area() << ", Perimeter: " << rectangles[i].perimeter() << "\n\n";
    }

    return 0;
}
