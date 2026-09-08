#include <iostream>
using namespace std;

class Notification {
public:
    virtual void send() = 0;
};

class Email : public Notification {
public:
    void send() override {
        cout << "Sending Email..." << endl;
    }
};

class SMS : public Notification {
public:
    void send() override {
        cout << "Sending SMS..." << endl;
    }
};

class Telegram : public Notification {
public:
    void send() override {
        cout << "Sending Telegram..." << endl;
    }
};

class Viber : public Notification {
public:
    void send() override {
        cout << "Sending Viber..." << endl;
    }
};

class WhatsApp : public Notification {
public:
    void send() override {
        cout << "Sending WhatsApp..." << endl;
    }
};

class Messenger : public Notification {
public:
    void send() override {
        cout << "Sending Messenger..." << endl;
    }
};

int main() {

    Email email;
    SMS sms;
    Telegram telegram;
    Viber viber;
    WhatsApp whatsapp;
    Messenger messenger;

    email.send();
    sms.send();
    telegram.send();
    viber.send();
    whatsapp.send();
    messenger.send();

    return 0;
}
