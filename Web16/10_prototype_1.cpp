#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Shape {
    double x, y;
public:
    Shape(double x, double y): x(x), y(y){}
    virtual ~Shape() = default;
    virtual shared_ptr<Shape> clone() const = 0;
    virtual void printInfo() const = 0;    
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double width, double height) 
        :Shape(0,0), width(width), height(height) {}

    shared_ptr<Shape> clone() const override {
        return make_unique<Rectangle>(*this);
    }

    void printInfo() const override {
        cout << "Rectangle: (" << width << ", " << height << ")\n";
    }   
};

class Circle : public Shape {
    double radius;
public:
    Circle(double R):Shape(0,0), radius(R){}

    shared_ptr<Shape> clone() const override {
        return make_unique<Circle>(*this);
    }

    void printInfo() const override {
        cout << "Circle: (" << radius << ")\n";
    }
};

int main() {
    // Создаем прототипы
    shared_ptr<Shape> RectanglePrototype = make_shared<Rectangle>(100, 100);
    shared_ptr<Shape> CirclePrototype = make_shared<Circle>(200);

    // Клонируем и кастомизируем
    auto Rectangle1 = RectanglePrototype->clone();    
    Rectangle1->printInfo(); // Rectangle: Boromir (Strength: 100)

    auto Circle1 = CirclePrototype->clone();    
    Circle1->printInfo(); // Circle: Saruman (Mana: 200)

    return 0;
}