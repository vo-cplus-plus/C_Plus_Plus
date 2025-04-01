#include <concepts>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Point{
    double x, y;
    void Draw(){cout << "Point (" << x << " " << y <<")";}
};
struct Circle{
    Point center;
    double R;
    void Draw(){cout << "Circle {" << R << "}";}
};

template <typename T>
// Концепт = под объект типа выделяется 
// меньше памяти, чем под int
concept can_draw = requires(T object)
{
    {object.Draw()} -> same_as<void>;
};

template <typename T> 
requires can_draw<T>
void DrawAll(vector<T> &objects){
    for(auto &obj: objects){
        obj.Draw();
        cout << "\n";
    }
}

int main(){
    vector<Circle> circles({Circle{Point{1,1}, 10}, Circle{Point{0,0}, 5}});
    DrawAll(circles); 
    vector<Point> points({Point{1,1}, Point{0,0}, Point{5, -4}});
    DrawAll(points); 
    vector<int> v({1,2,3,4,5}); 
    DrawAll(v); // Error!
}