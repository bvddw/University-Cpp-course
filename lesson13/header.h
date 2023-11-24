#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

class LongNumber {
private:
    std::string value;

public:
    // Конструктор за замовчуванням
    LongNumber();
    // Конструктор зі строковим параметром
    LongNumber(const std::string& str);
    // Перевірка дійсності формату довгого числа
    bool isValid(const std::string& str) const;
    // Перегрузка оператора "+" для довгих чисел
    LongNumber operator+(const LongNumber& other) const;
    // Перегрузка оператора "-"
    LongNumber operator-(const LongNumber& other) const;
    // Перегрузка оператора "*"
    LongNumber operator*(const LongNumber& other) const;
    // Перегрузка оператора "<<"
    friend std::ostream& operator<<(std::ostream& os, const LongNumber& num);
    // Перегрузка оператора ">>"
    friend std::istream& operator>>(std::istream& is, LongNumber& num);

private:
    // Внутрішня функція для додавання двох довгих чисел у вигляді рядків
    std::string add(const std::string& num1, const std::string& num2) const;
    // Внутрішня функція для віднімання двох довгих чисел у вигляді рядків
    std::string subtract(const std::string& num1, const std::string& num2) const;
    // Внутрішня функція для множення двох довгих чисел у вигляді рядків
    std::string multiply(const std::string& num1, const std::string& num2) const;
};

std::ostream& operator<<(std::ostream& os, const LongNumber& num);

std::istream& operator>>(std::istream& is, LongNumber& num);