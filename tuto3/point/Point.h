#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;
class Point
{
    public:
        Point();
        Point (double,double,double);
        friend istream& operator>> (istream&, Point&);
        friend ostream& operator<< (ostream&, const Point&);
        Point operator+ (const Point&);
        Point operator- (const Point&);
        double operator% (const Point&);
        void operator++ ();
        void operator++(int);
    private:
        double x,y,z;
};

#endif // POINT_H
