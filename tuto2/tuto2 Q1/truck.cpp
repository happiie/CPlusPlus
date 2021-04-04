#include "truck.h"
#include<iostream>

using namespace std;

truck::truck()
{
    loadCap=0;
    towCap=0;
}

truck::truck(int a,int b)
{
    loadCap=a;
    towCap=b;
}

truck::truck(const truck &t)
{
    loadCap=t.loadCap;
    towCap=t.towCap;
}

void truck::setLoad(int a)
{
    loadCap=a;
}

void truck::setTow(int b)
{
    towCap=b;
}

int truck::getLoad()
{
    return loadCap;
}

int truck::getTow()
{
    return towCap;
}

ostream& operator<< (ostream& os,truck& t)
{
    os << "Manufacturer name: " << t.getManu() << "\nCylinders: " << t.getCyl() << "\nOwner: " << t.getOwner();
    os << "\nLoad capacity: " << t.loadCap << "\nTow capacity: " << t.towCap ;
    return os;
}

istream& operator>> (istream& is,truck &t)
{
    char ch;
    is >> ch >> t.loadCap >> ch >> t.towCap >> ch ;
    return is;
}

