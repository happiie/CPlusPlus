#include <iostream>

#include "Organism.h"
#include "World.h"

Organism::Organism() {
    world = NULL;
    moved = false;
    breedTicks = 0;
    x = 0;
    y = 0;
}

Organism::Organism(World* aWorld, int xcoord, int ycoord) {
    world = aWorld;
    x = xcoord;
    y = ycoord;
    breedTicks = 0;
    moved = false;
    world->setAt(x, y, this);
}

void Organism::setMoved(bool hasMoved) {
    moved = hasMoved;
}

bool Organism::hasMoved() const {
    return moved;
}

void Organism::movesTo(int xNew, int yNew) {
	world->setAt(xNew, yNew, this);
	world->setAt(x , y, NULL);
	setMoved(true);
	x = xNew;
	y = yNew;
}

void Organism::breedAtAdjacentCell()  {
    int direction = world->randomNumber(4);
    if((direction == UP) && (y < SIZE - 1) && (world->getAt(x, y + 1) == NULL) )
        generateOffspring(x, y + 1);
    else if((direction == DOWN) && (y > 0) && (world->getAt(x, y - 1) == NULL) )
        generateOffspring(x, y - 1);
    else if((direction == LEFT) && (x > 0) && (world->getAt(x - 1, y) == NULL) )
        generateOffspring(x - 1, y);
    else if((direction == RIGHT) && (x < SIZE - 1) && (world->getAt(x + 1, y) == NULL) )
        generateOffspring(x + 1, y);
}
