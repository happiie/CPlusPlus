#include "Restaurant.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Restaurant::Restaurant(){}

void Restaurant::setUserName()
{
    string name;
    cout<<"Please Enter Username : ";
    cin>>username;
    username = name;
}

void Restaurant::setPassword()
{
    string pass;
    cout<<"Please Enter Password : ";
    cin>>password;
    password = pass;
}

void Restaurant::setEmail()
{
    string Email;
    cout<<"Please Enter Email : ";
    cin>>email;
    email = Email;
}

void Restaurant::setCallNumber()
{
    string callNum;
    cout<<"Please Enter Call Number : ";
    cin>>callNumber;
    callNumber = callNum;
}

string Restaurant::getUserName()
{
    return username;
}

string Restaurant::getPassword()
{
    return password;
}

string Restaurant::getEmail()
{
    return email;
}
string Restaurant::getCallNumber()
{
    return callNumber;
}
bool Restaurant::userCheck(string u)
{
    if(u==username)
        return true;
    else
        return false;
}

bool Restaurant::pwdCheck(string p)
{
    if(p==password)
        return true;
    else
        return false;
}
