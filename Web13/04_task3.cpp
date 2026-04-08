#include <set>
#include <list>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vect({30,25, 10, 44, 10, 58, 10, 15});
  	multiset<int> ms({30,25, 10, 44, 10, 58, 10, 15});
    list<int> l({30,25, 10, 44, 10, 58, 10, 15});
    set<int> s({30,25, 10, 44, 10, 58, 10, 15});

    sort(vect.begin(), vect.end());
    //sort(ms.begin(), ms.end());
    //sort(l.begin(), l.end());
    //sort(s.begin(), s.end());
    for(auto&x: vect) cout << x << " ";
    cout << endl;
}