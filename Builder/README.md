# Builder Pattern

## What is Builder Pattern?

Builder Pattern-ը Creational Design Pattern է, որը թույլ է տալիս **բարդ օբյեկտը կառուցել քայլ առ քայլ**։

## Why use it?

Երբ օբյեկտն ունի շատ parameters կամ optional properties, սովորական constructor-ը կարող է դառնալ անհասկանալի։

Builder-ի դեպքում՝

```cpp
PizzaBuilder()
    .setSize("Large")
    .setCrust("Thin")
    .addCheese()
    .addMushrooms()
    .build();
```

Կոդը ավելի readable է և պարզ երևում է՝ ինչ ենք ավելացնում կամ փոխում։

## Main Parts

* **Product** → `Pizza`
* **Builder** → `PizzaBuilder`
* **Builder methods** → `setSize()`, `setCrust()`, `addCheese()`, etc.
* **build()** → վերադարձնում է պատրաստ `Pizza` object-ը

## Key Idea

```text
Builder
   ↓
configure step by step
   ↓
build()
   ↓
final Product
```

`return *this`-ը թույլ է տալիս նույն Builder-ի վրա շարունակաբար կանչել մեթոդները (method chaining)։
