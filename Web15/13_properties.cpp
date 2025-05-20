#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;


int main() {	
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};   

    int limit = 10;
	if (all_of(v.begin(), v.end(), [limit](const int & x){return x < limit;})){
        cout << "Все элементы меньше " <<  limit <<endl;
    }
    int k = 1;
    if (all_of(v.begin(), v.end(), [&k](const int & x){return x == k++;})){
        cout << "Все элементы совпадают со своим индексом" <<endl;
    }

    int d = 5;
    if (any_of(v.begin(), v.end(), [d](const int & x){return !(x % d);})){
        cout << "Есть хотя бы один элемент кратный " << d <<endl;
    }
    
    if (none_of(v.begin(), v.end(), [limit](const int & x){return x > limit;})){
        cout << "Нет ни одного элемента, большего чем " << limit <<endl;
    }    
}