#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

template <typename T>
struct Node{
    T info;
    Node * next;
    Node * prev;
};

template <typename T>
class List{
    Node<T> *first;
    Node<T> *last;
public:    
    // создание пустого  списка 
    List(){    
        first = last = nullptr;    
    }
    List(initializer_list<T> list):List(){                       
       for(auto element:list){
            push_back(element);
       }         
    }

    bool isEmpty(){     
        return first==nullptr;   
    }
    
    void pull_back(){   
        if (last){
            Node<T> *temp = last; // запоминаем последний
            last = last->prev; // последним становится предыдущий
            delete temp;  // удаляем того, что был последним   
            // за последним элементом нет другого
            if (last) last->next = nullptr;
            else first = nullptr;
        }
    }
    void push_back(const T &info){ // добавляет элемент в список  
        Node<T> * node = new Node<T>{info, nullptr, last};
        if (!first) first = node;        
        else last->next = node;
        last = node;
    }
    friend ostream & operator<< (ostream & out, List &list)
    {      
        for(auto cur=list.first; cur; cur = cur->next){
            out << cur->info << " ";           
        }
        out << "\n"; 
        return out; 
    }
    ~List(){
        while(last){
            pull_back();
        }
    }
};

int main(){
    List<int> list({1,2,3,4,5});
    int value = 10;
    list.push_back(value);
    cout << list;
}