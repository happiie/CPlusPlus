#include "Class2.h"
#include <iostream>
using namespace std;

void Class2::setpro2(int x)
{
    pro1 = x;
}
int Class2::getpro2()
{
    return pro2;
}
void Class2::display2()
{
    //cout<<"This from Class2 :-"<<endl;
    Class1::display1();
    cout<<"\nTHIS IS PROTECTED 2 "<<endl;
}
