#include <iostream>

using namespace std;

class Rectangle {
protected:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int getHeight() {
        return height;
    }

    int getWidth() {
        return width;
    }

    int area() {
        return width * height;
    }

    int perimeter() {
        return 2 * (width + height);
    }

    void changeSize(int width, int height = 0) {
        this->width = width;
        if (height) {
            this->height = height;
        }
    }
};

// Closed Inheritance
class Window_Inheritance : public Rectangle {
private:
    int x;
    int y;

public:
    Window_Inheritance(int w, int h, int initialX, int initialY) : Rectangle(w, h), x(initialX), y(initialY) {}

    void move(int newX, int newY) {
        x = newX;
        y = newY;
    }
    // bottom left x
    int getBLX() {
        return x;
    }
    // bottom left y
    int getBLY() {
        return y;
    }
    // top left x
    int getTLX() {
        return x;
    }
    // bottom left y
    int getTLY() {
        return y + height;
    }
    // top right x
    int getTRX() {
        return x + width;
    }
    // top right y
    int getTRY() {
        return y + height;
    }
    // bottom right x 
    int getBRX() {
        return x + width;
    }
    // bottom right y
    int getBRY() {
        return y;
    }

    void displayInfo() {
        cout << "Window position: (" << x << ", " << y << ")\n";
        cout << "Window width: " << width << "\n";
        cout << "Window height: " << height << "\n";
        cout << "Window area: " << area() << "\n";
        cout << "Window perimeter: " << perimeter() << "\n";
        cout << "Coordinates of angles:";
        cout << "\n\tBottom left: (" << getBLX() << ", " << getBLY() << ')';
        cout << "\n\tTop left: (" << getTLX() << ", " << getTLY() << ')';
        cout << "\n\tTop right: (" << getTRX() << ", " << getTRY() << ')';
        cout << "\n\tBottom right: (" << getBRX() << ", " << getBRY() << ')';
    }
};

// Composition
class Window_Composition {
private:
    Rectangle rectangle;
    int x;
    int y;

public:
    Window_Composition(int w, int h, int initialX, int initialY) : rectangle(w, h), x(initialX), y(initialY) {}

    void move(int newX, int newY) {
        x = newX;
        y = newY;
    }

    int area() {
        return rectangle.area();
    }

    int perimeter() {
        return rectangle.perimeter();
    }

    int height() {
        return rectangle.getHeight();
    }

    int width() {
        return rectangle.getWidth();
    }

    void changeSize(int width, int height = 0) {
        rectangle.changeSize(width, height);
    }

    // bottom left x
    int getBLX() {
        return x;
    }
    // bottom left y
    int getBLY() {
        return y;
    }
    // top left x
    int getTLX() {
        return x;
    }
    // bottom left y
    int getTLY() {
        return y + height();
    }
    // top right x
    int getTRX() {
        return x + width();
    }
    // top right y
    int getTRY() {
        return y + height();
    }
    // bottom right x 
    int getBRX() {
        return x + width();
    }
    // bottom right y
    int getBRY() {
        return y;
    }

    void displayInfo() {
        cout << "Window position: (" << x << ", " << y << ")\n";
        cout << "Window width: " << width() << "\n";
        cout << "Window height: " << height() << "\n";
        cout << "Window area: " << area() << "\n";
        cout << "Window perimeter " << perimeter() << "\n";
        cout << "Coordinates of angles:";
        cout << "\n\tBottom left: (" << getBLX() << ", " << getBLY() << ')';
        cout << "\n\tTop left: (" << getTLX() << ", " << getTLY() << ')';
        cout << "\n\tTop right: (" << getTRX() << ", " << getTRY() << ')';
        cout << "\n\tBottom right: (" << getBRX() << ", " << getBRY() << ')';
    }
};

int main() {
    cout << endl << "INHERITANCE" << endl;
    Window_Inheritance window_inh(10, 20, 5, 5);
    cout << "\nBefore moving:\n";
    window_inh.displayInfo();
    window_inh.move(10, 15);
    cout << "\n\nAfter moving:\n";
    window_inh.displayInfo();
    window_inh.changeSize(20, 30);
    cout << "\n\nAfter size changing:\n";
    window_inh.displayInfo();

    cout << endl << endl << "COMPOSITION" << endl;
    Window_Composition window_com(10, 20, 5, 5);
    cout << "\nBefore moving:\n";
    window_com.displayInfo();
    window_com.move(10, 15);
    cout << "\n\nAfter moving:\n";
    window_com.displayInfo();
    window_com.changeSize(20, 30);
    cout << "\n\nAfter size changing:\n";
    window_com.displayInfo();
    
    return 0;
}
