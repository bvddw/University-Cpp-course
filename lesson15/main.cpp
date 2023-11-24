#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

// Користувацький клас Point
class Point {
public:
    int x, y;

    // Конструктор за замовчуванням
    Point() : x(0), y(0) {}

    // Конструктор з параметрами
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}

    // Перевизначення оператора виведення для точки
    friend ostream& operator<<(ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    // Перевизначення оператора введення для точки
    friend istream& operator>>(istream& is, Point& point) {
        is >> point.x >> point.y;
        return is;
    }

    // Перевизначення оператора присвоєння для точки
    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }
};

template <typename T, int Size = 10>
class Vector {
private:
    T elements[Size];

public:
    // Конструктор за замовчуванням
    Vector() {
        for (int i = 0; i < Size; ++i) {
            elements[i] = T();  // Значення за замовчуванням для ініціалізації елементів
        }
    }

    // Оператор індексації
    const T& operator[](int index) const {
        if (index < 0 || index >= Size) {
            throw out_of_range("Index out of range");
        }
        return elements[index];
    }

    // Оператор присвоєння
    Vector& operator=(const Vector& other) {
        for (int i = 0; i < Size; ++i) {
            elements[i] = other.elements[i];
        }
        return *this;
    }

    // Оператор порівняння на рівність
    bool operator==(const Vector& other) const {
        for (int i = 0; i < Size; ++i) {
            if (elements[i] != other.elements[i]) {
                return false;
            }
        }
        return true;
    }

    // Вивід вектора
    friend ostream& operator<<(ostream& os, const Vector& vec) {
        os << "(";
        for (int i = 0; i < Size - 1; ++i) {
            os << vec.elements[i] << ", ";
        }
        os << vec.elements[Size - 1] << ")";
        return os;
    }

    // Функція для зчитування вектора з файлу
    friend ifstream& operator>>(ifstream& in, Vector<T, Size>& v) {
        for (int i = 0; i < Size; ++i) {
            T t;
            if (!(in >> t)) {
                throw runtime_error("Error reading from file");
            }
            v.elements[i] = t;  // Update the elements array, not using operator=
        }
        return in;
    }

    // Функція для запису вектора в файл
    friend ofstream& operator<<(ofstream& out, const Vector<T, Size>& v) {
        for (int i = 0; i < Size; ++i) {
            out << v[i] << " ";
        }
        return out;
    }
};

int main() {
    try {
        Vector<Point, 3> v1;
        Vector<Point, 3> v2;

        // Зчитування векторів з файлу
        ifstream inFile("input.txt");
        if (!inFile.is_open()) {
            cerr << "Error opening input file." << endl;
            return 1;
        }

        inFile >> v1 >> v2;
        inFile.close();

        // Виведення векторів
        cout << "v1: " << v1 << endl;
        cout << "v2: " << v2 << endl;

        // Запис векторів у файл
        ofstream outFile("output.txt");
        if (!outFile.is_open()) {
            cerr << "Error opening output file." << endl;
            return 1;
        }

        outFile << v1 << endl << v2;
        outFile.close();

    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
