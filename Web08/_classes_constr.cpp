#include <iostream>
#include <string>
using namespace std;

class A{
    int key;
public:
    A(){
        cout << "Вызов конструктора\n";
    } // конструктор по умолчанию
    A(int n):A(){
        key = n;
    }
    A(float f):key(f){
        //cout << "Вызов конструктора\n";
        A(); // !!! Создание объекта
    }
    ~A(){
        cout << "Вызов деструктора\n";
    }
};

int main(){
    //A a0; // Конструктор по умолчанию
    // A a1(1); // Конструктор A(int n);
    A a1(1.0f); // Конструктор A(float f);
}

