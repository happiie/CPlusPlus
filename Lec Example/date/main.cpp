#include <iostream>
#include "date.h"
#include "person.h"
using namespace std;

int main()
{
    date today(28,10,1997);
    today.display();

    //date obj;
    person stud("AKMAL FARHAN KAMSANI TUAH", today);
    stud.display();

    return 0;
}
