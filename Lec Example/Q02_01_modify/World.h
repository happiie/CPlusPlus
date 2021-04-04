#ifndef WORLD_H
#define WORLD_H

#include "Organism.h"

enum MOVE {UP = 0, DOWN, LEFT, RIGHT};
const int SIZE = 20;
const int NUM_MOUSE = 50;
const int NUM_SNAKE = 10;
const int BREED_MOUSE = 2;
const int BREED_SNAKE = 5;
const int STARVE_SNAKE = 3;

class World
{
    public:
        World(unsigned int);
        Organism* getAt(int, int) const;
        int randomNumber(int) const;
        void setAt(int, int, Organism*);
        void display(int) const;
        void simulateOneStep();

    private:
        Organism* grid[SIZE][SIZE];
        void createOrganisms(OrganismType, int);
        void resetOrganisms();
        void moveOrganism(OrganismType);
        void makeStarve();
        void breedOrganisms();
};

#endif // WORLD_H
