#include <set>
#include <list>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <memory>
using namespace std;

int main() {
    vector<int> data({5, 10, 15, 12, 7, 8, 10, 11, 6});
    vector<int> res(data.size(), 0);
  	multiset<int> ms;
    for(auto itd = data.begin(), itr = res.begin(); itd!=data.end(); itd++, itr++){
        ms.insert(*itd);
        auto it = ms.find(*itd);
        *itr = distance(ms.begin(), it);
    }

    for(auto itd = data.begin(), itr = res.begin(); itd!=data.end(); itd++, itr++){
        cout << *itd << ":\t" << *itr << endl;
    }
    cout << endl;
}