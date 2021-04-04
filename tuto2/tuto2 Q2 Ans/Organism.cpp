#include "Organism.h"

Organism::Organism()
{
    //ctor
}
bool Organism::Tracking_cell(char z[][20],int r,int c)
{
    if(z[r][c]=='O' || z[r][c]=='X')
    {
        return true;
    }
    else
    {
        return false;
    }
}

char Organism::check_A_cell(char a[][20],int x,int y)
{  char empty_cell='1';

    if(a[x+1][y]!='O' && a[x+1][y]!='X' && x!=19) ///down
        {empty_cell='0';
                        }
    else if(a[x-1][y]!='O' && a[x-1][y]!='X' && x!=0) ///up
        {empty_cell='0';
                        }
    else if(a[x][y+1]!='O' && a[x][y+1]!='X' && y!=19) ///right
        {empty_cell='0';
                        }
    else if(a[x][y-1]!='O' && a[x][y-1]!='X' && y!=0) ///left
        {empty_cell='0';
                        }
    else
        empty_cell='1';
    return empty_cell;
}
int Organism::getmouse_No()
{
    return mouse;
};

int Organism::getsnake_No()
{
    return snake;
};
void Organism::MS_Track(char t[][20])
{
    for(int x2=0;x2<20;x2++)
        for(int y2=0;y2<20;y2++)
        SnakeMouse_track[x2][y2]=Tracking_cell(t,x2,y2);


};
void Organism::No_Track(char p[][20])
{ mouse=0;
    snake=0;
    for(int s=0;s<20;s++)
        for(int e=0;e<20;e++)
    {
        if(p[s][e]=='O')
            mouse++;
        if(p[s][e]=='X')
            snake++;
    }
}
