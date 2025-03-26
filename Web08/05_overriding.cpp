#include <string>
#include <sstream>
#include <iostream>
using namespace std;

struct Date{
    int d,m,y;
    string toString(){
        stringstream s;
        s << d <<"." <<m<<"."<<y;
        return s.str();
    }
};

class Person{
    string name;
    Date birth;
public:
    Person(const string &name, const Date& date):
                            name(name), birth(date){}
    string getName() const{return name;}
    virtual string getInfo(){
        return name + " " + birth.toString();
    }
};

class Employee: public Person{
  float salary;
  string position;
public:
  Employee(const string &name, const Date& date,
             float salary, string pos):
  Person(name, date), salary(salary), position(pos){}
  float getSalary() const{return salary;}
  string getInfo() override{
        return Person::getInfo() + " " + position;
    }
};


int main(){

    //typeid(type) или typeid(expression)
    
    Person person("Petrov", Date{1,1,2000});    
    Employee employee("Ivanov", Date{1,1,1990}, 35000, "Worker");
    cout << person.getInfo() << "\n" << employee.getInfo() <<endl;

    Person * someone = new Person ("Petrov", Date{1,1,2000}); 
    Person * worker = new Employee ("Ivanov", Date{1,1,1990}, 35000, "Worker");
    cout << someone->getInfo() << "\n" << worker->getInfo() <<endl;
    delete someone;
    delete worker;
}