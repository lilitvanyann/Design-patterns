#include <iostream>
using namespace std;

class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;
    virtual void code() = 0;
    virtual void manage() = 0;
};

class Developer : public Worker {
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

    void manage() override {
        cout << "Developer doesn't manage" << endl;
    }
};

class Manager : public Worker {
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

    void code() override {
        cout << "Manager doesn't code" << endl;
    }

    void manage() override {
        cout << "Manager is managing" << endl;
    }
};
