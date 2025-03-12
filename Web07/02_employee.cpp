#include <string>
#include <sstream>
#include "02_date.h"
using std::string, std::stringstream, std::ostream;



class Employee{
    string name;
    Date birth;    
    double salary;
    string job;
public:
    Employee(){}
    Employee(string name, Date date, double salary, string job):name(name), birth(date),
    salary(salary), job(job){}
    Employee(string line);
    Employee(const Employee & employee){}
    Employee(Employee && employee){}
    string get_info() const{return name + " " + job;}
    void salary_increase(double rise){salary += rise;}
    void promotion(string position){job = position;}
    // внутренний оператор
    bool operator > (const Employee & employee) const;
    // внешний оператор 
    friend ostream& operator << (ostream & out, Employee employee);
};


int main(){
    Employee head{"Орлов А.А.", Date(1,1,1970), 120000.0, "Зав.лаб"};
    Employee engineer{"Иванов И.И.", Date(2,5,1990), 50000.0, "Инженер"};
    Employee programmer{"Петров П.П.", Date(23,11,1997), 95000, "Программист"};
    Employee assistant("Сидоров С.С.;01.01.1997;30000;Лаборант");
    
}

Employee::Employee(string line){
    string temp_salary, temp_birth;
    stringstream line_stream(line);
    getline(line_stream, name, ';');
    getline(line_stream, temp_birth, ';');
    int day = stoi(temp_birth.substr(0,2));
    int month = stoi(temp_birth.substr(3,2));
    int year = stoi(temp_birth.substr(6,4));
    birth = Date(day, month, year);    
    getline(line_stream, temp_salary, ';');
    salary = stof(temp_salary);
    getline(line_stream, job);
}
