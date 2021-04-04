#include "LList.h"

LList::LList() {
    first = NULL;
}

bool LList::isEmpty() {
    return (first == 0);
}

void LList::printList() {
    if (isEmpty()) {
        cout << "0 Student.\n\n";
        return;
    }

    cout << findLength() << " student(s).\n";

    Student *tmp = first;
    int counter=0;
    while (tmp!=NULL) {
        counter++;
        cout << *tmp << "  ";
        tmp = tmp->getNext();
        if (counter%3==0)
            cout << endl;
    }
    cout << endl << endl;
}

int LList::findLength() {
    if (isEmpty()) {
        return 0;
    }

    int counter=0;
    Student *tmp = first;
    while (tmp!=NULL) {
        counter++;
        tmp = tmp->getNext();
    }
    return counter;
}

void LList::deleteItem(const string s) {
    if (!searchItem(s)) {
        cout << s << " not found\n";
        return;
    }

    Student *tmp = first;
    Student *prev;

    while (tmp!=NULL) {
       if (tmp->getName() == s)
           break;
       prev = tmp;
       tmp = tmp->getNext();
    }

    if (tmp == first)
        first = tmp->getNext();
    else
        prev->setNext(tmp->getNext());

    delete tmp;
    cout << s << " deleted\n";
}

bool LList::searchItem(const string s) {
    Student *tmp = first;

    while (tmp != NULL) {
        if (tmp->getName() == s)
            return true;
        tmp = tmp->getNext();
    }

    return false;
}

void LList::insertItem(const string s, const string m) {
    Student* newNode = new Student(s, m);
    newNode->setNext(NULL);

    Student *tmp = first;

    if (isEmpty() || tmp->getName() > s) {
        newNode->setNext(first);
        first = newNode;
    }
    else {
        Student *left = first;
        tmp = tmp->getNext();
        while (tmp!=NULL && tmp->getName() < s) {
            left = tmp;
            tmp = tmp->getNext();
        }
        newNode->setNext(tmp);
        left->setNext(newNode);
    }
}
