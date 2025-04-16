#include <iostream>
#include <cmath>

using namespace std;

int main(){
    // дифференцируемая функция
    auto f = [](double x){return sin(x);};
    // производная 
    auto df = [](double x){return cos(x);};
    // точка, в которой оцениваем значение производной
    double x = M_PI / 15.0;
    // оценка точности вычислений       
    for(double dx = 0.1; dx > 1.0e-16; dx /= 10.0){
        // оценка значения производной в точке x
        double _df = (f(x + dx) - f(x)) / dx;
        // ошибка
        double error = abs(df(x) - _df);
        cout << "dx = " << dx << " df = " << df(x) << " df_approx = " << _df
         << " error = " << error << "\n";
    }    
}