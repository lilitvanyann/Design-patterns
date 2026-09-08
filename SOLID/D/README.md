# DIP — Dependency Inversion Principle

## Ի՞նչ է DIP-ը

> **High-level class-ը չպետք է կախված լինի կոնկրետ low-level class-ից։ Երկուսն էլ պետք է կախված լինեն abstraction-ից։**

Պարզ ասած՝

> **Depend on abstraction, not concrete implementation.**

### ❌ Վատ

```cpp
class MySQL {
public:
    void save() {
        cout << "Saving to MySQL";
    }
};

class User {
    MySQL database;
};
```

Այստեղ `User`-ը ուղղակիորեն կախված է `MySQL`-ից։

### ✅ Լավ

Ստեղծում ենք interface.

```cpp
class Database {
public:
    virtual void save() = 0;
};
```

Հետո.

```cpp
class MySQL : public Database {
public:
    void save() override {
        cout << "Saving to MySQL";
    }
};
```

`User`-ը կախված է `Database`-ից.

```cpp
class User {
    Database& database;

public:
    User(Database& db) : database(db) {}

    void saveUser() {
        database.save();
    }
};
```

Այսպես `User`-ը կարող է աշխատել ցանկացած `Database` implementation-ի հետ։

### Հիշելու համար

```text
❌ User → MySQL

✅ User → Database ← MySQL
                  ← PostgreSQL
```

**DIP = Depend on abstractions, not concrete classes.**
