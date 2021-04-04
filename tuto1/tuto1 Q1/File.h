#ifndef FILE_H
#define FILE_H
#include <string>
#include "Text.h"
#include "Person.h"

using namespace std;



class File : public Text
{
    public:
        File();
        virtual ~File();
        void setPathname(string);
        string getPathname();
        void setAuthor(string);
        void getAuthor();

    protected:

    private:
        string pathname;
        Person author;
};

#endif // FILE_H
