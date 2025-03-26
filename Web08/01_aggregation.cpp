#include <vector>
#include <string>
#include <iostream>
#include <chrono>
using namespace std;

class Company;
class Employee{
    Company *company;
    string name;
    string department;
    string passport;    
public:
    Employee(string name, string passport):name(name), passport(passport){}
    friend ostream & operator << (ostream & out, const Employee&employee){
        out << employee.name << " работает в отделе " << employee.department;
        return out;
    }
    void setDepartment(string department){
        this->department = department;
    }
    void setCompany(Company *company){
        this->company = company;
    }
    Company& getCompany(){return *company;}
};


class Company{
    string name;
    vector<Employee> employees;
public:
    Company(const string name):name(name){}
    vector<Employee>& getEmployees(){return employees;}
    void addEmployee(Employee &&employee, string department){
        employee.setCompany(this);
        employee.setDepartment(department);
        employees.push_back(employee);
    }
    string& Name(){return name;}
};

int main(){
    Company company("НПО");
    company.addEmployee(Employee("Иванов ИИ", "1111 111111"), "Отдел #1");
    company.addEmployee(Employee("Петров ИИ", "1111 222222"), "Отдел #2");
    cout << company.Name() <<":\n";
    for (auto& employee : company.getEmployees()){
        cout << employee << " в " << employee.getCompany().Name()<< endl;
    }
}