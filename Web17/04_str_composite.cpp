#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

// Базовый компонент
class Graphic {
public:
    virtual ~Graphic() = default;
    virtual void draw() const = 0;    
};

// Лист: Простая фигура (круг)
class Circle : public Graphic {
public:
    void draw() const override {
        cout << "Риисую круг" << endl;
    }
};

// Лист: Простая фигура (квадрат)
class Square : public Graphic {
public:
    void draw() const override {
        cout << "Рисую квадрат" << endl;
    }
};

// Компоновщик: Группа фигур
class Group : public Graphic {
private:
    vector<unique_ptr<Graphic>> children;
public:
    void draw() const override {
        cout << "Рисую группу Group:" << endl;
        for (const auto& child : children) {
            child->draw();
        }
    }

    void add(unique_ptr<Graphic> graphic) {
        children.push_back(move(graphic));
    }

    void remove(Graphic* graphic) {
        auto it = remove_if(children.begin(), children.end(),
            [graphic](const unique_ptr<Graphic>& ptr) { return ptr.get() == graphic; });
        children.erase(it, children.end());
    }
};

// Клиентский код
int main() {
    // Создаем простые фигуры
    auto circle = make_unique<Circle>();
    auto square = make_unique<Square>();    

    // Создаем внутреннюю группу и добавляем в нее фигуры
    auto innerGroup = make_unique<Group>();
    innerGroup->add(make_unique<Circle>());
    innerGroup->add(make_unique<Square>());

    // Создаем группу и добавляем в нее фигуры и внутреннюю группу
    auto group = make_unique<Group>();
    group->add(move(circle));
    group->add(move(square));
    group->add(move(innerGroup));

    // Отрисовываем всю структуру
    group->draw();
}