#include "supplier.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

supplier::supplier()
{
    //ctor
}
void supplier::setdelived()
{
    ofstream dlvd("delivered.csv");

    cout<<"Enter the Quantity of (set) : \n(1)Menu 1: \n(2)Menu 2:"
    <<" \n(3)Menu 3: \n(4)Menu 4: \n(5)Menu 5: \n(6)Menu 6:\n";
    int delivered;

    for(int i=0; i<6; i++)
    {
        while(cin>>delivered)
        {
            dlvd << delivered <<endl;
        }
    }
    dlvd.close();
}

int supplier::getdelived()
{
    return delived;
}
