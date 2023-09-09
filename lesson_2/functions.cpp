#include <iostream>

using namespace std;


void person_data(const char* lastname = "Ivanov", int year = 1, float mark = 4.0) {
    cout << "Last Name: " << lastname << endl;
    cout << "Year of enrollment: " << year << endl;
    cout << "Average Mark: " << mark << endl;
    cout << endl;
}

void person_data(int year, float mark = 4.0) {
    const char* lastname = "Ivanov";
    cout << "Last Name: " << lastname << endl;
    cout << "Year of enrollment: " << year << endl;
    cout << "Average Mark: " << mark << endl;
    cout << endl;
}

void person_data(float mark) {
    const char* lastname = "Ivanov";
    int year = 1;
    cout << "Last Name: " << lastname << endl;
    cout << "Year of enrollment: " << year << endl;
    cout << "Average Mark: " << mark << endl;
    cout << endl;
}

void person_data(const char* lastname, float mark) {
    int year = 1;
    cout << "Last Name: " << lastname << endl;
    cout << "Year of enrollment: " << year << endl;
    cout << "Average Mark: " << mark << endl;
    cout << endl;
}

int main() {    
    struct Person {
        const char* name;
        int year;
        float mark;
    };

    Person people[8] = {
        {"Brown", 3, 1.7}, 
        {"Taylor", 2, NULL}, 
        {"Wilson", NULL, NULL}, 
        {nullptr, NULL, NULL}, 
        {nullptr, 4, 2.8}, 
        {nullptr, 2, NULL}, 
        {"White", NULL, 3.9}, 
        {nullptr, NULL, 4.7}
    };

    for (int i = 0; i < 8; ++i) {
        if (people[i].name) {
            if (people[i].year) {
                if (people[i].mark) {
                    person_data(people[i].name, people[i].year, people[i].mark); // +++
                } else {
                    person_data(people[i].name, people[i].year); // ++-
                }
            } else if (people[i].mark) {
                person_data(people[i].name, people[i].mark); // +-+
            } else {
                person_data(people[i].name); // +--
            }
        } else {
            if (people[i].year) {
                if (people[i].mark) {
                    person_data(people[i].year, people[i].mark); // -++
                } else {
                    person_data(people[i].year); // -+-
                }
            } else if (people[i].mark) {
                person_data(people[i].mark); // --+
            } else {
                person_data(); // ---
            }
        }
    }


    return 0;
}

