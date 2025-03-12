#include <stdexcept>
#include <string>
using namespace std;

using Day = unsigned char;
using Month = unsigned char;
using Year = unsigned short;
class Date{
    Day day;
    Month month;
    Year year;
    static const inline int days_in_month[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    public:
    Date(Day day, Month month, Year year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        if (!correct()){
            throw runtime_error("Неправильные параметры");
        }        
    }       

    bool correct(){
        if (month < 1 || month > 12)
            return false;
        if (month == 2 && day == 29 && year % 4 == 0)
            return true;
        if (day < 1 && day > days_in_month[month - 1])
            return false;
        return true;
    }

    int get_days() const{
        int res = (year - 1900) * 365 + (year - 1900) / 4;
        for(int m = 0; m < month - 1; m++){
            res += days_in_month[m];
        }
        return res + day;
    }


    friend int operator - (const Date &d1, const Date &d2);
};

int leap(int year){
    return year / 4 - year / 100 +  year/ 400;
}

int operator - (const Date &d1, const Date &d2){
    // количество високосных лет на промежутке [d1, d2]
    int num_leap_years = leap(d1.year) - leap(d2.year - 1); 
    // количество дней между датами
    int days = d1.get_days() - d2.get_days();
    return (days - num_leap_years) / 365;
}

int main(){
    Date d1(19,3,2025), d2(20,5,1999);
    int res = d1 - d2;
    return 0;
}

