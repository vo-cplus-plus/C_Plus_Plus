#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;

// Задача. В массиве целых чисел, все числа до последнего максимума (включая)
// переписать в новый массив, возведя предварительно в квадрат
int main() {	
    vector<int> v = {1, 8, 8, 4, 5, 2, 3, 6, 7, 8, 1, 2, 3};   

    auto last_max = std::max_element(v.begin(), v.end(),
    [](const auto& a, const auto& b) {
        return a <= b;
    });  
    vector<int> res(last_max + 1 - v.begin());
    transform(v.begin(), last_max + 1, res.begin(), 
              [](int &x){return x * x;});
    for_each(res.begin(), res.end(), [](const int&x){cout << x << " ";});
    cout << endl;
}