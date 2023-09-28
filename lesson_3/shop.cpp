#include <iostream>
#include <cstring>
using namespace std;

class User; // Forward declaration

class Product {
    public:
        const char* productName;
        float productPrice;

        Product(const char* name, float price) : 
            productName(name), productPrice(price) {}

        void getProductInfo() {
            cout << this->productName << " costs $" << this->productPrice << endl;
        }
};

class OrderDetails {
    public:
        OrderDetails() : totalPrice(0.0) {}

        void addProduct(Product* product) {
            if (this->productListSize < this->maxProductCount) {
                this->productList[this->productListSize++] = product;
                this->totalPrice += product->productPrice;
            } else {
                std::cout << "The cart is full. Cannot add more products." << std::endl;
            }
        }

        void displayOrderDetails() {
            for (int i = 0; i < this->productListSize; i++) {
                cout << "Product " << i + 1 << ":" << endl;
                this->productList[i]->getProductInfo();
            }
        }

        float getTotalPrice() const {
            return this->totalPrice;
        }

    private:
        static const int maxProductCount = 100;
        Product* productList[maxProductCount];
        int productListSize = 0;
        float totalPrice;
};

class ShippingInfo {
    public:
        ShippingInfo(const char* type, const char* country, float cost) :
            shippingType(type), shippingCountry(country), shippingCost(cost) {}

        void displayShippingInfo() {
            cout << "Type: " << this->shippingType << endl;
            cout << "Country: " << this->shippingCountry << endl;
            cout << "Price: $" << this->shippingCost << endl;
        }

        float getTotalPrice() const {
            return this->shippingCost;
        }

    private:
        const char* shippingType;
        const char* shippingCountry;
        float shippingCost;
};

class Customer {
    public:
        Customer(const char* name, const char* address, const char* email, const char* cardNumber, float balance = 0)
            : customerName(name), customerAddress(address), customerEmail(email), cardNumber(cardNumber), accountBalance(balance) {}

        float addFunds(float amountOfMoney) {
            this->accountBalance += amountOfMoney;
            return this->accountBalance;
        }

        void displayCustomerInfo() {
            cout << "Name: " << this->customerName << endl;
            cout << "Address: " << this->customerAddress << endl;
            cout << "Email: " << this->customerEmail << endl;
        }

        const char* getCustomerName() const {
            return this->customerName;
        }

        User registration(const char* usern, const char* pass);

    protected:
        const char* customerName;
        const char* customerAddress;
        const char* customerEmail;
        const char* cardNumber;
        float accountBalance;
};

class User : public Customer {
    private:
        const char* username;
        const char* password;

    public:
        User(const char* name, const char* address, const char* email, const char* cardNumber, const char* username, const char* password)
            : Customer(name, address, email, cardNumber), username(username), password(password) {}

        void displayUserInfo() {
            cout << "Name: " << this->customerName << endl;
            cout << "Address: " << this->customerAddress << endl;
            cout << "Email: " << this->customerEmail << endl;
            cout << "Username: " << this->username << endl;
            cout << "Balance: $" << this->accountBalance << endl;
        }

        bool verify_login(const char* usernameToCheck, const char* passwordToCheck) {
            if (strcmp(this->username, usernameToCheck) == 0 && strcmp(this->password, passwordToCheck) == 0) {
                cout << "Success login!" << endl;
                return true;
            } 
            if (strcmp(this->username, usernameToCheck) != 0) {
                cout << "No user with such username." << endl;
                return false;
            }
            cout << "Incorrect password." << endl;
            return false;
        }
};

User Customer::registration(const char* usern, const char* pass) {
    User new_user(this->customerName, this->customerAddress, this->customerEmail, this->cardNumber, usern, pass);
    new_user.addFunds(this->accountBalance);
    cout << "Registration complete successfully! Your login: " << usern << endl;
    return new_user;
}

class Order {
    public:
        Order(Customer customer, const char* status, ShippingInfo shipping, OrderDetails details):
            orderCustomer (customer), orderStatus(status), orderShipping(shipping),  orderDetails (details) {}

        void displayOrderInfo() {
            cout << "ORDER STATUS: " << this->orderStatus << endl;
            cout << endl << "CUSTOMER INFO" << endl;
            this->orderCustomer.displayCustomerInfo();
            cout << endl << "SHIPPING INFO" << endl;
            this->orderShipping.displayShippingInfo();
            cout << endl << "ORDER DETAILS" << endl;
            this->orderDetails.displayOrderDetails();
            cout << endl << "TOTAL PRICE $" << this->orderDetails.getTotalPrice() + this->orderShipping.getTotalPrice() << endl;
        }

    private:
        Customer orderCustomer;
        const char* orderStatus;
        ShippingInfo orderShipping;
        OrderDetails orderDetails;
};

int main() {
    User user1("Jack", "NewAvenue", "test@gmail.com", "4141232311332244", "jack", "testpass");
    Customer customer1("Bill", "OldAvenue", "email@gmail.com", "4141323233114422", 300);
    Product product1("banana", 6);
    Product product2("apple", 7);
    OrderDetails cart;
    cart.addProduct(&product1);
    cart.addProduct(&product2);
    ShippingInfo new_shipping("Barge", "Ukraine", 120);
    
    Order new_order(customer1, "pending", new_shipping, cart);
    new_order.displayOrderInfo();
    return 0;
}
