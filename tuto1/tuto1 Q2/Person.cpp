#include "Person.h"
#include <string>
using namespace std;
Person::Person()
{
    //ctor
}

 Person::Person(string )
 {

 }

Person::Person(const Person& p)
{
    name=p.name;
}

void Person::setName(string n)
{
    name=n;
}

string Person::getName()
{
    return name;
}

Person::~Person()
{
    //dtor
}


