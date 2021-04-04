#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class point
{
    public:
    friend ostream& operator<< (ostream&, const point&);
    friend istream& operator>> (istream&, point&);

    point() : x(0.0), y(0.0), z(0.0){};
    point(double x1, double y1, double z1) : x(x1), y(y1), z(z1) {};

    void display();

    void operator=(const point& );
    point operator+(const point& );
    void operator++();
    void operator+=(int);
    bool operator== (const point& );

    private:
        double x;
        double y;
        double z;
};

#endif // POINT_H
