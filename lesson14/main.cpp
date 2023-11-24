#include <iostream>
#include <stdexcept>

using namespace std;

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
    T& operator[](int index) {
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

    // Оператор додавання
    Vector operator+(const Vector& other) const {
        Vector result;
        for (int i = 0; i < Size; ++i) {
            result.elements[i] = elements[i] + other.elements[i];
        }
        return result;
    }

    // Оператор віднімання
    Vector operator-(const Vector& other) const {
        Vector result;
        for (int i = 0; i < Size; ++i) {
            result.elements[i] = elements[i] - other.elements[i];
        }
        return result;
    }

    // Оператор множення на скаляр
    Vector operator*(const T& scalar) const {
        Vector result;
        for (int i = 0; i < Size; ++i) {
            result.elements[i] = elements[i] * scalar;
        }
        return result;
    }

    // Оператор додавання з присвоєнням
    Vector& operator+=(const Vector& other) {
        for (int i = 0; i < Size; ++i) {
            elements[i] += other.elements[i];
        }
        return *this;
    }

    // Оператор віднімання з присвоєнням
    Vector& operator-=(const Vector& other) {
        for (int i = 0; i < Size; ++i) {
            elements[i] -= other.elements[i];
        }
        return *this;
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
};

int main() {
    try {
        Vector<int, 3> v1;
        Vector<int, 3> v2;
        v1[0] = 1;
        v1[1] = 2;
        v1[2] = 3;

        v2[0] = 4;
        v2[1] = 5;
        v2[2] = 6;

        cout << "v1: " << v1 << endl;
        cout << "v2: " << v2 << endl;
        cout << "v1 + v2: " << v1 + v2 << endl;
        cout << "v1 - v2: " << v1 - v2 << endl;
        cout << "v1 * 2: " << v1 * 2 << endl;
        cout << "v2 * 7: " << v2 * 7 << endl;

    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}