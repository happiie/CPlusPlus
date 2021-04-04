#ifndef TRUCK_H
#define TRUCK_H
#include "vehicle.h"

class truck: public vehicle
{

        friend ostream& operator<< (ostream&, truck& );
        friend istream& operator>> (istream&, truck& );

    public:
        truck();
        truck(int,int);
        truck(const truck &);
        void setLoad(int);
        void setTow(int);
        int getLoad();
        int getTow();

    private:
        int loadCap,towCap;
};

#endif // TRUCK_H
