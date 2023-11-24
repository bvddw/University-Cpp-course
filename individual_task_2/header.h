#include <iostream>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    double price;

    Product(const string& n, double p); // конструктор
    string getName(); // отримуємо ім'я
    virtual double getPrice(); // отримуємо ціну
};

/*
В цьому випадку, DiscountedProduct успадковується від Product з закритим наслідуванням, але жодні методи чи властивості Product не виходять в публічний інтерфейс DiscountedProduct. Ми визначаємо новий метод getDiscountedPrice(), який використовує інформацію з базового класу для розрахунку зниженої ціни.
*/

class DiscountedProduct : private Product {
private:
    double discount;

public:
    DiscountedProduct(const string& n, double p, double discount); // конструктор
    double getDiscountedPrice(); // отримуємо ціну після знижки
    double getDiscount(); // отримуємо розмір знижки
};

/*
Композиція вказує на те, що об'єкти класу ShoppingCart складаються з об'єктів класу Product. У цьому випадку, ShoppingCart містить (або володіє) екземплярами класу Product. Якщо ShoppingCart знищується, також будуть знищені всі об'єкти класу Product, які входять до його складу.
*/

class ShoppingCart {
public:
    vector<Product> items;

    ShoppingCart(const string& n, double p); // конструктор
    void addItem(const Product& item); // додаємо у кошик
    void removeItem(const Product& item); // видаляємо з кошику
    void getAllItems(); // виводить усе що у кошику
    Product retrieveItem(int number); // повертає один продукт
    double getTotalPrice(); // розраховує загальну вартість
    void createOrder(); // створюємо замовлення з того, що маємо у кошику
};

/*
Композиція вказує на те, що об'єкти класу Order складаються з об'єктів класу Product. У цьому випадку, Order містить (або володіє) екземплярами класу Product. Якщо Order знищується, також будуть знищені всі об'єкти класу Product, які входять до його складу.
*/
class Order {
public:
    vector<Product> products;

    void addProduct(const Product& product); // додаємо продукт
    double calculateTotalPrice() const; // розраховуємо вартість
    bool processOrder(); // завершаємо замовлення
};

class User {
private:
    string username;
    string password;
    double balance;

public:
    User(const string& username, const string& passwrod); // конструктор
    void checkCredentials(const string& inputUsername, const string& inputPassword); // перевіряємо дані
    void deposit(double amount); // додати гроші
    double getBalance() const; // отримати баланс
    string get_username();
    string get_password();
    void change_username();
    void change_password();
};

class SuperUser : public User { // успадковуємось від користувача
public:
    void createProduct(const string& name, double price); // додати продукт до магазину
    void removeProduct(const Product& product); // прибрати продукт з магазину 
};

class OnlineShop { // магазин
private:
    User currentUser;
    vector<User> users;
public:
    vector<Product> availableProducts;
    vector<Order> orders;

    void displayAvailableProducts(); // виводить усі наявня товари
    User& loginUser(const string& username, const string& password); // зайти у сайт під цим користувачем
    bool registerUser(const string& username, const string& password); // зареєструватись
    bool logoutUser(User& user); // вийти з сайту
    User checkUser(); // перевірити залогіненого користувача
    Order createOrder(User& user); // створити замовлення
    void processOrder(Order& order); // розмістити замовлення
};
