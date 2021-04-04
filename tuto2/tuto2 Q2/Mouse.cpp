#include "Mouse.h"
#include <iostream>

using namespace std;

Mouse::Mouse()
{

}

void Mouse::die()
{
    survive=false;
}

bool Mouse::getSurvive()
{
    return survive;
}

void Mouse::setBreed()
{
    if(breed==2)
        breed=1;
    else
        breed++;
}

int Mouse::getBreed()
{
    return breed;
}

void Mouse::send(int a)
{
    place=a;
}

int Mouse::get()
{
    if(place==1)
        one=true;
    else if(place==2)
        two=true;
    else if(place==3)
        three=true;
    else
        four=true;

    return place;
}

bool Mouse::check()
{
    if(place==1)
    {
        if(one==true)
            return true;
        else
            return false;
    }
    else if(place==2)
    {
        if(two==true)
            return true;
        else
            return false;
    }
    else if(place==3)
    {
        if(three==true)
            return true;
        else
            return false;
    }
    else
    {
        if(four==true)
            return true;
        else
            return false;
    }
}

bool Mouse::checkAll()
{
    if(one==true&&two==true&&three==true&&four==true)
        return true;
}

void Mouse::reset()
{
    one=false;
    two=false;
    three=false;
    four=false;
}
