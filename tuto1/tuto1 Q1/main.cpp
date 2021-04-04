#include "Email.h"
#include <string>
#include "Person.h"
#include "Text.h"
#include <iostream>
#include "File.h"

using namespace std;

bool containKeyword(Text& obj, string keyword)
{
    if (obj.getText().find(keyword)!= string::npos)
        return true;
    return false;
}


int main()
{
    Email e1;
    File f1;
    Text send, receive;
    string s, r, t, c, p, a;

    cout << "Sender : ";
    getline(cin, s);
    send.setText(s);
    while(containKeyword(send, "@") == false)
    {
        cout << "Invalid email." << endl;
        cout << "Sender : ";
        getline(cin, s);
        send.setText(s);
    }

    cout << "Recipient : ";
    getline(cin, r);
    receive.setText(r);
    while(containKeyword(receive, "@") == false)
    {
        cout << "Invalid email." << endl;
        cout << "Receive : ";
        getline(cin, r);
        receive.setText(r);
    }

    cout << "Title : " ;
    getline(cin, t);

    cout << "Content : ";
    getline(cin, c);

    cout << "Author : ";
    getline(cin, a);

    e1.setSender(s);
    e1.setRecipient(r);
    e1.setTitle(t);
    e1.setContent(c);
    f1.setAuthor(a);
    p = "hotmail.com";
    f1.setPathname(p);

    cout << "Pathname : " << f1.getPathname() ;




}
