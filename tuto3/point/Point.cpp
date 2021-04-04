#include "Point.h"
#include <cmath>
#include<iostream>
using namespace std;
Point::Point()
{
    //ctor
}
Point::Point (double a,double b,double c)
{
    x=a;
    y=b;
    z=c;
}
istream& operator>> (istream& is, Point& a)
{
    char c;
    is>>c; //(
    is>>a.x;
    is>>c; //,
    is>>a.y;
    is>>c; //,
    is>>a.z;
    is>>c; //)
}
ostream& operator<< (ostream& os, const Point& b)
{
    os<<"("<<b.x<<", "<<b.y<<", "<<b.z<<")";
}
Point Point::operator+ (const Point& c)
{
    double aa=x+c.x;
    double bb=y+c.y;
    double cc=z+c.z;
    return Point (aa,bb,cc);
}
Point Point::operator- (const Point& e)
{
    double aa=x-e.x;
    double bb=y-e.y;
    double cc=z-e.z;
    return Point(aa,bb,cc);
}
double Point::operator% (const Point& g)
{
    double dist1=this->x-g.x;
    double dist2=this->y-g.y;
    double dist3=this->z-g.z;
    double s=dist1*dist1+dist2*dist2+dist3*dist3;
    return sqrt(s);
}

void Point::operator++ ()
{
    x++;
    y++;
    z++;
}
void Point::operator++(int)
{
    x++;
    y++;
    z++;
}
