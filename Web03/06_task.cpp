#include <iostream>

using namespace std;

int main(){
    cout << "Введите количество элементов:\n"; 
    int n; cin >> n;

    int *A = new int [n];
    cout << "Введите значения:\n"; 
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    int even_digit = 0;
    for(int i=0; i<n; i++){
        if (A[i] % 2 == 0) even_digit++;
    }

    int *res = new int[even_digit];
    for(int i=0, j=0; i<n; i++){
        if (A[i] % 2 == 0) res[j++] = A[i];
    }
    delete[] A;

    for(int i=0; i<even_digit; i++){
        cout << res[i] << " ";
    }
    cout << endl;
    delete[]res;
}