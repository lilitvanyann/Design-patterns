#include <iostream>
using namespace std;

class Animal {
public:
    virtual void eat() {
        cout << "Animal is eating" << endl;
    }

    virtual void swim() {
        cout << "Animal is swimming" << endl;
    }
};

class Dog : public Animal {
public:
    void eat() override {
        cout << "Dog is eating" << endl;
    }

    void swim() override {
        cout << "Dog is swimming" << endl;
    }
};

class Fish : public Animal {
public:
    void eat() override {
        cout << "Fish is eating" << endl;
    }

    void swim() override {
        cout << "Fish is swimming" << endl;
    }
};

class Cat : public Animal {
public:
    void eat() override {
        cout << "Cat is eating" << endl;
    }

    void swim() override {
        cout << "Cat cannot swim!" << endl;
    }
};

void makeAnimalSwim(Animal& animal) {
    animal.swim();
}

int main() {

    Dog dog;
    Fish fish;
    Cat cat;

    makeAnimalSwim(dog);
    makeAnimalSwim(fish);
    makeAnimalSwim(cat);

    return 0;
}
