#include <iostream>
#include <limits>

using namespace std;

void print_max() {  
    std::cout << "Максимальные значения:\n" ; 
    std::cout << "\tfor float: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "\tfor double: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "\tfor long double: " << std::numeric_limits<long double>::max() << std::endl;
}

void print_min() {  
    std::cout << "Минимальные значения:\n" ; 
    std::cout << "\tfor float: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "\tfor double: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "\tfor long double: " << std::numeric_limits<long double>::min() << std::endl;
}
void print_eps() {  
    std::cout << "Машинный эпсилон:\n" ; 
    std::cout << "\tfor float: " << std::numeric_limits<float>::epsilon() << std::endl;
    std::cout << "\tfor double: " << std::numeric_limits<double>::epsilon() << std::endl;
    std::cout << "\tfor long double: " << std::numeric_limits<long double>::epsilon() << std::endl;
}

void print_round() {  
    std::cout << "Ошибка округления:\n" ; 
    std::cout << "\tfor float: " << std::numeric_limits<float>::round_error() << std::endl;
    std::cout << "\tfor double: " << std::numeric_limits<double>::round_error() << std::endl;
    std::cout << "\tfor long double: " << std::numeric_limits<long double>::round_error() << std::endl;
}

void print_nan() {  
    std::cout << "Nan:\n" ; 
    std::cout << "\tfor float: " << std::numeric_limits<float>::quiet_NaN() << std::endl;
    std::cout << "\tfor double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
    std::cout << "\tfor long double: " << std::numeric_limits<long double>::quiet_NaN() << std::endl;
}

void print_inf() {  
    std::cout << "\"Бесконечность\":\n" ; 
    std::cout << "\tfor float: " << (double)std::numeric_limits<float>::infinity() << std::endl;
    std::cout << "\tfor double: " << (double)std::numeric_limits<double>::infinity() << std::endl;
    std::cout << "\tfor long double: " << (double)std::numeric_limits<long double>::infinity() << std::endl;
}


int main(){
    print_max();
    print_min();
    print_eps();
    print_round();
    print_nan();
    print_inf();
}