#include "employee.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

employee::employee()
{
    //ctor
}
void employee::setID()
{
    string id;
    cout<<"Please enter Chef ID : "<< cID <<endl;
    cin>>cID;
    cID=id;
}

void employee::displayStorage()
{
    ifstream listFood;
    listFood.open("listFood.csv");

    if(listFood.fail())
    {
        cerr<<"Sorry. Your file error to open. "<<endl;
    }

    string typeFood, num, code, quantity, sell, order, total, remaining;
    cout<<"List of Happy Grill Menu "<<endl;
    cout<<"\n No "<<" Type of Food "<<" Code "<<" Quantity (set) "
    <<" Sell "<<" Order "<<" Total "<<" Remaining (set)\n"<<endl;
    for(int i=0; i<6; i++)
    {
        getline(listFood,num,',');
        getline(listFood,typeFood,',');
        getline(listFood,code,',');
        getline(listFood,quantity,',');
        getline(listFood,sell,',');
        getline(listFood,order,',');
        getline(listFood,total,',');
        getline(listFood,remaining,'\n');

        std::cout <<setw(2)<<num<<setw(15)<<typeFood<<setw(6)<< code<<setw(10)<< quantity
        <<setw(12)<< sell<<setw(7)<<order<<setw(6)<<total<<setw(10)<<remaining<<"\n"<<endl;
    }
    system("PAUSE");

}

void employee::displayFood()
{
    ifstream ip("listItems.csv"); /// reading object file

    if (!ip.is_open()) /// check either file exist or not
        std::cout << "ERROR: File Open" << '\n';

    string typeFood;
    string item1;
    string item2;
    string item3;
    string item4;
    int foodCode, line;

    cout<<"\nEnter code of food: ";
    cin>>foodCode;

    switch(foodCode)
    {
    case 1001:
        line = 0;
        break;
    case 1002:
        line = 1;
        break;
    case 1003:
        line = 2;
        break;
    case 1004:
        line = 3;
        break;
    case 1005:
        line = 4;
        break;
    case 1006:
        line = 5;
        break;
    }
    cout << "...................." <<endl;
    for (int i=0; i<=line; i++)
    {
        getline(ip,typeFood,',');
        getline(ip,item1,',');
        getline(ip,item2,',');
        getline(ip,item3,',');
        getline(ip,item4,'\n');
    }
        std::cout << "Type of Food: " << typeFood <<endl;
        std::cout << "Ingredients 1: " << item1 << "\nIngredients 2: " << item2 << "\nIngredients 3: "
        << item3 << "\nIngredients 4: " << item4 << endl;
        std::cout << "...................." << '\n';

    ip.close();
}

void employee::setOrder()
{
    ofstream ordr("order.csv");

    cout<<"Enter the Quantity of (set) : \n(1)Menu 1: \n(2)Menu 2:"
    <<" \n(3)Menu 3: \n(4)Menu 4: \n(5)Menu 5: \n(6)Menu 6:\n";
    int order;

    for(int i=0; i<6; i++)
    {
        while(cin>>order)
        {
            ordr << order <<endl;
        }
    }
    ordr.close();
}

int employee::getOrder()
{
    return order;
}
string employee::getID()
{
    return cID;
}

