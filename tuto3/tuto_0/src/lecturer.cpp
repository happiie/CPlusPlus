#include "lecturer.h"
#include <iostream>

using namespace std;

lecturer::lecturer()
{

}
lecturer::lecturer(string name ,string post)
{
    lectname = name;
    lectpost = post;
}

void lecturer::setname(string name)
{
    lectname = name;
}

string lecturer::getname()
{
    return lectname;
}

void lecturer::setposition(string post)
{
    lectpost = post;
}

string lecturer::getposition()
{
    return lectpost;
}

void lecturer::displayInfo()
{
    cout << "Lecturer: " << lectname << "(position: " << lectpost << ") " << endl;
}
