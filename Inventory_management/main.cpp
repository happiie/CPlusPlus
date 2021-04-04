#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Restaurant.h"
#include "employee.h"
#include "supplier.h"
using namespace std;

int main()
{
    int create, type;

    Restaurant regis[33]={};

    exit:
    cout << "**********************************************"<<endl;
    cout << "                  HAPPY GRILL\n"
         << "           ALWAYS FULFIL YOUR APPETITE   \n" << endl;
    cout << "**********************************************"<<endl;
    cout << "\n         INVENTORY MANANGEMENT SYSTEM        \n"<<endl;
    cout << "**********************************************\n"<<endl;
         system("PAUSE");

    create:
    system("CLS");
    cout << "Please choose :\n" << "(1)Create New Account\n" << "(2)Sign Up" << endl;
    cin >> create;
    if(create!=1 && create!=2)
        goto create;
    system("CLS");

    static int regisCount=0;
    if(create == 1)    ///create new account
    {
        regis[regisCount].setUserName();
        regis[regisCount].setPassword();
        regis[regisCount].setEmail();
        regis[regisCount].setCallNumber();
        regisCount++;
        cout << "\nYour Account Created ..." << endl;
        system("PAUSE");
        if(regisCount>33){cout<<"Sorry, System already full of data.";}
        goto create;

    }
    system("CLS");

    if(create==2)    ///sign up
    {
        string username, password;
        SignUp:
        bool Ucheck=false, Pcheck=false;
        cout << "Please Enter Username: ";
        cin >> username;
        cout << "Please Enter Password: ";
        cin >> password;

        if(regisCount>0)
        {
            for(int i=0; i<33; i++)   ///user name and password check
                {
                Ucheck=regis[i].userCheck(username);
                Pcheck=regis[i].pwdCheck(password);
                if(Ucheck==false && Pcheck==false)
                    break;
                }
            if(Ucheck==true||Pcheck==true)
                {
                cout << "Sorry, System don't recognize that account \n" << endl;
                goto SignUp;
                }
            TYpe:     ///determine employee or supplier
            cout << "\nPlease choose :\n(1)Employee \n(2)Supplier " <<endl;
            cin >> type;
            if(type!=1&&type!=2){goto TYpe;}
            cout << "\n Sign Up....\n" <<endl;
            system("PAUSE");
            system("CLS");}

        if(regisCount<1)
        {
        cout << "\nSorry, System don't have your data. Please create one. \n"<< endl;
        system("PAUSE");
        goto create;
        }
    }
    if(type==1)
    {
    employee chef;
    ChceBack:
    int choose1, c1;
    cout << "Please choose: \n (1)Stock left\n (2)Order to supplier\n (3)exit\n";
    cin>>choose1;
    system("CLS");
    if(choose1==1)
        {chef.displayStorage(); bAck:
         cout<<"Please choose: \n (1)View Menu Details\n (2)Back\n";
         cin>>c1;
         if(c1==1){chef.displayFood(); goto bAck;} if(c1==2){system("CLS"); goto ChceBack;}
        }
    if(choose1==2){chef.setOrder(); cout<<"\nYour Order done Post!\n";
     system("PAUSE");system("CLS"); goto exit;}
    if(choose1==3){cout<<"\nThanks for your cooperation\n";system("PAUSE");system("CLS");goto exit;}
    }
    if(type==2)
    {
        supplier sup;
        int choose2;
    cout << "Please choose: \n (1)Delivered items\n (2)exit\n";
    cin>>choose2;
    system("CLS");
        if(choose2==1)
        {sup.setdelived();cout<<"\nYour Order done Delivered!\n";
        system("PAUSE");system("CLS"); goto exit;}
        if(choose2==2){cout<<"\nThanks for your cooperation\n";system("PAUSE");system("CLS");goto exit;}
    }

    return 0;
}
