#ifndef MOUSE_H
#define MOUSE_H
#include "Organism.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
class Mouse : public Organism
{
    public:
        Mouse();
        void M_random_place(char [][20],int);
        virtual void MOVE(char [][20]);
        void M_breed(char [][20]);


    private:

        int M_survive_track[20][20]={};
};

#endif // MOUSE_H
