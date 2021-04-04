#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <string>

using namespace std;

class Restaurant
{
    public:
        Restaurant();
        void setUserName();
        void setPassword();
        void setEmail();
        void setCallNumber();
        string getUserName();
        string getPassword();
        string getEmail();
        string getCallNumber();
        bool userCheck(string);
        bool pwdCheck(string);

    private:
        string username;
        string password;
        string email;
        string callNumber;
};

#endif // RESTAURANT_H
