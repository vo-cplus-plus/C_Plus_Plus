#include <iostream>
#include <algorithm>
using namespace std;

class IVector{
    public:
    virtual void push_back(int value)=0;
    virtual void push_front(int value)=0;
    virtual void pull_front()=0;
    virtual void pull_back()=0;
    virtual void print()=0;    
};

struct Node{
    int info;
    Node *next;
    Node *prev;
};

class LinkedVector: public IVector{
    Node *first;
    Node * last;

public:
    LinkedVector(){
        first = last = nullptr;
        for(int i=0; i<5; i++){
            push_back(i + 1);
        }
    }
    // реализуем правило пяти
    LinkedVector(const LinkedVector& v){
        for(Node * p = v.first; p; p=p->next){
            push_back(p->info);
        }
    }
    LinkedVector(LinkedVector&& v){
        for(Node * p = v.first; p; p=p->next){
            push_back(p->info);
        }
        v.first = v.last = nullptr;
    }
    friend void swap(LinkedVector & v1, LinkedVector &v2){
        std::swap(v1.first, v2.first);
        std::swap(v1.last, v2.last);        
    }
    LinkedVector& operator = (const LinkedVector& v){
        LinkedVector local_copy = v;
        swap(*this, local_copy);
        return *this;
    }
    LinkedVector& operator = (LinkedVector&& v){
        LinkedVector local_copy = v;
        swap(*this, local_copy);
        v.first = nullptr;
        return *this;
    }
    virtual ~LinkedVector(){
        while(first){
            Node *tmp = first;
            first = first->next;
            delete tmp;
        }
    }
   
    // упрощенная функциональность дека
    void push_back(int value) override{
        Node *node  = new Node{value, nullptr, last};
        if (last) last->next = node;
        else first = node;
        last = node; 
               
    }
    void pull_back() override{
        if (last){
            Node *tmp = last ;
            last = last->prev;
            delete tmp;
            if (!last) first  = last;
            else last->next = nullptr;
        }
        
    }
    void push_front(int value) override{
        Node *node  = new Node{value, first, nullptr};
        if (first) first->prev = node;
        else last = node;
        first = node;
    }
    void pull_front() override{
        if (first){
            Node *tmp = first ;
            first = first->next;
            delete tmp;
            if (!first) last  = first;
            else first->prev = nullptr;
        }
    }

    friend ostream& operator << (ostream & out, const LinkedVector&v){
        for(Node *p = v.first; p; p = p->next){
           out <<  p->info<< " ";
        }
        out << endl;
        return out;
    }

    void print() override{
        cout << *this;        
    }
};

class A{
    int *data;
};


int main(){   
    IVector *v = new LinkedVector;

    for(int i=0; i<10; i++){
        v->push_back(10);
        v->push_front(-10);   
    } 
    v->print();
    v->pull_back();
    v->pull_front();
    v->print();   
}