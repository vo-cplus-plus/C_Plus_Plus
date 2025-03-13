#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

void get_values(const string& line, string &name, string& birth, double& salary, string& job);
string convert_date(const string &date);

int main(){
    ifstream input("data 01.csv");
    ofstream output("res 02.txt");
    string line;
    string richest_person;
    double max_salary = 0;
    while(getline(input, line)){
        string name, birth, job;
        double salary;        
        get_values(line, name, birth, salary, job);
        output << setw(20) << right << name;
        output << setw(25) << right << job;
        output <<" " << fixed << setw(9) << setprecision(2) << left << salary ;
        output <<setw(30) << right << convert_date(birth) << endl;
    }
}

void get_values(const string& line, string &name, string& birth,double & salary,string& job){
    string temp_salary;
    stringstream line_stream(line);
    getline(line_stream, name, ';');
    getline(line_stream, birth, ';');
    getline(line_stream, temp_salary, ';');
    salary = stof(temp_salary);
    getline(line_stream, job);

}

void get_date(const string &date, int &day, int &month, int &year){
    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(3, 2));
    year = stoi(date.substr(6, 4));
}

string convert_date(const string &date){
    int day, month, year;
    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(3, 2));
    year = stoi(date.substr(6, 4));    
    static const string months[]{"€нвар€", "феврал€", "марта", "апрел€", "ма€",
     "июн€", "июл€", "августа", "сент€бр€", "окт€бр€", "но€бр€", "декабр€"};
    
    stringstream res;
    res << setw(2) << setfill('0') << day << " ";
    res << months[month - 1] << " ";
    res << setw(4) << year << " ";
    return res.str();
}