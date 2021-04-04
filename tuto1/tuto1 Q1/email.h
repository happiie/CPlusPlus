#ifndef EMAIL_H
#define EMAIL_H
#include <string>
#include "Person.h"
#include "Text.h"
#include <iostream>

using namespace std;


class Email
{
    public:
        Email();
        virtual ~Email();
        void setSender(string);
        void setRecipient(string);
        void setTitle(string);
        void setContent(string);
        void getSender();
        void getRecipient();
        string getTitle();
        void getContent();

    protected:

    private:
        Person sender;
        Person recipient;
        string title;
        Text content;
};

#endif // EMAIL_H
