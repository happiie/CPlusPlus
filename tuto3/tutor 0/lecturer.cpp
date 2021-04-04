#include "lecturer.h"
#include <iostream>
#include <string>

using namespace std;

lecturer :: lecturer(string m,string p)
{
    nameh=m;
    position=p;
}

lecturer :: lecturer()
{

}

string lecturer :: getnameh()
{
    return nameh;
}

string lecturer :: getposition()
{
    return position;
}

void lecturer :: setposition(string p)
{
    position=p;
}

void lecturer :: setnameh(string n)
{
    nameh=n;
}
