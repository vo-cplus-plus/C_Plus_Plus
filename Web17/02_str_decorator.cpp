#include <iostream>
#include <string>
#include <memory>
using namespace std;


// Базовый интерфейс 
class Notifier {
public:
    virtual ~Notifier() = default;
    virtual void send(string message) const = 0;
    virtual string getDescription() const = 0;
};

// Конкретный компонент: уведомление о событии
class EventNotifier : public Notifier {
    string event;
public:
    EventNotifier(const string &e):event(e){}
    string getDescription() const override{
        return event;
    }
    void send(string message) const override {
        cout << event + " " + message << endl;
    }
};

// Абстрактный декоратор
class BaseDecorator : public Notifier {
protected:
    shared_ptr<Notifier> wrappee; // Ссылка на оборачиваемый объект
public:
    BaseDecorator(const shared_ptr<Notifier>& notifier) : wrappee(notifier) {}
    virtual ~BaseDecorator() = default;
};

// Конкретный декоратор: Email
class EmailDecorator : public BaseDecorator {
public:
    EmailDecorator(const shared_ptr<Notifier>& notifier) : BaseDecorator(notifier) {}

    string getDescription() const override {
        return wrappee->getDescription() + " via Email";
    }

    void send(string message) const override {
        cout << "Email: ";
        wrappee->send(message);
    }
};

// Конкретный декоратор: SMS
class SMSDecorator : public BaseDecorator {
public:
    SMSDecorator(const shared_ptr<Notifier>& notifier) : BaseDecorator(notifier) {}

    string getDescription() const override {
        return wrappee->getDescription() + " via SMS";
    }

    void send(string message) const override {
        cout << "SMS: ";
        wrappee->send(message);
    }
};

// Клиентский код
int main() {
    // Создаем базовое уведомление
    shared_ptr<Notifier> notifier = make_shared<EventNotifier>("Совещание");
    cout << "Событие: " << notifier->getDescription()<< endl;
    notifier->send("назначено на 10:00");

    // Добавляем способ рассылки
    shared_ptr<Notifier> notifierEmail = make_shared<EmailDecorator> (notifier);
    shared_ptr<Notifier> notifierSMS = make_shared<SMSDecorator> (notifier);
    shared_ptr<Notifier> notifierSMS_Email = make_shared<SMSDecorator> (notifierEmail);

    cout << "Событие: " << notifierSMS_Email->getDescription() << endl;
    notifierSMS_Email->send("переносится на 11:00");
}