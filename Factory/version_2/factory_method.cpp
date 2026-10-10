#include <iostream>
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

class TransportFactory {
public:
    virtual Transport* createTransport() = 0;
    virtual ~TransportFactory() = default;
};

class TruckFactory : public TransportFactory {
public:
    Transport* createTransport() override {
        return new Truck();
    }
};

class ShipFactory : public TransportFactory {
public:
    Transport* createTransport() override {
        return new Ship();
    }
};

int main() {
    TransportFactory* factory = new TruckFactory();

    Transport* transport = factory->createTransport();
    transport->deliver();

    delete transport;
    delete factory;

    return 0;
}
