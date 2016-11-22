#ifndef date_h
#define date_h 2016

class Date {
public:
    Date(int date, int dmonth, int dyear): day(date),month(dmonth),year(dyear){}

    int get_date() {
        return day;
    }
    int get_month() {
        return month;
    }
    int get_year() {
        return year;
    }
private:
    int day;
    int month;
    int year;
};
#endif
