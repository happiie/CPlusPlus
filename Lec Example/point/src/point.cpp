#include "point.h"
#include <iostream>

using namespace std;

void point::display() {
    cout << x << " , " << y <<" , "<< z << endl;
}

void point::operator= (const point& other) {
    x = other.x;
    y = other.y;
    z = other.z;
}

point point::operator+ (const point& other) {
    double result_x = x + other.x;
    double result_y = y + other.y;
    double result_z = z + other.z;
    return point(result_x, result_y, result_z);
}

void point::operator++ () {
    x +=1;
    y +=1;
    z +=1;
}

void point::operator+= (int n) {
    x +=n;
    y +=n;
    z +=n;
}

bool point::operator== (const point& other) {
    if (x == other.x && y == other.y)
        return true;

    return false;
}

ostream& operator<< (ostream& os, const point& other) {
    os << other.x << " +j" << other.y << endl;
    return os;
}

istream& operator>> (istream& is, point& other) {
    char ch;

    is >> ch;
    is >> other.x;
    is >> ch;
    is >> other.y;
    is >> ch;

    return is;
}
