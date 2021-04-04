#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>

using namespace std;

class Snake
{
    public:
        Snake();
        void moves();
        void die();
        bool getSurvive();
        int checkMouse1(char[20][20],int,int);
        int checkMouse2(char[20][20],int,int);
        int checkMouse3(char[20][20],int,int);
        int checkMouse4(char[20][20],int,int);
        int checkMouse5(char[20][20],int,int);
        int checkMouse6(char[20][20],int,int);
        int checkMouse7(char[20][20],int,int);
        int checkMouse8(char[20][20],int,int);
        void setZeroStarve();
        void setStarve();
        int getStarve();
        void setBreed();
        int getBreed();
        void send(int);
        int get();
        bool check();
        bool checkAll();
        void reset();

    protected:

    private:
        bool survive=true;
        bool eat=true;
        int starve=0;
        int breed=0;
        int place=0;
        bool one=false;
        bool two=false;
        bool three=false;
        bool four=false;
};

#endif // SNAKE_H
