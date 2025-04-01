#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
concept constructor = is_constructible_v<T, ostream&>;


template<typename T>
concept can_output =requires(const T& object){
    {cout << object};
};

template<typename Iter>
concept is_iterator = requires(Iter i) { ++i; };

template<typename T>
concept get_value = requires(T object) {
  { object.value() } -> std::same_as<int>;
};

template<typename T, typename V>
concept get_at = requires(T object, int i) {
  { object.at(i) } -> std::same_as<V>;
};


class Cube{/*TO DO*/};

class Person{/*TO DO*/};

class Vector{/*TO DO*/};

template <typename T>
string get_method(istream &in){
    string method;
    in >> method;
    if ((method == "get_at" && get_at<T, int>) ||
        (method == "get_value" && get_value<T>) ||
        (method == "can_output" && can_output<T>) ||
        (method == "is_iterator" && is_iterator<T>)){
        return method;
    }
    return "";
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");  
    string class_name;
    while(in >> class_name){
        if (class_name == "Vector"){  
            Vector v(in); 
            string method = get_method<Vector>(in);                     
            if (method!= "") v.execute(method, out);
            else out << "false";
        }
        else if (class_name == "Cube"){
            Cube cube(in); 
            string method = get_method<Cube>(in);                     
            if (method!= "") cube.execute(method, out);
            else out << "false";
        }else if (class_name == "Person"){
            Person person(in); 
            string method = get_method<Person>(in);                     
            if (method!= "") person.execute(method, out);
            else out << "false";
        }
        out << endl;        
    }     
}
