# ISP — Interface Segregation Principle

**ISP** նշանակում է՝

> **Class-ին չպետք է ստիպել implement անել այն մեթոդները, որոնք իրեն պետք չեն։**

### ❌ Վատ

```cpp
class Worker {
public:
    virtual void work() = 0;
    virtual void code() = 0;
    virtual void manage() = 0;
};
```

`Developer`-ը ստիպված է գրել `manage()`, չնայած իրեն պետք չէ։

### ✅ Լավ

Մեծ interface-ը բաժանում ենք փոքրերի.

```cpp
class Workable {
public:
    virtual void work() = 0;
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

`Developer`-ը վերցնում է միայն անհրաժեշտները։

### Հիշելու համար

> **Don't force classes to depend on methods they don't use.**

**ISP-ի հարցը՝**

> «Այս class-ին պե՞տք են interface-ի բոլոր մեթոդները»։
