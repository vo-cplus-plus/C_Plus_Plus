#include <iostream>
#include <cmath>

int main(){
    int Ax, Ay, Bx, By, Cx, Cy;
    double a, b, c, p, S;

    std::cout << "Введите значения: ";
    std::cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
    // требуется проверка, лежат ли точки на одной прямой

    a = sqrt(pow(Bx - Cx, 2.0)+ pow(By - Cy, 2.0));
    b = sqrt(pow(Ax - Cx, 2.0)+ pow(Ay - Cy, 2.0));
    c = sqrt(pow(Bx - Ax, 2.0)+ pow(By - Ay, 2.0));

    double A = std::max(a, std::max(b, c));
    double BC = a + b + c - A;
    // !!! Возможны ошибки округления !!!
    if (std::abs(A - BC) < 1e-10){
        std::cout << "Точки лежат на одной прямой!";
    }
    else{
        p = (a + b + c) / 2.0;
        S = sqrt(p * (p - a)*(p - b)*(p - c));
        std::cout << "S = " << S << std::endl;
    }
}