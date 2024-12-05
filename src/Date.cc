// Reference for calculate the difference between two days
// https://www.tutorialspoint.com/find-number-of-days-between-two-given-dates-in-cplusplus#:~:text=Count%20from%20month%20array.,1st%20date%20of%20the%20month.

#include "Entity_base.h"
#include "Date.h"
#include <string>
#include <iostream>
using namespace std;

Date::Date():month(1), day(1), year(2000){} // default constructor
Date::Date(int month,int day, int year){
    if ((month <= 12) && (day <= 31)){
        this->month = month;
        this->day = day;
        this->year = year;
    }else{
        throw invalid_argument("The month/day is out of scope.");
    }
}

int Date::getDay(){ return this->day;}
int Date::getMonth(){ return this->month;}
int Date::getYear(){ return this->year;}

void Date::setDay(int day) {
    if (day <= 31){
        this->day = day;
    }else{
        throw invalid_argument("The day is out of scope.");
    }
}
void Date::setMonth(int month) {
    if (month <= 12){
        this->month = month;
    }else{
        throw invalid_argument("The month is out of scope.");
    }
}
void Date::setYear(int year) {this->year = year;}

double Date::diff(Date other){
    const int monthDays[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    int dayCount1 = monthDays[this->getMonth() - 1];
    dayCount1 += this->getDay();

    int dayCount2 = monthDays[other.getMonth() - 1];
    dayCount2 += other.getDay();

    if (this->year > other.getYear()){
            return (dayCount1 - dayCount2 + 365*(this->year-other.getYear()));
        }else{
            return (dayCount2 - dayCount1 + 365*(other.getYear()-this->year));
    }
}

string Date::toString() const{
    return to_string(this->month) +'/'+ to_string(this->day) +'/'+ to_string(this-> year);
}

