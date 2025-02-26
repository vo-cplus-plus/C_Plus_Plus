#include <iostream>
int main(){
    unsigned long long n = 123456789654;
    int k = 0;
    for(; n > 0; k++, n /= 10);
    std::cout << k;
}