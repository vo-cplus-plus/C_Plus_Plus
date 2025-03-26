#include <vector>
#include <string>
#include <iostream>
#include <chrono>
using namespace std;

struct Date{
    int d,m,y;
};

class Person{
    string name;
    Date birth;
public:
    Person(const string &name, const Date& date):
    name(name), birth(date){}
    string getName() const{return name;}
};

class Employee: public Person{
    float salary;
    string position;
public:
    Employee(const string &name, const Date& date, float salary, string pos):
    Person(name, date), salary(salary), position(pos){}
    float getSalary() const{return salary;}
};

class Student: public Person{
    vector<int> grades;
public:
    Student(const string &name, const Date& date):Person(name, date){}
    void addGrade(int grade){grades.push_back(grade);}    
};

class Retiree: public Person{
    float pension;
public:
    Retiree(const string &name, const Date& date):Person(name, date),pension(20000){}
    float getPension() const{return pension;}    
};

int main(){
    Person person("Someone", Date{1,1,1990});
    Employee worker("Ivanov", Date{1,1,1990}, 35000, "Worker");
    Student student("Petrov", Date{1,1,2006});
    cout << worker.getName() << " " << student.getName()<<endl;
    student.addGrade(5);
}