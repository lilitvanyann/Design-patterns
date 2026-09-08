#include <iostream>
using namespace std;

class Work {
    public:
    virtual void work() = 0;
};
class Eat {
    public:
    virtual void eat() = 0;
};
class Sleep {
    public:
    virtual void sleep() = 0;
};
class Code {
    public:
    virtual void code() = 0;
};
class Manage {
    public:
    virtual void manage() = 0;
};


class Developer : public Work,public Eat,public Sleep,public Code {
public:
    void work() override {
        cout << "Developer is working" << endl;
    }

    void eat() override {
        cout << "Developer is eating" << endl;
    }

    void sleep() override {
        cout << "Developer is sleeping" << endl;
    }

    void code() override {
        cout << "Developer is coding" << endl;
    }

};

class Manager : public Work,public Eat,public Sleep,public Manage {
public:
    void work() override {
        cout << "Manager is working" << endl;
    }

    void eat() override {
        cout << "Manager is eating" << endl;
    }

    void sleep() override {
        cout << "Manager is sleeping" << endl;
    }


    void manage() override {
        cout << "Manager is managing" << endl;
    }
};
