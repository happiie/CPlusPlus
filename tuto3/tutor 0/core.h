#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED
#include "course.h"
#include "lecturer.h"
#include "student.h"
#include <string>
using namespace std;

class core

{
public:
    core(course,lecturer);
    void  print();
    void getl();
    void getc();
private:
    course c1;
    lecturer l1;
    student s[10];


};


#endif // CORE_H_INCLUDED
