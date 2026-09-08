#include <iostream>
using namespace std;

class Notification {
public:
    void send(string type) {

        if (type == "email") {
            cout << "Sending Email..." << endl;
        }
        else if (type == "sms") {
            cout << "Sending SMS..." << endl;
        }
        else if (type == "telegram") {
            cout << "Sending Telegram..." << endl;
        }
    }
};

int main() {

    Notification notification;

    notification.send("email");
    notification.send("sms");
    notification.send("telegram");

    return 0;
}
