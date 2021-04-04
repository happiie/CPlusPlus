#ifndef ORGANISM_H
#define ORGANISM_H
#include <iostream>
using namespace std;
class Organism
{
    public:
        int mouse,snake;
        bool SnakeMouse_track[20][20]={};
        Organism();
        virtual void MOVE(char[][20])=0;

        bool Tracking_cell(char[][20],int,int);
        char check_A_cell(char[][20],int,int);
        int getmouse_No();
        int getsnake_No();
        void MS_Track(char [][20]);
        void No_Track(char[][20]);
    private:

};

#endif // ORGANISM_H
