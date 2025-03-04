#include <iostream>
using uint = unsigned int;
int f(uint n){  // рекуррентный подход
    uint f0 = 1, f1 = 1;
    for(uint i = 1; i < n; i++){
        uint f = f1 + f0;
        f0 = f1;
        f1 = f;
    }
    return f1;
}

int F(uint n){ // рекурсивный подход
    if (n < 2) return 1;
    return F(n - 1) + F(n - 2);
}

int main(){
    uint n = 40;
    std::cout << f(n) << " " << F(n) << "\n";
}