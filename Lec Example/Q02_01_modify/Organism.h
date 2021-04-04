#ifndef ORGANISM_H
#define ORGANISM_H

enum OrganismType {SNAKE=0, MOUSE};

class World;        //forward declaration

class Organism {
    public:
        Organism();
        Organism(World* aWorld, int xcoord, int ycoord);
		virtual void Move() = 0;
        virtual void Breed() = 0;
        virtual OrganismType getType() = 0;
        void setMoved(bool);
        bool hasMoved() const;

    protected:
        virtual void generateOffspring(int whereX, int whereY) = 0;
		void movesTo(int xNew, int yNew);
        void breedAtAdjacentCell();
        int x;
        int y;
        bool moved;
        int breedTicks;
        World* world;
};

#endif
