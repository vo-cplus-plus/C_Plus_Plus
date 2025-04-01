#include <concepts>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
struct Point{
    double x, y;
    void Draw(){cout << "Point\n";}
};
struct Circle{
    Point center;
    double R;
    void Draw(){cout << "Circle\n";}
};

template <typename T>
// Концепт = под объект типа выделяется 
// меньше памяти, чем под int
concept can_draw = requires(T object)
{
    {object.Draw()} -> same_as<void>;
};


int main(){
    cout.setf(ios::boolalpha);
    cout <<"int: " << can_draw<int> <<endl;
    cout <<"Circle: " << can_draw<Circle> <<endl;
    cout <<"Point: " << can_draw<Point> <<endl;
}