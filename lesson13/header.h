#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

class LongNumber {
private:
    string value;

public:
    // Конструктор за замовчуванням
    LongNumber();
    // Конструктор зі строковим параметром
    LongNumber(const string& str);
    // Перевірка дійсності формату довгого числа
    bool isValid(const string& str) const;
    // Перегрузка оператора "+" для довгих чисел
    LongNumber operator+(const LongNumber& other) const;
    // Перегрузка оператора "-"
    LongNumber operator-(const LongNumber& other) const;
    // Перегрузка оператора "*"
    LongNumber operator*(const LongNumber& other) const;
    // Перегрузка оператора "<<"
    friend ostream& operator<<(ostream& os, const LongNumber& num);
    // Перегрузка оператора ">>"
    friend istream& operator>>(istream& is, LongNumber& num);

private:
    // Внутрішня функція для додавання двох довгих чисел у вигляді рядків
    string add(const string& num1, const string& num2) const;
    // Внутрішня функція для віднімання двох довгих чисел у вигляді рядків
    string subtract(const string& num1, const string& num2) const;
    // Внутрішня функція для множення двох довгих чисел у вигляді рядків
    string multiply(const string& num1, const string& num2) const;
};

ostream& operator<<(ostream& os, const LongNumber& num);

istream& operator>>(istream& is, LongNumber& num);