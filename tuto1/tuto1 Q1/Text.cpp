#include "Text.h"
#include <string>

using namespace std;

Text::Text()
{
    //ctor
}

Text::~Text()
{
    //dtor
}

void Text::setText(string a)
{
    text = a;
}

string Text::getText()
{
    return text;
}
