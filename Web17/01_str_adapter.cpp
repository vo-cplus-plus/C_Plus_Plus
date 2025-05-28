#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Клиентский интерфейс
class ClientInterface {
public:
    virtual ~ClientInterface() = default;
    virtual string request() const = 0;
};

// Несовместимый класс (требует адаптации)
class Service {
public:
    string specificRequest() const {
        return "Specific request";
    }
};

// Адаптер (объектная реализация)
class AdapterObj : public ClientInterface {
private:
    shared_ptr<Service> adaptee;  // Композиция

public:
    AdapterObj(const shared_ptr<Service> &a): adaptee(a){ }
    string request() const override {
        return "Adapter: " + adaptee->specificRequest();
    }
};

class AdapterClass : public ClientInterface, public Service {
public:
    std::string request() const override {
        return "ClassAdapter: " + specificRequest();
    }
};

// Клиентский код
int main() {
    shared_ptr<Service> service = make_shared<Service>();
    shared_ptr<ClientInterface> adapterObj = make_shared<AdapterObj>(AdapterObj(service));
    cout << adapterObj->request() << endl;  
    shared_ptr<ClientInterface> adapterClass = make_shared<AdapterClass>();
    cout << adapterClass->request() << endl;   
}