#include <iostream>
using namespace std;

int main(){
    int a = 5, b = 7;
    int c = 1, d = 2;
    // не может работать с переменными a и b, видит только x
    auto f_empty = [](double x)->double {return x * x;};
    // видит все внешние переменные, захватывает их значения
    auto f_all_value = [=](double x)->double {return (a + b + c + d) * x;};
    // видит все внешние переменные, захватывает их по ссылке
    auto f_all_ref = [&](double x)->double {
        a+= b; c+= d;
        return (a * b + c * d) * x;};
    // видит только указанные переменные
    auto f_all_ref = [a, &b](double x)->double {return a * x + b++;};
}