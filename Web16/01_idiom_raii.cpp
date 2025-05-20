#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Writer{
    ostream &out;  
    vector<string> data; 
public:
    Writer(ostream &out, initializer_list<string> data):out(out), data(data){}   
    void save(){
        for_each(data.begin(), data.end(), [&out=this->out](string x){out << x<<endl;});
    }
}; // Деструктор "отпускает" файл, и автоматически удаляет вектор

int main(){
    Writer w(cout, {"1", "2", "3"});
    w.save();
}