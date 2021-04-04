#include "Snake.h"

Snake::Snake() : Organism(){ }

Snake::Snake(World* aWorld, int xcoord, int ycoord) : Organism(aWorld,xcoord, ycoord){starveCounter=0;}

void Snake::Move(){
	int direction = world->randomNumber(4);
    if((direction == UP) && (y < SIZE - 1) && ((world->getAt(x, y + 1) == NULL) || (world->getAt(x, y + 1)->getType() == MOUSE)))
        movesTo(x, y + 1);
    else if((direction == DOWN) && (y > 0) && ((world->getAt(x, y - 1) == NULL))) {
        movesTo(x, y - 1);
        starveCounter++;
    }
    else if((direction == LEFT) && (x > 0) && ((world->getAt(x - 1, y) == NULL))) {
        movesTo(x - 1, y);
        starveCounter++;
    }
    else if((direction == RIGHT) && (x < SIZE - 1) && ((world->getAt(x + 1, y) == NULL))) {
        movesTo(x + 1, y);
        starveCounter++;
    }

    breedTicks++;
}

void Snake::Breed(){
    if (breedTicks >= BREED_SNAKE)
		breedAtAdjacentCell();
}

OrganismType Snake::getType(){
    return SNAKE;
}

bool Snake::Starve() {
    if (starveCounter >= STARVE_SNAKE)
        return 1;

	return 0;
}

void Snake::generateOffspring(int whereX, int whereY){
	Snake* newSnake = new Snake(world, whereX, whereY);
    breedTicks = 0;
}
