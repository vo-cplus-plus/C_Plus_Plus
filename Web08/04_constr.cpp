#include <cstring>
class Person{
    char *name;
public:
    Person(const char * name){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);  
        return;      
    }
    virtual ~Person(){
        delete[]name;
    }
};

class Employee:public Person{
    char *position;
public:
    Employee(const char * name, const char*position):Person(name){
        this->position = new char[strlen(position) + 1];
        strcpy(this->position, position);        
    }
    virtual ~Employee(){
        delete[] position;
    }
};

int main(){
    Employee employee("Ivanov", "Worker");    
}