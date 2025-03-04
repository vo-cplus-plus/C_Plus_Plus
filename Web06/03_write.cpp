#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using std::ifstream;
using std::ofstream;
using std::string;
using std::cout, std::cin;

int main(){    
    ofstream output("output.txt");
    output << std::setiosflags (std::ios::boolalpha);
    output << false << " " << true << std::endl;  // false true

    output << std::setw(10);
    output << 123 << std::endl;   // перед 123 добавлено  7 пробелов (общая ширина вывода 10)

    output << std::setw(10) << std::setfill('_');
    output << 123 << std::endl;   // перед 123 добавлено  7 '_' (общая ширина вывода 10)
    
    double pi = 3.1415926535897932384626433832795;
    output << std::fixed << std::setprecision(5);
    output << pi << std::endl;


    return 0;

}