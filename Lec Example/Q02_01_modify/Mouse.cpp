#include "Mouse.h"

Mouse::Mouse() : Organism(){ }

Mouse::Mouse(World* aWorld, int xcoord, int ycoord) : Organism(aWorld,xcoord, ycoord){}

void Mouse::Move(){
	int direction = world->randomNumber(4);
    if((direction == UP) && (y < SIZE - 1) && (world->getAt(x, y + 1) == NULL) )
        movesTo(x, y + 1);
    else if((direction == DOWN) && (y > 0) && (world->getAt(x, y - 1) == NULL) )
        movesTo(x, y - 1);
    else if((direction == LEFT) && (x > 0) && (world->getAt(x - 1, y) == NULL) )
        movesTo(x - 1, y);
    else if((direction == RIGHT) && (x < SIZE - 1) && (world->getAt(x + 1, y) == NULL) )
        movesTo(x + 1, y);
    breedTicks++;
}

void Mouse::Breed(){
	if (breedTicks >= BREED_MOUSE)
		breedAtAdjacentCell();
}

OrganismType Mouse::getType(){
	return MOUSE;
}

void Mouse::generateOffspring(int whereX, int whereY){
	Mouse* newMouse = new Mouse(world, whereX, whereY);
    breedTicks = 0;
}
