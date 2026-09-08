#include <iostream>
using namespace std;

// Abstraction
class Database {
public:
    virtual void save() = 0;
};

// Low-level implementation
class MySQL : public Database {
public:
    void save() override {
        cout << "Saving to MySQL" << endl;
    }
};

// High-level class
class User {
private:
    Database& database;

public:
    User(Database& db) : database(db) {}

    void saveUser() {
        database.save();
    }
};

int main() {

    MySQL mysql;

    User user(mysql);

    user.saveUser();

    return 0;
}
