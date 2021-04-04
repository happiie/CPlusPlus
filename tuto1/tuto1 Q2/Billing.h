#ifndef BILLING_H
#define BILLING_H
#include <string>
#include "Patient.h"
#include "Doctor.h"
using namespace std;

class Billing
{
    public:
        Billing();
         void setPat(Patient);
        Patient getPat();
         void setDoc(Doctor);
        Doctor getDoc();
        void setAmountfee(double);
        double getAmountfee();
        virtual ~Billing();
        void displayBill();

    protected:

    private:
        Patient pat;
        Doctor doc;
        double amountfee;
};

#endif // BILLING_H
