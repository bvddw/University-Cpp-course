#include <iostream>

class BankAccount {
private:
    double balance;
    static double annualInterestRate;
    static double totalBalance;
    int accountNumber;
    BankAccount* next;

public:
    BankAccount(int numberOfAccount = 0, double initialBalance = 0.0) : balance(initialBalance), accountNumber(numberOfAccount) ,next(nullptr) {
        totalBalance += initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        totalBalance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            totalBalance -= amount;
        } else {
            std::cout << "Insufficient funds in the account." << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void addInterest() {
        double sumToBeAdded = balance * (annualInterestRate / 100.0);
        balance += sumToBeAdded;
        totalBalance += sumToBeAdded;
    }

    static void setAnnualInterestRate(double rate) {
        annualInterestRate = rate;
    }

    static double getAnnualInterestRate() {
        return annualInterestRate;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    void setAccountNumber(int newNumber) {
        accountNumber = newNumber;
    }

    void setNext(BankAccount* nextAccount) {
        next = nextAccount;
    }

    double getTotalBalance() const {
        return totalBalance;
    }

    void withdrawFromTotalBalance(double money) {
        totalBalance -= money;
    }

    BankAccount* getNext() {
        return next;
    }
};

double BankAccount::annualInterestRate = 0.0;
double BankAccount::totalBalance = 0.0;

class AccountList {
private:
    BankAccount* head;
    static int numberOfAccounts;
    
public:
    AccountList() : head(nullptr) {}

    int getNumberOfAccounts() {
        return this->numberOfAccounts;
    }

    void addAccount(BankAccount* account) {
        if (head == nullptr) {
            head = account;
        } else {
            BankAccount* current = head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(account);
        }
        this->numberOfAccounts++;
    }

    BankAccount* getAccount(int accountNumber) {
        BankAccount* current = head;
        while (current != nullptr) {
            if (current->getAccountNumber() == accountNumber) {
                return current;
            }
            current = current->getNext();
        }
        return nullptr;
    }

    void removeAccount(int accountNumber) {
        BankAccount* current = head;
        BankAccount* previous = nullptr;

        while (current != nullptr) {
            if (current->getAccountNumber() == accountNumber) {
                if (previous == nullptr) {
                    head = current->getNext();
                } else {
                    previous->setNext(current->getNext());
                }
                previous = current;
                current->withdrawFromTotalBalance(current->getBalance());
                current = current->getNext();
                while (current != nullptr) {
                    current->setAccountNumber(current->getAccountNumber() - 1);
                    previous = current;
                    current = current->getNext();
                }
                numberOfAccounts--;
                delete current;
                std::cout << "Account " << accountNumber << " removed." << std::endl;
                return;
            }

            previous = current;
            current = current->getNext();
        }

        std::cout << "Account not found." << std::endl;
    }

    void displayAccountBalances() {
        BankAccount* current = head;
        double totalBalance = current->getTotalBalance();
        while (current != nullptr) {
            std::cout << "Account " << current->getAccountNumber() << ": Balance $" << current->getBalance() << std::endl;
            current = current->getNext();
        }
        std::cout << "Total Balance: $" << totalBalance << std::endl;
    }
};

int AccountList::numberOfAccounts = 0;

int main() {
    AccountList accountList;
    BankAccount::setAnnualInterestRate(5.0);

    int choice;
    double amount;
    int accountNumber;

    while (true) {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Create a new account" << std::endl;
        std::cout << "2. Deposit money into an account" << std::endl;
        std::cout << "3. Withdraw money from an account" << std::endl;
        std::cout << "4. Add interest to all accounts" << std::endl;
        std::cout << "5. Check account balances" << std::endl;
        std::cout << "6. Remove an account" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                BankAccount* newAccount = new BankAccount(accountList.getNumberOfAccounts() + 1);
                accountList.addAccount(newAccount);
                std::cout << "Created a new account (Account number: " << accountList.getNumberOfAccounts()<< ")." << std::endl;
                break;
            }
            case 2: {
                std::cout << "Enter the account number: ";
                std::cin >> accountNumber;
                BankAccount* account = accountList.getAccount(accountNumber);
                if (account != nullptr) {
                    std::cout << "Enter the amount to deposit: ";
                    std::cin >> amount;
                    account->deposit(amount);
                    std::cout << "Transaction completed." << std::endl;
                } else {
                    std::cout << "Invalid account number." << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "Enter the account number: ";
                std::cin >> accountNumber;
                BankAccount* account = accountList.getAccount(accountNumber);
                if (account != nullptr) {
                    std::cout << "Enter the amount to withdraw: ";
                    std::cin >> amount;
                    account->withdraw(amount);
                    std::cout << "Transaction completed." << std::endl;
                } else {
                    std::cout << "Invalid account number." << std::endl;
                }
                break;
            }
            case 4: {
                BankAccount* current = accountList.getAccount(1);
                while (current != nullptr) {
                    current->addInterest();
                    current = current->getNext();
                }
                std::cout << "Interest added to all accounts." << std::endl;
                break;
            }
            case 5:
                accountList.displayAccountBalances();
                break;
            case 6: {
                std::cout << "Enter the account number to remove: ";
                std::cin >> accountNumber;
                accountList.removeAccount(accountNumber);
                break;
            }
            case 7:
                std::cout << "Program terminated." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}