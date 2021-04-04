#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include "Person.h"
#include "Doctor.h"
using namespace std;

class Patient: public Person
{
    public:
        Patient();

        void setPrimary(Doctor);
        Doctor getPrimary();
        virtual ~Patient();

    protected:

    private:

        Doctor primary;

};

#endif // PATIENT_H
