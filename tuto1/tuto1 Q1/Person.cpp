#include "Person.h"
#include <string>

using namespace std;


Person::Person()
{
    //ctor
}

Person::Person(string a)
{
    setName(a);
}

Person::~Person()
{
    //dtor
}

void Person::setName(string b)
{
    name = b;
}

string Person::getName()
{
    return name;
}
