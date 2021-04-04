#include "student.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

student::student()
{
    cout << "Enter Student name: " ;
    cin >> Sname;
    cout << "Enter Student Id: " ;
    cin >> SId;

    srand(time(0));
    Smark = rand()%101;
    setgrade(Smark);

}

void student::setname(string name)
{
    Sname = name;
}

void student::setId(string Id)
{
    SId = Id;
}

void student::setmark(int mark)
{
    Smark = mark;
}

void student::setgrade(int mark)
{
    if(mark>=90)
        Sgrade="A+";
    else if(mark>=80 && mark<90)
        Sgrade="A";
    else if(mark>=75 && mark<80)
        Sgrade="A-";
        else if(mark>=70 && mark<75)
        Sgrade="B+";
        else if(mark>=65 && mark<70)
        Sgrade="B";
        else if(mark>=60 && mark<65)
        Sgrade="B-";
        else if(mark>=55 && mark<60)
        Sgrade="B";
        else if(mark>=50 && mark<55)
        Sgrade="C+";
        else if(mark>=45 && mark<50)
        Sgrade="C-";
        else if(mark>=40 && mark<45)
        Sgrade="C+";
        else if(mark>=35 && mark<40)
        Sgrade="D";
        else
        Sgrade="F";
}

string student::getname()
{
    return Sname;
}

string student::getId()
{
    return SId;
}

int student::getmark()
{
    return Smark;
}

string student::getgrade()
{
    return Sgrade;
}


