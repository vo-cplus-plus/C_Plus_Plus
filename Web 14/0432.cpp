
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class AllOne {
    map<string, int> words;
    map<int, vector<string>> nums;
public:
    AllOne() {
        
    }

    void remove(string key){
        auto& vec = nums[words[key]];
        auto to_remove = find(vec.begin(), vec.end(), key);
        nums[words[key]].erase(to_remove);
        if (nums[words[key]].size() == 0) nums.erase(words[key]);
    }
    
    void inc(string key) {
        if (words.find(key) != words.end()){
            remove(key);
            words[key]++;
        }
        else words[key] = 1;
        nums[words[key]].push_back(key);
    }
    
    void dec(string key) {
        remove(key);
        words[key]--;
        if (!words[key]) words.erase(key);
        else nums[words[key]].push_back(key);
    }
    
    string getMaxKey() {
        return nums.rbegin()->second.front();
    }
    
    string getMinKey() {
        return nums.begin()->second.front();
    }
};

int main(){
    AllOne allOne;
    allOne.inc("hello");
    allOne.inc("hello");
    allOne.inc("key");
    allOne.getMaxKey(); // return "hello"
    allOne.getMinKey(); // return "hello"
    allOne.inc("leet");
    string m1 = allOne.getMaxKey(); // return "hello"
    string m2 = allOne.getMinKey(); // return "leet"
    return 0;
}