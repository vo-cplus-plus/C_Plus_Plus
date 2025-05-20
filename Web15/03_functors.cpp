#include <iostream>
#include <string>

using namespace std;

class Greeting {
    string name;
public:
    Greeting(string name) : name(name) {}
    void operator()() { std::cout << "Добрый день, " << name << endl; }
};

int main() {
    cout << "Вывод:\n";
    Greeting greeting("Иван Иванович");
    greeting();
    Greeting("Петр Петрович")();  
}