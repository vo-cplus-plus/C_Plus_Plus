

#include <iostream>
#include <iomanip>
using namespace std;
struct Point{double x, y;};

template <typename T>
// Концепт = под объект типа выделяется 
// меньше памяти, чем под int
concept real_types = convertible_to<T, double>; 

int main(){
    cout.setf(ios::boolalpha);
    cout <<"int: " << real_types<int> <<endl;
    cout <<"float: " << real_types<float> <<endl;
    cout <<"Point: " << real_types<Point> <<endl;
}