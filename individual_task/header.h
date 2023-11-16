
#ifndef INDIVIDUAL_TASK_HEADER_H
#define INDIVIDUAL_TASK_HEADER_H

class Book {
private:
    int id;
    char* title;
    char* author;
    int postYear;
    char* publisher;
    char* language;
    float price;
    int numberOfBuying;

public:
    static int numberOfBooks;

    Book(char* title, char* author, int year, char* publisher, char* language, float price, int id = 0, int numberOfBuying = 0);
    void infoToConsole();
    int getID() const;
    char* getAuthor() const;
    char* getTitle() const;
    int getYear() const;
    char* getPublisher() const;
    char* getLanguage() const;
    float getPrice() const;
    int getNumberOfBuying() const;

    void setTitle(char* _title);
    void setAuthor(char* _author);
    void setYear(int _year);
    void setPublisher(char* _publisher);
    void setLanguage(char* _language);
    void setPrice(float _price);
};

class AbstractUser {
protected:
    char* login;
    char* password;
    int numberOfBooks;
    float funds;
    float spentCosts;
    bool isVIPStatus;
    Book** books;

public:
    static int numberOfUsers;

    AbstractUser(char* login, char* password, float funds = 0, float spentConsts = 0);
    char* getLogin() const;
    char* getPassword() const;
    bool checkCredential(char* _login, char* _password);
    void setNewLogin(char* newLogin);
    void setNewPassword(char* newPassword);
    int BooksNumber() const;
    bool transaction(Book* book);
    void addBook(Book* book);
    void getBooksList() const;
    void deposit(float money);
    float checkBalance() const;
    float checkSpentCosts() const;
    void getStatistics() const;
    void saveData() const;
    void loadData(Book** allBooks);
    virtual bool isSuperUser() = 0;

    ~AbstractUser();
};

class User: public AbstractUser{
public:
    User(char* login, char* password, float funds = 0, float spentConsts = 0);
    bool isSuperUser() override;
};

class SuperUser: public AbstractUser {
public:
    SuperUser(char* login, char* password, float funds = 0, float spentConsts = 0);
    bool isSuperUser() override;
};

Book* createBookFromLine(char* line);
User* createUserFromLine(char* line);
SuperUser* createSuperUserFromLine(char* line);

class Library {
private:
    Book** books;
    AbstractUser** users;

public:
    static int NumberOfBooks;
    static int NumberOfUsers;
    static AbstractUser* CurrentUser;
    Library();
    void saveBooks();
    void saveUsers();
    void saveSuperUsers();
    void GetAllBooks();
    Book* RetrieveBook(int id);
    void GetBooksByAuthor(char* author);
    void GetBooksByYear(int year);
    void GetBooksByPublisher(char* publisher);
    void GetBooksByLanguage(char* language);
    bool AddBook(Book* book);
    bool UpdateBook(int id);
    bool RemoveBook(int id);

    bool login(char* login, char* password);
    bool logout();
    bool registration(char* login, char* password);
    bool createSuperUser(char* login, char* password);

    ~Library();
};

int AbstractUser::numberOfUsers = 0;
int Book::numberOfBooks = 0;
int Library::NumberOfBooks = 0;
int Library::NumberOfUsers = 0;
AbstractUser* Library::CurrentUser = nullptr;
#endif //INDIVIDUAL_TASK_HEADER_H
