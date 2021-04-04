#include "Email.h"
#include <string>
#include "Person.h"
#include "Text.h"
#include <iostream>

using namespace std;

Email::Email()
{
    //ctor
}

Email::~Email()
{
    //dtor
}

void Email::setSender(string a)
{
    sender.setName(a);
}

void Email::setRecipient(string b)
{
    recipient.setName(b);
}

void Email::setTitle(string c)
{
    title = c;
}

void Email::setContent(string d)
{
    content.setText(d);
}

void Email::getSender()
{
    cout << sender.getName();
}

void Email::getRecipient()
{
    cout << recipient.getName();
}

string Email::getTitle()
{
    return title;
}

void Email::getContent()
{
    cout << content.getText();
}

