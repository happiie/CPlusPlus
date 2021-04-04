#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
    public:
        Person();
        Person(string );
        Person(const Person&);
        void setName(string);
        string getName();
        virtual ~Person();

    protected:

    private:
        string name;
};

#endif // PERSON_H
