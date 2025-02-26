#include <iostream>
int main(){
    unsigned long long n = 1231456789;
    auto m = n;
    bool same = false;
    for (; m > 0 && !same; m/=10){        
        unsigned char d = m % 10;
        for(auto k = m / 10; k > 0 && !same; k /= 10){
            if (k % 10 == d) same = true;
        }
    }
    if (same) std::cout << "Одинаковые цифры есть\n";
    else std::cout << "Одинаковых цифр нет\n";
    return 0;
}
