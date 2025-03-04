#include <fstream>
#include <iostream>
using std::ifstream;
using std::ofstream;
using std::cout, std::cin;


int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");

    if(!input.is_open()) return 1;
    char letter;
    while(input.get(letter)){
        output << letter;
    }    
    if(input.eof()){        
        cout << "Достигнут конец файла\n";
    }
    else{
        cout << "Ошибка чтения конец файла\n";
    }
}
