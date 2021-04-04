#ifndef MOUSE_H
#define MOUSE_H

#include <iostream>
#include "Organism.h"
#include "World.h"

class Mouse : public Organism {
public:
	Mouse();
	Mouse(World* aWorld, int xcoord, int ycoord);
	virtual void Move();
	virtual void Breed();
	virtual OrganismType getType();
	virtual void generateOffspring(int whereX, int whereY);
};

#endif
