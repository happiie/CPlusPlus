#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <stdlib.h>
#include "Organism.h"
class Snake : public Organism
{
    public:
        Snake();
        virtual void MOVE(char[][20]);
        void S_random_place(char [][20],int);
        void S_breed(char [][20]);
        char S_check_cell(char[][20],int,int);

    private:
        int S_survive_track[20][20]={};
        int S_hungry_track[20][20]={};
};

#endif // SNAKE_H
