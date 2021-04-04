#ifndef CORE_H
#define CORE_H
#include "course.h"
#include "lecturer.h"
#include "student.h"

#include <iostream>

using namespace std;


class core
{
    public:

        core(course , lecturer);
        void display();
    private:
        course c;
        lecturer l;
        student s[10];

};

#endif // CORE_H
