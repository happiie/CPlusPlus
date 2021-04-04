#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;

class person
{
    public:
        person();
        person(string );
        person(const person&);
        string getName();
        void setName(string );

        friend ostream& operator<< (ostream&, const person& );
        friend istream& operator>> (istream&, person& );
        person operator= (const person&);

        string name;
};

#endif // PERSON_H
