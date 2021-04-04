#ifndef TEXT_H
#define TEXT_H
#include <string>

using namespace std;


class Text
{
    public:
        Text();
        virtual ~Text();
        void setText(string);
        string getText();

    protected:
        string text;

    private:

};

#endif // TEXT_H
