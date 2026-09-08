#include <iostream>
using namespace std;

// Low-level class
class MySQL {
public:
    void save() {
        cout << "Saving to MySQL" << endl;
    }
};

// High-level class
class User {
private:
    MySQL database;   

public:
    void saveUser() {
        database.save();
    }
};

int main() {
    User user;

    user.saveUser();

    return 0;
}
