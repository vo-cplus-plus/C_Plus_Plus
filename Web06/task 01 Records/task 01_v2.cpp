#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <locale>
using namespace std;

void get_values(const string& line, string &name, string& birth, double& salary, string& job);

int main(){
    setlocale(LC_ALL, "Ru");
    ifstream input("data 01.csv");
    ofstream output("res 01.txt");
    string line;
    string richest_person;
    double max_salary = 0;
    while(getline(input, line)){
        string name, birth, job;
        double salary;        
        get_values(line, name, birth, salary, job);
        if (salary >= max_salary){
            max_salary = salary;
            richest_person = name;           
        } 
    }
    output << "Сотрудник с наибольшей з/п: " << richest_person <<endl;

}

void get_values(const string& line, string &name, string& birth, double& salary,string& job){
    string temp_salary;
    stringstream line_stream(line);
    getline(line_stream, name, ';');
    getline(line_stream, birth, ';');
    getline(line_stream, temp_salary, ';');
    salary = stof(temp_salary);
    getline(line_stream, job);
}