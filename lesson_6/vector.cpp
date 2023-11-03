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
        cout << "Vector, dimension - " << dimension << ": (";
        for (int i = 0; i < dimension; i++) {
            cout << elements[i];
            if (i < dimension - 1) {
                cout << ", ";
            }
        }
        cout << ")";
    }
};

bool isFirstGreater(const Vector* v1, const Vector* v2) {
    return v1->length() > v2->length();
}

Vector* sumOfVectors(const Vector* v1, const Vector* v2) {
    if (v1->getDimension() != v2->getDimension()) {
        return nullptr;
    }
    int dim = v1->getDimension();
    Vector* v = new Vector(dim);
    for (int i = 0; i < dim; i++) {
        v->setElement(i, v1->getElement(i) + v2->getElement(i));
    }
    return v;
}

double scalarProduct(const Vector* v1, const Vector* v2) {
    double product = 0;
    if (v1->getDimension() != v2->getDimension()) {
        return  NULL;
    }
    for (int i = 0; i < v1->getDimension(); i++) {
        product += v1->getElement(i) + v2->getElement(i);
    }
    return product;
}

double vectorLength(const Vector* v) {
    return v->length();
}

int main() {
    Vector v0(3);
    
    v0.setElement(0, 1.0);
    v0.setElement(1, 2.0);
    v0.setElement(2, 3.0);
    v0.print();

    Vector* v1 = new Vector(3);
    
    v1->setElement(0, 1.0);
    v1->setElement(1, 2.0);
    v1->setElement(2, 3.0);

    Vector* v2 = new Vector(3);
    
    v2->setElement(0, 1.5);
    v2->setElement(1, 2.5);
    v2->setElement(2, 3.5);

    Vector* array[2] = {v1, v2};
    cout << "Vectors:\n\t";
    array[0]->print();
    cout << "\n\tLength = " << array[0]->length();
    cout << "\n\n\t";
    array[1]->print();
    cout << "\n\tLength = " << array[1]->length();
    cout << "\n";
    cout << "Is vector 1 > vector 2: " << ((isFirstGreater(array[0], array[1])) ? ("True") : ("False")) << endl;
    cout << "Sum of vector 1 and vector 2 = ";
    sumOfVectors(array[0], array[1])->print();
    cout << "\nScalar product of v1 and v2 is " << scalarProduct(array[0], array[1]);
    return 0;
}
