#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;


int main() {
	set<int> s = {5, 8, 13, 2, 3, 4, 7};
    vector<int> v = {5, 8, 13, 5, 7, 2, 3, 4, 2, 2, 4, 7};

    // считает количество 5 в упорядоченном множестве
	size_t number_5 = count(s.begin(), s.end(), 5);
    // считает количество 2 в векторе
    size_t number_2 = count(v.begin(), v.end(), 2);

    // считает количество четных элементов в упорядоченном множестве
    size_t number_even = count_if(s.begin(), s.end(), [](const int&x){return x % 2 == 0;});
    // считает количество нечетных элементов в векторе
    size_t number_odd = count_if(v.begin(), v.end(), [](const int&x){return x % 2;});
    return 0;
}