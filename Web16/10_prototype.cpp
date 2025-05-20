// источник: https://refactoringu.ru/ru/design-patterns/prototype.html
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

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


class Client{
    vector<shared_ptr<Shape>> shapes;
public:
    Client(){
        shared_ptr<Shape> rectanglePrototype = make_shared<Rectangle>(100, 100);
        shapes.push_back(rectanglePrototype);
        shared_ptr<Shape> circlePrototype = make_shared<Circle>(200);
        shapes.push_back(circlePrototype);

        // Клонируем
        auto rectangle1 = rectanglePrototype->clone();
        shapes.push_back(rectangle1);

        auto circle1 = circlePrototype->clone();    
        shapes.push_back(circle1); 
        for_each(shapes.begin(), shapes.end(), [](auto &x){x->printInfo();});
    }
    void businessLogic(){
        // Плюс Прототипа в том, что вы можете клонировать набор
        // объектов, не зная их конкретные классы.
        vector<shared_ptr<Shape>> shapesCopy;        

        // Например, мы не знаем, какие конкретно объекты
        // находятся внутри массива shapes, так как он объявлен
        // с типом Shape. Но благодаря полиморфизму, мы можем
        // клонировать все объекты «вслепую». Будет выполнен
        // метод clone того класса, которым является этот
        // объект.
        for(auto &s: shapes){
            shapesCopy.push_back(s->clone());
        }        
        // Переменная shapesCopy будет содержать точные копии
        // элементов массива shapes.
        for(auto &s: shapesCopy){
            s->printInfo();
        }
    }
};

int main(){
    Client client;
    cout << "________________\n";
    client.businessLogic();
}