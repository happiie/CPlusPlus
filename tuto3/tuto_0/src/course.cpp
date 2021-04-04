#include "course.h"
#include <iostream>

using namespace std;

course::course()
{

    cout << "enter course's code: " ;
    getline(cin, courseCode);
    cout << "enter course's name: " ;
    getline(cin, courseName);

}

course::course(string code, string name)
{
    courseName = name;
    courseCode = code;
}

course::course(string code)

{
        courseCode = code;
        cout<< "enter the course's name ;" <<endl;
        getline(cin ,courseName);
}

void course::setcoursename(string name)
{
    courseName = name;
}


void course::setcode(string code)
{
    courseCode = code;
}

string course::getcoursename()
{
    return courseName;
}

string course::getcode()
{
    return courseCode;
}






