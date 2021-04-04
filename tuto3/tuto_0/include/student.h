#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;


class student
{
    public:
        student();
        void setname(string);
        void setId(string);
        void setmark(int);
        void setgrade(int);
        string getname();
        string getId();
        int getmark();
        string getgrade();

    private:
        string Sname;
        string SId;
        int Smark;
        string Sgrade;


};

#endif // STUDENT_H
