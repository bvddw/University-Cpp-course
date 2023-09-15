#include <iostream>

using namespace std;

// struct Person
struct Person {
    const char* name;
    int year;
    float mark;
};


// function for processing such data (+++, ++-, +--, ---)
void person_data(const char* lastname = "Ivanov", int year = 1, float mark = 4.0) {
    cout << "Last Name: " << lastname << endl;
    cout << "Year of enrollment: " << year << endl;
    cout << "Average Mark: " << mark << endl;
    cout << endl;
}

// function for processing such data (-++, -+-)
void person_data(int year, float mark = 4.0) {
    const char* lastname = "Ivanov";
    cout << "Last Name: " << lastname << endl;
    cout << "Year of enrollment: " << year << endl;
    cout << "Average Mark: " << mark << endl;
    cout << endl;
}
// function for processing such data (--+)
void person_data(float mark) {
    const char* lastname = "Ivanov";
    int year = 1;
    cout << "Last Name: " << lastname << endl;
    cout << "Year of enrollment: " << year << endl;
    cout << "Average Mark: " << mark << endl;
    cout << endl;
}
// function for processing such data (+-+)
void person_data(const char* lastname, float mark) {
    int year = 1;
    cout << "Last Name: " << lastname << endl;
    cout << "Year of enrollment: " << year << endl;
    cout << "Average Mark: " << mark << endl;
    cout << endl;
}

void correct_calling(Person people) {
    if (people.name) { // if there is name
        if (people.year) { // if there is name and year
            if (people.mark) { // if there is mark
                person_data(people.name, people.year, people.mark); // +++
            } else { // if there no mark
                person_data(people.name, people.year); // ++-
            }
        } else if (people.mark) { // if there are name and mark but no year
            person_data(people.name, people.mark); // +-+
        } else { // if there is name, but no mark and year
            person_data(people.name); // +--
        }
    } else { // if there no name
        if (people.year) { // if there no name but there is year
            if (people.mark) { // if there are year and mark but no name
                person_data(people.year, people.mark); // -++
            } else { // if there is year but no name and mark
                person_data(people.year); // -+-
            }
        } else if (people.mark) { // if there is mark but no name and year 
            person_data(people.mark); // --+
        } else { // if there no given data
            person_data(); // ---
        }
    }
}

int main() {    
    // array of people with diff given data
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

    // loop for correct calling
    for (int i = 0; i < 8; i++) {
        correct_calling(people[i]); // calling function for define in which fields we have data 
    }


    return 0;
}

