#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// Стул
class Chair {
public:
    virtual ~Chair() = default;
    virtual bool hasLegs() = 0;
    virtual void sitOn() = 0;
};

// Диван
class Sofa {
public:
    virtual ~Sofa() = default;
    virtual void folding() = 0;
};

// Модерн
class ModernChair : public Chair {
public:
    bool hasLegs() override{return false;};
    void sitOn() override{ cout << "Модерн, стул\n";};
};

class ModernSofa : public Sofa {
public:
    void folding() override {
        std::cout << "Диван (модерн) не раскладывается\n";
    }
};

// Викторианский стиль
class VictorianChair : public Chair {
public:
    bool hasLegs() override{return true;};
    void sitOn() override{ cout << "Викторианский стул\n";};
};

class VictorianSofa : public Sofa {
public:
    void folding() override {
        std::cout << "Викторианский диван не раскладывается\n";
    }
};

// Абстрактная фабрика
class FurnitureFactory  {
public:
    virtual ~FurnitureFactory() = default;
    virtual Chair* createChair() = 0;
    virtual Sofa* createSofa() = 0;
};

class VictorianFactory : public FurnitureFactory {
public:
    Chair* createChair() override {
        return new VictorianChair();
    }
    Sofa* createSofa() override {
        return new VictorianSofa();
    }
};

class ModernFactory : public FurnitureFactory {
public:
    Chair* createChair() override {
        return new ModernChair();
    }
    Sofa* createSofa() override {
        return new ModernSofa();
    }
};

class Production{
private:
    FurnitureFactory* factory;
    vector<Chair*> chairs;
    vector<Sofa*> sofas;

public:
    Production(FurnitureFactory* factory) : factory(factory){}

    void addFurniture() {
        chairs.push_back(factory->createChair());
        sofas.push_back(factory->createSofa());
    }

    void check() {
        for_each(chairs.begin(), chairs.end(), [](Chair*& c){c->sitOn();});
        for_each(sofas.begin(), sofas.end(), [](Sofa*& s){s->folding();});
    }

    ~Production() {
        for(auto iter = chairs.begin(); iter != chairs.end(); iter++)
            delete *iter;
        for(auto iter = sofas.begin(); iter != sofas.end(); iter++)
            delete *iter;        
        delete factory;
    }
};

// Использование
int main() {
    // Выбор фабрики
    FurnitureFactory* factory = new ModernFactory();
    Production production(factory);
    for(int i=0; i< 5; i++) production.addFurniture();
    production.check();    
}