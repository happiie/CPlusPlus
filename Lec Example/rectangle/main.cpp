#include <iostream>
using namespace std;

class rectangle
{
private :
    float width, length, area;

public :
    void setData(float,float);
    void calcArea();
    float getWidth();
    float getLength();
    float getArea();
};

void rectangle::setData(float wid, float len)
{
    width=wid;
    length=len;
}
void rectangle::calcArea()
{
    area = width * length;
}
float rectangle::getWidth()
{
    return width;
}
float rectangle::getLength()
{
    return length;
}
float rectangle::getArea()
{
    return area;
}

int main()
{
    float wid, len, area;

    rectangle box;
    rectangle *boxPtr;
    boxPtr = &box;

    boxPtr -> setData( 15 , 12 );
    boxPtr -> calcArea();

    len = boxPtr -> getLength();
    wid = boxPtr -> getWidth();
    area = boxPtr -> getArea();

    cout << "Length : " << len << " Width : " << wid << " Area : " << area << endl;
}
