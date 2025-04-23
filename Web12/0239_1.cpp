#include <vector>

#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0) {
            return vector<int>();
        }
        int n = nums.size();
        auto lastWindow = nums.begin() + n - k + 1;
        vector<int> res(n - k + 1);          
        
        for(auto first = nums.begin(), cur = res.begin(); first != lastWindow; first++, cur++) {
            priority_queue<int> pq(first, first + k); 
            *cur = pq.top();                       
        } 
        return res;
    }
};

int main(){
    Solution s;
    vector<int> v({-7,-8,7,5,7,1,6,0});
    auto res = s.maxSlidingWindow(v, 4);
    return 0;
}