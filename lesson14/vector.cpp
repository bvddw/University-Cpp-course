#include <iostream>
#include <stdexcept>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Default constructor
    Rectangle() : length(0.0), width(0.0) {}

    Rectangle(double l, double w) : length(l), width(w) {}

    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    double area() const {
        return length * width;
    }

    friend ostream& operator<<(ostream& os, const Rectangle& rect) {
        os << "Rectangle(" << rect.length << ", " << rect.width << ")";
        return os;
    }
};

template <typename T, int Size = 10>
class Vector {
private:
    T elements[Size];
    int currentSize;

public:
    Vector() : currentSize(0) {}

    T& operator[](int index) {
        if (index < 0 || index >= currentSize) {
            throw out_of_range("Index out of range");
        }
        return elements[index];
    }

    Vector& operator=(const Vector& other) {
        for (int i = 0; i < currentSize; ++i) {
            elements[i] = other.elements[i];
        }
        return *this;
    }

    bool operator==(const Vector& other) const {
        if (currentSize != other.currentSize) {
            return false;
        }
        for (int i = 0; i < currentSize; ++i) {
            if (elements[i] != other.elements[i]) {
                return false;
            }
        }
        return true;
    }

    // // Оператор додавання
    // Vector operator+(const Vector& other) const {
    //     Vector result;
    //     for (int i = 0; i < Size; ++i) {
    //         result.elements[i] = elements[i] + other.elements[i];
    //     }
    //     return result;
    // }

    // // Оператор віднімання
    // Vector operator-(const Vector& other) const {
    //     Vector result;
    //     for (int i = 0; i < Size; ++i) {
    //         result.elements[i] = elements[i] - other.elements[i];
    //     }
    //     return result;
    // }

    // // Оператор множення на скаляр
    // Vector operator*(const T& scalar) const {
    //     Vector result;
    //     for (int i = 0; i < Size; ++i) {
    //         result.elements[i] = elements[i] * scalar;
    //     }
    //     return result;
    // }

    // // Оператор додавання з присвоєнням
    // Vector& operator+=(const Vector& other) {
    //     for (int i = 0; i < Size; ++i) {
    //         elements[i] += other.elements[i];
    //     }
    //     return *this;
    // }

    void push_back(const T& value) {
        if (currentSize < Size) {
            elements[currentSize++] = value;
        } else {
            throw overflow_error("Vector is full");
        }
    }

    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        } else {
            throw underflow_error("Vector is empty");
        }
    }

    T& at(int index) {
        if (index < 0 || index >= currentSize) {
            throw out_of_range("Index out of range");
        }
        return elements[index];
    }

    void clear() {
        currentSize = 0;
    }

    T& front() {
        if (currentSize > 0) {
            return elements[0];
        }
        throw underflow_error("Vector is empty");
    }

    T& back() {
        if (currentSize > 0) {
            return elements[currentSize - 1];
        }
        throw underflow_error("Vector is empty");
    }

    int size() const {
        return currentSize;
    }

    friend ostream& operator<<(ostream& os, const Vector& vec) {
        os << "(";
        for (int i = 0; i < vec.currentSize - 1; ++i) {
            os << vec.elements[i] << ", ";
        }
        if (vec.currentSize > 0) {
            os << vec.elements[vec.currentSize - 1];
        }
        os << ")";
        return os;
    }
};

int main() {
    try {
        // Using Vector with Rectangle objects
        Vector<Rectangle, 3> rectangles;

        Rectangle r1(4.0, 5.0);
        Rectangle r2(2.5, 3.0);
        Rectangle r3(6.0, 8.0);

        rectangles.push_back(r1);
        rectangles.push_back(r2);
        rectangles.push_back(r3);

        cout << "Rectangles: " << rectangles << endl;
        cout << "Last: " << rectangles.back() << endl;
        rectangles.pop_back();
        cout << "Rectangles: " << rectangles << endl;
        cout << "First: " << rectangles.front() << endl;
        rectangles.clear();
        cout << "Rectangles after clearing: " << rectangles << endl;

    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    try {
        Vector<int, 3> v1;

        cout << "v1: " << v1 << endl;
        v1.push_back(7);
        cout << "v1: " << v1; 
        v1.push_back(7);
        cout << "v1: " << v1;
        v1.push_back(7);
        cout << "v1: " << v1;

    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
