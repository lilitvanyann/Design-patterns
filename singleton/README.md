# Singleton Pattern

Singleton ensures that a class has **only one instance** and provides a global access point to it.

### Main ideas

* `private` constructor → prevents direct object creation.
* `static` instance → stores the single object.
* `getInstance()` → returns the same object every time.

### Meyers' Singleton

Uses a local `static` instance inside `getInstance()`.
Since C++11, its initialization is **thread-safe**.
