# OCP — Open/Closed Principle

## Ինչ ենք ուզում OCP-ով

Ուզում ենք, որ `Payment`-ի հիմնական կոդը **չփոխենք**, այլ նոր payment type-եր **ավելացնենք extension-ով**։

Օրինակ՝

```text
             Payment
                ↑
       ┌────────┼────────┐
       ↓        ↓        ↓
     Card      Cash    PayPal
```

Հիմա եթե նոր `ApplePay` է պետք՝

```text
             Payment
                ↑
       ┌────────┼────────┬─────────┐
       ↓        ↓        ↓         ↓
     Card      Cash    PayPal   ApplePay
```

Մենք **չփոխեցինք արդեն եղած `Card`, `Cash`, `PayPal` կոդը**։

Ուղղակի ավելացրեցինք նոր implementation՝ `ApplePay`։

### Գլխավոր գաղափարը

> **Open for extension, closed for modification.**

Այսինքն՝

* **Open for extension** → կարող ենք ավելացնել նոր functionality։
* **Closed for modification** → արդեն գրված և աշխատող կոդը չենք փոփոխում նոր functionality ավելացնելու համար։
