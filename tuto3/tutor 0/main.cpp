#include <iostream>
#include "core.h"
#include "student.h"
#include "course.h"
#include "lecturer.h"

using namespace std;
void display(course &x)
{
    cout<<"Gradebook for "<<x.getnamec()<<": "<<x.getcode()<<endl;
}

int main()
{
    course c("PROGRAMMING II","KIE1008");
    lecturer l("DR CHOW CHEE ONN","ASSOCIATE PROFESSOR");
    core test(c,l);
    test.print();
    test.getc();



    return 0;
}
