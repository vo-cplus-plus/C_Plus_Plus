#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

class FrontMiddleBackQueue {
    deque<int> left;
    deque<int> right;
public:
    FrontMiddleBackQueue() {}  

    void shiftRight(){
        if (right.size() < left.size()){
            int temp = left.back();
            left.pop_back();
            right.push_front(temp);
        }
    }  
    void shiftLeft(){
        if (right.size() - left.size() > 1){
            int temp = right.front();
            right.pop_front();
            left.push_back(temp);
        }
    }
    
    void pushFront(int val) {
        left.push_front(val);        
        shiftRight();       
    }
    
    void pushMiddle(int val) {
        if (left.size()==right.size())
            right.push_front(val);
        else left.push_back(val);
    }
    
    void pushBack(int val) {
        right.push_back(val);        
        shiftLeft();       
    }
    
    int popFront() {
        if (left.size() == 0 && right.size() == 0) return -1;        
        if (left.size() == 0) {
            int temp = right.front();
            right.pop_front();
            return temp;}
        int temp = left.front();
        left.pop_front();        
        shiftLeft();
        return temp;
    }
    
    int popMiddle() {
        int temp;
        if (right.size() > left.size()){
            temp = right.front();
            right.pop_front();            
        }
        else{
            temp = left.back();
            left.pop_back();
        }
        return temp;
    }
    
    int popBack() {
        if (left.size() == 0 && right.size() == 0) return -1;        
        int temp = right.back();
        right.pop_back();        
        shiftRight();                
        return temp;
    }
};

int main(){
 int val = 7;
  FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
  obj->pushFront(1);
  obj->pushBack(2);
  obj->pushMiddle(3);
  obj->pushMiddle(4);
  int param_4 = obj->popFront();
  int param_5 = obj->popMiddle();
  int param_5_1 = obj->popMiddle();
  int param_6 = obj->popBack();
  int param_7 = obj->popFront();
 return 0;
}
