#ifndef MOUSE_H
#define MOUSE_H

#include <iostream>

using namespace std;

class Mouse
{
    public:
        Mouse();
        void die();
        bool getSurvive();
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
        int breed=0;
        int place=0;
        bool one=false;
        bool two=false;
        bool three=false;
        bool four=false;
};

#endif // MOUSE_H
