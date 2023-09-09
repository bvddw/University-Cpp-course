#include <iostream>

using namespace std;

// void func(const char* lastname = "Ivanov", int year = 1, float mark = 4.0); // +++ ++- +-- ---
// void func(int year, float mark = 4.0); // -++ -+-
// void func(float mark); // --+
// void func(const char* lastname, float mark); // +-+



void func(const char* lastname = "Ivanov", int year = 1, float mark = 4.0) {
    cout << "Last Name: " << lastname << endl;
    cout << "Year of enrollment: " << year << endl;
    cout << "Average Mark: " << mark << endl;
    cout << endl;
}

void func(int year, float mark = 4.0) {
    const char* lastname = "Ivanov";
    cout << "Last Name: " << lastname << endl;
    cout << "Year of enrollment: " << year << endl;
    cout << "Average Mark: " << mark << endl;
    cout << endl;
}

void func(float mark) {
    const char* lastname = "Ivanov";
    int year = 1;
    cout << "Last Name: " << lastname << endl;
    cout << "Year of enrollment: " << year << endl;
    cout << "Average Mark: " << mark << endl;
    cout << endl;
}

void func(const char* lastname, float mark) {
    int year = 1;
    cout << "Last Name: " << lastname << endl;
    cout << "Year of enrollment: " << year << endl;
    cout << "Average Mark: " << mark << endl;
    cout << endl;
}

int main() {    
    // Масив тестових викликів func
    const char* testCases[][3] = {
        {"Smith", "2", "4.5"}, // +++
        {"Johnson", "3", NULL},     // ++-
        {"Brown", NULL, NULL},            // +--
        {NULL, NULL, NULL},            // ---
        {NULL, "2", "4.5"}, // -++
        {NULL, "3", NULL},       // -+-
        {NULL, NULL, "3.0"},              // --+
        {"Petrov", NULL, "3.2"} // +-+
    };

    for (int i = 0; i < 8; ++i) {
        const char* lastname = testCases[i][0];
        const char* yearStr = testCases[i][1];
        const char* markStr = testCases[i][2];

        // Перевірка на відсутність параметрів та їхній розбір
        int year = (yearStr != NULL) ? atoi(yearStr) : NULL;
        float mark = (markStr != NULL) ? atof(markStr) : NULL;

        func(lastname, year, mark);
    }


    return 0;
}

