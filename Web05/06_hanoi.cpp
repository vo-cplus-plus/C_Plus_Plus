#include <iostream>
void hanoi(int n, int A, int B);
int main(){
    int n = 4;
    hanoi(n, 1, 3);
}

void hanoi(int n, int A, int B){    
    if (n == 1){
        std::cout << A << "->" << B<<"\n";
        return;
    }
    int C = 6 - A - B;
    hanoi(n - 1, A, C);
    hanoi(1, A, B);
    hanoi(n-1, C, B);
}