#ifndef PERSON_H
#define PERSON_H
#include "date.h"
#include <string>
using namespace std;

class person
{
    public:
        person(string, date);
        void setName(string);
        void setDOB(date);
        string getName();
        date getDOB();
        void display();

    private:
        string name;
        date doBirth;

};

#endif // PERSON_H
