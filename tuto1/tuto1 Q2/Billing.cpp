#include "Billing.h"
#include <string>
using namespace std;
Billing::Billing()
{
    //ctor
}

void Billing::setPat(Patient p)
{
    pat=p;
}

Patient Billing::getPat()
{
    return pat;
}

void Billing::setDoc(Doctor d)
{
    doc=d;
}

Doctor Billing::getDoc()
{
    return doc;
}

 void Billing::setAmountfee(double af)
 {
     amountfee=af;
 }

double Billing::getAmountfee()
{
    return amountfee;
}

void Billing::displayBill()
{
    cout<<"Patient's Name: "<<pat.getName()<<endl;
    cout<<"Primary Physician: "<<pat.getPrimary().getName()<<endl;
    cout<<"Fee: RM"<<pat.getPrimary().getFee()<<endl;
    cout<<"Doctor's Name: "<<doc.getName()<<endl;
    cout<<"Doctor's Specialty: "<<doc.getSpeciality()<<endl;
    cout<<"Fee: RM"<<doc.getFee()<<endl;
    cout<<"Amount due: RM"<<doc.getFee()+pat.getPrimary().getFee()<<endl<<endl;
}


Billing::~Billing()
{
    //dtor
}
