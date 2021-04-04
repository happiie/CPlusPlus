#include "date.h"
#include <iostream>
using namespace std;

date::date()   //ctor
{
    day = 1;
    month = 1;
    year = 2000;
}
date::date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}
void date::setDay(int d)
{
    day = d;
}
void date::setMonth(int m)
{
    month = m;
}
void date::setYear(int y)
{
    year = y;
}
int date::getDay()
{
    return day;
}
int date::getMonth()
{
    return month;
}
int date::getYear()
{
    return year;
}
void date::display()
{
    cout << "Date : " << day << " " << month << " " << year << endl;
}
