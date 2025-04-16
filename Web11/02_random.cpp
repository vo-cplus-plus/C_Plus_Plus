#include <iostream>
#include <random>

int main() {
    std::mt19937 gen;
    std::poisson_distribution<int> intP(1);
    std::poisson_distribution<long> longP(1);
    
    std::cout << "Random Float: " << intP(gen) << std::endl;
    std::cout << "Random Double: " << longP(gen) << std::endl;    
}