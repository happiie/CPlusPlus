#ifndef ITEMLIST_H_INCLUDED
#define ITEMLIST_H_INCLUDED
#include<string>
#include<iostream>
using namespace std;

class itemlist
{
public:
    itemlist(){};
    void setAll(product &);
    void display(const product[] ,int ,int  );
    int getCodes(){return codes;};
    double getTprice(){return tPrice;};
protected:
    string colour,saizz;
    double tPrice;
    int num,codes;
};

void itemlist::setAll(product &pr)
{
    colour=pr.color;
    saizz=pr.saiz;
    tPrice=pr.quantity*pr.price;
    num=pr.quantity;
    codes=pr.code;
}

void itemlist::display(const product p[16],int x,int i)
{
    if(i==0)
        cout<<"     Colour   Size   Price(RM) Units  Code\n";
    cout<<setw(10)<<p[x].color<<setw(7)<<p[x].saiz<<setw(10)<<tPrice<<setw(7)<<num;
    cout<<setw(7)<<codes<<endl;
}
#endif // ITEMLIST_H_INCLUDED
