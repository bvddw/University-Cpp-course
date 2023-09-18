#include <iostream>

using namespace std;

class BabyChair {
    public:
        const char* color;

        BabyChair(const char* color) : color(color) {}
};

class Car {
    public:
        class Engine {
            public:
                const char* type;

                Engine(const char* type) {
                    this->type = type;
                }

                const char* str() {
                    return this->type;
                }
        };

        const char* make;
        const char* model;
        int year;
        double price;
        Engine engine;

        Car(const char* make, const char* model, int year, double price, const char* engine)
        : make(make), model(model), year(year), price(price), engine(engine) {}

        void print() {
            cout << "Car data:" << endl;
            cout << "Make: " << this->make << endl;
            cout << "Model: " << this->model << endl;
            cout << "Year: " << this->year << endl;
            cout << "Price: " << this->price << endl;
            cout << "Engine: " << this->engine.str() << endl;
            cout << "------------------------------------" << endl;
        }
};

class SportCar : public Car {
    public:
        int speed;

        SportCar(const char* make, const char* model, int year, double price, const char* engine, int speed)
        : Car(make, model, year, price, engine), speed(speed) {}

        void print() {
            cout << "Sport car data:" << endl;
            cout << "Make: " << this->make << endl;
            cout << "Model: " << this->model << endl;
            cout << "Year: " << this->year << endl;
            cout << "Price: " << this->price << endl;
            cout << "Engine: " << this->engine.str() << endl;
            cout << "Maximum speed: " << this->speed << "mph" << endl;
            cout << "------------------------------------" << endl;
        }
};

class FamilyCar : public Car {
    public:
        BabyChair chair;

        FamilyCar(const char* make, const char* model, int year, double price, const char* engine, BabyChair chair)
        : Car(make, model, year, price, engine), chair(chair) {}

        void print() {
            cout << "Family car data:" << endl;
            cout << "Make: " << this->make << endl;
            cout << "Model: " << this->model << endl;
            cout << "Year: " << this->year << endl;
            cout << "Price: " << this->price << endl;
            cout << "Engine: " << this->engine.str() << endl;
            cout << "Chair color: " << this->chair.color << endl;
            cout << "------------------------------------" << endl;
        }
};

class Owner {
    public:
        const char* name;
        Car car;
        
        Owner(const char* name, Car car) : name(name), car(car) {}

        void print () {
            cout << this->name << " is owner of car: " << this->car.make << ' ' << this->car.model << endl; 
            cout << "------------------------------------" << endl;
        }
};

int main(){
    Car car1("Honda", "Civic", 2020, 20000.0, "V8");

    BabyChair chair("black");
    FamilyCar car2("Toyota", "Camry", 2022, 25000.0, "V8", chair);
    SportCar car3("Ford", "Mustang", 2023, 45000.0, "V12", 250);

    car1.print();
    car2.print();
    car3.print();

    Owner owner1("Jack", car1);
    Owner owner2("Smith", car2);
    Owner owner3("Johnson", car3);

    owner1.print();
    owner2.print();
    owner3.print();
    return 0;
}