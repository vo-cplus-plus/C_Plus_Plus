#include <iostream>
#include <memory>
using namespace std;

// Интерфейс стратегии оплаты
class PaymentStrategy {
public:
    virtual ~PaymentStrategy() = default;
    virtual void pay(double amount) const = 0;
};

// Конкретные стратегии
class CardPayment : public PaymentStrategy {
public:
    void pay(double amount) const override {
        cout << "Оплачено " << amount << " р. банковской картой" << endl;
    }
};

class CryptoPayment : public PaymentStrategy {
public:
    void pay(double amount) const override {
        cout << "Оплачено " << amount << " р. через криптокошелек" << endl;
    }
};

class CashPayment : public PaymentStrategy {
public:
    void pay(double amount) const override {
        cout << "Оплачено " << amount << " р. наличными" << endl;
    }
};

// Контекст (корзина покупок)
class ShoppingCart {
private:
    unique_ptr<PaymentStrategy> strategy;
public:
    void setPaymentStrategy(unique_ptr<PaymentStrategy> strategy) {
        this->strategy = move(strategy);
    }

    void checkout(double amount) const {
        if (strategy) {
            strategy->pay(amount);
        } else {
            cerr << "Способ оплаты не выбран!" << endl;
        }
    }
};

// Клиентский код
int main() {
    ShoppingCart cart;

    // Оплата картой
    cart.setPaymentStrategy(make_unique<CardPayment>());
    cart.checkout(100.50); 

    // Смена стратегии крипту
    cart.setPaymentStrategy(make_unique<CryptoPayment>());
    cart.checkout(75.25); 

    // Оплата наличными
    cart.setPaymentStrategy(make_unique<CashPayment>());
    cart.checkout(30.0); 
}