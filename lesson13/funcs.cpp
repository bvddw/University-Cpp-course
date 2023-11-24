#include "header.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

// Конструктор за замовчуванням
LongNumber::LongNumber() : value("0") {}

// Конструктор зі строковим параметром
LongNumber::LongNumber(const string& str) {
    value = str;
}

// Перевірка дійсності формату довгого числа
bool LongNumber::isValid(const string& str) const {
    return all_of(str.begin(), str.end(), ::isdigit);
}

// Перегрузка оператора "+" для довгих чисел
LongNumber LongNumber::operator+(const LongNumber& other) const {
    return LongNumber(add(value, other.value));
}

// Перегрузка оператора "-"
LongNumber LongNumber::operator-(const LongNumber& other) const {
    return LongNumber(subtract(value, other.value));
}

// Перегрузка оператора "*"
LongNumber LongNumber::operator*(const LongNumber& other) const {
    return LongNumber(multiply(value, other.value));
}

// Перегрузка оператора "<<"
ostream& operator<<(ostream& os, const LongNumber& num);

// Перегрузка оператора ">>"
istream& operator>>(istream& is, LongNumber& num);

// Внутрішня функція для додавання двох довгих чисел у вигляді рядків
string LongNumber::add(const string& num1, const string& num2) const {
    int carry = 0;
    string result;

    // Заповнюємо нулями, щоб вирівняти числа за довжиною
    string paddedNum1(num1.rbegin(), num1.rend());
    string paddedNum2(num2.rbegin(), num2.rend());
    while (paddedNum1.length() < paddedNum2.length()) {
        paddedNum1.push_back('0');
    }
    while (paddedNum2.length() < paddedNum1.length()) {
        paddedNum2.push_back('0');
    }

    for (size_t i = 0; i < paddedNum1.length(); ++i) {
        int sum = (paddedNum1[i] - '0') + (paddedNum2[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry > 0) {
        result.push_back(carry + '0');
    }

    // Реверсуємо результат, так як ми додавали числа з кінця
    return string(result.rbegin(), result.rend());
}

// Внутрішня функція для віднімання двох довгих чисел у вигляді рядків
string LongNumber::subtract(const string& num1, const string& num2) const {
    if (num1 < num2) {
        throw invalid_argument("Result is negative, subtraction not supported");
    }

    int borrow = 0;
    string result;

    // Заповнюємо нулями, щоб вирівняти числа за довжиною
    string paddedNum1(num1.rbegin(), num1.rend());
    string paddedNum2(num2.rbegin(), num2.rend());
    while (paddedNum2.length() < paddedNum1.length()) {
        paddedNum2.push_back('0');
    }

    for (size_t i = 0; i < paddedNum1.length(); ++i) {
        int digit1 = paddedNum1[i] - '0';
        int digit2 = paddedNum2[i] - '0' - borrow;

        if (digit1 >= digit2) {
            result.push_back(digit1 - digit2 + '0');
            borrow = 0;
        } else {
            result.push_back(10 + digit1 - digit2 + '0');
            borrow = 1;
        }
    }

    // Видаляємо зайві нулі в початку результату
    while (!result.empty() && result.back() == '0') {
        result.pop_back();
    }

    // Реверсуємо результат, так як ми віднімали числа з кінця
    return string(result.rbegin(), result.rend());
}

// Внутрішня функція для множення двох довгих чисел у вигляді рядків
string LongNumber::multiply(const string& num1, const string& num2) const {
    int len1 = num1.length();
    int len2 = num2.length();
    vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = len2 - 1; j >= 0; --j) {
            int product = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1] + carry;
            result[i + j + 1] = product % 10;
            carry = product / 10;
        }
        result[i] += carry;
    }

    string resultStr;
    for (int digit : result) {
        resultStr.push_back(digit + '0');
    }

    // Видаляємо зайві нулі в початку результату
    while (resultStr.length() > 1 && resultStr.front() == '0') {
        resultStr.erase(resultStr.begin());
    }

    return resultStr;
}

ostream& operator<<(ostream& os, const LongNumber& num) {
    os << num.value;
    return os;
}

istream& operator>>(istream& is, LongNumber& num) {
    string input;
    is >> input;

    if (!num.isValid(input)) {
        is.setstate(ios::failbit);
    } else {
        num.value = input;
    }

    return is;
}