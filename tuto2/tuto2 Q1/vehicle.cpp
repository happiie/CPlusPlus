#include "vehicle.h"

vehicle::vehicle()
{
    ManuName="Proton";
    NoCylinder=10;
    Owner.setName("Myself");
}

vehicle::vehicle(string a,int b)
{
    ManuName=a;
    NoCylinder=b;
}

void vehicle::setManu(string a)
{
    ManuName=a;
}

void vehicle::setCyl(int a)
{
    NoCylinder=a;
}

void vehicle::setOwner(string a)
{
    Owner.setName(a);
}

string vehicle::getManu()
{
    return ManuName;
}

int vehicle::getCyl()
{
    return NoCylinder;
}

string vehicle::getOwner()
{
    return Owner.name;
}
