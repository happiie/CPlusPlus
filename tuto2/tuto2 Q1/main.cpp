#include <iostream>
#include "truck.h"
#include "person.h"
#include "vehicle.h"
using namespace std;

int main()
{
    person p1("catdog kucing");
    cout<<p1<<endl;
    p1.setName("tiger harimau");
    cout<<p1<<"\nEnter new name:";
    cin>>p1;
    cout<<p1<<endl;
    person p2=p1;
    cout<<"p2:"<<p2<<endl<<endl;

    truck t1(20,30);
    t1.setOwner("Ali");
    t1.setCyl(2017);
    cout<<"Enter loadCap and towCap with format (a,b):";
    cin>>t1;
    cout<<t1;

    return 0;
}
