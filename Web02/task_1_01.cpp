#include <iostream> // Ввод-вывод
#include <cmath>
using namespace std;

const double pi = 3.141592653589793238;

int main(){
    double R, alpha, beta, gamma;
    cout << "Input:\n";
    cin >> R >> alpha >> beta >> gamma;
    // && - и
    // ||  - или
    // ! - не
    if (/*условие*/ R > 0 && alpha > 0 && beta > 0 && 
    gamma > 0 && (alpha + beta + gamma - 180.0) < 1.0e-7){
        // выполняем, если условие верно
        double a = 2 * R * sin(alpha* pi / 180.0 );
        double b = 2 * R * sin(beta* pi / 180.0);
        double c = 2 * R * sin(gamma * pi / 180.0);
        cout << "Result: " << a << " " << b << " " << c << endl; 
    }
    else{
        // альтернатива
        cout << "Error\n";
    }

}
