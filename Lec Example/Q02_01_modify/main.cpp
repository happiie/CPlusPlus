#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "World.h"

using namespace std;

int main()
{
    World myWorld(time(NULL));
    myWorld.display(0);
    cin.get();

    for (int i=1; i<=20; i++) {
//        system("cls");
        myWorld.simulateOneStep();
        myWorld.display(i);
        cin.get();
    }

    return 0;
}
