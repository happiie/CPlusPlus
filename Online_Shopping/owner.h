#ifndef OWNER_H_INCLUDED
#define OWNER_H_INCLUDED
#include "product.h"

using namespace std;

class owner
{
public:
    owner(string );
    void checkStock(product &,int);
    void calcValue();
    void resetStock();
//protected:
    string name;
    int S=0,M=0,L=0,XL=0;
    int totalS=0,totalM=0,totalL=0,totalXL=0;
    double valueSold;
};

owner::owner(string n)
{
    name=n;
}

void owner::checkStock(product &p,int j)
{
    if(j==0)
        {   totalS=0; totalM=0; totalL=0; totalXL=0;
            cout<<"     Color   S    M    L   XL"; }
    if(j%4==0)
        cout<<endl<<setw(10)<<p.color<<"  ";
    switch(j%4)
    {
        case 0:cout<<p.s<<"   "; totalS=totalS+p.s; break;
        case 1:cout<<p.m<<"   "; totalM=totalM+p.m; break;
        case 2:cout<<p.l<<"   "; totalL=totalL+p.l; break;
        case 3:cout<<p.xl; totalXL=totalXL+p.xl; break;
    }
    if(j==15)
    {
        cout<<"\n     Total "<<totalS<<"  "<<totalM<<"  "<<totalL<<"  "<<totalXL<<endl;
        calcValue();
    }
}

void owner::resetStock()
{
    S=0; M=0; L=0; XL=0;
}

void owner::calcValue()
{
    double totalAll=(320-totalS)*39.9+(320-totalM)*41.9+(320-totalL)*43.9+(320-totalXL)*45.9;
    cout<<"  The value of items sold is: RM"<<totalAll<<endl;
    cout<<"  Number of item sold is: "<<320-totalS<<"S "<<320-totalM<<"M "<<320-totalL<<"L "<<320-totalXL<<"XL\n";

    int w=320-totalS, x=320-totalM, y=320-totalL, z =320-totalXL;
}
#endif // OWNER_H_INCLUDED
