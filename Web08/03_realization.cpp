// Задача: Дан набор фигур на плоскости
// (точки, окружности, многоугольники, треугольники, прямоугольники и т.д)
// Для каждой фигуры определить, сколько других фигур она содержит

// Построение иерархии наследования
#include <vector>
#include <iostream>
using namespace std;
// Базовый класс
class Figure{
protected:    
public:    
    /*Виртуальный метод в C++ — это метод, который может быть переопределён
    в классах-наследниках так, что конкретная реализация метода для вызова будет
    определяться во время исполнения. */
    /*Чисто виртуальный метод в C++ — это метод, тело которого не определено.
    После объявления виртуального метода в нём пишут «= 0».*/
    virtual void print()=0;
    virtual bool contains(Figure& f)=0;
    virtual ~Figure(){}   
};

class Point: public Figure{
    double x0, y0;
public:
    Point(double x0=0, double y0=0):x0(x0), y0(y0){ }
    virtual ~Point(){ }
    void print() override {cout << "Point " << x0 << " " << y0 << "\n";}
    bool contains(Figure& f) override{       
        return false;
    }
    double X0() const{return x0;}
    double Y0() const{return y0;}
};

// Вектор включает точку, не участвует в иерархии наследования
class Vector{
    Point A, B;
    double dx, dy;
public:
    Vector(const Point &A, const Point &B):A(A),B(B){
        dx = B.X0() - A.X0();
        dy = B.Y0() - A.Y0();
    }
    int sign_vector_product(Vector & v){
        return this->dx * v.dy - v.dx * this-> dy;
    }
};

class Circle:public Figure{
    Point center;
    double R;
public:
    Circle(double x0=0, double y0=0, double R=10):center(x0, y0), R(R){ }
    virtual ~Circle(){ }
    void print() override {
        cout << "Circle with center in ";
        center.print(); 
        cout << "R = " << R << "\n";}
    bool contains(Figure& f) override{       
        throw "not implemented";
    }
};

// производный класс многоугольник
class Polygon: public Figure{
    vector<Point> points;
    public:
    Polygon(vector<Point> points):points(points){        
    }
    void print() override {
        cout << "Polygon:\n";
        for(Point &p: points){
            p.print();
        }
        cout << "\n";
    }
    bool contains(Figure&p){
        throw "not implemented";
        /*cout <<"Name: " << typeid(p).name() << "\n";
        string class_name(typeid(p).name());
        if (class_name == "5Point"){
            int k = 0;
            // перебираем все точки многоугольника
            Point& point = (Point&)p;
            for(int i=0; i<points.size(); i++){
                Point& A = points[i];
                Point& B = points[(i+1)% points.size()];
                Vector v(A, B);
                Vector v0(B, point);
                int prod = v.sign_vector_product(v0);
                cout << "pr = " << prod << "\n";
                if (prod < 0) k++;            
            } 
            return k == points.size();
             } 
            */              
    }
};


int main(){    
    Polygon poly(vector<Point> ({Point(0,0), Point(2,1), Point(4,0)}));
    Point pointA(2,0.5);      
    Point pointB(10, 4); 
    Circle circle(0,0, 20);
   
    vector<Figure*> pointers({&pointA, &pointB, &poly, &circle});
    for(auto p: pointers){
        p->print();
    }      
}

