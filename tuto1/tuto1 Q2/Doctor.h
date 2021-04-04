#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>
#include <iostream>
#include "Person.h"
using namespace std;

class Doctor : public Person
{
    public:
        Doctor();
        void setSpeciality(int );
        string getSpeciality();
        void setFee(double);
        double getFee();
        virtual ~Doctor();
        void operator+ (Doctor&);


    protected:

    private:
        string speciality;
        double fee;
};

#endif // DOCTOR_H
