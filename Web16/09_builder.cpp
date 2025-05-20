#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Pizza {   
    string sauce_;
    vector<string> top_;
public:
    void setSauce(const string& sauce){ sauce_ = sauce; }    
    void setTopping(const initializer_list<string>& top) {
        top_.resize(top.size());
        copy(top.begin(), top.end(), top_.begin());
    }
    void show() const {
        cout << "Пицца (" << sauce_ << " " << top_.size() << " ингридиент(а/ов))\n";
    }
};
class Pasta{
    string sauce_;
    string spaghetti_;
public:
    void setSauce(const string& sauce){ sauce_ = sauce; }
    void setType(const string& spaghetti){ spaghetti_ = spaghetti; }
    void show() const {
        cout << "Паста (" << sauce_ << " " << spaghetti_ << ")\n";
    }
};

class Builder {
public:
    virtual ~Builder() = default;    
    virtual void stepA() = 0;
    virtual void stepB() = 0;     
};

// Строитель для пиццы Маргарита
class MargheritaBuilder : public Builder { 
    Pizza pizza;  
public:       
    void stepA() override {
        pizza.setSauce("томатный");
    }
    void stepB() override {
        pizza.setTopping({"моцарелла"});
    } 
    Pizza getResult() {return pizza;} 
};

// Строитель для Пепперони
class PepperoniBuilder : public Builder {   
    Pizza pizza; 
public:    
    void stepA() override {
        pizza.setSauce("острый");
    }
    void stepB() override { 
        pizza.setTopping({"пепперони", "сыр"});
    }
    Pizza getResult() {return pizza;} 
};
// Строитель для Пасты
class PastaBuilder : public Builder {   
    Pasta pasta; 
public:     
    void stepA() override{
        pasta.setType("спагетти");
    }
    void stepB() override {
        pasta.setSauce("болоньез");
    }
    Pasta getResult() {return pasta;} 
};

class Cook {    
public:
    void make(Builder& builder) {       
        builder.stepA();
        builder.stepB();
    }   
};

int main() {
    // Создаем строителя для Маргариты
    MargheritaBuilder margheritaBuilder;
    // Строитель для Пепперони 
    PepperoniBuilder pepperoniBuilder;
    // Строитель для Пасты 
    PastaBuilder pastaBuilder;
    Cook cook;
    cook.make(margheritaBuilder);
    cook.make(pepperoniBuilder);
    cook.make(pastaBuilder);
    margheritaBuilder.getResult().show(); 
    pepperoniBuilder.getResult().show();
    pastaBuilder.getResult().show();
    return 0;
}