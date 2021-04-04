#include<iostream>
#include<string>
#include "core.h"
#include "course.h"
#include "student.h"
#include "lecturer.h"

using namespace std;

core :: core(course co,lecturer lo)

{
    c1=co;
    l1=lo;


}

void core ::print()

{
    display(c1);
    cout<<"Lecturer : "<<l1.getnameh()<<"   Position : "<<l1.getposition()<<endl;
    for(int i=0;i<10;i++)
    {
       cout<<i+1<<")"<<s[i].getnames()<<" || "<<s[i].getid()<<" || "<<s[i].getmark()<<"("<<s[i].getgrade()<<")"<<endl;
    }
}

void core :: getl()
{
    cout<<"Lecturer : "<<l1.getnameh()<<"   Position : "<<l1.getposition()<<endl;
}

void core :: getc()
{
    display(c1);
}


