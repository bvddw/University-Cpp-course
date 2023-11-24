#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include "funcs.cpp"

using namespace std;

int main() {
    try {
        LongNumber num1("98765432109876543210");
        LongNumber num2("12345678901234567890");

        LongNumber result1 = num1 + num2;
        cout << "Sum: " << result1 << endl;

        LongNumber result2 = num2 - num1;
        cout << "Difference: " << result2 << endl;

        LongNumber result3 = num1 * num2;
        cout << "Product: " << result3 << endl;

        LongNumber num4;
        cout << "Enter a long number: ";
        cin >> num4;
        LongNumber num5;
        cout << "Enter a long number: ";
        cin >> num5;
        cout << "Sum: " << num4 + num5 << endl;
        cout << "Difference: " << num4 - num5 << endl;
        cout << "Product: " << num4 * num5 << endl;
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
