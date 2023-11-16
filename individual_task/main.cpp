#include <iostream>
#include "logic.cpp"

using namespace std;

int main() {
    auto* library = new Library();
    bool flag = true;
    int choice;
    int _choice;
    char login[50];
    char password[50];
    int num_filter;
    float funds;
    char char_filter[50];
    char title[50];
    char author[50];
    char publisher[50];
    char language[50];
    int year;
    float price;
    Book* book = nullptr;

    while (flag) {
        if (!Library::CurrentUser) {
            cout << "\nLOGIN PAGE" << endl;
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            cout << "3. Create Super User" << endl;
            cout << "4. Finish Program" << endl;
            cout << "Choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Your login: ";
                    cin >> login;
                    cout << "Your password: ";
                    cin >> password;
                    if (library->login(login, password)) {
                        cout << "Welcome to app!" << endl;
                    } else {
                        cout << "Incorrect credentials!" << endl;
                    }
                    break;
                case 2:
                    cout << "Your login: ";
                    cin >> login;
                    cout << "Your password: ";
                    cin >> password;
                    if (library->registration(login, password)) {
                        cout << "Your registration success!" << endl;
                    } else {
                        cout << "User with that username already exist!" << endl;
                    }
                    break;
                case 3:
                    cout << "Your login: ";
                    cin >> login;
                    cout << "Your password: ";
                    cin >> password;
                    if (library->createSuperUser(login, password)) {
                        cout << "Your registration success!" << endl;
                    } else {
                        cout << "User with that username already exist!" << endl;
                    }
                    break;
                case 4:
                    cout << "The program finished successfully!" << endl;
                    flag = false;
                    library->saveBooks();
                    library->saveUsers();
                    library->saveSuperUsers();
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
        } else if (!Library::CurrentUser->isSuperUser()) {
            cout << "\nREGULAR USER PAGE" << endl;
            cout << "1. Check all books" << endl;
            cout << "2. Check book by its ID" << endl;
            cout << "3. Check chosen authors books" << endl;
            cout << "4. Check books posted in the chosen year" << endl;
            cout << "5. Check books on chosen language" << endl;
            cout << "6. Check books by chosen publisher" << endl;
            cout << "7. Profile page" << endl;
            cout << "8. Logout" << endl;
            cout << "9. Buy a book" << endl;
            cout << "10. Finish Program" << endl;
            cout << "Your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    library->GetAllBooks();
                    break;
                case 2:
                    cout << "Enter the ID of the book: ";
                    cin >> num_filter;
                    book = library->RetrieveBook(num_filter);
                    if (!book) {
                        cout << "There no books with that ID" << endl;
                    } else {
                        book->infoToConsole();
                    }
                    break;
                case 3:
                    cout << "Enter the author: ";
                    cin >> char_filter;
                    library->GetBooksByAuthor(char_filter);
                    break;
                case 4:
                    cout << "Enter the year: ";
                    cin >> num_filter;
                    library->GetBooksByYear(num_filter);
                    break;
                case 5:
                    cout << "Enter the language: ";
                    cin >> char_filter;
                    library->GetBooksByLanguage(char_filter);
                    break;
                case 6:
                    cout << "Enter the publisher company: ";
                    cin >> char_filter;
                    library->GetBooksByPublisher(char_filter);
                    break;
                case 7:
                    cout << "\nPROFILE PAGE" << endl;
                    cout << "1. Change username" << endl;
                    cout << "2. Change password" << endl;
                    cout << "3. Get statistics" << endl;
                    cout << "4. Deposit money" << endl;
                    cout << "5. Check balance" << endl;
                    cout << "6. Return on user page" << endl;
                    cout << "Your choice: ";
                    cin >> _choice;
                    if (_choice == 1) {
                        cout << "Enter new username: ";
                        cin >> login;
                        Library::CurrentUser->setNewLogin(login);
                    } else if (_choice == 2) {
                        cout << "Enter new password: ";
                        cin >> password;
                        Library::CurrentUser->setNewPassword(password);
                    } else if (_choice == 3) {
                        Library::CurrentUser->getStatistics();
                    } else if (_choice == 4) {
                        cout << "Enter amount of money: ";
                        cin >> funds;
                        Library::CurrentUser->deposit(funds);
                    } else if (_choice == 5) {
                        cout << "You have " << Library::CurrentUser->checkBalance() << " dollars on you account." << endl;
                    }
                    break;
                case 8:
                    library->logout();
                    break;
                case 9:
                    cout << "\nEnter the ID of the book you want to buy: ";
                    cin >> num_filter;
                    book = library->RetrieveBook(num_filter);
                    if (!book) {
                        cout << "There no that id." << endl;
                        break;
                    }
                    if (!Library::CurrentUser->transaction(book)) {
                        cout << "You do not have enough money, or you already have this book" << endl;
                    } else {
                        cout << "The operation was successful!" << endl;
                    }
                    break;
                case 10:
                    flag = false;
                    library->saveBooks();
                    library->saveUsers();
                    library->saveSuperUsers();
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
        } else {
            cout << "\nADMIN USER PAGE" << endl;
            cout << "1. Check all books" << endl;
            cout << "2. Check book by its ID" << endl;
            cout << "3. Check chosen authors books" << endl;
            cout << "4. Check books posted in the chosen year" << endl;
            cout << "5. Check books on chosen language" << endl;
            cout << "6. Check books by chosen publisher" << endl;
            cout << "7. Profile page" << endl;
            cout << "8. Logout" << endl;
            cout << "9. Buy a book" << endl;
            cout << "10. Add new book" << endl;
            cout << "11. Update book by ID" << endl;
            cout << "12. Delete book by ID" << endl;
            cout << "13. Finish Program" << endl;
            cout << "Your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    library->GetAllBooks();
                    break;
                case 2:
                    cout << "Enter the ID of the book: ";
                    cin >> num_filter;
                    book = library->RetrieveBook(num_filter);
                    if (!book) {
                        cout << "There no books with that ID" << endl;
                    } else {
                        book->infoToConsole();
                    }
                    break;
                case 3:
                    cout << "Enter the author: ";
                    cin >> char_filter;
                    library->GetBooksByAuthor(char_filter);
                    break;
                case 4:
                    cout << "Enter the year: ";
                    cin >> num_filter;
                    library->GetBooksByYear(num_filter);
                    break;
                case 5:
                    cout << "Enter the language: ";
                    cin >> char_filter;
                    library->GetBooksByLanguage(char_filter);
                    break;
                case 6:
                    cout << "Enter the publisher company: ";
                    cin >> char_filter;
                    library->GetBooksByPublisher(char_filter);
                    break;
                case 7:
                    cout << "\nPROFILE PAGE" << endl;
                    cout << "1. Change username" << endl;
                    cout << "2. Change password" << endl;
                    cout << "3. Get statistics" << endl;
                    cout << "4. Deposit money" << endl;
                    cout << "5. Check balance" << endl;
                    cout << "6. Return on user page" << endl;
                    cout << "Your choice: ";
                    cin >> _choice;
                    if (_choice == 1) {
                        cout << "Enter new username: ";
                        cin >> login;
                        Library::CurrentUser->setNewLogin(login);
                    } else if (_choice == 2) {
                        cout << "Enter new password: ";
                        cin >> password;
                        Library::CurrentUser->setNewPassword(password);
                    } else if (_choice == 3) {
                        Library::CurrentUser->getStatistics();
                    } else if (_choice == 4) {
                        cout << "Enter amount of money: ";
                        cin >> funds;
                        Library::CurrentUser->deposit(funds);
                    } else if (_choice == 5) {
                        cout << "You have " << Library::CurrentUser->checkBalance() << " dollars on you account." << endl;
                    }
                    break;
                case 8:
                    library->logout();
                    break;
                case 9:
                    cout << "\nEnter the ID of the book you want to buy: ";
                    cin >> num_filter;
                    book = library->RetrieveBook(num_filter);
                    if (!book) {
                        cout << "There no that id." << endl;
                        break;
                    }
                    if (!Library::CurrentUser->transaction(book)) {
                        cout << "You do not have enough money, or you already have this book" << endl;
                    } else {
                        cout << "The operation was successful!" << endl;
                    }
                    break;
                case 10:
                    cout << "Enter the title of the book: ";
                    cin >> title;
                    cout << "Enter the author of the book: ";
                    cin >> author;
                    cout << "Enter the year of publishing: ";
                    cin >> year;
                    cout << "Enter the publisher: ";
                    cin >> publisher;
                    cout << "Enter the language: ";
                    cin >> language;
                    cout << "Enter the price of the book: ";
                    cin >> price;
                    book = new Book(title, author, year, publisher, language, price);
                    if (!library->AddBook(book)) {
                        cout << "This book already exist" << endl;
                    } else {
                        cout << "The operation completed successfully" << endl;
                    }
                    break;
                case 11:
                    cout << "Enter the ID of the book: ";
                    cin >> num_filter;
                    if (!library->UpdateBook(num_filter)) {
                        cout << "There no book with that ID" << endl;
                    }
                    break;
                case 12:
                    cout << "Enter the ID of the book: ";
                    cin >> num_filter;
                    if (!library->RemoveBook(num_filter)) {
                        cout << "There no book with that ID" << endl;
                    } else {
                        cout << "The operation completed successfully" << endl;
                    }
                    break;
                case 13:
                    flag = false;
                    library->saveBooks();
                    library->saveUsers();
                    library->saveSuperUsers();
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
        }
    }


    return 0;
}
