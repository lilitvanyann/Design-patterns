# LSP — Liskov Substitution Principle

## Ի՞նչ է LSP-ն

**LSP (Liskov Substitution Principle)** նշանակում է՝

> **Child class-ի object-ը պետք է կարողանա փոխարինել Parent class-ի object-ին՝ առանց ծրագրի ճիշտ աշխատանքի խախտման։**

Այսինքն՝ եթե `Child`-ը ժառանգում է `Parent`-ից, ապա `Child`-ը պետք է պահպանի այն **behavior-ը**, որը Parent-ից սպասվում է։

---

## Պարզ օրինակ

Ունենք `Bird` class.

```cpp
class Bird {
public:
    virtual void fly() {
        cout << "Flying..." << endl;
    }
};
```

Այստեղ `Bird`-ը ասում է, որ ունի `fly()` behavior։

Հետո ստեղծում ենք `Eagle`.

```cpp
class Eagle : public Bird {
public:
    void fly() override {
        cout << "Eagle is flying..." << endl;
    }
};
```

Սա ճիշտ է, որովհետև `Eagle`-ը կարող է թռչել։

Բայց եթե ստեղծենք `Penguin`.

```cpp
class Penguin : public Bird {
public:
    void fly() override {
        cout << "Penguin cannot fly!" << endl;
    }
};
```

Այստեղ խնդիր կա։

`Bird`-ը ենթադրում է, որ `fly()` հնարավոր է, բայց `Penguin`-ը չի կարող թռչել։

Այսպիսով `Penguin`-ը չի կարող լիարժեք փոխարինել `Bird`-ին։

**Սա LSP violation է։**

---

## Ինչպե՞ս ուղղել

Պետք է Parent class-ում չդնենք behavior, որը բոլոր Child-ներին չի համապատասխանում։

Օրինակ՝

```cpp
class Bird {
};

class FlyingBird : public Bird {
public:
    virtual void fly() = 0;
};

class Eagle : public FlyingBird {
public:
    void fly() override {
        cout << "Eagle is flying..." << endl;
    }
};

class Penguin : public Bird {
};
```

Այժմ structure-ը կլինի՝

```text
        Bird
       /    \
      /      \
FlyingBird  Penguin
     |
   Eagle
```

Այստեղ միայն այն թռչունները, որոնք իրականում կարող են թռչել, ժառանգում են `FlyingBird`-ից։

---

## Կարևոր գաղափար

LSP-ն **չի նշանակում**, որ Child-ը չպետք է ունենա նոր ֆունկցիաներ։

Օրինակ՝

```cpp
class Dog : public Animal {
public:
    void eat() override {
        cout << "Dog is eating";
    }

    void bark() {
        cout << "Woof!";
    }
};
```

`bark()`-ը նոր ֆունկցիա է և LSP-ի խախտում չէ։

Խնդիրը առաջանում է այն ժամանակ, երբ Child-ի behavior-ը չի համապատասխանում Parent-ի սպասված behavior-ին։

---

## LSP-ի հիմնական հարցը

Երբ ունենք՝

```cpp
Parent* obj = new Child();
```

պետք է հարցնենք.

> **«Եթե Child-ին դնեմ Parent-ի տեղը, ծրագիրը կաշխատի՞ այնպես, ինչպես Parent-ի դեպքում սպասվում էր»։**

Եթե՝ **այո → LSP ✅**

Եթե՝ **ոչ → LSP violation ❌**

---

## LSP-ի կարճ տարբերակը

```text
Parent
   ↑
Child
```

Child-ը պետք է կարողանա փոխարինել Parent-ին՝

```text
Parent → Child
```

առանց ծրագրի behavior-ը կոտրելու։

---

## SOLID-ի մեջ LSP-ն

**S — Single Responsibility**

> One class should have one responsibility.

**O — Open/Closed**

> Open for extension, closed for modification.

**L — Liskov Substitution**

> Child should be substitutable for Parent.

**I — Interface Segregation**

> Don't force classes to depend on methods they don't need.

**D — Dependency Inversion**

> Depend on abstractions, not concrete implementations.
