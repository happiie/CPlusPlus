#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student {
    friend class LList;

    public:

        Student(string a, string b) : name(a), metric(b), next(0) {};
        void setNext(Student *s) { next = s; };
        Student* getNext() const { return next; };
        string getName() const { return name; };

        friend ostream& operator<< (ostream& os, const Student& s) {
            os << s.name << " (" << s.metric << ")";
            return os;
        }

    private:
        string name;
        string metric;
        Student *next;
};
#endif // STUDENT_H
