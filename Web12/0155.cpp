#include <algorithm>
using namespace std;
class MinStack {
    struct Node{int key, min; Node*next, *prev;};
    Node *last;    
public:
    MinStack() {
        last = nullptr;         
    }
    
    void push(int val) {
        if (last){
            Node * node = new Node{val, min(last->min, val), nullptr, last};
            last->next = node;
            last = node;
        }
        else{
            last = new Node{val, val, nullptr, nullptr};
        }
    }
    
    void pop() {
        if (!last) return;
        Node *toDelete = last;
        last = last->prev;
        if (last) last->next = nullptr;
        delete toDelete;
    }
    
    int top() {
        if (last) return last->key;
        return -1;
    }
    int getMin() {
        if (last) return last->min;
        return -1;
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