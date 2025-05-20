#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(vector<int> v) {
    for (auto x : v) cout << x << " ";
    cout << endl;
}

int main() {
	vector<int> v = {21, 753, 6232, 48, 39};
	// Сортировка по убыванию
	sort(v.begin(), v.end(), [] (const int& a, const int&b) {
		return a > b;
	});
    print(v);
    // Сортировка по возрастанию последней цифры
	sort(v.begin(), v.end(), [] (const int& a, const int&b) {
		return a % 10 < b % 10;
	});
	print(v);
}