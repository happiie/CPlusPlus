#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class employee
{
    public:
        employee();
        void setID();
        void displayStorage();
        void displayFood();
        void setOrder();
        int getOrder();
        string getID();

    private:
        string cID;
        int order;
};

#endif // EMPLOYEE_H
