#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>
using namespace std;

template <typename Derived>
class Base {
    static int num_calls;
public:
    void call() {num_calls++; static_cast<Derived*>(this)->implementation(); }
    int get_num_calls(){return num_calls;}
};

template <typename Derived> int Base<Derived>::num_calls = 0;

class Derived1 : public Base<Derived1> {
public:
    void implementation() {cout << "Реализация #1\n";}
};

class Derived2 : public Base<Derived2> {
public:
    void implementation() {cout << "Реализация #2\n";}
};

int main(){
    Derived1 d11, d12;
    Derived2 d2;
    d11.call();
    d12.call();
    d2.call();
    cout << "Количество вызовов: " << d11.get_num_calls() << " "<<
    d12.get_num_calls() << " " << d2.get_num_calls() << endl; 

}