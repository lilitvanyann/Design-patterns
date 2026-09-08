# ISP — Interface Segregation Principle

## Ի՞նչ է ISP-ն

**ISP (Interface Segregation Principle)** նշանակում է՝

> **Class-ին չպետք է ստիպել կախված լինել այն մեթոդներից, որոնք իրեն պետք չեն։**

Ավելի պարզ՝

> **Մեկ մեծ interface-ի փոխարեն ավելի լավ է ունենալ մի քանի փոքր և կոնկրետ interface։**

---

## Վատ օրինակ

Ունենք մեծ `Worker` interface.

```cpp
class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual void code() = 0;
    virtual void manage() = 0;
};
```

Հետո ունենք `Developer`.

```cpp
class Developer : public Worker {
public:
    void work() override {
        cout << "Developer is working";
    }

    void eat() override {
        cout << "Developer is eating";
    }

    void code() override {
        cout << "Developer is coding";
    }

    void manage() override {
        cout << "Developer doesn't manage";
    }
};
```

Խնդիրն այն է, որ `Developer`-ին ստիպեցինք implement անել `manage()`-ը, չնայած Developer-ը Manager չէ։

Նույնը կարող է լինել `Manager`-ի դեպքում՝ նրան ստիպեն implement անել `code()`։

**Սա ISP-ի խախտում է։**

---

## Ինչպե՞ս ուղղել

Մեծ interface-ը բաժանում ենք փոքր interface-ների։

```cpp
class Workable {
public:
    virtual void work() = 0;
};

class Eatable {
public:
    virtual void eat() = 0;
};

class Coder {
public:
    virtual void code() = 0;
};

class Manager {
public:
    virtual void manage() = 0;
};
```

Այժմ `Developer`-ը վերցնում է միայն իրեն անհրաժեշտ interface-ները.

```cpp
class Developer : public Workable, public Eatable, public Coder {
};
```

Իսկ `Manager`-ը՝

```cpp
class Manager : public Workable, public Eatable, public Manager {
};
```

Այսպես յուրաքանչյուր class կախված է միայն այն մեթոդներից, որոնք իրեն անհրաժեշտ են։

---

## Հիմնական գաղափարը

```text
❌ Մեծ interface

          Worker
       / / / / / \
     work eat code manage
            ↓
    Բոլորը պարտադիր են


✅ Փոքր interface-ներ

Workable → work()

Eatable → eat()

Coder → code()

Manager → manage()
```

Class-ը վերցնում է միայն անհրաժեշտ interface-ները։

---

## Ինչի՞ց հասկանալ ISP-ի խախտումը

Եթե տեսնում ես՝

```cpp
void something() {
    // I don't need this
}
```

կամ՝

```cpp
void code() override {
    cout << "I don't code";
}
```

կամ՝

```cpp
void fly() override {
    // I can't fly
}
```

դա կարող է լինել ISP-ի խախտման նշան։

Այսինքն՝ class-ը ստիպված է implement անել մի մեթոդ, որն իրեն պետք չէ։

---

## ISP-ի հիմնական հարցը

Երբ ստեղծում ենք interface, հարցնում ենք.

> **«Այս class-ին իրոք պե՞տք են այս interface-ի բոլոր մեթոդները»։**

Եթե՝ **այո → ISP OK ✅**

Եթե՝ **ոչ → interface-ը պետք է բաժանել փոքր մասերի ❌**

---

## ISP-ի կարճ տարբերակը

> **Don't force classes to depend on methods they don't use.**

Կամ՝

> **Split large interfaces into smaller, specific interfaces.**

---

## SOLID-ի մեջ ISP-ն

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
