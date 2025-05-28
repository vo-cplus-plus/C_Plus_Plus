#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Базовый обработчик
class OrderHandler {
protected:
    unique_ptr<OrderHandler> next;

public:
    virtual ~OrderHandler() = default;

    void setNext(unique_ptr<OrderHandler> handler) {
        next = move(handler);
    }

    virtual void handle(const string& request) = 0;
};

// Конкретные обработчики
class ValidationHandler : public OrderHandler {
public:
    void handle(const string& request) override {
        if (request.find("valid") != string::npos) {
            cout << "ValidationHandler: Заказ валиден." << endl;
            if (next) next->handle(request);
        }
        else {
            cout << "ValidationHandler: Заказ невалиден. Обработка остановлена." << endl;
        }
    }
};

class PaymentHandler : public OrderHandler {
public:
    void handle(const string& request) override {
        if (request.find("paid") != string::npos) {
            cout << "PaymentHandler: Оплата подтверждена." << endl;
            if (next) next->handle(request);
        } 
        else {
            cout << "PaymentHandler: Оплата не прошла. Обработка остановлена." << endl;
        }
    }
};

class ShippingHandler : public OrderHandler {
public:
    void handle(const string& request) override {
        if (request.find("shipped") != string::npos) {
            cout << "ShippingHandler: Заказ отправлен." << endl;
            if (next) next->handle(request);
        }
        else {
            cout << "ShippingHandler: Ошибка доставки." << endl;
        }
    }
};

class Client{

};

// Клиентский код
int main() {
    // Создаем цепочку обработчиков
    auto validation = make_unique<ValidationHandler>();
    auto payment = make_unique<PaymentHandler>();
    auto shipping = make_unique<ShippingHandler>();

    // Настраиваем порядок: Validation -> Payment -> Shipping
    payment->setNext(move(shipping));
    validation->setNext(move(payment));
    

    // Тестовые запросы
    cout << "--- Запрос 1: valid | paid | shipped ---" << endl;
    validation->handle("valid paid shipped");

    cout << "\n--- Запрос 2: valid | not_paid ---" << endl;
    validation->handle("valid not_Paid");

}