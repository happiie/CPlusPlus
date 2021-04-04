#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string.h>

using namespace std;

class course
{
    friend void displayInfo(course &);

    public:
        course();
        course(string, string);
        course(string);
        void setcoursename(string);
        void setcode(string);
        string getcoursename();
        string getcode();

    private:
        string courseName;
        string courseCode;
};




#endif // COURSE_H
