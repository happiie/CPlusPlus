#include<iostream>
#include "course.h"

using namespace std;

course :: course()
{

}

course :: course(string n,string c)
{
    namec=n;
    code=c;
}

string course :: getnamec()
{
    return namec;
}

void course :: setnamec(string n)
{
    namec=n;
}

string course :: getcode()
{
    return code;
}

void course :: setcode(string c)
{
    code=c;
}

course :: ~course()
{

}
