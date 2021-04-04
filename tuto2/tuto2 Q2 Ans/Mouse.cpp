#include "Mouse.h"

Mouse::Mouse()
{
    //ctor
}
void Mouse::M_random_place(char a1[][20],int no_mouse)
 {  mouse=no_mouse;
     int row,column;
    while(no_mouse!=0)
     {  row=rand()%20;
        column=rand()%20;
        if(Tracking_cell(a1,row,column)==false)
        {
            a1[row][column]='O';
            no_mouse--;
        }
     }
 }

void Mouse::MOVE(char a2[][20])
{
     MS_Track(a2);///true==MS,false==" "
    /* for(int x2=0;x2<20;x2++)
      {
        for(int y2=0;y2<20;y2++)
     {cout<<mouse_track[x2][y2]<<" ";}
     cout<<endl;
     }*/
    int mouse_turn=mouse;
    int random_move;
    char which_case;

 while(mouse_turn!=0)
    {   for(int x1=0;x1<20;x1++)
        for(int y1=0;y1<20;y1++)

        {  // cout<<"hello";
            if(a2[x1][y1]=='O' && SnakeMouse_track[x1][y1]==true)
            {
                bool move_success=false;
                which_case=check_A_cell(a2,x1,y1);

                switch(which_case){
            case '0':
                {
                    while(move_success==false)
                   {
                    random_move=rand()%4;
                    if(random_move==0 && Tracking_cell(a2,x1+1,y1)==false && x1!=19 ) ///move down
                    {  // cout<<x1<<" "<<y1<<"=Mouse move down"<<endl;
                        a2[x1+1][y1]='O';
                        a2[x1][y1]=' ';
                        SnakeMouse_track[x1][y1]=false;
                        SnakeMouse_track[x1+1][y1]=false;
                        M_survive_track[x1+1][y1]+=M_survive_track[x1][y1];
                        M_survive_track[x1+1][y1]++;
                        M_survive_track[x1][y1]=0;
                        move_success=true;
                   }
                   if(random_move==1 && Tracking_cell(a2,x1-1,y1)==false && x1!=0 ) ///move up
                    {  // cout<<x1<<" "<<y1<<"=Mouse move up"<<endl;
                        a2[x1-1][y1]='O';
                        a2[x1][y1]=' ';
                        SnakeMouse_track[x1][y1]=false;
                        SnakeMouse_track[x1-1][y1]=false;
                        M_survive_track[x1-1][y1]+=M_survive_track[x1][y1];
                        M_survive_track[x1-1][y1]++;
                        M_survive_track[x1][y1]=0;
                        move_success=true;
                   }
                   if(random_move==2 && Tracking_cell(a2,x1,y1-1)==false && y1!=0) ///move left
                    {  // cout<<x1<<" "<<y1<<"=Mouse move left"<<endl;
                        a2[x1][y1-1]='O';
                        a2[x1][y1]=' ';
                        SnakeMouse_track[x1][y1]=false;
                        SnakeMouse_track[x1][y1-1]=false;
                        M_survive_track[x1][y1-1]+=M_survive_track[x1][y1];
                        M_survive_track[x1][y1-1]++;
                        M_survive_track[x1][y1]=0;
                        move_success=true;
                   }
                   if(random_move==3 && Tracking_cell(a2,x1,y1+1)==false && y1!=19 ) ///move right
                   {   // cout<<x1<<" "<<y1<<"=Mouse move right"<<endl;
                        a2[x1][y1+1]='O';
                        a2[x1][y1]=' ';
                        SnakeMouse_track[x1][y1]=false;
                        SnakeMouse_track[x1][y1+1]=false;
                        M_survive_track[x1][y1+1]+=M_survive_track[x1][y1];
                        M_survive_track[x1][y1+1]++;
                        M_survive_track[x1][y1]=0;
                        move_success=true;
                   }
                  }break;
                  }
            case '1':
                {   //cout<<x1<<" "<<y1<<"=Mouse Stay"<<endl;
                    M_survive_track[x1][y1]++;
                    break;
                }

            }
        }


    }mouse_turn--;

}
};

void Mouse::M_breed(char a3[][20])
{   int random_breed;
    char  which_case2;
     for(int x3=0;x3<20;x3++)
    {
        for(int y3=0;y3<20;y3++)
        {
            if(a3[x3][y3]=='O' && M_survive_track[x3][y3]==2)
            {
                 bool breed_success=false;
                which_case2=check_A_cell(a3,x3,y3);
                switch(which_case2){
            case '0':
                {
                    while(breed_success==false)
                   {
                    random_breed=rand()%4;
                    if(random_breed==0 && Tracking_cell(a3,x3+1,y3)==false && x3!=19 ) ///breed down
                    {
                        a3[x3+1][y3]='O';
                        M_survive_track[x3+1][y3]=0;

                        breed_success=true;
                   }
                   if(random_breed==1 && Tracking_cell(a3,x3-1,y3)==false && x3!=0 ) ///breed up
                    {
                        a3[x3-1][y3]='O';
                      M_survive_track[x3-1][y3]=0;
                        breed_success=true;

                   }
                   if(random_breed==2 && Tracking_cell(a3,x3,y3-1)==false && y3!=0) ///breed left
                    {
                        a3[x3][y3-1]='O';
                       M_survive_track[x3][y3-1]=0;
                        breed_success=true;

                   }
                   if(random_breed==3 && Tracking_cell(a3,x3,y3+1)==false && y3!=19 ) ///breed right
                   {
                        a3[x3][y3+1]='O';

                        M_survive_track[x3][y3+1]=0;

                        breed_success=true;
                   }
                  }M_survive_track[x3][y3]=0;
                    mouse++;
                  break;}
            case '1':
                {
                    M_survive_track[x3][y3]=0;
                break;
                }
        }
}}}
}
