#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include "Organism.h"
#include "World.h"

class Snake : public Organism {
public:
	Snake();
    Snake(World* aWorld, int xcoord, int ycoord);
    virtual void Move();
    virtual void Breed();
    virtual OrganismType getType();
    virtual void generateOffspring(int whereX, int whereY);
  	bool Starve();
	int starveCounter;
};

#endif
