#include <memory>
#include <vector>
#include <iostream>
using namespace std; 

// Базовый абстрактный класс
class Shape {
public:
    virtual ~Shape() = default;
    virtual shared_ptr<Shape> create(initializer_list<double> values) const = 0;// Виртуальный "конструктор"
    virtual shared_ptr<Shape> clone() const = 0; // Виртуальный "конструктор копирования"
    virtual void print()=0;
};

// Производный класс: Circle
class Circle : public Shape {
    double R;
public:
    Circle(){}
    Circle(double R):R(R){}
    shared_ptr<Shape> create(initializer_list<double> values) const override { // Виртуальный "конструктор" (создание объекта)
       return  make_unique<Circle>(*values.begin()); // Использует конструктор по умолчанию
    }
    shared_ptr<Shape> clone() const override { // Виртуальный "конструктор копирования"
        return  make_unique<Circle>(*this); // Использует копирующий конструктор Circle
    }
    void print() override { cout << "Окружность с радиусом " << R << endl;}
};

// Производный класс: Rectangle
class Rectangle : public Shape {
    double a, b;
public:
    Rectangle(){}
    Rectangle(double a, double b):a(a), b(b){}
    shared_ptr<Shape> create(initializer_list<double> values) const override { // Виртуальный "конструктор" (создание объекта)
       double a = *values.begin(), b = *(values.begin() + 1);       
       return  make_unique<Rectangle>(a, b); // Использует конструктор по умолчанию
    }
    shared_ptr<Shape> clone() const override { // Виртуальный "конструктор копирования"
        return  make_unique<Rectangle>(*this); // Использует копирующий конструктор Circle
    }
    void print() override { cout << "Прямоугольник со стронами" << a << " "<<b<< endl;}
};

// Пример использования
int main() {
    Circle c; Rectangle r;
    vector<shared_ptr<Shape>> figures({c.create({5}), c.create({3}), r.create({1,2})});
    
    shared_ptr<Shape> copy = figures.front()->clone(); // Создается копия первого объекта
    copy->print();
    return 0;
}