#include <iostream>
#include "Class1.h"
#include "Class2.h"
#include "Class4.h"

using namespace std;

int main()
{
    cout<<"Hello Genius !!!"<<endl;

    Class1 c1;
    c1.display1();

    Class2 c2;
    c2.display1();
    c2.display2();

    Class4 c4;
    c4.display1();
    c4.display2();
    c4.display4();

    return 0;
}
