#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

bool compare (double a, double b){
    long long *pa = reinterpret_cast<long long *> (&a);
    long long *pb = reinterpret_cast<long long *> (&b);
    return abs(*pb - *pa) < 2;  
}

int main(){
    RAND_MAX;
    ofstream f("data.dat",ios::binary);

    double value = 1.0 / 3.0; // * pow(10.0, 300.0);
    double _value = (1 - sqrt(27) * 2 / sqrt(243)); // *pow(10, 300.0);
    void *pv = &value;
    void*_pv = &_value;
    f.write(reinterpret_cast<char *>(pv), 8);
    f.write(reinterpret_cast<char *>(_pv), 8);
    cout << value << " " << _value << endl;
    if (abs(value - _value) < 1e-16){
        cout << "Величины равны" << endl;
    }else{
        cout << "Величины не равны" << endl;
    }
    
    if (compare(value, _value))    {
        cout << "Величины равны" << endl;
    }else{
        cout << "Величины не равны" << endl;
    } 
}

#include <cfloat>
#include <cmath>
#include <iostream>
 
int main2()
{
    std::cout << std::boolalpha
              << "isnan(NaN) = " << std::isnan(NAN) << '\n'
              << "isnan(Inf) = " << std::isnan(INFINITY) << '\n'
              << "isnan(0.0) = " << std::isnan(0.0) << '\n'
              << "isnan(DBL_MIN/2.0) = " << std::isnan(DBL_MIN / 2.0) << '\n'
              << "isnan(0.0 / 0.0)   = " << std::isnan(0.0 / 0.0) << '\n'
              << "isnan(Inf - Inf)   = " << std::isnan(INFINITY - INFINITY) << '\n';
}

#include <cfloat>
#include <cmath>
#include <iostream>
#include <limits>
 
int main1()
{
    const double max = std::numeric_limits<double>::max();
    const double inf = std::numeric_limits<double>::infinity();
 
    std::cout << std::boolalpha
              << "isinf(NaN) = " << std::isinf(NAN) << '\n'
              << "isinf(Inf) = " << std::isinf(INFINITY) << '\n'
              << "isinf(max) = " << std::isinf(max) << '\n'
              << "isinf(inf) = " << std::isinf(inf) << '\n'
              << "isinf(0.0) = " << std::isinf(0.0) << '\n'
              << "isinf(exp(800)) = " << std::isinf(std::exp(800)) << '\n'
              << "isinf(DBL_MIN/2.0) = " << std::isinf(DBL_MIN / 2.0) << '\n';
}