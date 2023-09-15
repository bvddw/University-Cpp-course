#include <iostream>

using namespace std;

// struct Person
struct Person {
    const char* name;
    int year;
    float mark;
};

// function for processing such data (+++, ++-, +--, ---)
Person person_data(const char* lastname = "Ivanov", int year = 1, float mark = 4.0) {
    Person new_person;
    new_person.name = lastname;
    new_person.year = year;
    new_person.mark = mark;
    return new_person;
}

// function for processing such data (-++, -+-)
Person person_data(int year, float mark = 4.0) {
    Person new_person;
    new_person.name = "Ivanov";
    new_person.year = year;
    new_person.mark = mark;
    return new_person;
}
// function for processing such data (--+)
Person person_data(float mark) {
    Person new_person;
    new_person.name = "Ivanov";
    new_person.year = 1;
    new_person.mark = mark;
    return new_person;
}
// function for processing such data (+-+)
Person person_data(const char* lastname, float mark) {
    Person new_person;
    new_person.name = lastname;
    new_person.year = 1;
    new_person.mark = mark;
    return new_person;
}

Person initialization_free_fields(Person person) {
    // loop for correct calling
    if (person.name) { // if there is name
        if (person.year) { // if there is name and year
            if (person.mark) { // if there is mark
                person = person_data(person.name, person.year, person.mark); // +++
            } else { // if there no mark
                person = person_data(person.name, person.year); // ++-
            }
        } else if (person.mark) { // if there are name and mark but no year
            person = person_data(person.name, person.mark); // +-+
        } else { // if there is name, but no mark and year
            person = person_data(person.name); // +--
        }
    } else { // if there no name
        if (person.year) { // if there no name but there is year
            if (person.mark) { // if there are year and mark but no name
                person = person_data(person.year, person.mark); // -++
            } else { // if there is year but no name and mark
                person = person_data(person.year); // -+-
            }
        } else if (person.mark) { // if there is mark but no name and year 
            person = person_data(person.mark); // --+
        } else { // if there no given data
            person = person_data(); // ---
        }
    }
    return person;
}

void print_data(Person person) {
    cout << endl;
    cout << "Lastname: " << person.name << endl;
    cout << "Year: " << person.year << endl;
    cout << "Mark: " << person.mark << endl;
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

    // loop in which we initialize free fields
    for (int i = 0; i < 8; i++) {
        people[i] = initialization_free_fields(people[i]);
    }
    
    // printing data to console
    for (int i = 0; i < 8; i++) {
        print_data(people[i]);
    }

    return 0;
}