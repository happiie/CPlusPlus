#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class product
{
public:
    product(){};
    void initiateProduct(product& ,int );
    int getCode(){return code;};
    void setQuantity(int q){quantity=q;};
    void reduceStock(product &,int );
    double getTotalPrice(){return quantity*price;};
    string getColor(){return color;};
    string getSaiz(){return saiz;};
    void display(product& ,int );

//protected:
    int s=0,m=0,l=0,xl=0,code,quantity=0;
    double price;
    string color,saiz;
};

void product::initiateProduct(product &p,int i)
{
    static int kod=10;
    p.code=kod;
    kod++;
    switch(i/4)
    {
        case 0: p.color="Blue"; break;
        case 1: p.color="Red"; break;
        case 2: p.color="Yellow"; break;
        case 3: p.color="Green"; break;
    }

    switch(i%4)
    {
        case 0: p.saiz="S"; p.s=80;
                p.price=39.9; break;
        case 1: p.saiz="M"; p.m=80;
                p.price=41.9; break;
        case 2: p.saiz="L"; p.l=80;
                p.price=43.9; break;
        case 3: p.saiz="XL"; p.xl=80;
                p.price=45.9; break;
    }

}

void product::display(product &p,int i)
{
    if(i==0)
        cout<<"     Colour   Size    Price(RM)  Code\n\n";
    cout<<setw(10)<<p.color<<setw(7)<<p.saiz<<setw(10)<<fixed<<setprecision(2)<<p.price<<setw(8)<<p.code<<endl;
    if((i%4)==3)
        cout<<endl;
}

void product::reduceStock(product &p,int i)
{
    switch(i%4)
    {
        case 0: p.s=p.s-quantity; break;
        case 1: p.m=p.m-quantity; break;
        case 2: p.l=p.l-quantity; break;
        case 3: p.xl=p.xl-quantity; break;
    }
}
#endif // PRODUCT_H_INCLUDED
