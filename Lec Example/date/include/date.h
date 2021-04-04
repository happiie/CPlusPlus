#ifndef DATE_H
#define DATE_H

class date
{
    public:
        void display();
        date();
        date(int, int, int);
        void setDay(int);
        void setMonth(int);
        void setYear(int);
        int getDay();
        int getMonth();
        int getYear();

    private:
        int day, month, year;

};

#endif // DATE_H
