#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
void print(T left, T right_not_included){
    for(auto i=left; i != right_not_included; i++){
        cout << *i << " ";
    }
    cout << endl;
}

template<typename T>
pair<T, T> partition(T left, T right){
    auto length = right - left;
    T middle = left + length / 2;
    T forward = left, backward = right;
    do{
        while(*forward < *middle) forward++;
        while(*backward > *middle) backward--;
        if (forward <= backward){
            swap(*forward, *backward);
            forward++; backward--;
        }
    }while(forward <= backward);
    return {forward, backward};
}

template<typename T>
void quick_sort(T left, T right){
    auto [i, j] = partition(left, right);
    if (left < j)
        quick_sort(left, j);
    if (i < right)
        quick_sort(i, right);
}




int main(){
    int n = 10;
    int S[]{9,5,4,2,3,1,7,0,6,8};
    int * A = new int[n]{4,5,9,2,3,1,7,0,6,8};
    vector<int> B({4,5,9,2,3,1,7,0,6,8});

    quick_sort(begin(S), end(S) - 1);
    quick_sort<int*>(A, A + n - 1);
    quick_sort(B.begin(), B.end()-1);

    print(begin(S), end(S));
    print(A, A + n);
    print(B.begin(), B.end());
    
}

