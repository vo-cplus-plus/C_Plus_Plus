#include <functional>
#include <iostream>

using namespace std;
struct Point{double x, y;};
using DrawMethod = function<void(const Point&, double)>;

ostream & operator << (ostream &out, Point p){
    cout << "(" << p.x << ", " << p.y << ")";
    return out;
}
class Figure{
    Point point;
    double size;
    public:   
    Figure(Point point, double size, DrawMethod method):
           point(point), size(size), drawMethod(method){}
    DrawMethod drawMethod;
    void Draw(){
        cout << "Рисуем фигуру\n";
        drawMethod(point, size);
    }
};


void drawCube(const Point& p, double size){
    Point p1{p.x + size, p.y + size};
    cout << "Куб: " << p <<  " " << p1<< endl;
}

void drawCircle(const Point& p, double size){    
    cout << "Окружность: " << p <<  " R= " << size << endl;
}

int main(){
    Figure cirle({0,0}, 10, drawCircle);
    Figure cube({-5,-5}, 10, drawCube);
    Figure smth({0,0}, 0, [](const Point& p, double size)->void{cout << "<unknown>";});
    cirle.Draw();
    cube.Draw();
}
