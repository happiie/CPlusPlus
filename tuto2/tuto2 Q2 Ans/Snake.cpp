#include "Snake.h"

Snake::Snake()
{
    //ctor
}
char Snake::S_check_cell(char a[][20],int x,int y)
{
    char choice='1';
    if(a[x][y-1]=='O' && y!=0) ///food left
        {choice='2';
                        }
    else if(a[x][y+1]=='O' && y!=19) ///food right
        {choice='2';
                        }
    else if(a[x-1][y]=='O' && x!=0) /// food up
        {choice='2';
                        }
    else if(a[x+1][y]=='O' && x!=19) ///food down
        {choice='2';
                        }
    else if(a[x+1][y]!='X' && x!=19) ///down
        {choice='0';
                        }
    else if(a[x-1][y]!='X' && x!=0) ///up
        {choice='0';
                        }
    else if(a[x][y+1]!='X' && y!=19) ///right
        {choice='0';
                        }
    else if(a[x][y-1]!='X' && y!=0) ///left
        {choice='0';
                        }
    else
        choice='1';
    return choice;
}

void Snake::S_random_place(char a[][20],int no_snake)
{  int row,column;
        snake=no_snake;
    while(no_snake!=0)
     {  row=rand()%20;
        column=rand()%20;
        if(Tracking_cell(a,row,column)==false)
        {
            a[row][column]='X';
            no_snake--;
        }
     }

}
void Snake::MOVE(char b1[][20])
{
     MS_Track(b1);///true==MS,false==" "
    /* for(int x2=0;x2<20;x2++)
      {
        for(int y2=0;y2<20;y2++)
     {cout<<mouse_track[x2][y2]<<" ";}
     cout<<endl;
     }*/
    int snake_turn=snake;
    int random_move;
    char which_case;

 while(snake_turn!=0)
    {   for(int x1=0;x1<20;x1++)
        for(int y1=0;y1<20;y1++)
        {  // cout<<"hello";
            if(b1[x1][y1]=='X' && SnakeMouse_track[x1][y1]==true)
            {
                bool move_success=false;
                which_case=S_check_cell(b1,x1,y1);

                switch(which_case){
            case '2':
                {
                    while(move_success==false)
                   {
                    random_move=rand()%4;
                    if(random_move==0 && b1[x1+1][y1]=='O' && x1!=19 ) ///move down
                    {  // cout<<x1<<","<<y1<<"=fooddown"<<endl;
                        b1[x1+1][y1]='X';
                        b1[x1][y1]=' ';
                        SnakeMouse_track[x1][y1]=false;
                        SnakeMouse_track[x1+1][y1]=false;
                        S_survive_track[x1+1][y1]+=S_survive_track[x1][y1];
                        S_survive_track[x1+1][y1]++;
                        S_hungry_track[x1+1][y1]=0;

                        move_success=true;
                   }
                   if(random_move==1 && b1[x1-1][y1]=='O' && x1!=0 ) ///move up
                    {   //cout<<x1<<","<<y1<<"=foodup"<<endl;
                        b1[x1-1][y1]='X';
                        b1[x1][y1]=' ';
                        SnakeMouse_track[x1][y1]=false;
                        SnakeMouse_track[x1-1][y1]=false;
                        S_survive_track[x1-1][y1]+=S_survive_track[x1][y1];
                        S_survive_track[x1-1][y1]++;
                        S_hungry_track[x1-1][y1]=0;

                        move_success=true;
                   }
                   if(random_move==2 && b1[x1][y1-1]=='O' && y1!=0) ///move left
                    {  // cout<<x1<<","<<y1<<"=foodleft"<<endl;
                        b1[x1][y1-1]='X';
                        b1[x1][y1]=' ';
                        SnakeMouse_track[x1][y1]=false;
                        SnakeMouse_track[x1][y1-1]=false;
                        S_survive_track[x1][y1-1]+=S_survive_track[x1][y1];
                        S_survive_track[x1][y1-1]++;
                        S_hungry_track[x1][y1-1]=0;

                        move_success=true;
                   }
                   if(random_move==3 && b1[x1][y1+1]=='O' && y1!=19 ) ///move right
                   {   // cout<<x1<<","<<y1<<"=foodright"<<endl;
                        b1[x1][y1+1]='X';
                        b1[x1][y1]=' ';
                        SnakeMouse_track[x1][y1]=false;
                        SnakeMouse_track[x1][y1+1]=false;
                        S_survive_track[x1][y1+1]+=S_survive_track[x1][y1];
                        S_survive_track[x1][y1+1]++;
                        S_hungry_track[x1][y1+1]=0;

                        move_success=true;
                   }
                  }
                  S_survive_track[x1][y1]=0;
                  S_hungry_track[x1][y1]=0;

                 // cout<<"1 mouse die"<<endl;

                  }break;





            case '0':
                {
                      while(move_success==false)
                   {
                    random_move=rand()%4;
                    if(random_move==0 && b1[x1+1][y1]!='X' && x1!=19 ) ///move down
                    {  // cout<<x1<<" "<<y1<<"=Snake Move down\n";
                        b1[x1+1][y1]='X';
                        b1[x1][y1]=' ';
                        SnakeMouse_track[x1][y1]=false;
                        SnakeMouse_track[x1+1][y1]=false;
                        S_survive_track[x1+1][y1]+=S_survive_track[x1][y1];
                        S_survive_track[x1+1][y1]++;
                        S_hungry_track[x1+1][y1]+=S_hungry_track[x1][y1];
                        S_hungry_track[x1+1][y1]++;
                        if(S_hungry_track[x1+1][y1]==3)
                        {
                            b1[x1+1][y1]=' ';
                            S_hungry_track[x1+1][y1]=0;
                            S_survive_track[x1+1][y1]=0;
                            snake--;
                        }
                        move_success=true;
                   }
                   if(random_move==1 && b1[x1-1][y1]!='X' && x1!=0 ) ///move up
                    {   //cout<<x1<<" "<<y1<<"=Snake Move up\n";
                        b1[x1-1][y1]='X';
                        b1[x1][y1]=' ';
                        SnakeMouse_track[x1][y1]=false;
                        SnakeMouse_track[x1-1][y1]=false;
                        S_survive_track[x1-1][y1]+=S_survive_track[x1][y1];
                        S_survive_track[x1-1][y1]++;
                        S_hungry_track[x1-1][y1]+=S_hungry_track[x1][y1];
                        S_hungry_track[x1-1][y1]++;
                        if(S_hungry_track[x1-1][y1]==3)
                        {
                            b1[x1-1][y1]=' ';
                            S_hungry_track[x1-1][y1]=0;
                            S_survive_track[x1-1][y1]=0;
                            snake--;
                        }
                        move_success=true;
                   }
                   if(random_move==2 && b1[x1][y1-1]!='X' && y1!=0) ///move left
                    {   //cout<<x1<<" "<<y1<<"=Snake Move left\n";
                        b1[x1][y1-1]='X';
                        b1[x1][y1]=' ';
                        SnakeMouse_track[x1][y1]=false;
                        SnakeMouse_track[x1][y1-1]=false;
                        S_survive_track[x1][y1-1]+=S_survive_track[x1][y1];
                        S_survive_track[x1][y1-1]++;
                        S_hungry_track[x1][y1-1]+=S_hungry_track[x1][y1];
                        S_hungry_track[x1][y1-1]++;
                        move_success=true;
                        if(S_hungry_track[x1][y1-1]==3)
                        {
                            b1[x1][y1-1]=' ';
                            S_hungry_track[x1][y1-1]=0;
                            S_survive_track[x1][y1-1]=0;
                            snake--;
                        }
                   }
                   if(random_move==3 && b1[x1][y1+1]!='X' && y1!=19 ) ///move right
                   {   // cout<<x1<<" "<<y1<<"=Snake Move right\n";
                        b1[x1][y1+1]='X';
                        b1[x1][y1]=' ';
                        SnakeMouse_track[x1][y1]=false;
                        SnakeMouse_track[x1][y1+1]=false;
                        S_survive_track[x1][y1+1]+=S_survive_track[x1][y1];
                        S_survive_track[x1][y1+1]++;
                        S_hungry_track[x1][y1+1]+=S_hungry_track[x1][y1];
                        S_hungry_track[x1][y1+1]++;
                        if(S_hungry_track[x1][y1+1]==3)
                        {
                            b1[x1][y1+1]=' ';
                            S_hungry_track[x1][y1+1]=0;
                            S_survive_track[x1][y1+1]=0;
                            snake--;
                        }
                        move_success=true;
                   }
                  }

                    S_hungry_track[x1][y1]=0;
                    S_survive_track[x1][y1]=0;




                } break;
            case '1':
                {  // cout<<x1<<" "<<y1<<"=Snake Stay"<<endl;
                    S_survive_track[x1][y1]++;
                    S_hungry_track[x1][y1]++;
                    if(S_hungry_track[x1][y1]==3)
                    {
                        b1[x1][y1]=' ';
                        S_hungry_track[x1][y1]=0;
                        S_hungry_track[x1][y1]=0;
                        snake--;
                    }

                }break;

            }
        }


    } snake_turn--;

}
};

void Snake::S_breed(char b2[][20])
{
    int random_breed;
    char  which_case2;
     for(int x3=0;x3<20;x3++)
        for(int y3=0;y3<20;y3++)
        {
            if(b2[x3][y3]=='X' && S_survive_track[x3][y3]==5)
            {
                 bool breed_success=false;
                which_case2=check_A_cell(b2,x3,y3);
                switch(which_case2){
            case '0':
                {
                    while(breed_success==false)
                   {
                    random_breed=rand()%4;
                    if(random_breed==0 && Tracking_cell(b2,x3+1,y3)==false && x3!=19 ) ///breed down
                    {
                        b2[x3+1][y3]='X';
                        S_survive_track[x3+1][y3]=0;
                        S_hungry_track[x3+1][y3]=0;

                        breed_success=true;
                   }
                   if(random_breed==1 && Tracking_cell(b2,x3-1,y3)==false && x3!=0 ) ///breed up
                    {
                        b2[x3-1][y3]='X';
                      S_survive_track[x3-1][y3]=0;
                      S_hungry_track[x3-1][y3]=0;
                        breed_success=true;

                   }
                   if(random_breed==2 && Tracking_cell(b2,x3,y3-1)==false && y3!=0) ///breed left
                    {
                        b2[x3][y3-1]='X';
                       S_survive_track[x3][y3-1]=0;
                       S_hungry_track[x3][y3-1]=0;
                        breed_success=true;

                   }
                   if(random_breed==3 && Tracking_cell(b2,x3,y3+1)==false && y3!=19 ) ///breed right
                   {
                        b2[x3][y3+1]='X';

                        S_survive_track[x3][y3+1]=0;
                        S_hungry_track[x3][y3+1]=0;
                        breed_success=true;
                   }
                  }S_survive_track[x3][y3]=0;
                    snake++;
                  }break;
            case '1':
                {
                    S_survive_track[x3][y3]=0;

                }break;
        }
}}
};
