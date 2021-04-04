#include "Snake.h"
#include <iostream>

using namespace std;

Snake::Snake()
{

}

void Snake::die()
{
    survive=false;
}

bool Snake::getSurvive()
{
    return survive;
}

int Snake::checkMouse1(char arr[20][20],int y,int x)
{
    if(arr[y][x-1]=='O')
        return 1;
    if(arr[y-1][x]=='O')
        return 2;
    if(arr[y][x+1]=='O')
        return 3;
    if(arr[y+1][x]=='O')
        return 4;
    else
        return 0;
}

int Snake::checkMouse2(char arr[20][20],int y,int x)
{
    if(arr[y][x+1]=='O')
        return 3;
    if(arr[y+1][x]=='O')
        return 4;
    if(arr[y][x-1]=='O')
        return 1;
    if(arr[y-1][x]=='O')
        return 2;
    else
        return 0;
}

int Snake::checkMouse3(char arr[20][20],int y,int x)
{
    if(arr[y+1][x]=='O')
        return 4;
    if(arr[y][x+1]=='O')
        return 3;
    if(arr[y-1][x]=='O')
        return 2;
    if(arr[y][x-1]=='O')
        return 1;
    else
        return 0;
}

int Snake::checkMouse4(char arr[20][20],int y,int x)
{
    if(arr[y-1][x]=='O')
        return 2;
    if(arr[y][x-1]=='O')
        return 1;
    if(arr[y+1][x]=='O')
        return 4;
    if(arr[y][x+1]=='O')
        return 3;
    else
        return 0;
}

int Snake::checkMouse5(char arr[20][20],int y,int x)
{
    if(arr[y][x-1]=='O')
        return 1;
    if(arr[y][x+1]=='O')
        return 3;
    if(arr[y-1][x]=='O')
        return 2;
    if(arr[y+1][x]=='O')
        return 4;
    else
        return 0;
}

int Snake::checkMouse6(char arr[20][20],int y,int x)
{
    if(arr[y-1][x]=='O')
        return 2;
    if(arr[y+1][x]=='O')
        return 4;
    if(arr[y][x-1]=='O')
        return 1;
    if(arr[y][x+1]=='O')
        return 3;
    else
        return 0;
}

int Snake::checkMouse7(char arr[20][20],int y,int x)
{
    if(arr[y][x-1]=='O')
        return 1;
    if(arr[y-1][x]=='O')
        return 2;
    if(arr[y+1][x]=='O')
        return 4;
    if(arr[y][x+1]=='O')
        return 3;
    else
        return 0;
}

int Snake::checkMouse8(char arr[20][20],int y,int x)
{
    if(arr[y][x-1]=='O')
        return 1;
    if(arr[y+1][x]=='O')
        return 4;
    if(arr[y][x+1]=='O')
        return 3;
    if(arr[y-1][x]=='O')
        return 2;
    else
        return 0;
}

void Snake::setZeroStarve()
{
    starve=0;
}

void Snake::setStarve()
{
    if(starve==3)
        starve=1;
    else
        starve++;
}

int Snake::getStarve()
{
    return starve;
}

void Snake::setBreed()
{
    if(breed==5)
        breed=1;
    else
        breed++;
}

int Snake::getBreed()
{
    return breed;
}

void Snake::send(int a)
{
    place=a;
}

int Snake::get()
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

bool Snake::check()
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

bool Snake::checkAll()
{
    if(one==true&&two==true&&three==true&&four==true)
        return true;
}

void Snake::reset()
{
    one=false;
    two=false;
    three=false;
    four=false;
    eat=true;
}
