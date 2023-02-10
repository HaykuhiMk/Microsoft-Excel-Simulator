#ifndef DATE_H
#define DATE_H

struct Day
{
    explicit Day(int d);
    int val;
};

struct Month
{
    explicit Month(int m);
    int val;
};

struct Year
{
    explicit Year(int y);
    int val;
};

class Date
{
public:
    bool operator!=(const Date& rhs);
    Date(const Month& m, const Day& d, const Year& y);   
    void print() const;
    int getMonth() const;
    int getDay() const;
    int getYear() const;


private:
    int month;
    int day;
    int year;
};

#endif  //DATE_H