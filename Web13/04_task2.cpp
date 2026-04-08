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

    unordered_map<string, int> res({
        {"vector", count(vect.begin(), vect.end(), 10)},
        {"multiset", count(ms.begin(), ms.end(), 10)},
        {"list", count(l.begin(), l.end(), 10)},
        {"set", count(s.begin(), s.end(), 10)}
    });
    cout << "Подсчет количества 10 в:\n";
    for(auto record: res){
        cout << record.first << ": " << record.second<< endl;
    }     
    return 0;
}