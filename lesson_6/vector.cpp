#include <iostream>
#include <cmath>

using namespace std;

class Vector {
private:
    int dimension;
    double* elements;

public:
    Vector(int dim) : dimension(dim) {
        elements = new double[dimension];
        for (int i = 0; i < dimension; i++) {
            elements[i] = 0.0;
        }
    }

    Vector(const Vector& other) : dimension(other.dimension) {
        elements = new double[dimension];
        for (int i = 0; i < dimension; i++) {
            elements[i] = other.elements[i];
        }
    }

    ~Vector() {
        delete[] elements;
    }

    int getDimension() const {
        return dimension;
    }

    void setElement(int index, double value) {
        if (index >= 0 && index < dimension) {
            elements[index] = value;
        } else {
            cout << "Incorrect index" << endl;
        }
    }

    double getElement(int index) const {
        if (index >= 0 && index < dimension) {
            return elements[index];
        } else {
            cout << "Incorrect index" << endl;
            return 0.0;
        }
    }

    double length() const {
        double sumOfSquares = 0.0;
        for (int i = 0; i < dimension; i++) {
            sumOfSquares += elements[i] * elements[i];
        }
        return sqrt(sumOfSquares);
    }

    void print() const {
        cout << "Vector (dimension: " << dimension << ")";
        for (int i = 0; i < dimension; i++) {
            cout << elements[i];
            if (i < dimension - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
};

double vectorLength(const Vector& v) {
    return v.length();
}

int main() {
    Vector v1(3);
    
    v1.setElement(0, 1.0);
    v1.setElement(1, 2.0);
    v1.setElement(2, 3.0);

    v1.print();
    cout << "Vector`s length (using method): " << v1.length() << endl;
    cout << "Vector`s length (using func, not method): " << vectorLength(v1) << endl;

    return 0;
}
