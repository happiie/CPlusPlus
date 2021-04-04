#include "person.h"

using namespace std;

person::person()
{
    name="no name input";
}

person::person(string n)
{
    setName(n);
}

person::person(const person &p)
{
    name=p.name;
}

string person::getName()
{
    return name;
}

void person::setName(string a)
{
    name=a;
}


ostream& operator<< (ostream& os, const person& p)
{
    os <<"NAME:"<< p.name ;
    return os;
}

istream& operator>> (istream& is, person& p)
{
    getline(is,p.name);
    return is;
}

person person::operator= (const person& p)
{
    return person(p.name);
}
