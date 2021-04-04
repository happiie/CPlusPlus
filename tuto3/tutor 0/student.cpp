#include<iostream>
#include "student.h"

using namespace std;

student :: student(string n,string i,int m)
{
    setnames(n);
    setid(i);
    setmark(m);
    setgrade(m);

}

student :: student()
{
  cout<<"Enter student's name:";
  cin>>names;
  cout<<"Enter student's ID:";
  cin>>id;
  srand(time(0));
  mark=rand()%101;
  setgrade(mark);
}

string student :: getnames()
{
    return names;
}

string student :: getid()
{
    return id;
}

int student :: getmark()
{
    return mark;
}

string student :: getgrade()
{
    return grade;
}

void student :: setnames(string a)
{
    names=a;
}

void student :: setid(string i)
{
    id=i;
}

void student :: setmark(int m)
{
    mark=m;
}

void student :: setgrade(int m)
{
    if(m>=90)
        grade="A+";
    else if(m>=80 && m<90)
        grade="A";
    else if(m>=75 && m<80)
        grade="A-";
        else if(m>=70 && m<75)
        grade="B+";
        else if(m>=65 && m<70)
        grade="B";
        else if(m>=60 && m<65)
        grade="B-";
        else if(m>=55 && m<60)
        grade="B";
        else if(m>=50 && m<55)
        grade="C+";
        else if(m>=45 && m<50)
        grade="C-";
        else if(m>=40 && m<45)
        grade="C+";
        else if(m>=35 && m<40)
        grade="D";
        else
        grade="F";
}
