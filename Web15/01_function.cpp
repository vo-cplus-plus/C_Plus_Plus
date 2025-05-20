#include <functional>
#include <iostream>

using namespace std;
using TCalculation = function<double(double, double)>;
struct Rect{
    double a, b, c, d;
    Rect(double a=-1, double b=1, double c=-1, double d=1):
        a(a), b(b), c(c), d(d){}
};
void printTable(TCalculation f, Rect r, double h=0.2){
    for(double x = r.a; x <= r.b; x += h) cout << x << "\t";
    cout << endl;
    for(double y = r.c; y <= r.d; y += h){
        for(double x = r.a; x <= r.b; x += h) cout << f(x, y) << "\t";
        cout << endl;
    }
}
int main(){
    Rect r{0,10, 0, 10};
    printTable([](double x, double y)->double{return x + y;}, r);
}