#include "File.h"
#include <string>
#include "Person.h"
#include "Text.h"
#include <iostream>

using namespace std;


File::File() : Text()
{
    //ctor
}

File::~File()
{
    //dtor
}

void File::setPathname(string a)
{
    pathname = a;
}

string File::getPathname()
{
    return pathname;
}

void File::setAuthor(string b)
{
    author.setName(b);
}

void File::getAuthor()
{
    cout << author.getName();
}


