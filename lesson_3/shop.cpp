#include <iostream>
#include <cstring>
using namespace std;

class User; // Forward declaration

class Product {
    public:
        Product(const char* name, float price) : 
            productName(name), productPrice(price) {}

        void getProductInfo() {
            cout << this->productName << " costs $" << this->productPrice << endl;
        }

        float getProductPrice() {
            return this->productPrice;
        }

    private:
        const char* productName;
        float productPrice;
};

class OrderDetails {
    public:
        OrderDetails() : totalPrice(0.0) {}

        void addProduct(Product* product) {
            if (this->productListSize < this->maxProductCount) {
                this->productList[this->productListSize++] = product;
                this->totalPrice += product->getProductPrice();
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

        float getTotalPrice() {
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

        float getTotalPrice() {
            return this->shippingCost;
        }

        void displayShippingInfo() {
            cout << "Type: " << this->shippingType << endl;
            cout << "Country: " << this->shippingCountry << endl;
            cout << "Price: $" << this->shippingCost << endl;
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

        float checkBalance() {
            return this->accountBalance;
        }

        const char* getCustomerName() const {
            return this->customerName;
        }

        void displayCustomerInfo() {
            cout << "Name: " << this->customerName << endl;
            cout << "Address: " << this->customerAddress << endl;
            cout << "Email: " << this->customerEmail << endl;
        }

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
        User(const char* name, const char* address, const char* email, const char* cardNumber, const char* username, const char* password, float balance)
            : Customer(name, address, email, cardNumber, balance), username(username), password(password) {}

        void displayCustomerInfo() {
            cout << "Name: " << this->customerName << endl;
            cout << "Address: " << this->customerAddress << endl;
            cout << "Email: " << this->customerEmail << endl;
            cout << "Username: " << this->username << endl;
            cout << "Balance: $" << this->accountBalance << endl;
        }

        bool verifyLogin(const char* usernameToCheck, const char* passwordToCheck) {
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

class Order {
    public:
        Order(Customer customer, const char* status, ShippingInfo shipping, OrderDetails details):
        orderCustomer(customer), orderShipping(shipping), orderDetails(details) {
            orderStatus = new char[strlen(status) + 1];
            strcpy(this->orderStatus, status);
        }

        ~Order() {
            delete[] orderStatus;
        }


        float getOrderTotalPrice() {
            float shippingPrice = this->orderShipping.getTotalPrice();
            float detailsPrice = this->orderDetails.getTotalPrice();
            return shippingPrice + detailsPrice;
        }

        bool placeOrder() {
            if (this->getOrderTotalPrice() <= this->orderCustomer.checkBalance()) {
                strcpy(this->orderStatus, "completed");
                cout << "Your order successfully completed!" << endl;
                return true;
            }
            strcpy(this->orderStatus, "canceled");
            cout << endl << "You do not have enough money." << endl;
            return false;
        }

        void displayOrderInfo() {
            cout << "ORDER STATUS: " << this->orderStatus << endl;
            cout << endl << "CUSTOMER INFO" << endl;
            this->orderCustomer.displayCustomerInfo();
            cout << endl << "SHIPPING INFO" << endl;
            this->orderShipping.displayShippingInfo();
            cout << endl << "ORDER DETAILS" << endl;
            this->orderDetails.displayOrderDetails();
            cout << endl << "TOTAL PRICE $" << this->getOrderTotalPrice() << endl;
        }

    private:
        Customer orderCustomer;
        char* orderStatus;
        ShippingInfo orderShipping;
        OrderDetails orderDetails;
};

int main() {
    User user1("Jack", "NewAvenue", "test@gmail.com", "4141232311332244", "jack", "testpass", 300);
    Customer customer1("Bill", "OldAvenue", "email@gmail.com", "4141323233114422", 100);
    // Product product1("banana", 6);
    // Product product2("apple", 7);
    // OrderDetails cart;
    // cart.addProduct(&product1);
    // cart.addProduct(&product2);
    // ShippingInfo new_shipping("Barge", "Ukraine", 120);
    
    // Order new_order(customer1, "pending", new_shipping, cart);
    // new_order.displayOrderInfo();
    // new_order.placeOrder();
    // new_order.displayOrderInfo();
    customer1.displayCustomerInfo();
    user1.displayCustomerInfo();
    return 0;
}
