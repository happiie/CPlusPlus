#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Mouse.h"
#include "Snake.h"
#include "Organism.h"
using namespace std;

const int grid=20;

void display_simulation(char a[][20])
{    char b=218;///above left corner
    char w=191;///above right corner
    char q=194;///above down T-junction
    char c=197;///+ junction
    char r=195;///left closing T-junction
    char d=196;///horizontal line
    char e=179;///vertical line
    char z=180;///right closing T-junction
    char x=192;///btm left corner
    char t=193;///btm up T-juntion
    char y=217;///btm right corner
    int counter=1;
    cout<<b<<d<<q<<d<<q<<d<<q<<d<<q<<d<<q<<d<<q<<d<<q<<d<<q<<d<<q<<d<<q<<d<<q<<d<<q<<d<<q<<d<<q<<d<<q<<d<<q<<d<<q<<d;
    cout<<q<<d<<q<<d<<w<<endl;
    for(int row=0;row<20;row++)
    {   cout<<e;
        for(int collumn=0;collumn<20;collumn++)
        {
            cout<<a[row][collumn]<<e;
        }
        cout<<endl;
        counter++;
        if(row==19)
        cout<<x<<d<<t<<d<<t<<d<<t<<d<<t<<d<<t<<d<<t<<d<<t<<d<<t<<d<<t<<d<<t<<d<<t<<d
        <<t<<d<<t<<d<<t<<d<<t<<d<<t<<d<<t<<d<<t<<d<<t<<d<<y<<endl;
        else
        cout<<r<<d<<c<<d<<c<<d<<c<<d<<c<<d<<c<<d<<c<<d<<c<<d<<c<<d<<c<<d<<c<<d<<c<<d
        <<c<<d<<c<<d<<c<<d<<c<<d<<c<<d<<c<<d<<c<<d<<c<<d<<z<<endl;
    }
}

int main()
{   char cell[grid][grid]={};
    srand(time(0));
    int snake_no=10;
    int mice_no=50;
    Organism *Snake1,*Mouse1;
    Mouse m1;
    Snake s1;
    Mouse1=&m1;
    Snake1=&s1;
    m1.M_random_place(cell,mice_no);
    s1.S_random_place(cell,snake_no);
    display_simulation(cell);
    cout<<"Time Step 0 : "<<mice_no<<" mice   "<<snake_no<<" snake"<<endl;

    char enter;
    cout<<"Press enter to next time step:"<<endl;
    cin>>enter;
    int x=1;

    while(x<=20)
    {
        cout<<endl;
        Snake1->MOVE(cell);
        Mouse1->MOVE(cell);
        s1.S_breed(cell);
        m1.M_breed(cell);
        Mouse1->No_Track(cell);
        display_simulation(cell);
        cout<<"Time Step "<<x<<" : "<<Mouse1->getmouse_No()<<" mice   "<<Snake1->getsnake_No()<<" snake"<<endl;
         if(Mouse1->getmouse_No()==0 || Snake1->getsnake_No()==0)
            break;

        cout<<"Press enter to next time step:"<<endl;
        cin>>enter;
        x++;

    };
    display_simulation(cell);
    cout<<"Time Step "<<--x<<" : "<<Mouse1->getmouse_No()<<" mice   "<<Snake1->getsnake_No()<<" snake"<<endl;
    return 0;
}
