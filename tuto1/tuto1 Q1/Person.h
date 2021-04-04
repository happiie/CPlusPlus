#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;



class Person
{
    public:
        Person();
        Person(string);
        virtual ~Person();
        void setName(string);
        string getName();

    protected:

    private:
        string name;
};

#endif // PERSON_H
