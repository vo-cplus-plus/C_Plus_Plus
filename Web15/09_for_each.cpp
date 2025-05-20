#include <set>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

void out_function(const double &x){
    cout <<fixed<< setw(5) << setprecision(2) <<x << " "; 
}

class out_class{
    ostream& out;
    public:
    out_class(ostream& out):out(out){}
    void operator()(const double &x){
        out <<fixed<< setw(5) << setprecision(2) <<x << " ";
    }
};

int main() {
	set<double> v = {2.1, 7.53, 6.232, 4.8, 3.9};
	// передача функции в качестве аргумента
	for_each(v.begin(), v.end(), out_function);
    // вывод части последовательности
    for_each(v.begin(), next(v.begin(), 3), out_function);
    // передача функтора в качестве аргумента
    for_each(v.begin(), v.end(), out_class(cout));
    ofstream out("output.txt");
    for_each(v.begin(), v.end(), out_class(out));
    // лямбда выражение
    for_each(v.begin(), v.end(), [&out](const double &x){out << x << "\n";});	
}