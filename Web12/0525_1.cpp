#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(2 * n + 1, numeric_limits<int>::min());
        temp[n] = -1; // для значения sum = 0       
        int maxLen = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (nums[i] ? 1 : -1);
            if (temp[sum + n] >= -1)  maxLen = max(maxLen, i - temp[sum + n]);
            else  temp[sum + nums.size()] = i; 
        }
        return maxLen;
    }
};

int main(){
    vector<int> nums({0,1,1,1,1,0,0,1,1,0,0,0,1});
    Solution s;
    cout << "Длина максимальной последовательности:" << s.findMaxLength(nums) << endl;
}