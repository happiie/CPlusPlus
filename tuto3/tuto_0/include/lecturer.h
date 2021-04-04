#ifndef LECTURER_H
#define LECTURER_H
#include <iostream>

using namespace std;


class lecturer
{
    public:
        lecturer();
        lecturer(string , string);
        void setname(string);
        string getname();
        void setposition(string);
        string getposition();
        void displayInfo();



    private:
        string lectname;
        string lectpost;
};

#endif // LECTURER_H
