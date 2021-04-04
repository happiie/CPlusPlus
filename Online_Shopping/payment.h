#ifndef PAYMENT_H_INCLUDED
#define PAYMENT_H_INCLUDED
#include "registerID.h"

using namespace std;

class payment:public registerID
{
public:
    payment(registerID&);
    bool checkpayPass(string );
    string getUname(){return Uname;};
    string getAddr(){return Addr;};
protected:
    string Uname,Pword,Addr;
};

payment::payment(registerID &r)
{
    Uname=r.getUser();
    Pword=r.getPass();
    Addr=r.getAddress();
}

bool payment::checkpayPass(string b)
{
    if(b==Pword)
        return true;
    else
        return false;
}
#endif // PAYMENT_H_INCLUDED
