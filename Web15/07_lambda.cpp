#include <vector>
#include <iostream>
using namespace std;

void print(vector<int> v) {
    for (auto x : v) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> v1, v2;    
    auto push_ref = [&] (int m) {
        v1.push_back(m); // добавит значение
        v2.push_back(m); // добавит значение
    };    
    auto push_val = [=] (int m) mutable {
        v1.push_back(m); // игнорирует
        v2.push_back(m); // игнорирует
    };
    auto push_mixed = [v1, &v2] (int m) mutable {
        v1.push_back(m); // игнорирует
        v2.push_back(m); // добавит значение
    };    
    push_ref(1);
    push_val(2);
    push_mixed(3);
    
    print(v1);  // 1
    print(v2);  // 1, 3
}
