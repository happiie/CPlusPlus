#include <iostream>
#include <string>
#include "Person.h"
#include "Patient.h"
#include "Doctor.h"
#include "Billing.h"
using namespace std;

int main()
{
    Doctor doc[6];

    doc[0].setName("Dr.Issac");
    doc[0].setSpeciality(2);
    doc[0].setFee(1000);

    doc[1].setName("Dr.Johnny");
    doc[1].setSpeciality(1);
    doc[1].setFee(2000);

    doc[2].setName("Dr.Sally");
    doc[2].setSpeciality(0);
    doc[2].setFee(5000);

    doc[3].setName("Dr.Peter");
    doc[3].setSpeciality(3);
    doc[3].setFee(500);

    doc[4].setName("Dr.Kelly");
    doc[4].setSpeciality(3);
    doc[4].setFee(500);

    doc[5].setName("Dr.Sabrina");
    doc[5].setSpeciality(3);
    doc[5].setFee(500);

    Patient pat1,pat2,pat3;

    pat1.setName("Alexander");
    pat2=pat1;
    pat3.setName("Della");
    pat1.setPrimary(doc[3]);
    pat2.setPrimary(doc[4]);
    pat3.setPrimary(doc[5]);

    Billing bill1,bill2,bill3;

    bill1.setPat(pat1);
    bill1.setDoc(doc[0]);
    bill1.setAmountfee(doc[0].getFee());
    bill1.displayBill();

    bill2.setPat(pat2);
    bill2.setDoc(doc[1]);
    bill2.setAmountfee(doc[1].getFee());
    bill2.displayBill();

    bill3.setPat(pat3);
    bill3.setDoc(doc[2]);
    bill3.setAmountfee(doc[2].getFee());
    bill3.displayBill();

    int a,b,c;

    cout<<"Doctor Seeker and Calculator:"<<endl;
    for(int i=0;i<6;i++)
    {
        cout<<i+1<<". "<<doc[i].getName()<<"    ("<<doc[i].getSpeciality()<<")"<<endl;
    }
    cout<<"Please choose two doctors:";
    cin>>a>>b;
    if(a!=1||a!=2||a!=3||a!=4||a!=5||b!=1||b!=2||b!=3||b!=4||b!=5)
    {
        cout<<"Please Enter number of doctor from 1 to 5\n";
            cout<<"\nPlease choose two doctors:";
            cin>>a>>b;
    }
    doc[a]+doc[b];
    cout<<endl;


    return 0;
}
