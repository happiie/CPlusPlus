#include <iostream>
#include <string.h>
#include "course.h"
#include "lecturer.h"
#include "student.h"
#include "core.h"

using namespace std;

void displayInfo(course &c)
{
    cout << c.courseCode << " : " << c.courseName << endl;
}

int main()
{
    course c1;
    //course Course("KIE1008", " Programming II");

    displayInfo(c1);
    //displayInfo(Course);

    lecturer Lecturer("Chow Chee Onn" , "Associate Professor");
    Lecturer.displayInfo();

    core Core(c1,Lecturer);
    Core.display();

    return 0;
}
