#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;


int main() {	
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> v2 = {1, 2, 3, 4, 7, 8, 4, 10};
    vector<int> v3 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> v4 = {1, 2, 3};

    // Находит первую пару несовпадающих элементов
	auto diff_value = mismatch(v1.begin(), v1.end(), v2.begin());
    cout << *diff_value.first << " " << *diff_value.second<<endl;

    // Находит первую пару элементов, не соответствующих условию
    auto diff_if = mismatch(v1.begin(), v1.end(), v2.begin(), 
        [](const int &x, const int &y){return x % 2 == y % 2;});
    cout << *diff_if.first << " " << *diff_if.second<<endl;

    // Не находит первую пару несовпадающих элементов
    auto no_diff = mismatch(v1.begin(), v1.end(), v3.begin());
    if (no_diff.first == v1.end() && no_diff.second == v3.end())
        cout << "Последовательности равны"<<endl;

    // Проверяет последовательности разные по длине
    auto diff = mismatch(v1.begin(), v1.end(), v4.begin());
    if (diff.first == v1.end() || diff.second == v4.end())
        cout << "Последовательности разные по длине"<<endl;
}