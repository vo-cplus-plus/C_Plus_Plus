#include <vector>
#include <algorithm>
#include <iostream>
int main(){
    std::vector<int> v ({32, 71, 12, 4, 5, 26, 80, 53, 33});                
    std::sort (v.begin(), v.end());
    std::for_each(v.begin(), v.end(), [](int value){std::cout << value << " "; });
}