#include <algorithm>
#include <stack>
using namespace std;
class MinStack {
    stack<pair<int, int>> data;    
public:
    MinStack() {                 
    }
    
    void push(int val) {
        if (data.size() > 0)
            data.push({val,min(data.top().second, val)});        
        else
            data.push({val,val});
    }
    
    void pop() {
        data.pop();
    }
    
    int top() {
        return data.top().first;
    }
    int getMin() {
        return data.top().second;
    }
};

int main(){
  MinStack* obj = new MinStack();
  obj->push(3);
  obj->push(5);
 // obj->pop();
  int param_3 = obj->top();
  int param_4 = obj->getMin();
 return 0;
}