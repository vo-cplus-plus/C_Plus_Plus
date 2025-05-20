#include <iostream>
#include <set>
#include <algorithm>
#include <random>


using namespace std;

int main() {    
    vector<int> v1(10), v2(10); 
    random_device rd;     
    mt19937 engine(rd());    
    uniform_int_distribution<int> int_dist(0, 10);

    generate(v1.begin(), v1.end(), 
        [&]() {return int_dist(engine);});
    generate(v2.begin(), v2.end(), 
        [&]() {return int_dist(engine);});

    set<int> s1(v1.begin(), v1.end()), s2(v2.begin(), v2.end());

       
    vector<int> res_merge, res_union, res_intersect,
               res_diff, res_sym;

    merge(s1.begin(), s1.end(), s2.begin(), s2.end(),
        back_inserter(res_merge)
    );  
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(),
        back_inserter(res_union)
    );  // 1, 1, 2, 3, 5, 5, 7    
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
        back_inserter(res_intersect)
    );  // 1, 3    
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),        
        back_inserter(res_diff)
    );  // 5, 5, 7    
    set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
        back_inserter(res_sym)
    );  // 1, 2, 5, 5, 7

    bool res = includes(s1.begin(), s1.end(), s2.begin(), s2.end());  // false
}