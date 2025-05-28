#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
using namespace std;

// Интерфейс посредника
class SmartHomeMediator {
public:
    virtual ~SmartHomeMediator() = default;
    virtual void notify(const string& event, const string& deviceId) = 0;
};

// Базовый класс устройства
class Device {
protected:
    SmartHomeMediator* mediator;
    string id;
public:
    Device(SmartHomeMediator* m, const string& id) : mediator(m), id(id) {}
    virtual ~Device() = default;
    virtual void send(const string& event) = 0;
    virtual void receive(const string& event) = 0;
    string getID() const {return id;}
};

// Конкретные устройства
class Light : public Device {
public:
    using Device::Device;
    void send(const string& event) override {
        cout << "Освещение (" << id << ") создает событие: " << event << endl;
        mediator->notify(event, id);
    }

    void receive(const string& event) override {
        if (event == "ON") {
            cout << "Освещение (" << id << ") включено" << endl;
        } else if (event == "OFF") {
            cout << "Освещение (" << id << ") выключено" << endl;
        }
    }
};

class Thermostat : public Device {
public:
    using Device::Device;

    void send(const string& event) override {
        cout << "Термостат (" << id << ") создает событие: " << event << endl;
        mediator->notify(event, id);
    }

    void receive(const string& event) override {
        if (event == "TEMP_UP") {
            cout << "Термостат (" << id << ") увеличивает температуру" << endl;
        }
        if (event == "TEMP_DOWN") {
            cout << "Термостат (" << id << ") уменьшает температуру" << endl;
        }
    }
};

// Конкретный посредник
class SmartHomeController : public SmartHomeMediator {
private:
    unordered_map<string, Device*> devices;
public:
    void addDevice(Device* device) {
        devices[device->getID()] = device;
    }

    void notify(const string& event, const string& deviceId) override {
        // Логика взаимодействия устройств
        if (event == "DOOR_OPEN" && deviceId == "door1") {
            if (devices.find("light1") != devices.end()) {
                devices["light1"]->receive("ON");
            }
        } else if (event == "TEMP_UP") {
            if (devices.find("thermostat1") != devices.end()) {
                devices["thermostat1"]->receive("TEMP_UP");
            }
        }
    }
};

// Клиентский код
int main() {
    auto mediator = make_unique<SmartHomeController>();

    Light light(mediator.get(), "light1");
    Thermostat thermostat(mediator.get(), "thermostat1");

    mediator->addDevice(&light);
    mediator->addDevice(&thermostat);

    // Симулируем событие открытия двери
    mediator->notify("DOOR_OPEN", "door1");

    // Симулируем событие повышения температуры
    thermostat.send("TEMP_UP");
    
}