#include <string>
using namespace std;


# ifndef DATE_H
# define DATE_H


class Date{
public:
    Date(); //  default constructor
    Date(int, int, int);
    int getDay();
    int getYear();
    int getMonth();
    void setDay(int);
    void setYear(int);
    void setMonth(int);
    double diff(Date);
    string toString() const;


private:
    int year;
    int month;
    int day;
};

#endif