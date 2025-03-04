#include <fstream>
#include <iostream>
#include <string>
using std::ifstream;
using std::ofstream;
using std::string;
using std::cout, std::cin;

/*intup.txt

5
This is a simple; file
with some lines to read

So let's read all the letters

*/

int main(){    
    ifstream input("input.txt");
    int n;
    string word, another_word;
    input >>n >> word >> another_word; // 5 >> this >> is
    string line;
    getline(input, line, ';');         //  " a simple"
    getline(input, line);         //  " file"
    getline(input, line);         //  "with some lines to read"
    char c;
    input.get(c);    // '\n'
    input.get(c);    // 'S'
    getline(input, line);         //  "o let's read all the letters"
    return 0;

}