#include <iostream>
#include <stdlib.h>
#include "owner.h"
#include "itemlist.h"
#include "payment.h"

using namespace std;

int main()
{
    product a[16];
    owner master("PAK MAT TEMPE");
    registerID user[20]={};
    for(int i=0;i<16;i++)
    {
        a[i].initiateProduct(a[i],i);
    }

    int choice=0;
    while(choice!=1&&choice!=2&&choice!=24687531)
    {
        pakmat:
        system("cls");
        cout<<"  Welcome to Pak Mat Store of Baju Melayu!!!\n";
        cout<<"  1.Create id\n  2.Login\n  Choose 1 or 2:";
        cin>>choice;
    }

    static int userNum=0;
    static int currentUser=0;
    if(choice==1)
    {
        system("cls");
        createUser:
        if(userNum<20)
        {
        user[userNum].setUser();
        user[userNum].setPass();
        user[userNum].setEmail();
        user[userNum].setAddress();
        userNum++;
        cout<<"  ID created . . .\n";
        system("pause");
        goto pakmat;}
        else
            cout<<"  Maximum user data.";
    }
    if(choice==2)
    {
        if(userNum<1)
        {
            cout<<"  No user data.\n  Please register a new ID.\n";
            goto createUser;}
        else
        {
            system("cls");
            string nama,pswd;
            redo:
            bool check1=false,check2=false;
            cout<<"  Enter username:";
            cin>>nama;
            cout<<"  Enter password:";
            cin>>pswd;
            for(int i=0;i<20;i++)
            {
                check1=user[i].checkUser(nama);
                check2=user[i].checkPass(pswd);
                if(check1&&check2)
                    {currentUser=i; break;}
            }
            if(!check1||!check2)
            {
                cout<<"  Invalid username/password!\n";
                goto redo;
            }
            cout<<"  Logged in!\n";
            system("pause");
            goto nextMenu;
        }
    }

    if(choice==24687531)
    {
        system("cls");
        cout<<"  Welcome master "<<master.name<<"\n  The stock is as listed below:\n";
        for(int i=0;i<16;i++)
        {
            master.resetStock();
            master.checkStock(a[i],i);
        }
        system("pause");
        goto pakmat;
    }

    nextMenu:
    system("cls");
    for(int i=0;i<16;i++)
    {
        a[i].display(a[i],i);
    }
    cout<<"  1.Purchase shirt\n  2.View cart\n  3.Payment\n  4.Cancel the whole purchase\n  Enter choice:";
    static int pick=0;
    static int scode=0;
    static int quanty=0;
    static int itemNum=0;
    itemlist item[20]={};
    cin>>pick;
    if(pick<1||pick>4)
        goto nextMenu;
    if(pick==1)
    {
        cout<<"  Enter code of shirt:";
        recode:
        cin>>scode;
        if(scode<10||scode>25)
        {cout<<"  Wrong code,please reenter code:"; goto recode;}
        cout<<"  Enter quantity:";
        cin>>quanty;
        a[scode-10].setQuantity(quanty);
        item[itemNum].setAll(a[scode-10]);
        itemNum++;
        goto nextMenu;
    }
    if(pick==2)
    {
        system("cls");
        if(itemNum>0)
        {
            for(int i=0;i<itemNum;i++)
            {
                int x=item[i].getCodes()-10;
                item[i].display(a,x,i);
            }
            system("pause");
            goto nextMenu;
        }
        else
        {
            cout<<"  No item in cart\n";
            system("pause");
            goto nextMenu;
        }

    }

    if(pick==3)
    {
        payment pay(user[currentUser]);
        double tot=0;
        for(int i=0;i<itemNum;i++)
        {
            tot=tot+item[i].getTprice();
        }
        system("cls");
        if(itemNum>0)
            for(int i=0;i<itemNum;i++)
            {
                int x=item[i].getCodes()-10;
                a[x].reduceStock(a[x],x);
                item[i].display(a,x,i);
            }
        cout<<"  Total bill is RM"<<tot<<endl;
        cout<<"  Which way would you like to pay your bill?\n";
        cout<<"  1. Credit card\n  2. Debit card\n  3. Cash-on-delivery(KL area only)\n";
        repay:
        cout<<"  Enter 1-3:";
        int paying;
        cin>>paying;
        if(paying!=1&&paying!=2&&paying!=3)
            goto repay;
        if(paying==1||paying==2)
        {
            double x;
            ree:
            cout<<"  Enter 16-digit card code:";
            cin>>x;
            if(x<1000000000000000||x>=10000000000000000)
            {
                cout<<"  Invalid card code!."<<endl;
                goto ree;
            }
            cout<<"  Card accepted. Amount RM"<<fixed<<setprecision(2)<<tot<<" will be deducted from your account"<<endl;
            cout<<"  The item will be send to address "<<pay.getAddr()<<endl;
            cout<<"  Please reenter password to confirm purchase.\n  Username:";
            cout<<pay.getUname()<<endl;
            string pss;
            cout<<"  Password:";
            p:
            cin>>pss;
            bool check=pay.checkpayPass(pss);
            if(!check)
            {cout<<"  Wrong password!\n  Reenter Password"; goto p;}
            else
                cout<<"  Transaction accepted!Thank you for shopping with us :)"<<endl;
            itemNum=0;
            system("pause");
            goto pakmat;
        }
        if(paying==3)
        {
            cout<<"  The item with bill RM"<<fixed<<setprecision(2)<<tot<<" will be sent to address "<<pay.getAddr()<<endl;
            cout<<"  Please reenter password to confirm purchase.\n  Username:";
            cout<<pay.getUname()<<endl;
            string psss;
            cout<<"  Password:";
            q:
            cin>>psss;
            bool check=pay.checkpayPass(psss);
            if(!check)
            {cout<<"  Wrong password!\n  Reenter password"; goto q;}
            else
                cout<<"  Transaction accepted!Thank you for shopping with us :)"<<endl;
            itemNum=0;
            system("pause");
            goto pakmat;
        }
    }

    if(pick==4)
        {itemNum=0; goto pakmat;}

    return 0;
}
