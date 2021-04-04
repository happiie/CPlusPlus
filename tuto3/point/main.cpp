#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    Point p1(2.5,2.4,5.9),p2,p3;
    cout<< "Enter p2 (a,b,c): ";
    cin>>p2;
    p3=p1+p1;

    Point p4=p1+p2+p3;

    double distance=p4%p1;

    cout<<p1<<", "<<p2<<", "<<p3<<", "<<p4<<endl;
    cout<<"Distance p4-p1: "<<distance<<endl;

    cout<< p1+p4<<endl;
    p1++;
    cout<<"p1++: "<<p1<<endl;
    ++p1;
    cout<<"++p1: "<<p1<<endl;
    return 0;
}
