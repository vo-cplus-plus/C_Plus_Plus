#include <iostream>
#include <iomanip>
using namespace std;
struct Point{double x, y;};

template <typename T>
concept small_size = sizeof(T) < sizeof(int);
template <typename T>
concept real_types = convertible_to<T, double>; 

int main(){
    cout.setf(ios::boolalpha);
    cout <<"Int: " << small_size<int> <<endl;
    cout <<"Char: " << small_size<char> <<endl;
    cout <<"Point: " << small_size<Point> <<endl;

    cout.setf(ios::boolalpha);
    cout <<"int: " << real_types<int> <<endl;
    cout <<"float: " << real_types<float> <<endl;
    cout <<"Point: " << real_types<Point> <<endl;

}