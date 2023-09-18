#include <iostream>

using namespace std;

class Car{
    public:
        const char* make;
        const char* model;
        int year;
        double price;

        Car(const char* make, const char* model, int year, double price) {
            this->make = make;
            this->model = model;
            this->year = year;
            this->price = price;
        }

        void print() {
            cout << "Car data:" << endl;
            cout << "Make: " << this->make << endl;
            cout << "Model: " << this->model << endl;
            cout << "Year: " << this->year << endl;
            cout << "Price: " << this->price << endl;
            cout << "--------------------------" << endl;
        }
};

int main(){
    Car car1("Toyota", "Camry", 2022, 25000.0);
    Car car2("Honda", "Civic", 2020, 20000.0);
    Car car3("Ford", "Mustang", 2023, 45000.0);

    car1.print();
    car2.print();
    car3.print();

    return 0;
}