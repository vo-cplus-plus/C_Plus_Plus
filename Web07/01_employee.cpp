#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

class Employee{
    string name;
    int year_of_birth;    
    double salary;
    string job;
public:
    Employee(){}
    Employee(string name, int year, double salary, string job):name(name), year_of_birth(year),
    salary(salary), job(job){}
    Employee(string line);
    Employee(const Employee & employee){}
    Employee(Employee && employee){}
    string get_info() const{return name + " " + job;}
    void salary_increase(double rise){salary += rise;}
    void promotion(string position){job = position;}
    // внутренний оператор
    bool operator > (const Employee & employee) const{
        // ?????????????????????
        return true;
    }
    // внешний оператор 
    friend ostream& operator << (ostream & out, Employee employee){
        // ???????????????
        return out;
    }
};


int main(){
    Employee head{"Орлов А.А.", 1970, 120000.0, "Зав.лаб"};
    Employee engineer{"Иванов И.И.", 1990, 50000.0, "Инженер"};
    Employee programmer{"Петров П.П.", 1997, 95000, "Программист"};
    Employee assistant("Сидоров С.С.;01.01.1997;30000;Лаборант");
    
}

Employee::Employee(string line){
    string temp_salary, temp_birth;
    stringstream line_stream(line);
    getline(line_stream, name, ';');
    getline(line_stream, temp_birth, ';');
    year_of_birth = stoi(temp_birth.substr(6,4));    
    getline(line_stream, temp_salary, ';');
    salary = stof(temp_salary);
    getline(line_stream, job);
}