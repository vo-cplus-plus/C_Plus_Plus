#include <iostream>
#include <cmath>
int main(){
    double x0 = -5.0, x1 = 5.0, dx=0.1;
    // float x0 = -5.0f, x1 = 5.0f, dx=0.1f;

    //for(инициализация; условие; модификация)

    int count = 1;
    for(double x = x0; x < x1 && count < 6; x += dx, count++){
        double y = sin(3 * x) + 1;
        std::cout << count << "\t" << x << "\t" << y << std::endl;
    }
    

    /*for(;;){ // бесконечный цикл = while(true){}

    }*/

    int n = 5;
    double x = 1.0;
    double res = 1.0, f = 1.0, p = 1.0;
    
    for(int k = 0; k <= n; ){
        res *= (sin(k * x) / f + cos(k * x) /p);
        k++;
        p *= 2;
        f *= k;
    }
    std::cout << res << std::endl;
}