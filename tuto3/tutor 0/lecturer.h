#ifndef LECTURER_H_INCLUDED
#define LECTURER_H_INCLUDED

#include <string>
using namespace std;
class lecturer
{
    public:

        lecturer(string,string);
        lecturer();

        string getnameh();
        string getposition();
        void setposition(string);
        void setnameh(string);

    private:

    string position;
    string nameh;


};

#endif // LECTURER_H_INCLUDED
