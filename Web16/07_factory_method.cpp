#include <memory>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Transport {
public:
    virtual ~Transport() = default;
    virtual void load() = 0;
    virtual void move() = 0;
};

class Truck : public Transport {
public:
    void load() override {
        cout << "Загрузка грузовика...\n";
    }
    void move() override {
        cout << "Грузовик едет...\n";
    }
};

class Ship : public Transport {
public:
    void load() override {
        cout << "Погрузка корабля...\n";
    }
    void move() override {
        cout << "Корабль плывет...\n";
    }
};

class Logistics {
public:
    virtual ~Logistics() = default;
    
    // Фабричный метод
    virtual Transport* createTransport() = 0;
    // Для упрощения (лучше использовать умные указатели)
    void newTransport() {
        Transport* t = createTransport();
        t->load();
        t->move();
        delete t; 
    }
};

class SeaLogistics : public Logistics {
public:
    Transport* createTransport() override {
        return new Ship();
    }
};

class RoadLogistics : public Logistics {
public:
    Transport* createTransport() override {
        return new Truck();
    }
};

int main() {
    Logistics* logistics = new SeaLogistics();
    logistics->newTransport(); // Создает корабль    
    delete logistics;
    logistics = new RoadLogistics();
    logistics->newTransport(); // Создает грузовик    
    delete logistics;
}