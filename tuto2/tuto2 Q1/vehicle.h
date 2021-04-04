#ifndef VEHICLE_H
#define VEHICLE_H
#include "person.h"
#include<iostream>
#include<string>

using namespace std;

class vehicle
{
    public:
        vehicle();
        vehicle(string ,int );
        void setManu(string );
        void setCyl(int );
        void setOwner(string );
        string getManu();
        int getCyl();
        string getOwner();

        string ManuName;
        int NoCylinder;
        person Owner;
};

#endif // VEHICLE_H
