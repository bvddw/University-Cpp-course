#include <iostream>
#include <fstream>
#include <cstring>
#include "header.h"

using namespace std;

Book::Book(char* title, char* author, int year, char* publisher, char* language, float price, int id, int numberOfBuying):
    title(title), author(author), postYear(year), publisher(publisher), language(language), price(price) {
    numberOfBooks++;
    if (!id) {
        this->id = numberOfBooks;
    } else {
        this->id = id;
    }
    if (!numberOfBuying) {
        this->numberOfBuying = 0;
    } else {
        this->numberOfBuying = numberOfBuying;
    }
}

void Book::infoToConsole() {
    cout << "Book information:" << endl;
    cout << "\t\tId -- " << id << endl;
    cout << "\t\tTitle -- " << title << endl;
    cout << "\t\tYear of post -- " << postYear << endl;
    cout << "\t\tPublisher -- " << publisher << endl;
    cout << "\t\tLanguage -- " << language << endl;
    cout << "\t\tPrice -- " << price << endl;
    cout << "\t\tNumber of people, bought the book -- " << numberOfBuying << endl;
}

int Book::getID() const {
    return id;
}

char* Book::getAuthor() const {
    return author;
}

char* Book::getTitle() const {
    return title;
}

int Book::getYear() const {
    return postYear;
}

char* Book::getPublisher() const {
    return publisher;
}

char* Book::getLanguage() const {
    return language;
}

float Book::getPrice() const {
    return price;
}

int Book::getNumberOfBuying() const {
    return numberOfBuying;
}

void Book::setTitle(char *_title) {
    title = new char[strlen(_title) + 1];
    strcpy(title, _title);
}

void Book::setAuthor(char *_author) {
    author = new char[strlen(_author) + 1];
    strcpy(author, _author);
}

void Book::setYear(int _year) {
    if (_year > 1000 && _year < 2024) {
        postYear = _year;
    }
}

void Book::setPublisher(char *_publisher) {
    publisher = new char[strlen(_publisher) + 1];
    strcpy(publisher, _publisher);
}

void Book::setLanguage(char *_language) {
    language = new char[strlen(_language) + 1];
    strcpy(language, _language);
}

void Book::setPrice(float _price) {
    if (_price > 0) {
        price = _price;
    }
}

AbstractUser::AbstractUser(char *login, char *password, float funds, float spentConsts): login(login), password(password) {
    numberOfUsers++;
    this->funds = funds;
    this->spentCosts = spentConsts;
    numberOfBooks = 0;
    isVIPStatus = false;
    books = new Book*[0];
}

char* AbstractUser::getLogin() const {
    return login;
}

char* AbstractUser::getPassword() const {
    return password;
}

bool AbstractUser::checkCredential(char *_login, char *_password) {
    return !strcmp(login, _login) && !strcmp(password, _password);
}

void AbstractUser::setNewLogin(char* newLogin) {
    login = new char[strlen(newLogin) + 1];
    strcpy(login, newLogin);
}

void AbstractUser::setNewPassword(char *newPassword) {
    password = new char[strlen(newPassword) + 1];
    strcpy(password, newPassword);
}

int AbstractUser::BooksNumber() const {
    return numberOfBooks;
}

bool AbstractUser::transaction(Book* book) {
    for (int i = 0; i < numberOfBooks; i++) {
        if (books[i] == book) {
            return false;
        }
    }
    float price = book->getPrice();
    if (isVIPStatus) {
        price *= 0.75;
    }
    if (price > funds) {
        return false;
    }
    int len = strlen(login);
    char* filename = new char[len + 5];
    strcpy(filename, login);
    filename[len] = 'R';
    filename[len + 1] = '.';
    filename[len + 2] = 't';
    filename[len + 3] = 'x';
    filename[len + 4] = 't';
    filename[len + 5] = '\0';
    if (!numberOfBooks) {
        ofstream file(filename, ios::trunc);
        file.close();
    }
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }
    funds -= price;
    spentCosts += price;
    file << "Book: " << book->getTitle() << ", Price: " << price << endl;
    file.close();
    Book** newBooks = new Book*[numberOfBooks + 1];
    for (int i = 0; i < numberOfBooks; ++i) {
        newBooks[i] = books[i];
    }
    newBooks[numberOfBooks] = book;
    numberOfBooks++;
    books = newBooks;

    return true;
}

void AbstractUser::saveData() const {
    int len = strlen(login);
    char* filename = new char[len + 4];
    strcpy(filename, login);
    filename[len] = '.';
    filename[len + 1] = 't';
    filename[len + 2] = 'x';
    filename[len + 3] = 't';
    filename[len + 4] = '\0';

    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    for (int i = 0; i < numberOfBooks; i++) {
        file << books[i]->getID() << endl;
    }
}

void AbstractUser::addBook(Book *book) {
    Book** newBooks = new Book*[numberOfBooks + 1];
    for (int i = 0; i < numberOfBooks; ++i) {
        newBooks[i] = books[i];
    }
    newBooks[numberOfBooks] = book;
    numberOfBooks++;

    delete[] books;
    books = newBooks;
}

void AbstractUser::loadData(Book** allBooks) {
    int len = strlen(login);
    char* filename = new char[len + 4];
    strcpy(filename, login);
    filename[len] = '.';
    filename[len + 1] = 't';
    filename[len + 2] = 'x';
    filename[len + 3] = 't';
    filename[len + 4] = '\0';
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    char line[200];
    while (file.getline(line, 200)) {
        int pk = stoi(line);
        int index = 0;
        while (pk!=allBooks[index]->getID()) {
            index++;
        }
        addBook(allBooks[index]);
    }
}

float AbstractUser::checkBalance() const {
    return funds;
}

float AbstractUser::checkSpentCosts() const {
    return spentCosts;
}

void AbstractUser::deposit(float money) {
    funds += money;
}

void AbstractUser::getBooksList() const {
    cout << "\nMy books:" << endl;
    for (int i = 0; i < numberOfBooks; i++) {
        cout << '\t' << i + 1 << ')' << " Book -- " << books[i]->getTitle() << endl;
    }
    cout << endl;
}

void AbstractUser::getStatistics() const {
    cout << "\nMinute of statistics:" << endl;
    cout << "For all time, you spent on our library you have spent " << spentCosts << " dollars and you have bought " << numberOfBooks << " books." << endl;
    cout << "You bought " << BooksNumber() << " books!" << endl;
    getBooksList();
    cout << "Thank you for using our library!" << endl;
    cout << endl;
}

AbstractUser::~AbstractUser() {
    delete[] login;
    delete[] password;

    for (int i = 0; i < numberOfBooks; ++i) {
        delete books[i];
    }

    delete[] books;
}

User::User(char *login, char *password, float funds, float spentConsts): AbstractUser(login, password, funds, spentConsts) {}

bool User::isSuperUser() {
    return false;
}

SuperUser::SuperUser(char *login, char *password, float funds, float spentConsts): AbstractUser(login, password, funds, spentConsts) {}

bool SuperUser::isSuperUser() {
    return true;
}

Book* createBookFromLine(char* line) {
    const char delimiter = '~';
    char* tokens[8];  // Assuming there are 8 fields in the line
    int tokenIndex = 0;

    int fieldStart = 0;
    for (int i = 0; line[i] != '\0'; ++i) {
        if (line[i] == delimiter) {
            // Found a delimiter, extract the token
            int fieldLength = i - fieldStart;
            tokens[tokenIndex] = new char[fieldLength + 1];
            strncpy(tokens[tokenIndex], line + fieldStart, fieldLength);
            tokens[tokenIndex][fieldLength] = '\0';
            ++tokenIndex;

            // Move the starting position to the next character
            fieldStart = i + 1;
        }
    }

    // Extract the last token (or the only token if there's only one)
    int fieldLength = strlen(line) - fieldStart;
    tokens[tokenIndex] = new char[fieldLength + 1];
    strncpy(tokens[tokenIndex], line + fieldStart, fieldLength);
    tokens[tokenIndex][fieldLength] = '\0';

    // Check if the correct number of tokens is present
    if (tokenIndex == 7) {
        // Convert relevant tokens to appropriate types and create a Book object
        int id = stoi(tokens[0]);
        char* title = tokens[1];
        char* author = tokens[2];
        int year = stoi(tokens[3]);
        char* publisher = tokens[4];
        char* language = tokens[5];
        float price = stof(tokens[6]);
        int numberOfBuying = stoi(tokens[7]);
        Book* book = new Book(title, author, year, publisher, language, price, id, numberOfBuying);
        // Free memory allocated for tokens
        return book;
    } else {
        // Handle error, return nullptr, or throw an exception
        cerr << "Error: Invalid number of tokens in the line." << endl;

        // Free memory allocated for tokens
        for (int i = 0; i <= tokenIndex; ++i) {
            delete[] tokens[i];
        }

        return nullptr;
    }
}

User* createUserFromLine(char* line) {
    const char delimiter = '~';
    char* tokens[4];  // Assuming there are 2 fields in the line

    int tokenIndex = 0;
    int fieldStart = 0;

    for (int i = 0; line[i] != '\0'; ++i) {
        if (line[i] == delimiter) {
            int fieldLength = i - fieldStart;
            tokens[tokenIndex] = new char[fieldLength + 1];
            strncpy(tokens[tokenIndex], line + fieldStart, fieldLength);
            tokens[tokenIndex][fieldLength] = '\0';
            ++tokenIndex;

            fieldStart = i + 1;
        }
    }

    int fieldLength = strlen(line) - fieldStart;
    tokens[tokenIndex] = new char[fieldLength + 1];
    strncpy(tokens[tokenIndex], line + fieldStart, fieldLength);
    tokens[tokenIndex][fieldLength] = '\0';

    User* user = new User(tokens[0], tokens[1], stof(tokens[2]), stof(tokens[3]));

    return user;
}

SuperUser* createSuperUserFromLine(char* line) {
    const char delimiter = '~';
    char* tokens[4];  // Assuming there are 2 fields in the line

    int tokenIndex = 0;
    int fieldStart = 0;

    for (int i = 0; line[i] != '\0'; ++i) {
        if (line[i] == delimiter) {
            int fieldLength = i - fieldStart;
            tokens[tokenIndex] = new char[fieldLength + 1];
            strncpy(tokens[tokenIndex], line + fieldStart, fieldLength);
            tokens[tokenIndex][fieldLength] = '\0';
            ++tokenIndex;

            fieldStart = i + 1;
        }
    }

    int fieldLength = strlen(line) - fieldStart;
    tokens[tokenIndex] = new char[fieldLength + 1];
    strncpy(tokens[tokenIndex], line + fieldStart, fieldLength);
    tokens[tokenIndex][fieldLength] = '\0';

    SuperUser* user = new SuperUser(tokens[0], tokens[1], stof(tokens[2]), stof(tokens[3]));

    return user;
}


Library::Library() {
    char* booksFile = "books.txt";
    char* usersFile = "users.txt";
    char* superUsersFile = "superusers.txt";

    ifstream file1(booksFile);
    if (!file1.is_open()) {
        cerr << "Error opening file: " << booksFile << endl;
        return;
    }

    char line1[200];
    int number = 0;
    while (file1.getline(line1, 200)) {
        Book* book = createBookFromLine(line1);

        Book** newBooks = new Book*[number + 1];
        for (int i = 0; i < number; ++i) {
            newBooks[i] = books[i];
        }
        newBooks[number] = book;
        number++;
        books = newBooks;
    }
    NumberOfBooks = number;
    file1.close();

    ifstream file2(usersFile);
    if (!file2.is_open()) {
        cerr << "Error opening file: " << usersFile << endl;
        return;
    }

    number = 0;
    char line2[200];
    while (file2.getline(line2, 200)) {
        User* user = createUserFromLine(line2);
        user->loadData(books);

        AbstractUser** newUsers = new AbstractUser *[number + 1];
        for (int i = 0; i < number; ++i) {
            newUsers[i] = users[i];
        }
        newUsers[number] = user;
        number++;
        users = newUsers;
    }
    file2.close();

    ifstream file3(superUsersFile);
    if (!file3.is_open()) {
        cerr << "Error opening file: " << superUsersFile << endl;
        return;
    }

    char line3[200];
    while (file3.getline(line3, 200)) {
        SuperUser* user = createSuperUserFromLine(line3);
        user->loadData(books);

        AbstractUser** newUsers = new AbstractUser *[number + 1];
        for (int i = 0; i < number; ++i) {
            newUsers[i] = users[i];
        }
        newUsers[number] = user;
        number++;
        users = newUsers;
    }
    NumberOfUsers = number;
    file3.close();
}

void Library::saveBooks() {
    char* filename = "books.txt";
    ofstream file(filename);
    for (int i = 0; i < NumberOfBooks; i++) {
        file << books[i]->getID() << '~' << books[i]->getTitle() << '~' << books[i]->getAuthor() << '~' << books[i]->getYear() << '~' << books[i]->getPublisher() << '~' << books[i]->getLanguage() << '~' << books[i]->getPrice() << '~' << books[i]->getNumberOfBuying() << endl;
    }
}

void Library::saveUsers() {
    char* filename = "users.txt";
    ofstream file(filename);
    for (int i = 0; i < NumberOfUsers; i++) {
        if (!users[i]->isSuperUser()) {
            file << users[i]->getLogin() << '~' << users[i]->getPassword() << '~' << users[i]->checkBalance() << '~' << users[i]->checkSpentCosts() << endl;
            users[i]->saveData();
        }
    }
}

void Library::saveSuperUsers() {
    char* filename = "superusers.txt";
    ofstream file(filename);
    for (int i = 0; i < NumberOfUsers; i++) {
        if (users[i]->isSuperUser()) {
            file << users[i]->getLogin() << '~' << users[i]->getPassword() << '~' << users[i]->checkBalance() << '~' << users[i]->checkSpentCosts() << endl;
            users[i]->saveData();
        }
    }
}

void Library::GetAllBooks() {
    cout << "\nBooks:" << endl;
    for (int i = 0; i < NumberOfBooks; i++) {
        cout << "\t" << i + 1 << ") ";
        books[i]->infoToConsole();
    }
}

Book* Library::RetrieveBook(int id) {
    for (int i = 0; i < NumberOfBooks; i++) {
        if (id == books[i]->getID()) {
            return books[i];
        }
    }
    return nullptr;
}

void Library::GetBooksByAuthor(char *author) {
    bool flag = false;
    for (int i = 0; i < NumberOfBooks; i++) {
        if (!strcmp(author, books[i]->getAuthor())) {
            flag = true;
            books[i]->infoToConsole();
        }
    }
    if (!flag) {
        cout << "There no books with that author." << endl;
    }
}

void Library::GetBooksByPublisher(char *publisher) {
    bool flag = false;
    for (int i = 0; i < NumberOfBooks; i++) {
        if (!strcmp(publisher, books[i]->getPublisher())) {
            flag = true;
            books[i]->infoToConsole();
        }
    }
    if (!flag) {
        cout << "There no books with that publisher." << endl;
    }
}

void Library::GetBooksByLanguage(char *language) {
    bool flag = false;
    for (int i = 0; i < NumberOfBooks; i++) {
        if (!strcmp(language, books[i]->getLanguage())) {
            flag = true;
            books[i]->infoToConsole();
        }
    }
    if (!flag) {
        cout << "There no books with that language." << endl;
    }
}

void Library::GetBooksByYear(int year) {
    bool flag = false;
    for (int i = 0; i < NumberOfBooks; i++) {
        if (year == books[i]->getYear()) {
            flag = true;
            books[i]->infoToConsole();
        }
    }
    if (!flag) {
        cout << "There no books with that post year." << endl;
    }
}

bool Library::AddBook(Book *book) {
    if (!CurrentUser->isSuperUser()) {
        return false;
    }
    for (int i = 0; i < NumberOfBooks; i++) {
        if (!strcmp(books[i]->getTitle(), book->getTitle()) &&
        !strcmp(books[i]->getAuthor(), book->getAuthor()) &&
        books[i]->getYear() == book->getYear() &&
        !strcmp(books[i]->getLanguage(), book->getLanguage()) &&
        !strcmp(books[i]->getPublisher(), book->getPublisher())) {
            return false;
        }
    }
    Book** newBooks = new Book*[NumberOfBooks + 1];
    for (int i = 0; i < NumberOfBooks; ++i) {
        newBooks[i] = books[i];
    }
    newBooks[NumberOfBooks] = book;
    NumberOfBooks++;
    books = newBooks;
    return true;
}

bool Library::UpdateBook(int id) {
    Book* book = RetrieveBook(id);
    if (!book) {
        return false;
    }
    char title[50];
    char author[50];
    char publisher[50];
    char language[50];
    int year;
    float price;

    cout << "Enter new title: ";
    cin >> title;
    cout << "Enter new author: ";
    cin >> author;
    cout << "Enter new year of publishing: ";
    cin >> year;
    cout << "Enter new publisher: ";
    cin >> publisher;
    cout << "Enter new language: ";
    cin >> language;
    cout << "Enter new price: ";
    cin >> price;

    if (strlen(title)) {
        book->setTitle(title);
    }
    if (strlen(author)) {
        book->setAuthor(author);
    }
    if (year >= 1000 and year <= 2023) {
        book->setYear(year);
    }
    if (strlen(publisher)) {
        book->setPublisher(publisher);
    }
    if (strlen(language)) {
        book->setLanguage(language);
    }
    if (price > 0) {
        book->setPrice(price);
    }
    return true;
}

bool Library::RemoveBook(int id) {
    if (!CurrentUser->isSuperUser()) {
        return false;
    }
    for (int i = 0; i < NumberOfBooks; ++i) {
        if (books[i]->getID() == id) {
            delete books[i];
            for (int j = i; j < NumberOfBooks - 1; ++j) {
                books[j] = books[j + 1];
            }
            --NumberOfBooks;
            return true;
        }
    }
    return false;
};

bool Library::login(char *login, char *password) {
    for (int i = 0; i < NumberOfUsers; i++) {
        if (users[i]->checkCredential(login, password)) {
            CurrentUser = users[i];
            return true;
        }
    }
    return false;
}

bool Library::logout() {
    CurrentUser = nullptr;
    return true;
}

bool Library::registration(char *login, char *password) {
    for (int i = 0; i < NumberOfUsers; i++) {
        if (!strcmp(users[i]->getLogin(), login)) {
            return false;
        }
    }
    User* user = new User(login, password);
    AbstractUser** newUsers = new AbstractUser *[NumberOfUsers + 1];
    for (int i = 0; i < NumberOfUsers; ++i) {
        newUsers[i] = users[i];
    }
    newUsers[NumberOfUsers] = user;
    NumberOfUsers++;
    users = newUsers;
    return true;
}

bool Library::createSuperUser(char *login, char *password) {
    for (int i = 0; i < NumberOfUsers; i++) {
        if (!strcmp(users[i]->getLogin(), login)) {
            return false;
        }
    }
    SuperUser* user = new SuperUser(login, password);
    AbstractUser** newUsers = new AbstractUser *[NumberOfUsers + 1];
    for (int i = 0; i < NumberOfUsers; ++i) {
        newUsers[i] = users[i];
    }
    newUsers[NumberOfUsers] = user;
    NumberOfUsers++;
    users = newUsers;
    return true;
}