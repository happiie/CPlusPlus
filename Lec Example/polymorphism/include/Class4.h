#ifndef CLASS4_H
#define CLASS4_H
#include "Class2.h"
#include "Class1.h"


class Class4 : public Class2
{
    public:
        void setpro4(int);
        int getpro4();
        void display4();

    protected:
        int pro4;

};

#endif // CLASS4_H
