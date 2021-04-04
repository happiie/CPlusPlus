#ifndef LLIST_H
#define LLIST_H

#include "Student.h"

class LList
{
    public:
        LList();
        bool isEmpty();
        void printList();
        void insertItem(const string, const string);
        void deleteItem(const string);
        int findLength();
        bool searchItem(const string);

    private:
        Student *first;
};

#endif // LLIST_H
