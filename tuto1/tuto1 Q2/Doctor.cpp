#include "Doctor.h"
#include <string>
#include <iostream>
using namespace std;
Doctor::Doctor()
{
    //ctor
}

void Doctor::setSpeciality(int sp)
{
    string a[4]={"Pediatrician", "Obstetrician" , "General Practitioner","General Doctor"};
    speciality=a[sp];
}

string Doctor::getSpeciality()
{
    return speciality;
}

void Doctor::setFee(double f)
{
    fee=f;
}

double Doctor::getFee()
{
    return fee;
}

void Doctor::operator+ (Doctor& d)
 {
     cout<<"Fee of "<<getName()<<"+"<<d.getName()<<"= RM";
     double sum=0;
     sum=fee+d.fee;

     cout<<sum;
 }


Doctor::~Doctor()
{
    //dtor
}
