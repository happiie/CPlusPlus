#include "person.h"
#include "date.h"
#include <iostream>
using namespace std;

person::person(string n, date d)  //ctor
{
    name = n;
    doBirth = d;
}
void person::setName(string n)
{
    name = n;
}
void person::setDOB(date d)
{
    doBirth = d;
}
string person::getName()
{
    return name;
}
date person::getDOB()
{
    return doBirth;
}
void person::display()
{
    cout<<getName()<<endl;
    doBirth.display();
}
