// Определите первую цифру целого многоразрядного числа

#include <iostream>
using number = unsigned long;
using digit  = unsigned char;

[[nodiscard]]digit first_digit(number n);

int main(){
    number n;
    std::cin >> n;
    std::cout << "Первая цифра: ";
    std::cout <<static_cast<int>(first_digit(n))<<"\n";
}

digit first_digit(number n){
    if (!n) return 0;
    for(;n>9; n/=10);
    return n;
}