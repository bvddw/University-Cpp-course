#include <iostream>
#include <stdexcept>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduce();
        fixSign();
    }

    void reduce() {
        int gcd = calculateGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    int calculateGCD(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void fixSign() {
        if (denominator < 0) {
            numerator = (-1) * numerator;
            denominator = (-1) * denominator;
        }
    }

    // Арифметичні операції
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        Fraction result(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
        result.fixSign();
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by zero.");
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // Операції порівняння
    bool operator==(const Fraction& other) const {
        return (numerator * other.denominator == other.numerator * denominator);
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return (numerator * other.denominator < other.numerator * denominator);
    }

    bool operator<=(const Fraction& other) const {
        return (*this < other || *this == other);
    }

    bool operator>(const Fraction& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    // Інкремент та декремент
    Fraction& operator++() {  // Префіксний інкремент
        numerator += denominator;
        reduce();
        fixSign();
        return *this;
    }

    Fraction operator++(int) {  // Постфіксний інкремент
        Fraction temp = *this;
        numerator += denominator;
        reduce();
        fixSign();
        return temp;
    }

    Fraction& operator--() {  // Префіксний декремент
        numerator -= denominator;
        reduce();
        fixSign();
        return *this;
    }

    Fraction operator--(int) {  // Постфіксний декремент
        Fraction temp = *this;
        numerator -= denominator;
        reduce();
        fixSign();
        return temp;
    }

    // Виведення та введення
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Fraction& fraction) {
        char slash;
        is >> fraction.numerator >> slash >> fraction.denominator;
        if (fraction.denominator == 0 || slash != '/') {
            is.setstate(std::ios::failbit);
        } else {
            fraction.reduce();
        }
        return is;
    }
};

int main() {
    try {
        Fraction a(1, 2);
        Fraction b(3, 4);

        cout << "a = " << a << endl;
        cout << "b = " << b << endl;

        cout << "a + b = " << a + b << endl;
        cout << "a - b = " << a - b << endl;
        cout << "a * b = " << a * b << endl;
        cout << "a / b = " << a / b << endl;

        cout << "a == b: " << (a == b) << endl;
        cout << "a != b: " << (a != b) << endl;
        cout << "a < b: " << (a < b) << endl;
        cout << "a > b: " << (a > b) << endl;

        cout << "Prefix Increment of a: " << ++a << endl;
        cout << "Postfix Increment of a: " << a++ << endl;
        cout << "a after postfix increment: " << a << endl;

        cout << "Prefix Decrement of b: " << --b << endl;
        cout << "Postfix Decrement of b: " << b-- << endl;
        cout << "b after postfix decrement: " << b << endl;

        cout << "Enter a fraction (format: numerator/denominator): ";
        Fraction userFraction(0, 1);
        cin >> userFraction;
        cout << "You entered: " << userFraction << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}