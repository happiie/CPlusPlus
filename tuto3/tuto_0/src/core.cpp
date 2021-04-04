#include "core.h"
#include "course.h"
#include "lecturer.h"
#include "student.h"
#include <iostream>
#include<string>

using namespace std;

core::core(course c0, lecturer l0)
{
    c = c0;
    l = l0;
}
void core::display()
{
    for(int i=0 ;i<10;i++ )
    {
        cout << s[i].getname() << " | " << s[i].getId() << " | " <<s[i].getmark()<<"("<<s[i].getgrade()<<")"<<endl;
    }

}

