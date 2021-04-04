#include "Class4.h"
#include <iostream>
using namespace std;

void Class4::setpro4(int x)
{
    pro1 = x;
}
int Class4::getpro4()
{
    return pro4;
}
void Class4::display4()
{
    //cout<<"This from Class4 :-"<<endl;
    Class1::display1();
    Class2::display2();                //how to call function from other class
    cout<<"\nTHIS IS PROTECTED 4 "<<endl;
}
