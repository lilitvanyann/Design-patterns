
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

class TransportFactory  {
    public:
        static Transport* createTransport(string type){
            if(type=="Truck")
                return new Truck();
                
            else if (type=="Ship")
                return new Ship();
                
            return nullptr;
        }
        
};

int main() {
    Transport* transport = TransportFactory::createTransport("Truck") ;
    if(transport!=nullptr) 
    transport->deliver();
    
    delete transport;

    return 0;
}
