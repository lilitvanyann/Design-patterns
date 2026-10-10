#include <iostream>
#include <string>
using namespace std;

class Transport {
public:
    virtual void deliver() = 0;
    virtual ~Transport() = default;
};

class Truck : public Transport {
public:
    void deliver() override {
        cout << "Delivery by truck\n";
    }
};

class Ship : public Transport {
public:
    void deliver() override {
        cout << "Delivery by ship\n";
    }
};

int main() {
    Transport* transport = nullptr;

    string type;
    cout << "Enter transport type (truck/ship): ";
    cin >> type;

    if (type == "truck") {
        transport = new Truck();
    }
    else if (type == "ship") {
        transport = new Ship();
    }

    if (transport != nullptr) {
        transport->deliver();
        delete transport;
    }
    else {
        cout << "Invalid transport type\n";
    }

    return 0;
}
