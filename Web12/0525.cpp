#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        long long maxLen = 0;                
        for (auto start = nums.cbegin(); start != nums.cend(); start++) {
            int zeroes = 0, ones = 0;
            for (auto end = start + 1; end !=  nums.cend(); end++) {
                *end ? ones++: zeroes++;                
                if (zeroes == ones) {
                    maxLen = max(maxLen, end - start + 1);
                }
            }
        }
        return maxLen;
    }
};

int main(){
    vector<int> nums({0,1,1,1,1,0,0,1,1,0,0,0,1});
    Solution s;
    cout << "Длина максимальной последовательности:" << s.findMaxLength(nums) << endl;
}
    