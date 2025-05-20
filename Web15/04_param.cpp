#include <iostream>
using namespace std;

class Parabola {
    double a, b, c;
public:
    Parabola(double a, double b, double c) : a(a), b(b), c(c) {}
    double operator()(double x) { return a * x * x + b * x + c; }
};

int main() {
    cout << "Вывод:\n";
    Parabola p(1, 2, 1);
    cout << p(3) << " " << Parabola(1, -5, 6)(0.5)<< endl;  
}