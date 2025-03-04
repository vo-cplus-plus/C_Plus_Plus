// вычисление среднего арифметического значения в массиве
#include <iostream>
#include <vector>

[[nodiscard]]double mean(std::vector<double> & A);

int main(){
    std::vector<double> A({5.0, -0.4, 6.7, -1.2, 4.5});           
    std::cout << "Среднее арифметическое: ";
    std::cout << mean(A) <<"\n";
    std::cout << A.size() << " " << A.capacity() <<"\n";    
}

double mean(std::vector<double> & A){
    double res = 0.0;
    for(std::size_t i=0;i < A.size(); i++){
        res += A[i];
    }
    return res / A.size();
}