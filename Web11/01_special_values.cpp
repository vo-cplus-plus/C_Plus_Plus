#include <cfloat>
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <functional>

using namespace std;

string get_FPClass(double x)
{
    switch (_fpclass(x)){
        case _FPCLASS_SNAN:
            return "Cигнальный NaN";
        case _FPCLASS_QNAN:
            return "Обычный NaN";
        case _FPCLASS_NINF:
            return "Минус бесконечность";
        case _FPCLASS_NN:
            return "Отрицательное нормализованное";            
        case _FPCLASS_ND:
            return "Отрицательное ненормализованное";
        case _FPCLASS_NZ:
            return "Отрицательный нуль";
        case _FPCLASS_PZ:
            return "Положительный нуль";
        case _FPCLASS_PD:
            return "Положительное ненормализованное";
        case _FPCLASS_PN:
            return "Положительное нормализованное";
        case _FPCLASS_PINF:
            return "Плюс бесконечность";
    }
    return "";
}

string hex_mem(double x){    
    unsigned long* p = reinterpret_cast<unsigned long*>(&x);
    ostringstream os;
    os <<setw(8) << setfill('0')<< hex << p[1] << " ";
    os <<setw(8) << setfill('0')<< hex << p[0];
    return os.str();
}

void test(string title, string line, function<double()> f){
    cout <<"\n" << title << "\n";
    // нельзя выполнить явно деление на ноль
    // иначе будет ошибка  компиляции.
    double z = f();
    cout << line << z << "\n";
    cout << hex_mem(z) << "\n_fpclass(z) = " << get_FPClass(z) << "\n";
}

int main(){
    double x, y;

    // нельзя выполнить явно деление на ноль
    // иначе будет ошибка  компиляции.
    x = 1; y = 0;
    test("Проверка z = 1/0", "z = ", [&x, &y](){return x / y;});
    
    x = -1.0; y = 0;
    test("Проверка z = -1/0", "z = ", [&x, &y](){return x / y;});
    
    test("Проверка z = sqrt(-1)", "z = ", [&x](){return sqrt(x);});
   
    test("Проверка z = log(-1)", "z = ", [&x](){return log(x);});

    double z = DBL_MAX;
    test("Проверка максимального значения", "z = DBL_MAX = ", [&z](){return z;});
    test("Проверка переполнения", "z = 2 * DBL_MAX = ", [&z](){return 2.0 * z;});
    
    z = DBL_MIN;
    test("Проверка минимального значения", "z = DBL_MIN = ", [&z](){return z;});
    test("Проверка переполнения", "z = DBL_MIN / 2 = ", [&z](){return z / 2.0;});
    z /= pow(2.0, 52);
    test("Проверка переполнения", "z = DBL_MIN / 2^52 = ", [&z](){return z;});
    test("Проверка переполнения", "z = DBL_MIN / 2^53 = ", [&z](){return z / 2.0;});
    test("Проверка переполнения", "z = -DBL_MIN / 2^53 = ", [&z](){return -z / 2.0;});

    x = 1.0; y = 0.0; x /= y; y = -x;
    test("Проверка z = (+infinity) + (-infinity)", "z = ", [&x, &y](){return x + y;});

    test("Проверка z = 0 * (+infinity)", "z = ", [&x](){return 0.0 * x;});

    x = 0.0; y = 0.0;
    test("Проверка z = 0 / 0", "z = ", [&x, &y](){return x / y;});

    x = 1.0; y = 0.0; x /= y; y = x; 
    test("Проверка z = infinity/infinity", "z = ", [&x, &y](){return x / y;});

    x = 1.0e300; y = 1.0e300; z = x * y;
    if (z == numeric_limits<double>::infinity()){
        cout << "It works!\n"; 
    }
    
}    