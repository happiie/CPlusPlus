#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class student
{
public:
    student(string,string,int);
    student();
    string getnames();
    string getid();
    int getmark();
    string getgrade();
    void setnames(string);
    void setid(string);
    void setmark(int);
    void setgrade(int);

private:
    string names,id;
    int mark;
    string grade;
    static int a;

};

#endif // STUDENT_H_INCLUDED
