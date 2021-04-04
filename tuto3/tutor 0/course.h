#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED
#include<string>
using namespace std;
class course
{
    friend void display(course &);
public :

    course();
    ~course();
    course(string,string);
    string getnamec();
    void setnamec(string);
    string getcode();
    void setcode(string);




private :

    string namec,code;


};


#endif // COURSE_H_INCLUDED
