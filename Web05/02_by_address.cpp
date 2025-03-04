// вычисление среднего арифметического значения в массиве
#include <iostream>

[[nodiscard]]double mean(double * A, std::size_t n);

int main(){
    double A[]{5.0, -0.4, 6.7, -1.2, 4.5, 4.3, 3.8, -3.1};
    std::size_t n = sizeof(A) / sizeof(double);    
    std::cout << "Среднее арифметическое: ";
    std::cout << mean(A, n) <<"\n";
}

double mean(double * A, std::size_t n){
    double res = 0.0;
    for(std::size_t i=0;i < n; i++){
        res += A[i];
    }
    return res / n;
}