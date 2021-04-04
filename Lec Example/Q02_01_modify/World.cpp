#include <iostream>
#include <cstdlib>
#include <ctime>

#include "World.h"
#include "Snake.h"
#include "Mouse.h"

using namespace std;

World::World(unsigned int seed) {
    srand(seed);

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = NULL;

    createOrganisms(SNAKE, NUM_SNAKE);
    createOrganisms(MOUSE, NUM_MOUSE);
}

int World::randomNumber(int M) const {
    return rand()%M;
}

void World::createOrganisms(OrganismType orgType, int N) {
	int xRand = randomNumber(SIZE);
	int yRand = randomNumber(SIZE);

    for (int i = 0; i < N; i++) {
		while (grid[xRand][yRand] != NULL) {
			xRand = randomNumber(SIZE);
			yRand = randomNumber(SIZE);
		}

		if (orgType == 0)
            grid[xRand][yRand] = new Snake (this, xRand, yRand);
		else
			grid[xRand][yRand] = new Mouse (this, xRand, yRand);
    }
}

Organism* World::getAt(int x, int y) const {
    if  ((x >= 0) && (x < SIZE) && (y >= 0) && (y < SIZE))
        return grid[x][y];
    else
        return NULL;
}

void World::setAt(int x, int y, Organism* org) {
    if ((x >= 0) && (x < SIZE) && (y >= 0) && (y < SIZE))
            grid[x][y] = org;
}

void World::simulateOneStep() {
    resetOrganisms();
    moveOrganism(SNAKE);
    moveOrganism(MOUSE);
    makeStarve();
    breedOrganisms();
}

void World::resetOrganisms() {
	for (int i=0; i<SIZE; i++)
        for (int j=0; j<SIZE; j++)
			if (grid[i][j] != NULL)
				grid[i][j]->setMoved(false);
}

void World::moveOrganism(OrganismType aType) {
	for (int i=0; i<SIZE; i++)
        for (int j=0; j<SIZE; j++)
			if((grid[i][j] != NULL) && !((grid[i][j]->hasMoved())) && (grid[i][j]->getType() == aType))
				grid[i][j]-> Move();
}

void World::makeStarve() {
	for (int i=0; i<SIZE; i++)
        for (int j=0; j<SIZE; j++)
            if ((grid[i][j] != NULL) && (grid[i][j]->getType() == SNAKE)) {
                    Snake* b = (Snake*)grid[i][j];
                    if (b->Starve()) {
                        delete grid[i][j];
                        grid[i][j] = NULL;
                    }
            }
}

void World::breedOrganisms() {
	for (int i=0; i<SIZE; i++)
        for (int j=0; j<SIZE; j++)
            if (grid[i][j] != NULL)
                grid[i][j]->Breed();
}

void World::display(int x) const {
    int numSnake = 0;
    int numMouse = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == NULL)
                cout << "_";
            else if (grid[i][j]->getType() == SNAKE) {
                cout << "X";
                numSnake++;
            }
            else if (grid[i][j]->getType() == MOUSE) {
                cout << "O";
                numMouse++;
            }
            else
                cout << "!";
        }
        cout << endl;
    }
    cout << "\nIteration " << x <<  ": " << numSnake << " Snake & " << numMouse << " Mouse " <<endl;
}
