#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>
using namespace std;

class MyClass {
    shared_ptr<vector<int>> resource;    
public:
    MyClass(initializer_list<int> data){
        resource = make_shared<vector<int>>(data.size());
        copy(data.begin(), data.end(), resource->begin());
    }
    MyClass(const MyClass& obj){
        resource = make_shared<vector<int>>(obj.resource->size());
        copy(obj.resource->begin(), obj.resource->end(), resource->begin());
    }
    MyClass& operator=(MyClass other) { // для other работает контсруктор копирования
        swap(*this, other);
        return *this;
    }
    friend void swap(MyClass& a, MyClass& b) {
        swap(a.resource, b.resource);
    }
    void print(){
        for_each(resource->begin(), resource->end(), [](const int &x){cout << x << " ";});
        cout << endl;
    }
};

int main(){
    MyClass a({1,2,3}), b({3,2,1});
    a.print();
    a = b;
    a.print();
    return 0;
}