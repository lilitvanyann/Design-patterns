/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void eat() {
        cout << "Animal is eating" << endl;
    }
};

class SwimingAnimal:public Animal {
public:
    virtual void swim() {
        cout << "Animal is swimming" << endl;
    }
};

class Dog : public SwimingAnimal {
public:
    void eat() override {
        cout << "Dog is eating" << endl;
    }

    void swim() {
        cout << "Dog is swimming" << endl;
    }
};

class Fish : public SwimingAnimal {
public:
    void eat() override {
        cout << "Fish is eating" << endl;
    }

    void swim()  {
        cout << "Fish is swimming" << endl;
    }
};

class Cat : public Animal {
public:
    void eat() override {
        cout << "Cat is eating" << endl;
    }

    void swim()  {
        cout << "Cat cannot swim!" << endl;
    }
};

void makeAnimalSwim(SwimingAnimal& animal) {
    animal.swim();
}

int main() {

    Dog dog;
    Fish fish;
    Cat cat;

    makeAnimalSwim(dog);
    makeAnimalSwim(fish);
    dog.eat();
    return 0;
}
