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

class Vector: public IVector{
    int *data;
    int size;
    int capacity;

public:
    Vector(){
        capacity = 10;
        size = 5;
        data = new int[capacity]{1,2,3,4,5};
    }
    // реализуем правило пяти
    Vector(const Vector& v){
        size = v.size;
        capacity = v.capacity;
        data = new int[capacity];
        for(int i=0; i<size; i++){
            data[i] = v.data[i];
        }
    }
    Vector(Vector&& v){
        size = v.size;
        capacity = v.capacity;
        data = new int[capacity];
        for(int i=0; i<size; i++){
            data[i] = v.data[i];
        }
        v.data = nullptr;
    }
    friend void swap(Vector & v1, Vector &v2){
        std::swap(v1.size, v2.size);
        std::swap(v1.capacity, v2.capacity);
        std::swap(v1.data, v2.data);
    }
    Vector& operator = (const Vector& v){
        Vector local_copy = v;
        swap(*this, local_copy);
        return *this;
    }
    Vector& operator = (Vector&& v){
        Vector local_copy = v;
        swap(*this, local_copy);
        v.data = nullptr;
        return *this;
    }
    virtual ~Vector(){
        if (data) delete[] data;
    }
    void reserve(int new_capacity){
        if (capacity == new_capacity) return;
        capacity = new_capacity;
        int *tmp = new int[capacity];
        for(int i=0; i<size; i++) tmp[i] = data[i];
        delete[] data;
        data = tmp;
    }
    // упрощенная функциональность дека
    void push_back(int value) override{
        if (size == capacity){
            if (capacity) capacity *= 2;
            else capacity = 10;
            int *tmp = new int[capacity];
            for(int i=0; i<size; i++) tmp[i] = data[i];
            delete[] data;
            data = tmp;
        }
        data[size++] = value;        
    }
    void pull_back() override{
        if(size == 0) return;
        size--;
    }
    void push_front(int value) override{
        if (capacity == size) reserve(capacity?capacity * 2: 10);
        for(int i=size; i > 0; i--){
            data[i] = data[i - 1];
        }
        data[0] = value;
        size++;
        // 1 2 3 4 5 10 10 10 10 10 10 10 10 10
        // 20  7(R)            (L)1 2 3 4 5 10 10 10 10 10 10 10 10 10|
    }
    void pull_front() override{
        size--;
        for(int i=0; i > size; i++){
            data[i] = data[i + 1];
        }
    }

    friend ostream& operator << (ostream & out, const Vector&v){
        for(int i=0; i<v.size; i++){
           out <<  v.data[i] << " ";
        }
        out << endl;
        return out;
    }

    void print() override{
        for(int i=0; i < size; i++){
           cout <<  data[i] << " ";
        }
        cout << endl;        
    }
};

class A{
    int *data;
};


int main(){   
    IVector *v = new Vector;

    for(int i=0; i<10; i++){
        v->push_back(10);
        v->push_front(-10);   
    } 
    v->print();
    v->pull_back();
    v->pull_front();
    v->print();
    /*Vector v1(v);
    Vector *p = &v1;
    Vector *p1 = new Vector(v);
    delete p1;*/
}