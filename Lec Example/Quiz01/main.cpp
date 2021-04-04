#include <iostream>
#include "LList.h"

using namespace std;

int main()
{
    LList LIST;
    LIST.printList();
    LIST.insertItem("Kenny Lee", "KIE170001");
    LIST.printList();
    LIST.insertItem("Benny Lee", "KIE170002");
    LIST.insertItem("Jenny Lee", "KIE170003");
    LIST.insertItem("Tony Lee", "KIE170004");
    LIST.insertItem("Tommy Lee", "KIE170005");
    LIST.printList();
    LIST.deleteItem("Benny Lee");
    LIST.printList();
    LIST.deleteItem("Tommy Lee");
    LIST.printList();
    LIST.insertItem("Bonny Lee", "KIE170006");
    LIST.printList();
    LIST.deleteItem("Joanne Lee");

    return 0;
}
