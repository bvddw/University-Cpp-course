/*
Я створюю онлайн-магазин, де буде система реєстарції, логіна/логаута. Звичайний користувач після реєстреації може користуватись магазином, створювати замовлення, підтверджувати його, керувати балансом і своїм профілем. Адміністратор зможе додавати та прибирати товари з "полок" магазину, а також буде мати увесь функціонал звичайного користувача також. В результаті виходить консольний додаток, де буде реалізований онлайн-магазин. Замість баз даних я обираю файлову систему збереження магазину. Тобто при перезапуску додатку, магазин буде в тому самому стані, в якому лишився після останнього завершення.
*/

/*
Онлайн-магазин.
Є клас товар (Product), він буде основною складовою магазину. У товара є назва та ціна.
Клас DiscountedProduct - створюємо закритим успадкуванням від Product. Це буде товар за знижкою.
Клас ShoppingCart відповідає за корзину товарів, які користувач набирає протягом відвідування сайту.
Клас Order відповідає створення замовлення, тобто це підтверджена корзина.
Клас User - це клас, відповідаючий за звичайного користувача, який може купувати товари, в нього є юзернейм, пароль та баланс.
Клас SuperUser - це клас, успадкований від звичайного користувача. В нього є увесь функціонал звичайного користувача, але ще можливість додавати та прибирати товари з магазину.
Клас OnlineShop - це клас, який буде відповідати за магазин. В ньому буде список товарів, користувачів та замовлень. Він і надає функціонал користування магазином.
*/


#include <iostream>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    double price;

    Product(const string& n, double p); // конструктор
    string getName(); // отримуємо ім'я
    double getPrice(); // отримуємо ціну
};

/*
В цьому випадку, DiscountedProduct успадковується від Product з закритим наслідуванням, але жодні методи чи властивості Product не виходять в публічний інтерфейс DiscountedProduct. Ми визначаємо новий метод getDiscountedPrice(), який використовує інформацію з базового класу для розрахунку зниженої ціни.
*/

class DiscountedProduct : private Product {
private:
    double discount;

public:
    DiscountedProduct(const string& n, double p, double discount); // конструктор
    void getFullInfo();
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
    void displayProductWithFiltres(string* filtres); // вивід товарів з фільтрами
    User& loginUser(const string& username, const string& password); // зайти у сайт під цим користувачем
    bool registerUser(const string& username, const string& password); // зареєструватись
    bool logoutUser(User& user); // вийти з сайту
    User checkUser(); // перевірити залогіненого користувача
    Order createOrder(User& user); // створити замовлення
    void processOrder(Order& order); // розмістити замовлення
    void SaveShop();
    void LoadShop();
};
