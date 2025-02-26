#include <iostream>
#include <cmath>

int main(){
    char x1, y1, x2, y2;
    std::cout << "Введите значения: ";
    std::cin  >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2 || y1 == y2 || std::abs(x2 - x1) == std::abs(y2 - y1)){
        std::cout << "Фигура под боем\n";
    }
    else{
        std::cout << "Фигура не под боем\n";
    }
}