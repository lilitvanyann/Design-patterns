#include <iostream>
#include <string>
using namespace std;

class Pizza {
public:
    string size;
    string crust;
    bool cheese = false;
    bool mushrooms = false;
    bool pepperoni = false;
}; 

class PizzaBuilder {
private:
    Pizza pizza;
    
public:
    PizzaBuilder& setSize(string size1){
        pizza.size=size1;
        return *this;
    }
    PizzaBuilder& setCrust(string crust1){
        pizza.crust=crust1;
        return *this;
    }
    PizzaBuilder& addCheese(){
        pizza.cheese=true;
        return *this;
    }
    PizzaBuilder& addMushrooms( ){
        pizza.mushrooms=true;
        return *this;
    }
    PizzaBuilder& addPepperoni( ){
        pizza.pepperoni=true;
        return *this;
    }
    Pizza build() {
        return pizza;
    }

};

int main(){
    Pizza pizza=PizzaBuilder()
    .setSize("Large")
    .setCrust("Thin")
    .addCheese()
    .addMushrooms()
    .build();
    
    cout << "Size: " << pizza.size << endl;
    cout << "Crust: " << pizza.crust << endl;
    cout << "Cheese: " << pizza.cheese << endl;
    cout << "Mushrooms: " << pizza.mushrooms << endl;
    cout << "Pepperoni: " << pizza.pepperoni << endl;
    
    Pizza pizza2 = PizzaBuilder()
    .setSize("Medium")
    .setCrust("Thick")
    .addPepperoni()
    .build();
    
    cout << "Size: " << pizza2.size << endl;
    cout << "Crust: " << pizza2.crust << endl;
    cout << "Pepperoni: " << pizza2.pepperoni << endl;
    return 0;
}
