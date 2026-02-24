#include <iostream>
#include <fstream>
using namespace std;

enum Dir{UP=2, DOWN=3, LEFT=1, RIGHT=0};

int main(){
    ofstream out("out.txt");
    double x0{0.0}, y0{0.0}, x{1.0};
    
    int i;
    cin >> i;
    Dir dir = (Dir)i;

    switch(dir){
        case RIGHT: x0 += x; break;
        case LEFT: x0 -= x; break;
        case 2: y0 += x; break;
        case 3: y0 -= x; break;
        default: cout << "No move\n";
    }
    cout << "Point:" << x0 << " " << y0<< endl;
    out << "Point:" << x0 << " " << y0<< endl;
    return 0;
}