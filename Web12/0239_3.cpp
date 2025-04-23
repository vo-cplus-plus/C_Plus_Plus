#include <vector>
#include <queue>
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
        vector<int> res(n - k + 1); 
        // запоминаем индексы элементов в окне
        deque<int> window;
  
        for (int i = 0; i < n; ++i) { // хотим включить в рассмотрение nums[i]
            // удаляем слева элементы за пределами окна
            while (window.size() > 0 && window.front() <= i - k) {
                window.pop_front();
            }
            // пока справа есть элементы, меньше, чем включаемый, удаляем их
            while (window.size() > 0 && nums[window.back()] < nums[i]) {
                window.pop_back();
            }
            // добавляем индекс nums[i]
            window.push_back(i);
            // слева в окне гарантировано самый большой элемент
            if (i >= k - 1) {
                res[i - k + 1] = nums[window.front()];
            }
        }        
        return res;
    }
};

int main(){
    Solution s;
    vector<int> v({1,3,-1,-3,5,3,6,7});
    auto res = s.maxSlidingWindow(v, 4);
    return 0;
}