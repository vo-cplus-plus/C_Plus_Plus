// вычисление среднего арифметического значения в массиве
#include <iostream>

[[nodiscard]]double mean(double * A, std::size_t n);

int main(){
    std::size_t n = 5;
    double *A = new double[n]{5.0, -0.4, 6.7, -1.2, 4.5};       
    std::cout << "Среднее арифметическое: ";
    std::cout << mean(A, n) <<"\n";
    delete [] A;
}

double mean(double * A, std::size_t n){
    double res = 0.0;
    for(std::size_t i=0;i < n; i++){
        res += A[i];
    }
    return res / n;
}