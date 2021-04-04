#ifndef REGISTERID_H_INCLUDED
#define REGISTERID_H_INCLUDED
#include<iostream>
#include<string>

using namespace std;

class registerID
{
public:
    registerID(){};
    void setAddress(){string a; cout<<"  Enter address:"; cin>>a; address=a;};
    void setEmail(){string e; cout<<"  Enter email:"; cin>>e; email=e;};
    void setUser(){string u; cout<<"  Enter username:"; cin>>u; username=u;};
    void setPass(){string p; cout<<"  Enter password:"; cin>>p; password=p;};
    string getAddress(){return address;};
    string getEmail(){return email;};
    string getUser(){return username;};
    string getPass(){return password;};
    bool checkUser(string );
    bool checkPass(string );
protected:
    string address,email;
private:
    string username,password;
};

bool registerID::checkUser(string a)
{
    if(a==username)
        return true;
    else
        return false;
}

bool registerID::checkPass(string b)
{
    if(b==password)
        return true;
    else
        return false;
}
#endif // REGISTERID_H_INCLUDED
